// winamp remote control suite ©Patrick Michael Martin 2000
//
// MainF.cpp
//
// main form for remote project
//

#include <vcl.h>
#pragma hdrstop

#include <registry.hpp>

// forms...

#include "MainF.h"
#include "messageF.h"
#include "AboutF.h"

#include "PlaylistF.h"
#include "SettingsF.h"
#include "CommandF.h"
#include "ServersF.h"

// winamp IPC declarations
#include "waint.h"


// RPC functions
#include "RPCFuncsU.h"

char IdentChars[65];
WAPlaybackStatus WAStatus;


//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TfrmMain *frmMain;

/* global string binding information */
  unsigned char * pszStringBinding = NULL;

//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::DrawItem(TMessage& Msg)
{
     IconDrawItem((LPDRAWITEMSTRUCT)Msg.LParam);
     TForm::Dispatch(&Msg);
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
        ShowMainExecute(this);
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

   tnd.cbSize          = sizeof(NOTIFYICONDATA);
   tnd.hWnd            = Handle;
   tnd.uID             = IDC_TRAYICON;
   tnd.uFlags          = NIF_MESSAGE | NIF_ICON | NIF_TIP;
   tnd.uCallbackMessage	= TRAY_NOTIFY;

   if (dwMessage == NIM_MODIFY)
    {
        tnd.hIcon		= IconHandle();
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

  int IconIndex;

    switch (WAStatus){
    case WA_NOT_PLAYING:

      mnuPause->Caption = "&Pause";
      Pause1->Caption = "&Pause";
      IconIndex = 3;
      break;
    case WA_PLAYING:
      Pause->Caption = "&Pause";
      Pause->Checked = false;
      IconIndex = 1;
      break;
    case WA_PAUSED:
      Pause->Caption = "Un&Pause";
      Pause->Checked = true;
      IconIndex = 2;
      break;
    default:
      IconIndex = 5;
    }

    frmMain->imlCommandsHot->GetIcon( IconIndex, icoState->Picture->Icon);
    frmMain->imlTrayIcons->GetIcon( IconIndex, icoTrayIcon->Picture->Icon);

    Application->Icon->Handle = icoState->Picture->Icon->Handle;

    return icoTrayIcon->Picture->Icon->Handle;

}
//---------------------------------------------------------------------------
PSTR __fastcall TfrmMain::TipText(void)
{
AnsiString str = lblMessage->Caption;

  switch (WAStatus){
  case WA_PLAYING:
    str += " [playing]";
    break;
  case WA_NOT_PLAYING:
    str += " [stopped]";
    break;
  case WA_PAUSED:
    str += " [paused]";
    break;
  }

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

  DWORD dwExStyle = GetWindowLong(Application->Handle, GWL_EXSTYLE);
  dwExStyle |= WS_EX_TOOLWINDOW;
  SetWindowLong(Application->Handle, GWL_EXSTYLE, dwExStyle);

  Hide();

}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::EditKeyUp(TObject *Sender, WORD &Key,
    TShiftState Shift)
{
  if (!Visible)
      return;

  TrayMessage(NIM_MODIFY);
}
//---------------------------------------------------------------------------
LRESULT __fastcall TfrmMain::IconDrawItem(LPDRAWITEMSTRUCT lpdi)
{
  HICON hIcon;

  hIcon = (HICON)LoadImage(Application->Handle, MAKEINTRESOURCE(lpdi->CtlID), IMAGE_ICON,
          16, 16, 0);
  if (!hIcon)
          return(FALSE);

  DrawIconEx(lpdi->hDC, lpdi->rcItem.left, lpdi->rcItem.top, hIcon,
          16, 16, 0, NULL, DI_NORMAL);

  return true;
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

TRegistry * reg;

  if (!timerMain->Enabled){

    try{
        reg = new TRegistry();
        reg->OpenKey("software\\PMMSoft\\Winamp controller\\client settings", true);

        if (chkAutoRestore->Checked){

           if (reg->ReadString("Commands Visible").LowerCase() == "true"){
             ViewToolBarExecute(this);
             }

           if (reg->ReadString("Commands Docked").LowerCase() == "true"){
             frmCommands->ManualDock(pnlCommands, NULL, alLeft);
             EndDock(frmCommands, NULL, 0,0);
             }

           if (reg->ReadString("Commands Left").ToIntDef(-1) > 0){
             frmCommands->Left = reg->ReadString("Commands Left").ToInt();
             }

           if (reg->ReadString("Commands Top").ToIntDef(-1) > 0){
             frmCommands->Top = reg->ReadString("Commands Top").ToInt();
             }


           if (reg->ReadString("Volume Visible").LowerCase() == "true"){
             ViewVolumeExecute(this);
             }

           if (reg->ReadString("Volume Docked").LowerCase() == "true"){
             frmSettings->ManualDock(pgSettings, NULL, alClient);
             EndDock(frmSettings, NULL, 0,0);
             }


           if (reg->ReadString("Volume Left").ToIntDef(-1) > 0){
             frmSettings->Left = reg->ReadString("Volume Left").ToInt();
             }

           if (reg->ReadString("Volume Top").ToIntDef(-1) > 0){
             frmSettings->Top = reg->ReadString("Volume Top").ToInt();
             }


           if (reg->ReadString("Playlist Visible").LowerCase() == "true"){
             ViewPlaylistExecute(this);
             }

           if (reg->ReadString("Playlist Docked").LowerCase() == "true"){
             frmPlaylist->ManualDock(pgSettings, NULL, alClient);
             EndDock(frmPlaylist, NULL, 0,0);
             }

           if (reg->ReadString("Playlist Left").ToIntDef(-1) > 0){
             frmPlaylist->Left = reg->ReadString("Playlist Left").ToInt();
             }

           if (reg->ReadString("Playlist Top").ToIntDef(-1) > 0){
             frmPlaylist->Top = reg->ReadString("Playlist Top").ToInt();
             }
           }
      }

    __finally {
      delete reg;
      }
    }

  // show hints on visible forms
  frmPlaylist->ShowHint = false;
  frmSettings->ShowHint = false;
  frmCommands->ShowHint = false;

  // set drag mode
  frmPlaylist->DragKind = dkDock;
  frmCommands->DragKind = dkDock;
  frmSettings->DragKind = dkDock;


  // show hints on visible forms
  frmPlaylist->Visible = frmPlaylist->Showing;
  frmSettings->Visible = frmSettings->Showing;
  frmCommands->Visible = frmCommands->Showing;

  pgSettings->ActivePage = tbsMain;
  mnuShow->Visible = false;
  TrayMessage(NIM_DELETE);
  timerMain->Enabled = true;
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
      frmAbout->Caption = "About winamp remote control client";
      OutText->Text= "winamp\r\nremote\r\ncontrol\r\nclient";
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
  frmPlaylist->lstSongsRefresh(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuAddFileToPlayListClick(TObject *Sender)
{
AnsiString str;
AnsiString commandstr;

  OpenDialog1->FileName = "";

  if (Sender == mnuAddPlayList){
    OpenDialog1->Filter = "Playlist Files(*.m3u,*.pls)|*.m3u,*.pls";
    }
  else{
    OpenDialog1->Filter = "All files|*.*";
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
      frmPlaylist->lstSongsRefresh(this);
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
  frmMessage->memMessage->Lines->Text = MessageStr;
  frmMessage->Show();
  frmMessage->Refresh();
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
  ;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::DisplayHint(TObject *Sender)
{
  sbMain->Panels->Items[1]->Text = GetShortHint(Application->Hint);
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormCreate(TObject *Sender)
{

   /* set up the nice 256 colours icon now*/

  frmMain->imlCommandsHot->GetIcon( 5 , icoState->Picture->Icon);
  frmMain->imlTrayIcons->GetIcon( 5 , icoTrayIcon->Picture->Icon);

  Application->Icon->Handle = icoState->Picture->Icon->Handle;
  Application->OnHint = DisplayHint;


TRegistry * reg;

  try{
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
  __finally {
    delete reg;
    }

  Application->OnException = AppException;

  pgSettings->ActivePage = tbsMain;
  SetIdent();

  DoBind();

}

//---------------------------------------------------------------------------


void __fastcall TfrmMain::AppException(TObject *Sender, Exception *E)

{
char RPCHint[] = "An RPC call failed\n\n(hint) is the server running at that endpoint?\n";

  if (dynamic_cast <ERPCException*> (E)){
    MessageForm((AnsiString(RPCHint) + "\nMessage: " + E->Message));
    }
  else
  {
    MessageForm((AnsiString("There was an unhandled exception\nType: " + E->ClassName()+ "\nMessage: " + E->Message)));
  }
}

//---------------------------------------------------------------------------

void TfrmMain::UpdateWAStatus(void)
{
  WAStatus = (WAPlaybackStatus) IntegerResult(IdentChars, IPC_ISPLAYING, 0);
}

//---------------------------------------------------------------------------

void TfrmMain::UpdateIcon(void){
char title[MAX_PATH * 2 + 1]; // MAX_PATH == maximum user name
int index, length;
AnsiString saveStr;

Cardinal UpdateTime = 1000 * (lstTimer->ItemIndex + 1);

  try{

    sbMain->Panels->Items[0]->Text = "querying server";
    sbMain->Refresh();

    UpdateWAStatus();

    Shuffle->Checked = (WinampVerNo >= 0x2604) && IntegerResult(IdentChars, IPC_GETSHUFFLEOPTION, 0);
    Repeat->Checked = (WinampVerNo >= 0x2604) && IntegerResult(IdentChars, IPC_GETREPEATOPTION, 0);

    if (frmSettings->EQUpdateNeeded)
      frmSettings->UpdateBars();


    if ( timerMain->Interval != UpdateTime){
      timerMain->Interval = UpdateTime;
      WinampVerNo = IntegerResult(IdentChars, IPC_GETVERSION,  0);
      lblVersion->Caption = WinampVersion(WinampVerNo);
      }

    strcpy(title, IdentChars);

    length = IntegerResult(IdentChars, IPC_GETLISTLENGTH, 0);
    if (length > 0){
      index = IntegerResult(IdentChars, IPC_GETLISTPOS, 0);

      StringResult(title, IPC_GETPLAYLISTTITLE, index);
      if (title){
        lblMessage->Caption = (AnsiString(index + 1) + ". " + title);

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
           lblMessage->Hint = "current track";
           lblMessage->ParentShowHint = true;
           lblMessage->ShowHint = false;
         }

        }

        //update the playlist form
        //always check this first, to get length straight
        if ((rbPlaylistChange->Checked) || (index >= length)){
          if (length != frmPlaylist->lastlength){
            frmPlaylist->lstSongsRefresh(this);
            }
          }

        if (rbSongChange->Checked)
        {
          if ((index != frmPlaylist->lastindex) || (length != frmPlaylist->lastlength))
          {
            frmPlaylist->lstSongsRefresh(this);
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

      } // if list length non-zero
    }
  catch( ERPCException &E){
    doHide = false;
    frmPlaylist->lastindex = -1;
    frmPlaylist->lastlength = -1;

    WAStatus = WA_UNUSED;
    lblMessage->Caption = E.Message;
    lblVersion->Caption = WinampVersion(0);
    timerMain->Interval = 1000 * FAIL_TIMEOUT;
    }

    sbMain->Panels->Items[0]->Text = "idle";
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

  try{
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

       if  (rbSongChange->Checked){
          reg->WriteString("Playlist Update", "every song");
          }
        else{
          reg->WriteString("Playlist Update", "playlist change");
         }

      // only save settings if check box checked, to prevent overwriting with defaults
      if (chkAutoRestore->Checked){
        reg->WriteString("Commands Left", AnsiString(frmCommands->Left));
        reg->WriteString("Commands Top", AnsiString(frmCommands->Top));
        reg->WriteString("Commands Visible", frmCommands->Showing?"true":"false");
        reg->WriteString("Commands Docked", frmCommands->HostDockSite?"true":"false");

        reg->WriteString("Playlist Left", AnsiString(frmPlaylist->Left));
        reg->WriteString("Playlist Top", AnsiString(frmPlaylist->Top));
        reg->WriteString("Playlist Visible", frmPlaylist->Showing?"true":"false");
        reg->WriteString("Playlist Docked", frmPlaylist->HostDockSite?"true":"false");

        reg->WriteString("Volume Left", AnsiString(frmSettings->Left));
        reg->WriteString("Volume Top", AnsiString(frmSettings->Top));
        reg->WriteString("Volume Visible", frmSettings->Showing?"true":"false");
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
  ViewToolBar->Checked = frmCommands->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ViewPlaylistExecute(TObject *Sender)
{
  frmPlaylist->Visible = !frmPlaylist->Visible;
  ViewPlaylist->Checked = frmPlaylist->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ViewVolumeExecute(TObject *Sender)
{
  frmSettings->Visible = !frmSettings->Visible;
  ViewVolume->Checked = frmSettings->Visible;

}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ShowMainExecute(TObject *Sender)
{
  ShowWindow(Application->Handle, SW_SHOW);

  DWORD dwExStyle = GetWindowLong(Application->Handle, GWL_EXSTYLE);
  dwExStyle ^= WS_EX_TOOLWINDOW;
  SetWindowLong(Application->Handle, GWL_EXSTYLE, dwExStyle);

  Show();
}
//---------------------------------------------------------------------------

void SetIdent(void)
{

char UserName[32], ComputerName[32];
unsigned long maxlen = 31;
AnsiString str;

  if (GetUserName(UserName, &maxlen))
    str =UserName;
  else
    str = "<unknown>";

  maxlen = 31;
  str += '@';

  if (GetComputerName(ComputerName, &maxlen))
    str += ComputerName;
  else
    str += "<unknown>";

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
   sbMain->Panels->Items[0]->Text = "delaying";
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
    sbMain->Panels->Items[0]->Text = AnsiString("delaying for ") + Delay + " more s";
  }
  else
  {
    sbMain->Panels->Items[0]->Text = "restarting";
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



