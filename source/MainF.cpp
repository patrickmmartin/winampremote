/*
winamp remote control suite ©Patrick Michael Martin 2000, 2001, 2002

Copyright (C) 2000,2001,2002  Patrick M. Martin

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Patrick M. Martin may be reached by email at patrickmmartin@gmail.com.
*/

#include <vcl.h>
#pragma hdrstop

#include <registry.hpp>
#include <shellapi.h>

// forms...

#include "MainF.h"
#include "messageF.h"
#include "AboutF.h"

#include "PlaylistF.h"
#include "SettingsF.h"
#include "CommandF.h"
#include "ServersF.h"

// RPC functions
#include "RPCException.h"
#include "RPCBind.h"
#include "DetailsF.h"
#include "remotestrs.h"

#include <math.h>
#include "WinampClientBase.h"
#include "CursorGuard.h"
#include "remoteDM.h"

const int POLL_ERROR_FACTOR = 10; // seconds


#pragma resource "*.dfm"
TfrmMain *frmMain;


__fastcall TfrmMain::TfrmMain(TComponent* Owner)
  : TForm(Owner)
{
}

void __fastcall TfrmMain::TrayNotify(TMessage& Msg)
{
  POINT MousePos;
  WAPlaybackStatus Status = dmRemote->PlaybackStatus();

  switch(Msg.LParam)
  {
    case WM_RBUTTONDOWN:
    // get round clicks to spurious systray windows when show
      DoubleClickedR = false;
    break;

    case WM_RBUTTONUP:
      if (DoubleClickedR)
        dmRemote->ShowMainForm->Execute();
      else  
        if (GetCursorPos(&MousePos))
        {
            pmnuMain->PopupComponent = frmMain;
            SetForegroundWindow(Handle);
            pmnuMain->Popup(MousePos.x, MousePos.y);
        }
    break;

    case WM_RBUTTONDBLCLK:
      DoubleClickedR = true;
    break;


    case WM_LBUTTONDOWN:
      DoubleClickedL = false;
    break;

    case WM_LBUTTONUP:
      if (!DoubleClickedL)
        dmRemote->Pause->Execute();
    break;

    case WM_LBUTTONDBLCLK:
    // as pause will have updated WAstatus for us
      if (Status == WA_NOT_PLAYING)
      {
        dmRemote->Play->Execute();
      }
      if (Status == WA_PAUSED)
      {
        dmRemote->Stop->Execute();
      }
      DoubleClickedL = true;
    break;

    default:
      OutputDebugString(AnsiString(Msg.LParam).c_str());
    break;
  }

  TForm::Dispatch(&Msg);

}

bool __fastcall TfrmMain::TrayMessage(DWORD dwMessage)
{
   NOTIFYICONDATA tnd;
   PSTR pszTip;

   pszTip = TipText();

   tnd.cbSize = sizeof(NOTIFYICONDATA);
   tnd.hWnd = Handle;
   tnd.uID = 0;
   tnd.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
   tnd.uCallbackMessage	= TRAY_NOTIFY;

  if (dwMessage == NIM_MODIFY)
  {
    tnd.hIcon = IconHandle();
    if (pszTip)
       lstrcpyn(tnd.szTip, pszTip, sizeof(tnd.szTip));
    else
      tnd.szTip[0] = '\0';
  }
  else
  {
    tnd.hIcon = NULL;
    tnd.szTip[0] = '\0';
  }

   return (Shell_NotifyIcon(dwMessage, &tnd));
}

HANDLE __fastcall TfrmMain::IconHandle(void)
{

	WAPlaybackStatus Status = dmRemote->PlaybackStatus();

    switch (Status)
    {
      case WA_NOT_PLAYING:

        mnuPause->Caption = sPause;
        Pause1->Caption = sPause;
        fIconIndex = 3;
        break;
      case WA_PLAYING:
        dmRemote->Pause->Caption = sPause;
        dmRemote->Pause->Checked = false;
        fIconIndex = 1;
        break;
      case WA_PAUSED:
        dmRemote->Pause->Caption = sUnPause;
        dmRemote->Pause->Checked = true;
        fIconIndex = 2;
        break;
      default:
        fIconIndex = 5;
        break;
    }

  imlTrayIcons->GetIcon( fIconIndex, icoTrayIcon->Picture->Icon);

  return icoTrayIcon->Picture->Icon->Handle;

}

