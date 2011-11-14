/*
winamp remote control suite �Patrick Michael Martin 2000, 2001, 2002

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
#include "shellapi.h"

// forms...

#include "MainF.h"
#include "messageF.h"
#include "AboutF.h"

#include "PlaylistF.h"
#include "SettingsF.h"
#include "CommandF.h"
#include "ServersF.h"

// RPC functions
#include "RPCFuncsU.h"
#include "DetailsF.h"
#include "remotestrs.hpp"
#include "reinit.hpp"




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
        ShowMain(this);
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
        mnuPauseClick(this);
    break;

    case WM_LBUTTONDBLCLK:
    // as pause will have updated WAstatus for us
      if (WAStatus == WA_NOT_PLAYING)
      {
        mnuPlayClick(this);
      }
      if (WAStatus == WA_PAUSED)
      {
        mnuStopClick(this);
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

        mnuPause->Caption = Remotestrs_sPause;
        Pause1->Caption = Remotestrs_sPause;
        fIconIndex = 3;
        break;
      case WA_PLAYING:
        Pause->Caption = Remotestrs_sPause;
        Pause->Checked = false;
        fIconIndex = 1;
        break;
      case WA_PAUSED:
        Pause->Caption = Remotestrs_sUnPause;
        Pause->Checked = true;
        fIconIndex = 2;
        break;
      default:
        fIconIndex = 5;
    }
  }

  else
  {
    fIconIndex = 6;
  }

  frmMain->imlCommandsHot->GetIcon( fIconIndex, icoState->Picture->Icon);
  frmMain->imlTrayIcons->GetIcon( fIconIndex, icoTrayIcon->Picture->Icon);

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
    state = Remotestrs_sPlaying;
    break;
  case WA_NOT_PLAYING:
    state = Remotestrs_sStopped;
    break;
  case WA_PAUSED:
    state = Remotestrs_sPaused;
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
void __fastcall TfrmMain::HideMain(TObject *Sender)
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

void __fastcall TfrmMain::ShowMain(TObject *Sender)
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

void __fastcall TfrmMain::mnuPauseClick(TObject *Sender)
{
  if (WAStatus == IntegerResult(IdentChars, IPC_ISPLAYING, 0))
    ExecuteMessage(IdentChars, WINAMP_PAUSE);
    UpdateIcon();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnuShutDownClick(TObject *Sender)
{
  Close();
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormShow(TObject *Sender)
{


  // set up commands form images
  frmCommands->tbCommands->Images = imlCommandsCool;
  frmCommands->tbCommands->HotImages = imlCommandsHot;

  // show hints on visible forms
  frmPlaylist->ShowHint = false;
  frmSettings->ShowHint = false;
  frmCommands->ShowHint = false;

  // set drag mode
  frmPlaylist->DragKind = dkDock;
  frmCommands->DragKind = dkDock;
  frmSettings->DragKind = dkDock;

  if (!timerMain->Enabled)
  {
    TRegistry * reg = new TRegistry();
    TRect FormRect;
    int FormLeft, FormTop, FormWidth, FormHeight;
    try
    {
      reg->OpenKey("software\\PMMSoft\\Winamp controller\\client settings", true);

      if (chkAutoRestore->Checked)
      {

         if (reg->ReadString("Commands Docked").LowerCase() == "true")
         {
           frmCommands->ManualDock(pnlCommands, NULL, alTop);
           EndDock(frmCommands, NULL, 0,0);
         }

         FormRect = TRect(0, 0, frmCommands->Width, frmCommands->Height);
         FormLeft = reg->ReadString("Commands Left").ToIntDef(-1);
         FormTop = reg->ReadString("Commands Top").ToIntDef(-1);

         if ((FormLeft > 0) && (FormTop > 0))
         {
           OffsetRect(&FormRect, FormLeft, FormTop);
           frmCommands->BoundsRect = FormRect;
         }

         if (reg->ReadString("Commands Visible").LowerCase() == "true")
           ViewToolBarExecute(this);


         if (reg->ReadString("Volume Docked").LowerCase() == "true")
         {
           frmSettings->ManualDock(pgSettings, NULL, alClient);
           EndDock(frmSettings, NULL, 0,0);
         }


         FormRect = TRect(0, 0, frmSettings->Width, frmSettings->Height);
         FormLeft = reg->ReadString("Volume Left").ToIntDef(-1);
         FormTop = reg->ReadString("Volume Top").ToIntDef(-1);

         if ((FormLeft > 0) && (FormTop > 0))
         {
           OffsetRect(&FormRect, FormLeft, FormTop);
           frmSettings->BoundsRect = FormRect;
         }

         if (reg->ReadString("Volume Visible").LowerCase() == "true")
           ViewVolumeExecute(this);


         if (reg->ReadString("Playlist Docked").LowerCase() == "true")
         {
           frmPlaylist->ManualDock(pgSettings, NULL, alClient);
           EndDock(frmPlaylist, NULL, 0,0);
         }

         FormLeft = reg->ReadString("Playlist Left").ToIntDef(-1);
         FormTop = reg->ReadString("Playlist Top").ToIntDef(-1);
         FormWidth = reg->ReadString("Playlist Width").ToIntDef(180);
         FormHeight = reg->ReadString("Playlist Height").ToIntDef(240);
         FormRect = TRect(0, 0, FormWidth, FormHeight);

         if ((FormLeft > 0) && (FormTop > 0))
         {
           OffsetRect(&FormRect, FormLeft, FormTop);
           frmPlaylist->BoundsRect = FormRect;
         }

         if (reg->ReadString("Playlist Visible").LowerCase() == "true")
           ViewPlaylistExecute(this);


       }
       if (reg->OpenKey("Testing", false))
       {
         if (reg->ReadString("Language").LowerCase() == "true")
         {
           mnuLanguage->Visible = false;
         }
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

void __fastcall TfrmMain::mnuSayHelloClick(TObject *Sender)
{
  SendString(IdentChars);
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnCloseClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuPlayClick(TObject *Sender)
{
  ExecuteMessage(IdentChars, WINAMP_PLAYENTRY);
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::mnuNextClick(TObject *Sender)
{
  ExecuteMessage(IdentChars, WINAMP_NEXT);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuPreviousClick(TObject *Sender)
{
  ExecuteMessage(IdentChars, WINAMP_PREVIOUS);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormHide(TObject *Sender)
{
  mnuShow->Visible = true;
  frmPlaylist->DragKind = dkDrag;
  frmCommands->DragKind = dkDrag;
  frmSettings->DragKind = dkDrag;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuAboutClick(TObject *Sender)
{
  if (!frmAbout)
  {
    frmAbout = new TfrmAbout(this);
    try
    {
      frmAbout->Caption = Remotestrs_sAboutWinampRemoteControl;
      OutText->Text= Remotestrs_sWinampRemoteControl;
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

void __fastcall TfrmMain::mnuStopClick(TObject *Sender)
{
  ExecuteMessage(IdentChars, WINAMP_STOP);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuForward5Click(TObject *Sender)
{
  ExecuteMessage(IdentChars, WINAMP_FORWARD5S);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuBack5Click(TObject *Sender)
{
  ExecuteMessage(IdentChars, WINAMP_BACK5S);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuVolumeUpClick(TObject *Sender)
{
  frmSettings->tbVolume->Position++;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuVolumeDownClick(TObject *Sender)
{
  frmSettings->tbVolume->Position--;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuVolumeUpMoreClick(TObject *Sender)
{
  frmSettings->tbVolume->Position+=10;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuVolumeDownMoreClick(TObject *Sender)
{
  frmSettings->tbVolume->Position-=10;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuPlaylistStartClick(TObject *Sender)
{
  ExecuteMessage(IdentChars, WINAMP_STARTOFPLAYLIST);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuPlaylistEndClick(TObject *Sender)
{
  ExecuteMessage(IdentChars, WINAMP_ENDOFPLAYLIST);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuDeletePlayListClick(TObject *Sender)
{
  IntegerResult(IdentChars, IPC_DELETE, 0);
  frmPlaylist->SongsRefresh(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuAddFileToPlayListClick(TObject *Sender)
{
AnsiString str;
AnsiString commandstr;

  OpenDialog1->FileName = "";

  if (Sender == mnuAddPlayList){
    OpenDialog1->Filter = Remotestrs_sPlayListFiles;
    }
  else{
    OpenDialog1->Filter = Remotestrs_sAllFiles;
    }

  if (OpenDialog1->Execute())
  {

    TStringList * Files = new TStringList;
    try
    {
      // sort strings by name, for now
      Files->Sorted = true;

      Files->Assign(OpenDialog1->Files);

      frmPlaylist->AddFiles(Files);
      frmPlaylist->SongsRefresh(this);
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

void __fastcall TfrmMain::mnuStopFadeClick(TObject *Sender)
{
  ExecuteMessage(IdentChars, WINAMP_STOPFADE);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuStopCurrentClick(TObject *Sender)
{
  ExecuteMessage(IdentChars, WINAMP_STOPAFTERCURRENT);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::DisplayHint(TObject *Sender)
{
  sbMain->Panels->Items[1]->Text = GetShortHint(Application->Hint);
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormCreate(TObject *Sender)
{


  /* set up language IDs */
  mnuEnglishUS->Tag = ENGLISHUS;
  mnuEnglishUK->Tag = ENGLISHUK;
  mnuFrench->Tag = FRENCH;
  mnuGerman->Tag = GERMAN;
  mnuDutch->Tag = DUTCH;

  /* set language */

  switch (SysLocale.DefaultLCID)
  {
    case ENGLISHUS: SetLanguageMenu(mnuEnglishUS);
      break;
    case ENGLISHUK: SetLanguageMenu(mnuEnglishUK);
      break;
    case FRENCH: SetLanguageMenu(mnuFrench);
      break;
    case GERMAN: SetLanguageMenu(mnuGerman);
      break;
    case DUTCH: SetLanguageMenu(mnuDutch);
      break;
  }

  Application->OnException = AppException;

  /* set up the nice 256 colours icon now*/

  fIconIndex = 6;

  frmMain->imlCommandsHot->GetIcon( fIconIndex , icoState->Picture->Icon);
  frmMain->imlTrayIcons->GetIcon( fIconIndex , icoTrayIcon->Picture->Icon);

  Application->Icon->Handle = icoState->Picture->Icon->Handle;
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
      this->ebEndPoint->Text = AnsiString(PortDefault);
    if (this->ebAddress->Text == "")
      this->ebAddress->Text = "localhost";

     if (reg->ReadString("AutoHide").LowerCase() == "false"){
       chkAutoHide->Checked = false;
       }

     if (reg->ReadString("AutoRestore").LowerCase() == "false"){
       chkAutoRestore->Checked = false;
       }

     if (reg->ReadString("Playlist Update").LowerCase() == "every song"){
       rbSongChange->Checked = true;
       }

     if ((reg->ReadString("Visible").LowerCase() == "false") && (chkAutoHide->Checked)){
       doHide = true;
       }

    this->lstTimer->ItemIndex = reg->ReadString("Poll Interval").ToIntDef(1);

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


