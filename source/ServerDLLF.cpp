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

#include "ServerDLLF.h"
#include "rpcthreadDLL.h"
#include "waint.h"
#include "gen_plugin.h"
#include "AboutF.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;

HWND mainhwnd;
TRPCServerThread *serverThread;

//---------------------------------------------------------------------------
void __fastcall TfrmMain::ThreadMessage(TMessage &Message)

{
  if (lstMessages->Items->Add( (char *) Message.LParam) > 1000){
    lstMessages->Items->Clear();
    }
  lstMessages->ItemIndex = lstMessages->Items->Count - 1;
// act upon the passed message

  delete ((char *) Message.LParam);

}


//---------------------------------------------------------------------------
void __fastcall TfrmMain::ExecutionStatus(WAExecutionStatus NewThreadState)
{

  fThreadState = NewThreadState;

  if (ThreadState == waExecuting)
  {
    if (sbrMain->Panels->Items[0]->Text != "working")
    {
      sbrMain->Panels->Items[0]->Text = "working";
      sbrMain->Invalidate();
    }
  }


}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::ThreadStatus(TMessage &Message)
{

  ExecutionStatus ((WAExecutionStatus) Message.LParam);

}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::ThreadIdent(TMessage &Message)
{
//do something here

  int i;
  int pos = -1;
  char * Ident = (char *) Message.LParam;
  TListItem  *ListItem;

  ExecutionStatus(waExecuting);

  for (i = 0 ; i < lvUsers->Items->Count ; i++)
  {
    ListItem = lvUsers->Items->Item[i];
    if (ListItem->Caption == Ident)
    {
      ListItem->Data = (void *) GetTickCount();
      if ((ListItem->ImageIndex == 0) || (ListItem->ImageIndex == imlUsers->Count - 1))
      {
        ListItem->ImageIndex = 1;
      }
      pos = i;
      break;
    }
  } // for

  if (pos == -1)
  {
  //need new
    ListItem = lvUsers->Items->Add();
    ListItem->ImageIndex = 1;
    ListItem->Caption = Ident;
    ListItem->Data = (void *) GetTickCount();
    }

  delete ((char *) Message.LParam);

}

//---------------------------------------------------------------------------


void __fastcall TfrmMain::timerMainTimer(TObject *Sender)
{

  switch (fThreadState)
  {
    case waListening:
      sbrMain->Panels->Items[0]->Text = "listening...";
      break;

    /*
    case waExecuting:
      sbrMain->Panels->Items[0]->Text = "working";
      break;
    */

    case waServerStopped:
      sbrMain->Panels->Items[0]->Text = "stopped";
      break;

    case waInitialiseFailed:
      sbrMain->Panels->Items[0]->Text = "error";
      break;

    case waServerStarting:
      sbrMain->Panels->Items[0]->Text = "starting";
      break;

    case waServerStarted:
      sbrMain->Panels->Items[0]->Text = "started";
      break;
    default:
      sbrMain->Panels->Items[0]->Text = "unknown";
    }


  sbrMain->Invalidate();

  int i;
  TListItem  *ListItem;
  int NowTickCount = GetTickCount();

  for (i = lvUsers->Items->Count - 1; i >= 0 ; i--)
  {
    ListItem = lvUsers->Items->Item[i];

    //check for timed out clients
    if ((NowTickCount - (int ) ListItem->Data) > (1000 * FAIL_TIMEOUT)){
      // looks like it's timing out
      ListItem->ImageIndex = 0;
      }
    else
    {
      if (ListItem->ImageIndex == 0)
      {
        ListItem->ImageIndex = 1;
        }
      }

   if ((ListItem->ImageIndex > 0) && (ListItem->ImageIndex < imlUsers->Count - 1))
   {
     ListItem->ImageIndex = ListItem->ImageIndex + 1;
   }

    if ((NowTickCount - (int ) ListItem->Data) > (2000 * FAIL_TIMEOUT))
    {
      // looks like it's timing out
      lvUsers->Items->Delete(i);
      }

    } // for

}

//---------------------------------------------------------------------------


__fastcall TfrmMain::TfrmMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
const BufferSize = 32;		//Buffer max size
char Computername[BufferSize];     // pointer to system information string
DWORD cchBuff;       // size of computer or user name
bool success;
TRegistry * reg;


  try
  {
    reg = new TRegistry();
    reg->OpenKey("software\\PMMSoft\\Winamp controller\\server settings", true);
    AnsiString EndPoint = reg->ReadString("EndPoint");
    // issue #3
    success = true;
  }
  __finally
  {
    delete reg;
  }

  /*
  Get the computer name. */
  cchBuff = 32;
  if (success)
  {
    success = success && GetComputerName(Computername, &cchBuff);
    }

  if (success)
  {
      sbrMain->Panels->Items[1]->Text = AnsiString("name: ") + Computername;
      // TODO: this global should be factored out
      mainhwnd = this->Handle;


        }
  else
  {
    this->lstMessages->Items->Add("computer name not obtained");
    this->lstMessages->Items->Add("rpc service not starting");
  }

  Application->OnException = AppException;

  CreateThread();

  pgMain->ActivePage =  tbsMessages;

}


//---------------------------------------------------------------------------


void __fastcall TfrmMain::AppException(TObject *Sender, Exception *E)

{
  lstMessages->Items->Add(AnsiString("There was an unhandled exception Type: " + E->ClassName()+ " Message: " + E->Message));
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{

  if ((Key == VK_F4) && (Shift.Contains(ssAlt))){
    Key = 0;
  }

}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::chkListEventsClickCheck(TObject *Sender)
{
int i;

  for (i = 0 ; i < 4 ; i++){
    requestlog[i] = chkListEvents->Checked[i];
    }

}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::FormShow(TObject *Sender)
{
  chkListEvents->Checked[2] = true;
  chkListEvents->Checked[3] = true;

  lvUsers->Items->Clear();
    
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::CreateThread()
{
  // should
  serverThread =  new TRPCServerThread(true);
  // should set the server thread Endpoint property
  serverThread->Resume();
}

void __fastcall TfrmMain::StopThread(TObject *Sender)
{
  WAShutdown();
  serverThread->WaitFor();
  FreeAndNil(serverThread);
  
}


void __fastcall TfrmMain::FormCloseQuery(TObject *Sender, bool &CanClose)
{

TRegistry * reg;

  try{
      reg = new TRegistry();
      reg->OpenKey("software\\PMMSoft\\Winamp controller\\server settings", true);

      // should implement end point edits
      // reg->WriteString("EndPoint", "");

      reg->WriteString("Visible", Visible?"true":"false");
    }
  __finally {
    delete reg;
  }
        
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnConfigClick(TObject *Sender)
{
  config();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnAboutClick(TObject *Sender)
{
  frmAbout = new TfrmAbout(Application);

  try
  {
    frmAbout->Caption = "About winamp remote control server plugin";
    OutText->Clear();
    OutText->Add("winamp");
    OutText->Add("remote");
    OutText->Add("control");
    OutText->Add("RPC");
    OutText->Add("server");
    frmAbout->ShowModal();
  }
  __finally
  {
    delete frmAbout;
    frmAbout = NULL;
  }
}
//---------------------------------------------------------------------------