PSTR __fastcall TfrmMain::TipText(void)
{
  AnsiString str = SongTitle;
  AnsiString state;
  WAPlaybackStatus Status = dmRemote->PlaybackStatus();

  switch (Status){
  case WA_PLAYING:
    state = sPlaying;
    break;
  case WA_NOT_PLAYING:
    state = sStopped;
    break;
  case WA_PAUSED:
    state = sPaused;
    break;
  }

  if ((AnsiString(str) + state).Length() > 64)
    str = str.SubString(1, 60 - state.Length()) + "..." + state;
  else
    str  = str + state;
  strncpy(TipChars, str.c_str(), sizeof(TipChars));

  return TipChars;

}



void __fastcall TfrmMain::HideMain(TObject *)
{

  TrayMessage(NIM_ADD);
  TrayMessage(NIM_MODIFY);

  // show hints on visible forms
  frmPlaylist->ShowHint = true;
  frmSettings->ShowHint = true;
  frmCommands->ShowHint = true;

  ShowWindow(Application->Handle, SW_HIDE);
  // style trickery to lose the application window
  DWORD dwExStyle = GetWindowLong(Application->Handle, GWL_EXSTYLE);
  dwExStyle |= WS_EX_TOOLWINDOW;
  SetWindowLong(Application->Handle, GWL_EXSTYLE, dwExStyle);

  Hide();

  TRect FromRect, ToRect;
  ToRect = TRect(Screen->Width - 16, Screen->Height, Screen->Width, Screen->Height - 16);

  FromRect = BoundsRect;


#ifndef IDANI_CLOSE
  #define IDANI_CLOSE         2
#endif
#ifndef IDANI_CAPTION
  #define IDANI_CAPTION       3
#endif

  DrawAnimatedRects(Handle, IDANI_CAPTION, &FromRect, &ToRect);

}


const AnsiString sRegKey = "software\\PMMSoft\\Winamp controller\\client settings";
const AnsiString sCommandsLeft = "Commands Left";
const AnsiString sCommandsTop = "Commands Top";
const AnsiString sCommandsVisible = "Commands Visible";
const AnsiString sVolumeLeft = "Volume Left";
const AnsiString sVolumeTop = "Volume Top";
const AnsiString sVolumeVisible = "Volume Visible";
const AnsiString sPlaylistLeft = "Playlist Left";
const AnsiString sPlaylistTop = "Playlist Top";
const AnsiString sPlaylistWidth = "Playlist Width";
const AnsiString sPlaylistHeight = "Playlist Height";
const AnsiString sPlaylistVisible = "Playlist Visible";
const AnsiString sTesting = "Testing";
const AnsiString sLanguage = "Language";
const AnsiString sTrue = "true";
const AnsiString sFalse = "false";




void __fastcall TfrmMain::FormShow(TObject *)
{

  // TODO custom OnShow prevents having a generic hook in the datamodule
  // TODO handle setting up the GlassExtender

  // show hints on visible forms
  frmPlaylist->ShowHint = false;
  frmSettings->ShowHint = false;
  frmCommands->ShowHint = false;

  if (!timerMain->Enabled)
  {
    TRegistry * reg = new TRegistry();
    TRect FormRect;
    int FormLeft, FormTop, FormWidth, FormHeight;
    try
    {
      reg->OpenKey(sRegKey, true);

      if (chkAutoRestore->Checked)
      {

         FormRect = TRect(0, 0, frmCommands->Width, frmCommands->Height);
         FormLeft = reg->ReadString(sCommandsLeft).ToIntDef(-1);
         FormTop = reg->ReadString(sCommandsTop).ToIntDef(-1);

         if ((FormLeft > 0) && (FormTop > 0))
         {
           OffsetRect(&FormRect, FormLeft, FormTop);
           frmCommands->BoundsRect = FormRect;
         }

         if (reg->ReadString(sCommandsVisible).LowerCase() != sFalse)
           dmRemote->ViewToolBarExecute(this);

         FormRect = TRect(0, 0, frmSettings->Width, frmSettings->Height);
         FormLeft = reg->ReadString(sVolumeLeft).ToIntDef(-1);
         FormTop = reg->ReadString(sVolumeTop).ToIntDef(-1);

         if ((FormLeft > 0) && (FormTop > 0))
         {
           OffsetRect(&FormRect, FormLeft, FormTop);
           frmSettings->BoundsRect = FormRect;
         }

         if (reg->ReadString(sVolumeVisible).LowerCase() != sFalse)
           dmRemote->ViewVolumeExecute(this);

         FormLeft = reg->ReadString(sPlaylistLeft).ToIntDef(-1);
         FormTop = reg->ReadString(sPlaylistTop).ToIntDef(-1);
         FormWidth = reg->ReadString(sPlaylistWidth).ToIntDef(180);
         FormHeight = reg->ReadString(sPlaylistHeight).ToIntDef(240);
         FormRect = TRect(0, 0, FormWidth, FormHeight);

         if ((FormLeft > 0) && (FormTop > 0))
         {
           OffsetRect(&FormRect, FormLeft, FormTop);
           frmPlaylist->BoundsRect = FormRect;
         }

         if (reg->ReadString(sPlaylistVisible).LowerCase() != sFalse)
           dmRemote->ViewPlaylistExecute(this);


       }

    }

    __finally
    {
      delete reg;
    }
  }

  mnuShow->Visible = false;
  TrayMessage(NIM_DELETE);
  timerMain->Enabled = true;
  UpdateIcon();
  Refresh();
  pgSettings->ActivePage = tbsMain;


}



