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
#include "winampinterface.h"
#include "RPCFuncsU.h"
#include "DetailsF.h"
#include "remotestrs.h"
//#include "reinit.hpp"
#include "SplashF.h"

#include <math.h>

/* TODO -opatrick -cactions : may need concatenation of available actions in a specific order */

//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TfrmMain *frmMain;

//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::TrayNotify(TMessage& Msg)
{
  POINT MousePos;

  switch(Msg.LParam)
  {
    case WM_RBUTTONDOWN:
    // get round clicks to spurious systray windows when show
      DoubleClickedR = false;
    break;

    case WM_RBUTTONUP:
      if (DoubleClickedR)
        ShowMainForm->Execute();
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
        Pause->Execute();
    break;

    case WM_LBUTTONDBLCLK:
    // as pause will have updated WAstatus for us
      if (WAStatus == WA_NOT_PLAYING)
      {
        Play->Execute();
      }
      if (WAStatus == WA_PAUSED)
      {
        Stop->Execute();
      }
      DoubleClickedL = true;
    break;

    default:
      OutputDebugString(AnsiString(Msg.LParam).c_str());
    break;
  }

  TForm::Dispatch(&Msg);

}
//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
HANDLE __fastcall TfrmMain::IconHandle(void)
{

  if (!Querying)
  {
    switch (WAStatus)
    {
      case WA_NOT_PLAYING:

        mnuPause->Caption = sPause;
        Pause1->Caption = sPause;
        fIconIndex = 3;
        break;
      case WA_PLAYING:
        Pause->Caption = sPause;
        Pause->Checked = false;
        fIconIndex = 1;
        break;
      case WA_PAUSED:
        Pause->Caption = sUnPause;
        Pause->Checked = true;
        fIconIndex = 2;
        break;
      default: // no break
        fIconIndex = 5;
    }
  }

  else
  {
    fIconIndex = 6;
  }

  imlCommandsHot->GetIcon( fIconIndex, icoState->Picture->Icon);
  imlTrayIcons->GetIcon( fIconIndex, icoTrayIcon->Picture->Icon);

  Application->Icon->Handle = icoState->Picture->Icon->Handle;

  return icoTrayIcon->Picture->Icon->Handle;

}
//---------------------------------------------------------------------------
PSTR __fastcall TfrmMain::TipText(void)
{
  AnsiString str = SongTitle;
  AnsiString state;

  switch (WAStatus){
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


//---------------------------------------------------------------------------
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


//---------------------------------------------------------------------------

void __fastcall TfrmMain::ShowMainFormExecute(TObject *)
{

  ShowWindow(Application->Handle, SW_SHOW);

  DWORD dwExStyle = GetWindowLong(Application->Handle, GWL_EXSTYLE);
  dwExStyle ^= WS_EX_TOOLWINDOW;
  SetWindowLong(Application->Handle, GWL_EXSTYLE, dwExStyle);

  TRect FromRect, ToRect;
  FromRect = TRect(Screen->Width - 16, Screen->Height, Screen->Width, Screen->Height - 16);

  ToRect = BoundsRect;

  HRGN HideRegion = CreateRectRgn(0,0,1,1);
  SetWindowRgn(Handle, HideRegion, false);

  Show();

  DrawAnimatedRects(Handle, IDANI_CAPTION, &FromRect, &ToRect);

  SetWindowRgn(Handle, NULL, true);

  // dodge here
  Application->Restore();
  
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::PauseExecute(TObject *)
{
  if (WAStatus == IntegerResult(IdentChars, IPC_ISPLAYING, 0))
    ExecuteMessage(IdentChars, WINAMP_PAUSE);
    UpdateIcon();
}


//---------------------------------------------------------------------------
void __fastcall TfrmMain::ExitExecute(TObject *)
{
  Close();
}

const AnsiString sRegKey = "software\\PMMSoft\\Winamp controller\\client settings";
const AnsiString sCommandsDocked = "Commands Docked";
const AnsiString sCommandsLeft = "Commands Left";
const AnsiString sCommandsTop = "Commands Top";
const AnsiString sCommandsVisible = "Commands Visible";
const AnsiString sVolumeDocked = "Volume Docked";
const AnsiString sVolumeLeft = "Volume Left";
const AnsiString sVolumeTop = "Volume Top";
const AnsiString sVolumeVisible = "Volume Visible";
const AnsiString sPlaylistDocked = "Playlist Docked";
const AnsiString sPlaylistLeft = "Playlist Left";
const AnsiString sPlaylistTop = "Playlist Top";
const AnsiString sPlaylistWidth = "Playlist Width";
const AnsiString sPlaylistHeight = "Playlist Height";
const AnsiString sPlaylistVisible = "Playlist Visible";
const AnsiString sTesting = "Testing";
const AnsiString sLanguage = "Language";
const AnsiString sTrue = "true";
const AnsiString sFalse = "false";


//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormShow(TObject *)
{


  // set up commands form images
  frmCommands->tbCommands->Images = imlCommandsCool;
  frmCommands->tbCommands->HotImages = imlCommandsHot;

  // show hints on visible forms
  frmPlaylist->ShowHint = false;
  frmSettings->ShowHint = false;
  frmCommands->ShowHint = false;

  // set drag mode
  /*
  frmPlaylist->DragKind = dkDock;
  frmCommands->DragKind = dkDock;
  frmSettings->DragKind = dkDock;
  */

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

         if (reg->ReadString(sCommandsDocked).LowerCase() != sFalse)
         {
           frmCommands->ManualDock(pnlCommands, NULL, alTop);
           EndDock(frmCommands, NULL, 0,0);
         }

         FormRect = TRect(0, 0, frmCommands->Width, frmCommands->Height);
         FormLeft = reg->ReadString(sCommandsLeft).ToIntDef(-1);
         FormTop = reg->ReadString(sCommandsTop).ToIntDef(-1);

         if ((FormLeft > 0) && (FormTop > 0))
         {
           OffsetRect(&FormRect, FormLeft, FormTop);
           frmCommands->BoundsRect = FormRect;
         }

         if (reg->ReadString(sCommandsVisible).LowerCase() != sFalse)
           ViewToolBarExecute(this);


         if (reg->ReadString(sVolumeDocked).LowerCase() != sFalse)
         {
           frmSettings->ManualDock(pgSettings, NULL, alClient);
           EndDock(frmSettings, NULL, 0,0);
         }


         FormRect = TRect(0, 0, frmSettings->Width, frmSettings->Height);
         FormLeft = reg->ReadString(sVolumeLeft).ToIntDef(-1);
         FormTop = reg->ReadString(sVolumeTop).ToIntDef(-1);

         if ((FormLeft > 0) && (FormTop > 0))
         {
           OffsetRect(&FormRect, FormLeft, FormTop);
           frmSettings->BoundsRect = FormRect;
         }

         if (reg->ReadString(sVolumeVisible).LowerCase() != sFalse)
           ViewVolumeExecute(this);


         if (reg->ReadString(sPlaylistDocked).LowerCase() != sFalse)
         {
           frmPlaylist->ManualDock(pgSettings, NULL, alClient);
           EndDock(frmPlaylist, NULL, 0,0);
         }

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
           ViewPlaylistExecute(this);


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
  pgSettings->ActivePage = tbsConfig;
  pgSettings->ActivePage = tbsMain;


}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuSayHelloClick(TObject *)
{
  SendString(IdentChars);
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnCloseClick(TObject *)
{
  Close();
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::PlayExecute(TObject *)
{
  ExecuteMessage(IdentChars, WINAMP_PLAYENTRY);
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::NextExecute(TObject *)
{
  SongChanging->Execute();
  ExecuteMessage(IdentChars, WINAMP_NEXT);
  SongChanged->Execute();
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::NextFadeExecute(TObject *)
{
  StopFade->Execute();
  Next->Execute();
  Play->Execute();

}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::PreviousExecute(TObject *)
{
  SongChanging->Execute();
  ExecuteMessage(IdentChars, WINAMP_PREVIOUS);
  SongChanged->Execute();
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormHide(TObject *)
{
  mnuShow->Visible = true;
  /*
  frmPlaylist->DragKind = dkDrag;
  frmCommands->DragKind = dkDrag;
  frmSettings->DragKind = dkDrag;
  */
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::AboutExecute(TObject *)
{
  if (!frmAbout)
  {
    frmAbout = new TfrmAbout(this);
    try
    {
      frmAbout->Caption = sAboutWinampRemoteControl;
      OutText->Text= sWinampRemoteControl;
      frmAbout->ShowModal();
    }
    __finally
    {
      delete frmAbout;
      frmAbout = NULL;
    }
  }
  else
  {
    frmAbout->Show();
    frmAbout->BringToFront();
  }
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::StopExecute(TObject *)
{
  ExecuteMessage(IdentChars, WINAMP_STOP);
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::Forward5Execute(TObject *)
{
  ExecuteMessage(IdentChars, WINAMP_FORWARD5S);
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::Back5Execute(TObject *)
{
  ExecuteMessage(IdentChars, WINAMP_BACK5S);
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::VolumeUpExecute(TObject *)
{
  frmSettings->tbVolume->Position++;
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::VolumeDownExecute(TObject *)
{
  frmSettings->tbVolume->Position--;
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::VolumeUpMoreExecute(TObject *)
{
  frmSettings->tbVolume->Position+=10;
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::VolumeDownMoreExecute(TObject *)
{
  frmSettings->tbVolume->Position-=10;
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::PlaylistStartExecute(TObject *)
{
  SongChanging->Execute();
  ExecuteMessage(IdentChars, WINAMP_STARTOFPLAYLIST);
  SongChanged->Execute();
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::PlaylistEndExecute(TObject *)
{
  SongChanging->Execute();
  ExecuteMessage(IdentChars, WINAMP_ENDOFPLAYLIST);
  SongChanged->Execute();
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::DeletePlayListExecute(TObject *)
{
  IntegerResult(IdentChars, IPC_DELETE, 0);
  PlaylistRefresh->Execute();
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::AddFileToPlayListExecute(TObject *Sender)
{
AnsiString str;
AnsiString commandstr;

  OpenDialog1->FileName = "";

  if (Sender == mnuAddPlayList){
    OpenDialog1->Filter = sPlayListFiles;
    }
  else{
    OpenDialog1->Filter = sAllFiles;
    }

  if (OpenDialog1->Execute())
  {

    TStringList * Files = new TStringList;
    try
    {
      // sort strings by name, for now
      Files->Sorted = true;

      Files->Assign(OpenDialog1->Files);

      DoAddFiles(Files);
      PlaylistRefresh->Execute();
    }
    __finally
    {
      delete Files;
    }
  } // if
}


//---------------------------------------------------------------------------

void MessageForm(AnsiString MessageStr)
{
  if (!frmMessage)
    frmMessage = new TfrmMessage(Application);

  frmMessage->memMessage->Lines->Text = MessageStr;
  frmMessage->Show();
  frmMessage->Update();
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::StopFadeExecute(TObject *)
{
  ExecuteMessage(IdentChars, WINAMP_STOPFADE);
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::StopAfterCurrentExecute(TObject *)
{
  ExecuteMessage(IdentChars, WINAMP_STOPAFTERCURRENT);
}


//---------------------------------------------------------------------------
void __fastcall TfrmMain::DisplayHint(TObject *)
{
  sbMain->Panels->Items[1]->Text = GetShortHint(Application->Hint);
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormCreate(TObject *)
{

  Application->OnException = AppException;

  Application->OnHint = DisplayHint;
  WAStatus = WA_UNUSED;

  TRegistry * reg;
  try
  {
    reg = new TRegistry();
    reg->OpenKey("software\\PMMSoft\\Winamp controller\\client settings", true);
    this->ebEndPoint->Text = reg->ReadString("Endpoint");
    this->ebAddress->Text = reg->ReadString("Address");

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
  SetIdent();

  DoBind();

}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::AppException(TObject *, Exception *E)
{
  AnsiString RPCHint = sRPCFailed;

  if (dynamic_cast <ERPCException*> (E)){
    MessageForm((AnsiString(RPCHint) + "\nMessage: " + E->Message));
    }
  else
  {
    MessageForm((AnsiString(sUnhandledException) + E->ClassName()+ ":\n" + E->Message));
  }
}

//---------------------------------------------------------------------------


void TfrmMain::UpdateIcon(void)
{
  char title[sizeof(IdentChars)]; // MAX_PATH == maximum user name ?
  int index, length;
  AnsiString saveStr;

  Cardinal UpdateTime = 1000 * lstTimer->Items->Strings[lstTimer->ItemIndex].ToIntDef(1);

  try
  {

    Querying = true;
    IconHandle();
    sbMain->Refresh();

    WAStatus = (WAPlaybackStatus) IntegerResult(IdentChars, IPC_ISPLAYING, 0);
    TrayMessage(NIM_MODIFY);

    Shuffle->Checked = (WinampVerNo >= 0x2604) && IntegerResult(IdentChars, IPC_GETSHUFFLEOPTION, 0);
    Repeat->Checked = (WinampVerNo >= 0x2604) && IntegerResult(IdentChars, IPC_GETREPEATOPTION, 0);

    if ((frmSettings) && (frmSettings->EQUpdateNeeded))
      frmSettings->UpdateBars();

    if ( timerMain->Interval != UpdateTime)
    {
      timerMain->Interval = UpdateTime;
      WinampVerNo = IntegerResult(IdentChars, IPC_GETVERSION,  0);
      lblVersion->Caption = WinampVersion(WinampVerNo);
    }

    strcpy(title, IdentChars);

    length = IntegerResult(IdentChars, IPC_GETLISTLENGTH, 0);
    if (length > 0)
    {
      index = IntegerResult(IdentChars, IPC_GETLISTPOS, 0);

      StringResult(title, IPC_GETPLAYLISTTITLE, index);
      if (title)
      {
        SongTitle = title;
        lblMessage->Caption = (title);

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

       }

        //update the playlist form
        //always check this first, to get length straight

        if  (frmPlaylist)
        {
          if ((rbPlaylistChange->Checked) || (index >= length))
          {
            if (length != LastLength)
            {
              PlaylistRefresh->Execute();
            }
          }

          if (rbSongChange->Checked)
          {
            if ((index != LastIndex) || (length != LastLength))
            {
              PlaylistRefresh->Execute();
              PlaylistRefreshCurrent->Execute();
            }
          }
          else
          if (LastIndex != index)
          {
            CurrentIndex = index;
            /* TODO : replace with action */
            PlaylistRefreshCurrent->Execute();
          }

          // set last "OK" list index
          LastIndex = index;
          LastLength = length;
          if (timerMain->OnTimer != MainTimer)
            timerMain->OnTimer = MainTimer;

          PlaylistRefreshStats->Execute();

        }

      } // if list length non-zero
    }

  catch( ERPCException &E)
  {
    doHide = false;
    if (frmPlaylist)
    {
      LastIndex = -1;
      LastLength = -1;
    }  

    WAStatus = WA_UNUSED;
    lblMessage->Caption = E.Message;
    lblVersion->Caption = WinampVersion(0);
    timerMain->Interval = 1000 * FAIL_TIMEOUT;
  }

  Querying = false;
  IconHandle();
  sbMain->Refresh();

  // in all events, update status
  TrayMessage(NIM_MODIFY);
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::MainTimer(TObject *)
{
  UpdateIcon();
  if (doHide)
  {
    doHide = false;
    HideMain(this);
  }
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::SetVolume0Execute(TObject *)
{
  frmSettings->tbVolume->Position = 0;

}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::SetVolume100Execute(TObject *)
{
  frmSettings->tbVolume->Position = 255;
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::ShuffleExecute(TObject *)
{
  // shuffle / repeat status only works in very recent versions,
  // so always do for older
  if ( (WinampVerNo < 0x2604) || (Shuffle->Checked == IntegerResult(IdentChars, IPC_GETSHUFFLEOPTION, 0)) )
    ExecuteMessage(IdentChars, WINAMP_FILE_SHUFFLE);
  UpdateIcon();
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::RepeatExecute(TObject *)
{
  // shuffle / repeat status only works in very recent versions,
  // so always do for older
  if  ( (WinampVerNo < 0x2604) || (Repeat->Checked == IntegerResult(IdentChars, IPC_GETREPEATOPTION, 0)) )
    ExecuteMessage(IdentChars, WINAMP_FILE_REPEAT);
  UpdateIcon();
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::PlayFromStartExecute(TObject *)
{
  SongChanging->Execute();
  IntegerResult(IdentChars, IPC_STARTPLAY, 0);
  SongChanged->Execute();
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormClose(TObject *, TCloseAction &)
{
  TrayMessage(NIM_DELETE);
}


//---------------------------------------------------------------------------

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
      reg->WriteString("Playlist Docked", frmPlaylist->HostDockSite?sTrue:sFalse);

      reg->WriteString("Volume Left", AnsiString(frmSettings->Left));
      reg->WriteString("Volume Top", AnsiString(frmSettings->Top));
      reg->WriteString("Volume Visible", frmSettings->Visible?sTrue:sFalse);
      reg->WriteString("Volume Docked", frmSettings->HostDockSite?sTrue:sFalse);
      }
    }
  __finally
  {
    delete reg;
  }
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::lstTimerClick(TObject *)
{
  timerMain->Interval = 1000 * (lstTimer->ItemIndex + 1);
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::HalfExecute(TObject *)
{
  frmSettings->tbVolume->Position = 128;
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::ViewToolBarExecute(TObject *)
{
  // need to undock
  frmCommands->Visible = !frmCommands->Visible;
  AnimateForm(frmCommands, ViewToolBar->Checked);
  ViewToolBar->Checked = frmCommands->Visible;
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::ViewPlaylistExecute(TObject *)
{
  frmPlaylist->Visible = !frmPlaylist->Visible;
  AnimateForm(frmPlaylist, ViewPlaylist->Checked);
  ViewPlaylist->Checked = frmPlaylist->Visible;


}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::ViewVolumeExecute(TObject *)
{
  frmSettings->Visible = !frmSettings->Visible;
  AnimateForm(frmSettings, ViewVolume->Checked);
  ViewVolume->Checked = frmSettings->Visible;
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::SetIdent(void)
{

// no declaration for username max - appears to be same as machine ?
// see access .ldb file format
char buf[32];
unsigned long maxlen = 31;
AnsiString str;

  if (GetUserName(buf, &maxlen))
    str = buf;
  else
    str = sUnknown;

  maxlen = 31;
  str += '@';

  if (GetComputerName(buf, &maxlen))
    str += buf;
  else
    str += sUnknown;

  strncpy(IdentChars, str.c_str(), sizeof(IdentChars));
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormDestroy(TObject *)
{
  UnBind();
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::AddressChange(TObject *)
{
  UnBind();
  DoBind();

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


//---------------------------------------------------------------------------

void __fastcall TfrmMain::LocateServersExecute(TObject *)
{
  AnsiString EndPoint = ebEndPoint->Text;
  AnsiString Address = ebAddress->Text;

  timerMain->Enabled = false;
  UnBind();
  TfrmServers * ServersForm = new TfrmServers(this);
  try
  {
    ServersForm->ebEndPoint->Text = EndPoint;
    ServersForm->ShowModal();
    if (ServersForm->ModalResult != mrOk)
    {
      //restore
      ebEndPoint->Text = EndPoint;
      ebAddress->Text = Address;
    }
    else
    {
      ebEndPoint->Text = ServersForm->EndPoint;
      ebAddress->Text = ServersForm->Address;

    }
  }
  __finally
  {
    delete ServersForm;
    DoBind();
    MainTimer(this);
    timerMain->Enabled = true;
  }
}


//---------------------------------------------------------------------------

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


//---------------------------------------------------------------------------

void __fastcall TfrmMain::RefreshEQExecute(TObject *)
{
   frmSettings->UpdateBars();
}

//---------------------------------------------------------------------------

void _fastcall TfrmMain::DoBind(void)
{
  Bind(ebAddress->Text.c_str(), ebEndPoint->Text.c_str());
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::AutoloadExecute(TObject *)
{
  Autoload->Checked = !Autoload->Checked;
  IntegerResult(IdentChars, IPC_GETEQDATA, 11);
  IntegerResult(IdentChars, IPC_SETEQDATA, Autoload->Checked );
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormDockOver(TObject *, TDragDockObject *, int , int , TDragState , bool &Accept)
{
  Accept = true;
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::StartDock(TObject *Sender, TDragDockObject *&)
{
  // set up dock targets manually
  // note DragObject is not used
  pgSettings->DockSite = false;
  pnlCommands->DockSite = false;

  if ( (Sender == frmPlaylist) || (Sender == frmSettings) )
    pgSettings->DockSite = true;
  if ( Sender == frmCommands )
    pnlCommands->DockSite = true;

}


//---------------------------------------------------------------------------

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


//---------------------------------------------------------------------------

void __fastcall TfrmMain::EndDock(TObject *, TObject *, int , int )
{
  pgSettings->DockSite = true;
  pnlCommands->DockSite = true;
}


//---------------------------------------------------------------------------

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


//---------------------------------------------------------------------------

void __fastcall TfrmMain::sbMainDrawPanel(TStatusBar *StatusBar, TStatusPanel *, const TRect &Rect)
{
  imlTrayIcons->Draw(StatusBar->Canvas, Rect.Left + 3, Rect.Top + 3, fIconIndex, true);
}

//---------------------------------------------------------------------------

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




void __fastcall TfrmMain::SetLanguageMenu(TObject *Sender)
{
    mnuEnglishUS->Checked = mnuEnglishUS == Sender;
    mnuEnglishUK->Checked = mnuEnglishUK == Sender;
    mnuGerman->Checked  = mnuGerman == Sender;
    mnuFrench->Checked  = mnuFrench == Sender;
    mnuDutch->Checked  = mnuDutch == Sender;

}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::PreviousFadeExecute(TObject *)
{
  StopFade->Execute();
  Previous->Execute();
  Play->Execute();

}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::SongChangingExecute(TObject *)
{
  // if special actions required, this action can do them
  if (chkFadeOld->Checked)
    StopFade->Execute();

}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::SongChangedExecute(TObject *)
{
  // if special actions required, this action can do them
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::NewSongExecute(TObject *)
{
  // gets the index from the playlist form
  SongChanging->Execute();
  IntegerResult(IdentChars, IPC_SETPLAYLISTPOS, frmPlaylist->lstSongs->ItemIndex);
  Play->Execute();
  SongChanged->Execute();

}


//---------------------------------------------------------------------------

/*
void __fastcall TfrmMain::CountTimesExecute(TObject *)
{
  try
  {
    try
    {
      int i, Index, SongS, PlayListS;
      TStringList * StringList;

      Screen->Cursor = crHourGlass;
      Querying = true;
      IconHandle();
      sbMain->Update();
      TrayMessage(NIM_MODIFY);

      Index = IntegerResult(IdentChars, IPC_GETLISTPOS, 0);

      void * buf = NULL;
      int bufsize = 0;

      StringList = new TStringList;
      try
      {
        GetStringDataList(IdentChars, &buf, bufsize, IPC_GETPLAYLISTTITLE, IPC_GETOUTPUTTIME, 1);

        if (buf)
        {
          StringList->Text = (char *) buf;
          delete buf;
        }

        PlayListS = 0;
        for (i = 0 ; i < StringList->Count - 2 ; i += 2)
        {
          SongS = StringList->Strings[i + 1].ToIntDef(0);
          PlayListS += SongS;
        }

      }
      __finally
      {
        delete StringList;
      }


      AnsiString TimeFmt = "%02d:%02d:%02d";
      Word Hour, Minute, Second, MSec;

      TDateTime PlayListTime = (float) PlayListS / (SecsPerDay);
      DecodeTime(PlayListTime, Hour, Minute, Second, MSec);
      Hour +=  24 * floor(PlayListTime);

      frmPlaylist->sbPlaylist->Panels->Items[5]->Text =
                                        AnsiString().sprintf(TimeFmt.c_str(), Hour, Minute, Second);


      // reset the currently playing song
      IntegerResult(IdentChars, IPC_SETPLAYLISTPOS, Index);

    }
    catch( ERPCException &E)
    {
      //
    }

  }
  __finally
  {
    Screen->Cursor = crDefault;

    Querying = false;
    IconHandle();
    sbMain->Update();

    TrayMessage(NIM_MODIFY);

  }

}
*/




void __fastcall TfrmMain::alMainExecute(TBasicAction *Action, bool &)
{
  OutputDebugString(Action->Name.c_str());
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::PlaylistRefreshExecute(TObject *)
{

  if ((frmSplash) && (frmSplash->Visible))
  {
    frmSplash->lblMessage->Caption = sGettingPlaylist;
    frmSplash->Update();
  }

  frmPlaylist->lstSongs->Items->BeginUpdate();
  try
  {
    try
    {

      Screen->Cursor = crHourGlass;
      Querying = true;
      IconHandle();
      sbMain->Update();
      TrayMessage(NIM_MODIFY);


      LastLength = IntegerResult(IdentChars, IPC_GETLISTLENGTH, 0);
      LastIndex = CurrentIndex;
      CurrentIndex = IntegerResult(IdentChars, IPC_GETLISTPOS, 0);

      frmPlaylist->lstSongs->Items->Clear();

      void * buf = NULL;
      int bufsize = 0;
      TStringList * SongList = new TStringList;
      try
      {

        //GetStringDataList(IdentChars, &buf, bufsize, IPC_GETPLAYLISTTITLE, IPC_GETOUTPUTTIME, 1);
        // char * pszString, void ** Buffer, int& Size, int Command
        GetStringList(IdentChars, &buf, bufsize, IPC_GETPLAYLISTTITLE);



        SongList->Clear();
        if (bufsize)
          SongList->Text = (char *) buf;

        //run through, removing the data items in-place
        /*
        for (int i = 0 ; i < SongList->Count ; i++)
        {
          int SongTime = SongList->Strings[i + 1].ToIntDef(-1);
          SongList->Delete(i + 1);
          SongList->Objects[i] = (TObject *) SongTime;
        }
        */

        // after fixing up the returned StringList
        frmPlaylist->lstSongs->Items->Assign(SongList);

      }
      __finally
      {
        delete SongList;
      }

      if (buf)
        delete buf;

    }
    catch( ERPCException &E)
    {
      frmPlaylist->lstSongs->Items->Text = AnsiString().sprintf(sListUnobtainable.c_str(), E.Message.c_str());
    }

  }
  __finally
  {
    Screen->Cursor = crDefault;

    Querying = false;
    IconHandle();
    sbMain->Update();

    TrayMessage(NIM_MODIFY);

    frmPlaylist->lstSongs->Items->EndUpdate();
    if ((frmSplash) && (frmSplash->Visible))
    {
      frmSplash->lblMessage->Caption = sGettingPlaylist;
      frmSplash->Update();
    }
  }

}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::PlaylistRefreshCurrentExecute(TObject *)
{

  /*
  char title[sizeof(IdentChars)];
  // needed to ensure we can see the currently playing track

  strcpy(title, IdentChars);
  int SongS = IntegerResult(title, IPC_GETOUTPUTTIME, 1);
  strcpy(title, IdentChars);
  // update the current title, at least
  StringResult(title, IPC_GETPLAYLISTTITLE, CurrentIndex);

  if ((frmPlaylist->lstSongs->Items->Count - 1) > CurrentIndex)
  {
    bool Selected = frmPlaylist->lstSongs->Selected[CurrentIndex];
    frmPlaylist->lstSongs->Items->Strings[CurrentIndex] = (title);
    frmPlaylist->lstSongs->Items->Objects[CurrentIndex] = (TObject * ) SongS;
    frmPlaylist->lstSongs->Selected[CurrentIndex] = Selected;
  }

  // much neater...
  frmPlaylist->lstSongs->TopIndex = CurrentIndex - 2;
  frmPlaylist->lstSongs->Update();
  */

}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::PlaylistRefreshStatsExecute(TObject *)
{

  int SongS = IntegerResult(frmMain->IdentChars, IPC_GETOUTPUTTIME, 1);

  if ((SongS) && (!frmPlaylist->Dragging))
  {
    int PosMS = IntegerResult (frmMain->IdentChars, IPC_GETOUTPUTTIME, 0);
    frmPlaylist->pbSongPos->Position = (frmPlaylist->pbSongPos->Max * PosMS) / (SongS * 1000);
  }

  if (frmPlaylist->lstSongs->Items->Count > 1)
    frmPlaylist->pbListPos->Position = (frmPlaylist->pbListPos->Max * CurrentIndex) /
                                       (frmPlaylist->lstSongs->Items->Count - 1);
  else
    frmPlaylist->pbListPos->Position = 0;

  // time
  frmPlaylist->sbPlaylist->Panels->Items[1]->Text = TimeToStr(Time());
  // current song length
  frmPlaylist->sbPlaylist->Panels->Items[3]->Text = TimeToStr((float) SongS / SecsPerDay);

}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::DoAddFiles(TStrings * Files)
{
  Screen->Cursor = crHourGlass;
  try
  {
    SetStringList(frmMain->IdentChars, Files->Text.c_str(), Files->Text.Length() + 1, IPC_PLAYFILE);
  }
  __finally
  {
    Screen->Cursor = crDefault;
  }
}

void __fastcall TfrmMain::DoDeleteSelected(void)
{
  int i;
  Screen->Cursor = crAppStart;
  TStringList * StringList = new TStringList;
  try
  {
  /* rather wasteful, as we have to get all the undeleted items and resend them to winamp*/

    void * buf = NULL;
    int bufsize = 0;

    GetStringList(IdentChars, &buf, bufsize, IPC_GETPLAYLISTFILE);

    if (bufsize)
      StringList->Text = (char *) buf;

    if (buf)
      delete buf;

    for (i = frmPlaylist->lstSongs->Items->Count - 1 ; i >= 0 ; i--)
    {
      if (frmPlaylist->lstSongs->Selected[i])
      {
        StringList->Delete(i);
         if (i < CurrentIndex)
            CurrentIndex--;
      }
    } // for

    // delete current
    IntegerResult(IdentChars, IPC_DELETE, 0);

    // add remaining
    DoAddFiles(StringList);
    // reset position

    IntegerResult(IdentChars, IPC_SETPLAYLISTPOS, CurrentIndex);

    PlaylistRefresh->Execute();
  }
  __finally
  {
    delete StringList;
    Screen->Cursor = crDefault;
  }

}


void __fastcall TfrmMain::GetFilenames(int Start, int Stop, TStringList * Files)
{

int i;

char filename[RET_STR_SIZE];
char saveident[RET_STR_SIZE];

  // cache this
  strcpy(saveident, IdentChars);

  for (i = Start ; i < Stop; i++)
  {
    strcpy(filename, saveident);
    StringResult(filename, IPC_GETPLAYLISTFILE, i);
    Files->Add(filename);
  } // for

}


void __fastcall TfrmMain::DropFiles(TStringList *, int DropIndex)
{
  TStringList * Files = new TStringList;
  int NewPos;


  // get the top of the list
  if (DropIndex > -1)
    GetFilenames(0, DropIndex, Files);
  else
    GetFilenames(0, frmPlaylist->lstSongs->Items->Count, Files);


  // get the rest of the list;
  if (DropIndex > -1)
    GetFilenames(DropIndex, frmPlaylist->lstSongs->Items->Count, Files);

  // delete
  IntegerResult(frmMain->IdentChars, IPC_DELETE, 0);

  DoAddFiles(Files);
  // reset position here

  // AAAACK - used to be a "magic object"
  NewPos = Files->IndexOfObject((TObject *) true);
  IntegerResult(IdentChars, IPC_SETPLAYLISTPOS, NewPos);

  PlaylistRefresh->Execute();
  
}
