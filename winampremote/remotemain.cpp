//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#include <shellapi.h>
#include <shlobj.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <rpc.h>
#include <registry.hpp>
#pragma hdrstop

// problem with definition of __try
#define __try try

#include "winampinterface.h"    // header file generated by MIDL compiler
#include "winampinterface_c.c"   // needed to link in the stub functions - why?


// forms...

#include "remotemain.h"
#include "messageF.h"
#include "AboutF.h"

// winamp interface declarations

#include "waint.h"

//RPC Errors

#include "RPCErrors.h"
#include "PlaylistF.h"
#include "SettingsF.h"
#include "CommandF.h"
#include "global.h"

WAPlaybackStatus WAStatus = WA_UNUSED;


//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TfrmMain *frmMain;

/* global string binding information */
  unsigned char *   pszStringBinding = NULL;

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
void __fastcall TfrmMain::MyNotify(TMessage& Msg)
{
    POINT MousePos;

    switch(Msg.LParam)
    {
        case WM_RBUTTONUP:
            if (GetCursorPos(&MousePos))
            {
                pmnuMain->PopupComponent = frmMain;
                SetForegroundWindow(Handle);
                pmnuMain->Popup(MousePos.x, MousePos.y);
            }
            else
                this->Show();
            break;
        case WM_LBUTTONUP:
            mnuPauseClick(this);
            break;
        default:
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
   tnd.uID             = IDC_MYICON;
   tnd.uFlags          = NIF_MESSAGE | NIF_ICON | NIF_TIP;
   tnd.uCallbackMessage	= MYWM_NOTIFY;

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

    switch (WAStatus){
    case WA_NOT_PLAYING:
      Application->Icon->Handle = LoadIcon(HInstance, "STOPPED");
      mnuPause->Caption = "&Pause";
      Pause1->Caption = "&Pause";
      break;
    case WA_PLAYING:
      Application->Icon->Handle = LoadIcon(HInstance, "PLAYING");
      mnuPause->Caption = "&Pause";
      Pause1->Caption = "&Pause";
      break;
    case WA_PAUSED:
      Application->Icon->Handle = LoadIcon(HInstance, "PAUSED");
      mnuPause->Caption = "Un&Pause";
      Pause1->Caption = "Un&Pause";
      break;
    default:
      Application->Icon->Handle = LoadIcon(HInstance, "UNKNOWN");
    }

    this->Icon->Handle = Application->Icon->Handle;
    icoState->Picture->Icon->Handle = Application->Icon->Handle;
    return Application->Icon->Handle;


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
void __fastcall TfrmMain::btnHideClick(TObject *Sender)
{

  	TrayMessage(NIM_ADD);
    TrayMessage(NIM_MODIFY);

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
LRESULT IconDrawItem(LPDRAWITEMSTRUCT lpdi)
{
	HICON hIcon;

	hIcon = (HICON)LoadImage(g_hinst, MAKEINTRESOURCE(lpdi->CtlID), IMAGE_ICON,
		16, 16, 0);
	if (!hIcon)
		return(FALSE);

	DrawIconEx(lpdi->hDC, lpdi->rcItem.left, lpdi->rcItem.top, hIcon,
		16, 16, 0, NULL, DI_NORMAL);

	return(TRUE);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnuShowClick(TObject *Sender)
{
    this->Show();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnuPauseClick(TObject *Sender)
{
  if (WAStatus == IntegerResult(Ident(), IPC_ISPLAYING, 0))
    ExecuteMessage(Ident(), WINAMP_PAUSE);
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

  try{
      reg = new TRegistry();
      reg->OpenKey("software\\PMMSoft\\Winamp controller\\client settings", true);

      if (chkAutoRestore->Checked){

         if (reg->ReadString("Commands Visible") == "true"){
           frmCommands->Show();
           }

         if (reg->ReadString("Commands Left").ToIntDef(-1) > 0){
           frmCommands->Top = reg->ReadString("Commands Left").ToInt();
           }

         if (reg->ReadString("Commands Top").ToIntDef(-1) > 0){
           frmCommands->Top = reg->ReadString("Commands Top").ToInt();
           }


         if (reg->ReadString("Volume Visible") == "true"){
           frmSettings->Show();
           }

         if (reg->ReadString("Volume Left").ToIntDef(-1) > 0){
           frmSettings->Left = reg->ReadString("Volume Left").ToInt();
           }

         if (reg->ReadString("Volume Top").ToIntDef(-1) > 0){
           frmSettings->Top = reg->ReadString("Volume Top").ToInt();
           }


         if (reg->ReadString("Playlist Visible") == "true"){
           frmPlaylist->Show();
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



  mnuShow->Visible = false;
  TrayMessage(NIM_DELETE);
  timerMain->Enabled = true;
}

void __fastcall TfrmMain::mnuSayHelloClick(TObject *Sender)
{
  SendString(Ident());
}


//---------------------------------------------------------------------------


void __fastcall TfrmMain::btnCloseClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuPlayClick(TObject *Sender)
{
  ExecuteMessage(Ident(), WINAMP_PLAYENTRY);
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::mnuNextClick(TObject *Sender)
{
  ExecuteMessage(Ident(), WINAMP_NEXT);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuPreviousClick(TObject *Sender)
{
  ExecuteMessage(Ident(), WINAMP_PREVIOUS);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormHide(TObject *Sender)
{
  mnuShow->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuAboutClick(TObject *Sender)
{
  try{
    frmAbout = new TfrmAbout(this);
    frmAbout->Caption = "About winamp remote control client";
    OutText->Clear();
    OutText->Add("winamp");
    OutText->Add("remote");
    OutText->Add("control");
    OutText->Add("client");
    frmAbout->ShowModal();
    }
  __finally{
    delete frmAbout;
    frmAbout = NULL;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuStopClick(TObject *Sender)
{
  ExecuteMessage(Ident(), WINAMP_STOP);
  ;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuForward5Click(TObject *Sender)
{
  ExecuteMessage(Ident(), WINAMP_FORWARD5S);
  ;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuBack5Click(TObject *Sender)
{
  ExecuteMessage(Ident(), WINAMP_BACK5S);
  ;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuVolumeUpClick(TObject *Sender)
{
  ExecuteMessage(Ident(), WINAMP_VOLUMEUP);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuVolumeDownClick(TObject *Sender)
{
  ExecuteMessage(Ident(), WINAMP_VOLUMEDOWN);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuVolumeUpMoreClick(TObject *Sender)
{
  for (int i = 0 ; i < 10 ; i++){
    ExecuteMessage(Ident(), WINAMP_VOLUMEUP);
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuVolumeDownMoreClick(TObject *Sender)
{
  for (int i = 0 ; i < 10 ; i++){
    ExecuteMessage(Ident(), WINAMP_VOLUMEDOWN);
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuPlaylistStartClick(TObject *Sender)
{
  ExecuteMessage(Ident(), WINAMP_STARTOFPLAYLIST);
  ;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuPlaylistEndClick(TObject *Sender)
{
  ExecuteMessage(Ident(), WINAMP_ENDOFPLAYLIST);
  ;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuDeletePlayListClick(TObject *Sender)
{
  IntegerResult(Ident(), IPC_DELETE, 0);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuAddFileToPlayListClick(TObject *Sender)
{
//const BufferSize = 32;		//Buffer max size
//char Computername[BufferSize];     // pointer to system information string
//DWORD cchBuff;       // size of computer or user name
//bool success;							//flag for success
AnsiString str;
AnsiString commandstr;

  OpenDialog1->FileName = "";

  if (Sender == mnuAddPlayList){
    OpenDialog1->Filter = "Playlist Files(*.m3u,*.pls)|*.m3u,*.pls";
    }
  else{
    OpenDialog1->Filter = "All files|*.*";
    }

  if (OpenDialog1->Execute()){

  /*

    str = ExpandUNCFileName(OpenDialog1->FileName);

    if (str != OpenDialog1->FileName){
  // we do not have a public share
      MessageForm(&AnsiString("not UNC path - attempting to construct path based upon machine name"));

  // Get the computer names.

    cchBuff = 32;
    success = GetComputerName(Computername, &cchBuff);

  //make VERY BAD UNC name to access file passed

  //this seems to work?

    if (success){
        str = "\\\\";
        str += Computername;
        str += "\\";
        str += OpenDialog1->FileName[1];
        str += '$';
        str += (OpenDialog1->FileName.SubString(3, OpenDialog1->FileName.Length() - 2));
        }
      }

      */


  TStringList * Files = new TStringList;

  // sort strings by name, for now
  Files->Sorted = true;

  Files->Assign(OpenDialog1->Files);

    for (int i = 0; i < Files->Count; i++)
    {
      ExecuteStringMessage(Ident(), strdup(Files->Strings[i].c_str()), IPC_PLAYFILE);
    }
  frmPlaylist->lstSongsRefresh(this);

  }
}
//---------------------------------------------------------------------------

void MessageForm(AnsiString *MessageStr){

  frmMessage->Label1->Caption = * MessageStr;
  frmMessage->Show();
  frmMessage->Refresh();
    ;
  }

void __fastcall TfrmMain::mnuStopFadeClick(TObject *Sender)
{
  ExecuteMessage(Ident(), WINAMP_STOPFADE);
  ;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuStopCurrentClick(TObject *Sender)
{
  ExecuteMessage(Ident(), WINAMP_STOPAFTERCURRENT);
  ;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::DisplayHint(TObject *Sender)
{
  if (this->Visible){
    sbMain->SimpleText = GetShortHint(Application->Hint);
  }
  // else would like to display some nice hint?
}


void __fastcall TfrmMain::FormCreate(TObject *Sender)
{

TRegistry * reg;

  try{
      reg = new TRegistry();
      reg->OpenKey("software\\PMMSoft\\Winamp controller\\client settings", true);
      this->ebEndPoint->Text = reg->ReadString("Endpoint");
      this->ebAddress->Text = reg->ReadString("Address");

      if (this->ebEndPoint->Text == "")
        this->ebEndPoint->Text = "8000";
      if (this->ebAddress->Text == "")
        this->ebAddress->Text = "localhost";

       if (reg->ReadString("AutoHide") == "false"){
         chkAutoHide->Checked = false;
         }

       if (reg->ReadString("AutoRestore") == "false"){
         chkAutoRestore->Checked = false;
         }

       if (reg->ReadString("Playlist Update") == "every song"){
         rbSongChange->Checked = true;
         }

       if ((reg->ReadString("Visible") == "false") && (chkAutoHide->Checked)){
         doHide = true;
         }

      this->lstTimer->ItemIndex = reg->ReadString("Poll Interval").ToIntDef(0);

    }
  __finally {
    delete reg;
    }



  Application->OnException = AppException;
  Application->OnHint = DisplayHint;
  btnSettingsClick(this);

}


//---------------------------------------------------------------------------


void __fastcall TfrmMain::AppException(TObject *Sender, Exception *E)

{
char RPCHint[] = "A call to the RPC server failed\n\n(hint)\tis the server running at that endpoint?\n";

  if (dynamic_cast <ERPCException*> (E)){
    MessageForm(&(AnsiString(RPCHint) + "\nMessage:\t" + E->Message));
    }
  else{
    MessageForm(&(AnsiString("There was an unhandled exception\nType:\t" + E->ClassName()+ "\nMessage:\t" + E->Message)));
    }

}

//---------------------------------------------------------------------------

char changedir[MAX_PATH];

int __stdcall BrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam,  LPARAM lpData ){

  if (uMsg ==  BFFM_INITIALIZED){
    // it has initialised -send over initial text
    SendMessage(hwnd, BFFM_SETSELECTION, 1, (LPARAM) &changedir);
    }
   // can also trap for changes in the selection  
  return 0;
 }

void __fastcall TfrmMain::mnuAddDirClick(TObject *Sender)
{

BROWSEINFO BrowsingInfo;
char DirPath[MAX_PATH];
char FolderName[MAX_PATH];
LPITEMIDLIST ItemID;
const BufferSize = 32;		//Buffer max size
char Computername[BufferSize];     // pointer to system information string
DWORD cchBuff;       // size of computer or user name
bool success;							//flag for success
AnsiString str;
AnsiString dir;
AnsiString commandstr;


        memset(&BrowsingInfo, 0, sizeof(BROWSEINFO));
        memset(DirPath, 0, MAX_PATH);

        BrowsingInfo.hwndOwner      = frmMain->Handle;
        BrowsingInfo.pszDisplayName = FolderName;
        BrowsingInfo.lpszTitle      = "Browse for Folder.";
// choose the items we wish to see in the list
        BrowsingInfo.ulFlags =
//            BIF_BROWSEFORCOMPUTER &&// Only returns computers. If the user selects anything other than a computer, the OK button is grayed.
//            BIF_BROWSEFORPRINTER &&// Only returns printers. If the user selects anything other than a printer, the OK button is grayed.
            BIF_DONTGOBELOWDOMAIN &&// Does not include network folders below the domain level in the tree view control.
//            BIF_RETURNFSANCESTORS &&// Only returns file system ancestors. If the user selects anything other than a file system ancestor, the OK button is grayed.
            BIF_RETURNONLYFSDIRS   &&// Only returns file system directories. If the user selects folders that are not part of the file system, the OK button is grayed.
            BIF_STATUSTEXT &&// Includes a status area in the dialog box. The callback function can set the status text by sending messages to the dialog box.
            0;

        BrowsingInfo.lpfn = BrowseCallbackProc;

        ItemID = SHBrowseForFolder(&BrowsingInfo);

        SHGetPathFromIDList(ItemID, DirPath);

        if (ItemID != NULL){
            dir = DirPath;
            str = ExpandUNCFileName(AnsiString(DirPath));
            // save the directory
            strcpy(changedir, DirPath);

            if (str.AnsiCompare(dir)){
          // we do not have a public share
              MessageForm(&AnsiString("not UNC path - attempting to construct path based upon machine name"));

          // Get the computer names.

            cchBuff = 32;
            success = GetComputerName(Computername, &cchBuff);

          //make VERY BAD UNC name to access file passed

          //this seems to work?

            if (success){
                str = "\\\\";
                str += Computername;
                str += "\\";
                str += dir[1];
                str += '$';
                str += (dir.SubString(3, dir.Length() - 2));
                }
              }

           // finally...
          ExecuteStringMessage(Ident(), strdup(str.c_str()) ,IPC_CHDIR);
          }

      GlobalFree(ItemID);
//
}


char * Ident(void)
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

  return strdup(str.c_str());

}



void SendString(char * pszString){

  Bind();
    RpcTryExcept
    {
        WAMessageProc( (unsigned char *) pszString);
    }
    RpcExcept(1)
    {
        throw ERPCException(RPCError(RpcExceptionCode()));
    }
    RpcEndExcept;
  UnBind();

  }


void ExecuteMessage(char * pszString, int command){

  Bind();
    RpcTryExcept
    {
       WAExecuteMessage((unsigned char *) pszString, command);
    }
    RpcExcept(1)
    {
        throw ERPCException(RPCError(RpcExceptionCode()));
    }
    RpcEndExcept
  UnBind();

  }


void ExecuteStringMessage(char * pszString, char * pszParam, int command){

  Bind();
    RpcTryExcept
    {
        WAExecuteMessageString((unsigned char *) pszString, (unsigned char *) pszParam, command);
    }
    RpcExcept(1)
    {
        throw ERPCException(RPCError(RpcExceptionCode()));
    }
    RpcEndExcept
  UnBind();

  }


int StringResult(char * pszString, int command, int data){

int result = 0;

  Bind();
    RpcTryExcept
    {
        result = WAStringResult((unsigned char *) pszString, command, data);
    }
    RpcExcept(1)
    {
        throw ERPCException(RPCError(RpcExceptionCode()));
    }
    RpcEndExcept
  UnBind();

  return result;

  }

int IntegerResult(char * pszString, int command, int data){

  int result = 0;

  Bind();
    RpcTryExcept
    {
       result = WAIntegerResult((unsigned char *) pszString, command, data);
    }
    RpcExcept(1)
    {
        throw ERPCException(RPCError(RpcExceptionCode()));
    }
    RpcEndExcept
  UnBind();

  return result;

  }



void Shutdown(void){

  Bind();
    RpcTryExcept
    {
        WAShutdown();
    }
    RpcExcept(1)
    {
        throw ERPCException(RPCError(RpcExceptionCode()));
    }
    RpcEndExcept
  UnBind();

}



//---------------------------------------------------------------------------
void Bind(){


  unsigned char *   pszNetworkAddress = (unsigned char *) strdup (frmMain->ebAddress->Text.c_str());
  unsigned char *   pszEndpoint = (unsigned char *) strdup (frmMain->ebEndPoint->Text.c_str());
  unsigned char *   pszProtocolSequence = (unsigned char *) "ncacn_ip_tcp";

  RpcStringBindingCompose(NULL, pszProtocolSequence, pszNetworkAddress, pszEndpoint, NULL, &pszStringBinding);
  RpcBindingFromStringBinding(pszStringBinding, &winamp_IfHandle);

  delete pszNetworkAddress;
  delete pszEndpoint;


}

/* this unbinds to the interface after the RPC call*/
void UnBind(){

    RpcStringFree(&pszStringBinding);
    pszStringBinding = NULL;
    RpcBindingFree(&winamp_IfHandle);

  }

void  __RPC_FAR * __RPC_USER midl_user_allocate(size_t len)
{
    return(malloc(len));
}

void __RPC_USER midl_user_free(void __RPC_FAR * ptr)
{
    free(ptr);
}


//---------------------------------------------------------------------------


void TfrmMain::UpdateIcon(void){
char title[RET_STR_SIZE];
int retval, index, length;
AnsiString saveStr;

Cardinal UpdateTime = 1000 * (lstTimer->ItemIndex + 1);

  try{

    saveStr = sbMain->SimpleText;
    sbMain->SimpleText = "querying server";
    WAStatus = (WAPlaybackStatus) IntegerResult(Ident(), IPC_ISPLAYING, 0);
    if ( timerMain->Interval != UpdateTime){
      timerMain->Interval = UpdateTime;
      retval = IntegerResult(Ident(), IPC_GETVERSION,  0);
      lblVersion->Caption = WinampVersion(retval);
      }

    strcpy(title, Ident());

    length = IntegerResult(Ident(), IPC_GETLISTLENGTH, 0);
    if (length > 0){
      index = IntegerResult(Ident(), IPC_GETLISTPOS, 0);

      StringResult(title, IPC_GETPLAYLISTTITLE, index);
      if (title){
        lblMessage->Caption = (AnsiString(index + 1) + ". " + title);
        }

        //update the playlist form
        //always check this first, to get length straight 
        if ((rbPlaylistChange->Checked) || (index >= length)){
          if (length != frmPlaylist->lastlength){
            frmPlaylist->lstSongsRefresh(this);
            }
          }

        if (frmPlaylist->lastindex != index){
          frmPlaylist->currentpos = index;
          frmPlaylist->SongIndexUpdate(this);
          }

        if (rbSongChange->Checked) {
          if ((index != frmPlaylist->lastindex) || (length != frmPlaylist->lastlength)){
            frmPlaylist->lstSongsRefresh(this);
            }
          }


        // set last "OK" list index
        frmPlaylist->lastindex = index;
        frmPlaylist->lastlength = length;

      } // if list length non-zero
    }
  catch( ERPCException &E){
    doHide = false;
    frmPlaylist->lastindex = -1;
    frmPlaylist->lastlength = -1;

    WAStatus = WA_UNUSED;
    lblMessage->Caption = E.Message;
    lblVersion->Caption = WinampVersion(0);
    timerMain->Interval = 1000 * FAILTIMEOUT;
    }

  sbMain->SimpleText = saveStr;
  // in all events, update status
  TrayMessage(NIM_MODIFY);
  }
//---------------------------------------------------------------------------


void __fastcall TfrmMain::timerMainTimer(TObject *Sender)
{

  UpdateIcon();
  if (doHide){
    doHide = false;
    btnHideClick(this);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuSetVolume0Click(TObject *Sender)
{
  IntegerResult(Ident(), IPC_SETVOLUME, 0);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuSetVolume100Click(TObject *Sender)
{
  IntegerResult(Ident(), IPC_SETVOLUME, 255);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuShuffleClick(TObject *Sender)
{
  ExecuteMessage(Ident(), WINAMP_FILE_SHUFFLE);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuRepeatClick(TObject *Sender)
{
  ExecuteMessage(Ident(), WINAMP_FILE_REPEAT);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuPlayFromStartClick(TObject *Sender)
{

  IntegerResult(Ident(), IPC_STARTPLAY, 0);

}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuAdministerPlayListClick(TObject *Sender)
{

  frmPlaylist->Show();

}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{

  TrayMessage(NIM_DELETE);

}


/*

int __stdcall BrowseServersCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam,  LPARAM lpData ){

  if (uMsg ==  BFFM_INITIALIZED){
    // it has initialised -send over initial text
    SendMessage(hwnd, BFFM_SETSELECTION, 1, (LPARAM) "localhost");
    }
   // can also trap for changes in the selection
  return 0;
 }


//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnBrowseServersClick(TObject *Sender)
{


BROWSEINFO BrowsingInfo;
char DirPath[MAX_PATH];
char FolderName[MAX_PATH];
LPITEMIDLIST ItemID;
const BufferSize = 32;		//Buffer max size
char Computername[BufferSize];     // pointer to system information string
DWORD cchBuff;       // size of computer or user name
bool success;							//flag for success
AnsiString str;
AnsiString dir;
AnsiString commandstr;


        memset(&BrowsingInfo, 0, sizeof(BROWSEINFO));
        memset(DirPath, 0, MAX_PATH);

        BrowsingInfo.hwndOwner      = frmMain->Handle;
        BrowsingInfo.pszDisplayName = FolderName;
        BrowsingInfo.lpszTitle      = "Browse for Folder.";
// choose the items we wish to see in the list
        BrowsingInfo.ulFlags =
            BIF_BROWSEFORCOMPUTER &&// Only returns computers. If the user selects anything other than a computer, the OK button is grayed.
//            BIF_BROWSEFORPRINTER &&// Only returns printers. If the user selects anything other than a printer, the OK button is grayed.
//            BIF_DONTGOBELOWDOMAIN &&// Does not include network folders below the domain level in the tree view control.
//            BIF_RETURNFSANCESTORS &&// Only returns file system ancestors. If the user selects anything other than a file system ancestor, the OK button is grayed.
//            BIF_RETURNONLYFSDIRS   &&// Only returns file system directories. If the user selects folders that are not part of the file system, the OK button is grayed.
//            BIF_STATUSTEXT &&// Includes a status area in the dialog box. The callback function can set the status text by sending messages to the dialog box.
            0;

        BrowsingInfo.lpfn = BrowseServersCallbackProc;

        ItemID = SHBrowseForFolder(&BrowsingInfo);

        SHGetPathFromIDList(ItemID, DirPath);
      ShowMessage(DirPath);  

      GlobalFree(ItemID);
//
}

*/
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuShowSettingsClick(TObject *Sender)
{

  frmSettings->Show();

}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::btnHideMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   btnHide->Caption = ";-o";
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnHideMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   btnHide->Caption = ": -)";
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::btnSettingsClick(TObject *Sender)
{

  if (this->ClientHeight < grpSettings->Top + grpSettings->Height + sbMain->Height){
      this->ClientHeight = grpSettings->Top + grpSettings->Height + sbMain->Height;
      btnSettings->Caption = "<<";
    }
  else{
      this->ClientHeight  = pnlMid->Top + pnlMid->Height + sbMain->Height;
      btnSettings->Caption = ">>";
    }



}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::mnuViewCommandsClick(TObject *Sender)
{
  frmCommands->Show();    
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
        reg->WriteString("Commands Visible", frmCommands->Visible?"true":"false");

        reg->WriteString("Playlist Left", AnsiString(frmPlaylist->Left));
        reg->WriteString("Playlist Top", AnsiString(frmPlaylist->Top));
        reg->WriteString("Playlist Visible", frmPlaylist->Visible?"true":"false");

        reg->WriteString("Volume Left", AnsiString(frmSettings->Left));
        reg->WriteString("Volume Top", AnsiString(frmSettings->Top));
        reg->WriteString("Volume Visible", frmSettings->Visible?"true":"false");
        }

    }
  catch ( ... ){
    delete reg;
    }

}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::lstTimerClick(TObject *Sender)
{
  timerMain->Interval = 1000 * (lstTimer->ItemIndex + 1);
}
//---------------------------------------------------------------------------