void __fastcall TfrmMain::btnCloseClick(TObject *)
{
  Close();
}


void MessageForm(AnsiString MessageStr)
{
  if (!frmMessage)
    frmMessage = new TfrmMessage(Application);

  frmMessage->memMessage->Lines->Text = MessageStr;
  frmMessage->Show();
  frmMessage->Update();
}


void __fastcall TfrmMain::DisplayHint(TObject *)
{
  sbMain->Panels->Items[1]->Text = GetShortHint(Application->Hint);
}

void __fastcall TfrmMain::FormCreate(TObject *)
{

  Application->OnException = AppException;

  Application->OnHint = DisplayHint;

  TRegistry * reg;
  try
  {
    reg = new TRegistry();
    reg->OpenKey("software\\PMMSoft\\Winamp controller\\client settings", true);

    this->ebEndPoint->Text = reg->ReadString("Endpoint");
    this->ebAddress->Text = reg->ReadString("Address");

    // activate 
    this->ebEndPoint->OnChange = AddressChange;
    this->ebAddress->OnChange = AddressChange;

    if (this->ebEndPoint->Text == "")
      this->ebEndPoint->Text = AnsiString("\\pipe\\winampremote");
    if (this->ebAddress->Text == "")
      this->ebAddress->Text = "localhost";

     chkAutoHide->Checked =  !(reg->ReadString("AutoHide").LowerCase() == sFalse);

     chkAutoRestore->Checked = !(reg->ReadString("AutoRestore").LowerCase() == sFalse);

     if (reg->ReadString("Playlist Update").LowerCase() == "every song")
       rbSongChange->Checked = true;
     else
       rbPlaylistChange->Checked = true;

     if ((reg->ReadString("Visible").LowerCase() == sFalse) && (chkAutoHide->Checked)){
       doHide = true;
       }

    lstTimer->ItemIndex = reg->ReadString("Poll Interval").ToIntDef(1);
    if (lstTimer->ItemIndex < 0)
      lstTimer->ItemIndex = 1;


  }
  __finally
  {
    delete reg;
  }

  pgSettings->ActivePage = tbsMain;

  dmRemote->registerForm(this);

  dmRemote->DoBind(ebAddress->Text, ebEndPoint->Text);

}




void __fastcall TfrmMain::AppException(TObject *, Exception *E)
{
  AnsiString RPCHint = sRPCFailed;
  if (connected)
	  MessageForm((AnsiString(sUnhandledException) + E->ClassName()+ ":\n" + E->Message));
}




