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

#include <time.h>
#include <stdlib.h>  // max

#include "ServersF.h"    // servers
#include "messageF.h"    // message form
#include "MainF.h"       // TODO because of liberating DoBind from frmMain
#include "RFC1060U.h"    // ports
#include "IPAddressU.h"  // IP utility
#include "RPCFuncsU.h"   // RPC functions

// winamp IPC declarations
#include "waint.h"
#include "remotestrs.h"

#include "ServerEnumerator.h" // class to enumerate servers

#pragma package(smart_init)
#pragma resource "*.dfm"

TfrmServers *frmServers;

__fastcall TfrmServers::TfrmServers(TComponent* Owner)
        : TForm(Owner)
{
}


void __fastcall TfrmServers::btnLocateClick(TObject *)
{

  char szComputerName[MAX_COMPUTERNAME_LENGTH+1] = {0};
  DWORD dwSize;

  Screen->Cursor = crHourGlass;

  btnLocate->Enabled = false;

  try
  {
    pbServers->Position = 0;
    pbServers->Max = 100;
    lvMessages->Items->Clear();

    ServerEnumerator se;
    se.OnMessage = DoMessage;
    se.OnServer = DoServer;
    se.OnProgress = DoProgress;
    se.enumerateServers();

    pbServers->Position = 100;

    // TODO sweep out the API-isms
    dwSize = sizeof(szComputerName);
    Win32Check(GetComputerName(szComputerName, &dwSize));
    AnsiString ComputerName = szComputerName;
    DoServer(ComputerName.c_str(), sLocalMachine.c_str());
    btnTest->Enabled = true;
  }
  __finally
  {
    btnLocate->Enabled = true;
    Screen->Cursor = crDefault;
    pbServers->Position = 0;
  }
}


void __fastcall TfrmServers::DoServer(const AnsiString& RemoteName, const AnsiString& Comment)
{
  bool found = false;
  TListItem * ListItem;
  for ( int i = 0; (i < lvServers->Items->Count) && (!found) ; i ++)
  {
    ListItem = lvServers->Items->Item[i];
    if (ListItem->Caption == RemoteName)
    {
      found = true;
    }
  }

  if (!found)
   {
     ListItem = lvServers->Items->Add();
   }

   ListItem->Caption = RemoteName;
   ListItem->SubItems->Clear();
   ListItem->SubItems->Add(Comment);
   ListItem->SubItems->Add(sServerUntested);
   ListItem->ImageIndex = 0;

   // in the event of duplicate names, I imagine there will be big trouble

}

void __fastcall TfrmServers::DoProgress(const float progress)
{
    pbServers->Position = progress * pbServers->Max;
}


void __fastcall TfrmServers::FormCreate(TObject *)
{
  lvServers->Items->Clear();
  // sets up the standard icons from Windows
  imgInformation->Picture->Icon->Handle = LoadIcon(NULL, IDI_ASTERISK);
  imgWarning->Picture->Icon->Handle = LoadIcon(NULL, IDI_EXCLAMATION);
  imgError->Picture->Icon->Handle = LoadIcon(NULL, IDI_HAND);

  imlEvents->AddIcon(imgInformation->Picture->Icon);
  imlEvents->AddIcon(imgWarning->Picture->Icon);
  imlEvents->AddIcon(imgError->Picture->Icon);

}


void __fastcall TfrmServers::lvServersClick(TObject *)
{
  btnOK->Enabled =(lvServers->Selected != NULL );
  btnGetIp->Enabled =(lvServers->Selected != NULL );
}


void __fastcall TfrmServers::StartTest(TObject *)
{

  bool AbortTest = false;

  // validate the selected port
  CheckPort();
  // now this is OK

  lvMessages->Items->Clear();
  btnLocate->Enabled = false;
  btnOK->Enabled = false;
  btnGetIp->Enabled = false;
  btnCancel->Enabled = false;

  btnTest->Caption = sStop;
  btnTest->OnClick = StopTest;

  Screen->Cursor = crHourGlass;
  int retval;

  clock_t start, end;

  try
  {
    pbServers->Position = 0;
    pbServers->Max = lvServers->Items->Count;

    for ( int i = 0 ; i < lvServers->Items->Count ; i++)
    {
         frmMain->ebEndPoint->Text = ebEndPoint->Text;
         frmMain->ebAddress->Text = lvServers->Items->Item[i]->Caption;

         lvServers->Selected = lvServers->Items->Item[i];
         frmMain->DoBind();
         try
         {
            try
            {
              // issue warning
              DoMessage(AnsiString().sprintf(sAttemptingToContact.c_str(), lvServers->Items->Item[i]->Caption.c_str()),   1);
              DoMessage(sMayTakeTime,   2);
              start = clock();
              retval = IntegerResult(frmMain->IdentChars, IPC_GETVERSION,  0);
              end = clock();
              pbServers->StepIt();
              DoMessage(AnsiString().sprintf(sResponseReceivedFmt.c_str(), (end - start) / CLK_TCK), 1);
              lvServers->Items->Item[i]->ImageIndex = 2;
              lvServers->Items->Item[i]->SubItems->Strings[1] = WinampVersion(retval);
              if (AbortTest)
                break;
            }
            catch( ERPCException &E)
            {
              pbServers->StepIt();
              DoMessage(AnsiString(sCallFailed + E.Message),   3);
              lvServers->Items->Item[i]->ImageIndex = 1;
              lvServers->Items->Item[i]->SubItems->Strings[1] = sNotFound;
            }
         }
         __finally
         {
           UnBind();
         }
    }
    lvServers->Selected = NULL;

    StopTest(this);

  }
  __finally
  {
    Screen->Cursor = crDefault;
    pbServers->Position = 0;
  }

}