void __fastcall TfrmMain::AppException(TObject *Sender, Exception *E)
{
  AnsiString RPCHint = Remotestrs_sRPCFailed;

  if (dynamic_cast <ERPCException*> (E)){
    MessageForm((AnsiString(RPCHint) + "\nMessage: " + E->Message));
    }
  else
  {
    MessageForm((AnsiString(Remotestrs_sUnhandledException) + E->ClassName()+ ":\n" + E->Message));
  }
}

//---------------------------------------------------------------------------


void TfrmMain::UpdateIcon(void)
{
  char title[sizeof(IdentChars)]; // MAX_PATH == maximum user name ?
  int index, length;
  AnsiString saveStr;

  Cardinal UpdateTime = 1000 * (lstTimer->ItemIndex + 1);

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
           lblMessage->Hint = Remotestrs_sCurrentTrack;
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
            if (length != frmPlaylist->lastlength)
            {
              frmPlaylist->SongsRefresh(this);
            }
          }

          if (rbSongChange->Checked)
          {
            if ((index != frmPlaylist->lastindex) || (length != frmPlaylist->lastlength))
            {
              frmPlaylist->SongsRefresh(this);
              frmPlaylist->SongIndexUpdate(this);
            }
          }
          else
          if (frmPlaylist->lastindex != index)
          {
            frmPlaylist->currentpos = index;
            frmPlaylist->SongIndexUpdate(this);
          }

          // set last "OK" list index
          frmPlaylist->lastindex = index;
          frmPlaylist->lastlength = length;
          if (timerMain->OnTimer != MainTimer)
            timerMain->OnTimer = MainTimer;

          frmPlaylist->StatsUpdate();

        }

      } // if list length non-zero
    }

  catch( ERPCException &E)
  {
    doHide = false;
    if (frmPlaylist)
    {
      frmPlaylist->lastindex = -1;
      frmPlaylist->lastlength = -1;
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

void __fastcall TfrmMain::MainTimer(TObject *Sender)
{
  UpdateIcon();
  if (doHide)
  {
    doHide = false;
    HideMain(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuSetVolume0Click(TObject *Sender)
{
  frmSettings->tbVolume->Position = 0;

}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuSetVolume100Click(TObject *Sender)
{
  frmSettings->tbVolume->Position = 255;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuShuffleClick(TObject *Sender)
{
  // shuffle / repeat status only works in very recent versions,
  // so always do for older
  if ( (WinampVerNo < 0x2604) || (Shuffle->Checked == IntegerResult(IdentChars, IPC_GETSHUFFLEOPTION, 0)) )
    ExecuteMessage(IdentChars, WINAMP_FILE_SHUFFLE);
  UpdateIcon();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuRepeatClick(TObject *Sender)
{
  // shuffle / repeat status only works in very recent versions,
  // so always do for older
  if  ( (WinampVerNo < 0x2604) || (Repeat->Checked == IntegerResult(IdentChars, IPC_GETREPEATOPTION, 0)) )
    ExecuteMessage(IdentChars, WINAMP_FILE_REPEAT);
  UpdateIcon();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuPlayFromStartClick(TObject *Sender)
{
  IntegerResult(IdentChars, IPC_STARTPLAY, 0);
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
  TrayMessage(NIM_DELETE);
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormCloseQuery(TObject *Sender, bool &CanClose)
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

    reg->WriteString("Visible", Visible?"true":"false");

    reg->WriteString("Poll Interval", AnsiString(lstTimer->ItemIndex));

    reg->WriteString("AutoHide", chkAutoHide->Checked?"true":"false");
    reg->WriteString("AutoRestore", chkAutoRestore->Checked?"true":"false");

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
      reg->WriteString("Commands Visible", frmCommands->Visible?"true":"false");
      reg->WriteString("Commands Docked", frmCommands->HostDockSite?"true":"false");

      reg->WriteString("Playlist Left", AnsiString(frmPlaylist->Left));
      reg->WriteString("Playlist Top", AnsiString(frmPlaylist->Top));
      reg->WriteString("Playlist Width", AnsiString(frmPlaylist->Width));
      reg->WriteString("Playlist Height", AnsiString(frmPlaylist->Height));
      reg->WriteString("Playlist Visible", frmPlaylist->Visible?"true":"false");
      reg->WriteString("Playlist Docked", frmPlaylist->HostDockSite?"true":"false");

      reg->WriteString("Volume Left", AnsiString(frmSettings->Left));
      reg->WriteString("Volume Top", AnsiString(frmSettings->Top));
      reg->WriteString("Volume Visible", frmSettings->Visible?"true":"false");
      reg->WriteString("Volume Docked", frmSettings->HostDockSite?"true":"false");
      }
    }
  __finally
  {
    delete reg;
  }
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::lstTimerClick(TObject *Sender)
{
  timerMain->Interval = 1000 * (lstTimer->ItemIndex + 1);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::HalfExecute(TObject *Sender)
{
  frmSettings->tbVolume->Position = 128;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ViewToolBarExecute(TObject *Sender)
{
  // need to undock
  frmCommands->Visible = !frmCommands->Visible;
  AnimateForm(frmCommands, ViewToolBar->Checked);
  ViewToolBar->Checked = frmCommands->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ViewPlaylistExecute(TObject *Sender)
{
  frmPlaylist->Visible = !frmPlaylist->Visible;
  AnimateForm(frmPlaylist, ViewPlaylist->Checked);
  ViewPlaylist->Checked = frmPlaylist->Visible;


}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ViewVolumeExecute(TObject *Sender)
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
    str = Remotestrs_sUnknown;

  maxlen = 31;
  str += '@';

  if (GetComputerName(buf, &maxlen))
    str += buf;
  else
    str += Remotestrs_sUnknown;

  strncpy(IdentChars, str.c_str(), sizeof(IdentChars));
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormDestroy(TObject *Sender)
{
  UnBind();
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::AddressChange(TObject *Sender)
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
   sbMain->Panels->Items[1]->Text = Remotestrs_sDelaying;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::LocateServersExecute(TObject *Sender)
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

void __fastcall TfrmMain::DelayTimer(TObject *Sender)
{
  if (--Delay > 0)
  {
    sbMain->Panels->Items[1]->Text = AnsiString().sprintf(Remotestrs_sDelayingForFmt.c_str(), Delay);
  }
  else
  {
    sbMain->Panels->Items[1]->Text = Remotestrs_sRestarting;
    timerMain->Enabled = false;
    timerMain->OnTimer = MainTimer;
    timerMain->Enabled = true;
  }

}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::RefreshEQExecute(TObject *Sender)
{
   frmSettings->UpdateBars();
}

//---------------------------------------------------------------------------

void _fastcall TfrmMain::DoBind(void)
{
  Bind((unsigned char *) ebAddress->Text.c_str(),
       (unsigned char *) ebEndPoint->Text.c_str());
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::AutoloadExecute(TObject *Sender)
{
  Autoload->Checked = !Autoload->Checked;
  IntegerResult(IdentChars, IPC_GETEQDATA, 11);
  IntegerResult(IdentChars, IPC_SETEQDATA, Autoload->Checked );
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormDockOver(TObject *Sender,
      TDragDockObject *Source, int X, int Y, TDragState State,
      bool &Accept)
{
  Accept = true;
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::StartDock(TObject *Sender,
      TDragDockObject *&DragObject)
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

void __fastcall TfrmMain::pgSettingsDockDrop(TObject *Sender,
      TDragDockObject *Source, int X, int Y)
{
  int ImageIndex = 0;
// set the imageindex for the dropped form
  if (Source->Control == frmSettings)
  {
    ImageIndex = 4;
  }
  else if (Source->Control == frmPlaylist)
  {
    ImageIndex = 5;
  }

  // set image index
  int PageIndex = pgSettings->PageCount -1;
  pgSettings->Pages[PageIndex]->ImageIndex = ImageIndex;
  // and have a shortcut
  pgSettings->Pages[PageIndex]->Caption = "&" + pgSettings->Pages[PageIndex]->Caption;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::EndDock(TObject *Sender, TObject *Target, int X,
      int Y)
{
  pgSettings->DockSite = true;
  pnlCommands->DockSite = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::DetailsExecute(TObject *Sender)
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

void __fastcall TfrmMain::sbMainDrawPanel(TStatusBar *StatusBar,
      TStatusPanel *Panel, const TRect &Rect)
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





void __fastcall TfrmMain::SetLanguageExecute(TObject *Sender)
{

  // save some state for the child forms
  bool CommandsVisible, PlaylistVisible, SettingsVisible,
          CommandsDocked, PlaylistDocked, SettingsDocked;

  CommandsVisible = frmCommands->Visible;
  CommandsDocked = frmCommands->HostDockSite;
  PlaylistVisible = frmPlaylist->Visible;
  PlaylistDocked = frmPlaylist->HostDockSite;
  SettingsVisible = frmSettings->Visible;
  SettingsDocked = frmSettings->HostDockSite;


  if (LoadNewResourceModule(((TComponent*)Sender)->Tag) != 0)
  {

    // reinitialise the application resources
    // hide the lot
    frmCommands->Hide();
    frmPlaylist->Hide();
    frmSettings->Hide();
    // undock the lot
    if (CommandsDocked)
      frmCommands->ManualFloat(frmCommands->BoundsRect);


    ReinitializeForms();

    // now some of the docked forms may
    // look a little odd after reinitialising
    // and need their state reset

    // for instance, the commands bar sprouts a non-client area
    // the playlist will have the list cleared, and needs refreshing

    frmCommands->Visible = CommandsVisible;
    frmPlaylist->Visible = PlaylistVisible;
    frmSettings->Visible = SettingsVisible;

    if (CommandsDocked)
    {
      // DragObject is not used
      StartDock(frmCommands, NULL);
      frmCommands->ManualDock(pnlCommands, NULL, alTop);
      EndDock(frmCommands, NULL, 0,0);
    }


    SetLanguageMenu(Sender);

  }

}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::SetLanguageMenu(TObject *Sender)
{
    mnuEnglishUS ->Checked = mnuEnglishUS == Sender;
    mnuEnglishUK ->Checked = mnuEnglishUK == Sender;
    mnuGerman->Checked  = mnuGerman == Sender;
    mnuFrench->Checked  = mnuFrench == Sender;
    mnuDutch->Checked  = mnuDutch == Sender;

}

//---------------------------------------------------------------------------