void TfrmMain::UpdateIcon(void)
{
  int index, length = 0;
  AnsiString saveStr;

  Cardinal UpdateTime = 1000 * lstTimer->Items->Strings[lstTimer->ItemIndex].ToIntDef(1);

  bool previousConnected = connected;
  try
  {

    IconHandle();
    sbMain->Refresh();

    connected = true;
    TrayMessage(NIM_MODIFY);

    // TODO re-enable the client actions as this is the criterion for the re-connection
    if ( connected && !previousConnected )
    {
      timerMain->Interval = UpdateTime;
      lblVersion->Caption = dmRemote->WinampVersionString().c_str();
    }

  dmRemote->GetPlaylistState(length, index);

  if (length > 0)
  {

		SongTitle = dmRemote->CurrentSong().c_str();
	  	lblMessage->Caption = SongTitle;

		if (lblMessage->Canvas->TextWidth(lblMessage->Caption) > lblMessage->Width)
		{
		  lblMessage->Hint = lblMessage->Caption;
		  lblMessage->ParentShowHint = false;
		  lblMessage->ShowHint = true;

		  while (lblMessage->Canvas->TextWidth(lblMessage->Caption + "... ") > lblMessage->Width)
			lblMessage->Caption = lblMessage->Caption.SubString(1, lblMessage->Caption.Length() - 1);

		  lblMessage->Caption = lblMessage->Caption + "...";

		 }
		 else
		 {
		   lblMessage->Hint = sCurrentTrack;
		   lblMessage->ParentShowHint = true;
		   lblMessage->ShowHint = false;
		 }

        //update the playlist form
        //always check this first, to get length straight

        if  (frmPlaylist)
        {
          if ((rbPlaylistChange->Checked) || (index >= length))
          {
            if (length != LastLength)
            {
              dmRemote->PlaylistRefresh->Execute();
            }
          }

          if (rbSongChange->Checked)
          {
            if ((index != LastIndex) || (length != LastLength))
            {
              dmRemote->PlaylistRefresh->Execute();
              dmRemote->PlaylistRefreshCurrent->Execute();
            }
          }
          else
          if (LastIndex != index)
          {
            CurrentIndex = index;
            dmRemote->PlaylistRefreshCurrent->Execute();
          }

          // set last "OK" list index
          LastIndex = index;
          LastLength = length;
          if (timerMain->OnTimer != MainTimer)
            timerMain->OnTimer = MainTimer;

          dmRemote->PlaylistRefreshStats->Execute();

        }

      }
    } // try

  catch( ERPCException& E)
  {
	connected = false;
    doHide = false;
    if (frmPlaylist)
    {
      LastIndex = -1;
      LastLength = -1;
    }

    lblMessage->Caption = E.what();
    lblVersion->Caption = WinampVersionString(0);
    timerMain->Interval = 1000 * POLL_ERROR_FACTOR;
  }

  IconHandle();
  sbMain->Refresh();

  // in all events, update status
  TrayMessage(NIM_MODIFY);
}




void __fastcall TfrmMain::MainTimer(TObject *)
{
  UpdateIcon();
  if (doHide)
  {
    doHide = false;
    HideMain(this);
  }
}



void __fastcall TfrmMain::FormClose(TObject *, TCloseAction &)
{
  TrayMessage(NIM_DELETE);
}




void __fastcall TfrmMain::FormCloseQuery(TObject *, bool &)
{
  TRegistry * reg;

  try
  {
    reg = new TRegistry();
    reg->OpenKey("software\\PMMSoft\\Winamp controller\\client settings", true);

    if (this->ebEndPoint->Text != "")
      reg->WriteString("EndPoint", ebEndPoint->Text);
    if (this->ebAddress->Text != "")
      reg->WriteString("Address", ebAddress->Text);

    reg->WriteString("Visible", Visible?sTrue:sFalse);

    reg->WriteString("Poll Interval", AnsiString(lstTimer->ItemIndex));

    reg->WriteString("AutoHide", chkAutoHide->Checked?sTrue:sFalse);
    reg->WriteString("AutoRestore", chkAutoRestore->Checked?sTrue:sFalse);

     if  (rbSongChange->Checked)
     {
        reg->WriteString("Playlist Update", "every song");
      }
      else
      {
        reg->WriteString("Playlist Update", "playlist change");
      }

    // only save settings if check box checked, to prevent overwriting with defaults
    if (chkAutoRestore->Checked){
      reg->WriteString("Commands Left", AnsiString(frmCommands->Left));
      reg->WriteString("Commands Top", AnsiString(frmCommands->Top));
      reg->WriteString("Commands Visible", frmCommands->Visible?sTrue:sFalse);
      reg->WriteString("Commands Docked", frmCommands->HostDockSite?sTrue:sFalse);

      reg->WriteString("Playlist Left", AnsiString(frmPlaylist->Left));
      reg->WriteString("Playlist Top", AnsiString(frmPlaylist->Top));
      reg->WriteString("Playlist Width", AnsiString(frmPlaylist->Width));
      reg->WriteString("Playlist Height", AnsiString(frmPlaylist->Height));
      reg->WriteString("Playlist Visible", frmPlaylist->Visible?sTrue:sFalse);

      reg->WriteString("Volume Left", AnsiString(frmSettings->Left));
      reg->WriteString("Volume Top", AnsiString(frmSettings->Top));
      reg->WriteString("Volume Visible", frmSettings->Visible?sTrue:sFalse);
      }
    }
  __finally
  {
    delete reg;
  }
}