void __fastcall TfrmServers::StopTest(TObject *)
{

  btnLocate->Enabled = true;
  btnOK->Enabled = false;
  btnGetIp->Enabled = false;
  btnCancel->Enabled = true;
  AbortTest = true;
  btnTest->OnClick = StartTest;
  btnTest->Caption = sTest;

}


void __fastcall TfrmServers::DoMessage(const AnsiString& Message, const int Level)
{

  TListItem * ListItem =  lvMessages->Items->Add();
  ListItem->Caption = Message;
  ListItem->ImageIndex = Level - 1;
  lvMessages->Selected = ListItem;
  lvMessages->Update();

}


void __fastcall TfrmServers::FormClose(TObject *, TCloseAction &)
{
  if (ModalResult == mrOk)
  {
    EndPoint = ebEndPoint->Text;
    if (lvServers->Selected)
      Address = lvServers->Selected->Caption;
  }
}



void __fastcall TfrmServers::CheckPort(void)
{

// assumes the endpoint is an int, which needs amending

/*
  int port;

  try
  {
    port = ebEndPoint->Text.ToInt();
    if ((port < 0) || (port > 65535))
    {
      throw EConvertError(AnsiString().sprintf(sPortOutOfRangeFmt.c_str(), port).c_str());
    }
  }
  catch (EConvertError &E)
  {
    MessageBox(this->Handle, E.Message.c_str(), sEndpointInvalid.c_str(), MB_OK | MB_ICONERROR);
    throw EAbort("abort operation");
  }
  bool usedport = false;
  int i;

  for (i = 0  ; i < RFC1060portscount ; i++){
    if (RFC1060ports[i].port == port){
      usedport = true;
      break;
      }
    }

  if (usedport &&
        Application->MessageBox((AnsiString().sprintf(sWellKnownPortFmt.c_str(),
                                port , RFC1060ports[i].service)).c_str(),
                                sAlertWellKnownPort.c_str(),
                                MB_ICONEXCLAMATION + MB_OKCANCEL + MB_DEFBUTTON2) != IDOK)  throw EAbort("user cancellled bogus port");
*/
}


void __fastcall TfrmServers::btnOKClick(TObject *)
{
  CheckPort();
  ModalResult = mrOk;
}



void __fastcall TfrmServers::GetServerIp(TObject *)
{

  TStringList * Addresses = new TStringList;
  TStringList * Aliases = new TStringList;
  AnsiString HostName;

  Screen->Cursor = crHourGlass;
  try
  {
    lvMessages->Items->Clear();
    if (lvServers->Selected)
    {

      try
      {
        GetIPAddress(lvServers->Selected->Caption.c_str(), HostName, Addresses, Aliases);

        DoMessage(sIPLookup + lvServers->Selected->Caption, 1);
        DoMessage(sAuthoritativeName + HostName, 1);

        if (Addresses->Count > 0 )
        {
          DoMessage(sAddressesRetrieved, 1);
          for (int i = 0; i < Addresses->Count  ; i ++)
          {
            DoMessage(sIPAddress + Addresses->Strings[i], 1);
          }
        }
        else
        {
          DoMessage(sAddressesNotRetrieved, 2);
        }


        if (Aliases->Count > 0 )
        {
           DoMessage(sAliasesRetrieved, 1);
          for (int i = 0; i < Aliases->Count  ; i ++)
          {
            DoMessage(AnsiString(sIPAlias) + Aliases->Strings[i], 1);
          }
        }
        else
        {
          DoMessage(sAliasesNotRetrieved, 2);
        }

      }
      catch (EIPException &E)
      {
        DoMessage(sGetIPAddressFailed + E.Message, 3);
      }

    }
  }
  __finally
  {
     Screen->Cursor = crDefault;
     delete Aliases;
     delete Addresses;
  }
}


void __fastcall TfrmServers::spltMessagesCanResize(TObject * , int &NewSize, bool &Accept)
{
  Accept = (NewSize > 30);        
}



