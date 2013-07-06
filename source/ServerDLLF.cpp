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
#include "RPCBind.h"


#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPluginMain *frmPluginMain;

TRPCServerDLLThread *serverThread;

const int FAIL_TIMEOUT = 15; // seconds



void __fastcall TfrmPluginMain::timerMainTimer(TObject *Sender)
{

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


__fastcall TfrmPluginMain::TfrmPluginMain(TComponent* Owner)
        : TForm(Owner)
{
}

void __fastcall TfrmPluginMain::FormCreate(TObject *Sender)
{
const BufferSize = 32;		//Buffer max size
char Computername[BufferSize];     // pointer to system information string
DWORD cchBuff;       // size of computer or user name
bool success;
TRegistry * reg;

  Application->OnException = AppException;


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
        CreateThread();
  }

}


void __fastcall TfrmPluginMain::AppException(TObject *Sender, Exception *E)

{
  // TODO handle this error
}


void __fastcall TfrmPluginMain::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{

  if ((Key == VK_F4) && (Shift.Contains(ssAlt))){
    Key = 0;
  }

}


void __fastcall TfrmPluginMain::FormShow(TObject *Sender)
{
  lvUsers->Items->Clear();
}

void __fastcall TfrmPluginMain::CreateThread()
{
  serverThread =  new TRPCServerDLLThread(true, plugin.hwndParent, pszProtocolSequenceNP);
  serverThread->Resume();
}

void __fastcall TfrmPluginMain::StopThread(TObject *Sender)
{
  WAShutdown();
  serverThread->WaitFor();
  FreeAndNil(serverThread);
  
}


void __fastcall TfrmPluginMain::FormCloseQuery(TObject *Sender, bool &CanClose)
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


void __fastcall TfrmPluginMain::btnConfigClick(TObject *Sender)
{
  config();
}


void __fastcall TfrmPluginMain::btnAboutClick(TObject *Sender)
{
  frmAbout = new TfrmAbout(Application);

  try
  {
    frmAbout->Caption = "About winamp remote control server plugin";
    frmAbout->ShowModal();
  }
  __finally
  {
    delete frmAbout;
    frmAbout = NULL;
  }
}