void __fastcall TfrmMain::lstTimerClick(TObject *)
{
  timerMain->Interval = 1000 * (lstTimer->ItemIndex + 1);
}void __fastcall TfrmMain::AddressChange(TObject *)
{
  UnBind();
  dmRemote->DoBind(ebAddress->Text, ebEndPoint->Text);

  if (Visible)
  {
    // and give them 10s to decide - it will be reset
    timerMain->Enabled = false;
    timerMain->Interval = 1000;
    timerMain->OnTimer = DelayTimer;
    Delay = 11;
    timerMain->Enabled = true;
    timerMain->OnTimer(this);
   sbMain->Panels->Items[1]->Text = sDelaying;
   }
}



void __fastcall TfrmMain::DelayTimer(TObject *)
{
  if (--Delay > 0)
  {
    sbMain->Panels->Items[1]->Text = AnsiString().sprintf(sDelayingForFmt.c_str(), Delay);
  }
  else
  {
    sbMain->Panels->Items[1]->Text = sRestarting;
    timerMain->Enabled = false;
    timerMain->OnTimer = MainTimer;
    timerMain->Enabled = true;
  }

}




void __fastcall TfrmMain::FormDockOver(TObject *, TDragDockObject *, int , int , TDragState , bool &Accept)
{
  Accept = true;
}




void __fastcall TfrmMain::StartDock(TObject *Sender, TDragDockObject *&)
{
  // set up dock targets manually
  // note DragObject is not used
  pgSettings->DockSite = false;

  if ( (Sender == frmPlaylist) || (Sender == frmSettings) )
    pgSettings->DockSite = true;

}




void __fastcall TfrmMain::pgSettingsDockDrop(TObject *, TDragDockObject *Source, int , int )
{
  int ImageIndex = 0;
// set the imageindex for the dropped form
  if (Source->Control == frmSettings)
  {
    ImageIndex = 9;
  }
  else if (Source->Control == frmPlaylist)
  {
    ImageIndex = 10;
  }

  // set image index
  int PageIndex = pgSettings->PageCount -1;
  pgSettings->Pages[PageIndex]->ImageIndex = ImageIndex;
  // and have a shortcut
  pgSettings->Pages[PageIndex]->Caption = "&" + pgSettings->Pages[PageIndex]->Caption;
}



void __fastcall TfrmMain::DetailsExecute(TObject *)
{
  TfrmDetails *DetailsForm = new TfrmDetails(NULL);
  try
  {
    DetailsForm->ShowModal();
  }
  __finally
  {
    delete DetailsForm;
  }
}




void __fastcall TfrmMain::sbMainDrawPanel(TStatusBar *StatusBar, TStatusPanel *, const TRect &Rect)
{
  imlTrayIcons->Draw(StatusBar->Canvas, Rect.Left + 3, Rect.Top + 3, fIconIndex, true);
}



void __fastcall TfrmMain::AnimateForm(TForm * Form, bool FormVisible)
{

    TRect MainRect, FormRect;
    if (Visible)
    {
      MainRect = pgSettings->BoundsRect;
      OffsetRect(&MainRect, pgSettings->ClientToScreen(TPoint(0,0)).x, pgSettings->ClientToScreen(TPoint(0,0)).y);
    }
    else
      MainRect = TRect(Screen->Width - 16, Screen->Height, Screen->Width, Screen->Height - 16);

    FormRect = Form->BoundsRect;

  if (FormVisible)
    DrawAnimatedRects(Form->Handle, IDANI_CAPTION, &FormRect, &MainRect);
  else
    DrawAnimatedRects(Form->Handle, IDANI_CAPTION, &MainRect, &FormRect);

}    

void __fastcall TfrmMain::FormDestroy(TObject *Sender)
{
        dmRemote->unRegisterForm(this);
}
void __fastcall TfrmMain::NullAddressChange(TObject *Sender)
{
 // nothing here        
}
//---------------------------------------------------------------------------


