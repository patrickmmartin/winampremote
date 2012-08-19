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

#include <time.h>
#include <stdlib.h>  // max

#include "ServersF.h"    // servers
#include "messageF.h"    // message form
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

void __fastcall TfrmServers::FormClose(TObject *, TCloseAction &)
{
  if (ModalResult == mrOk)
  {
    EndPoint = ebEndPoint->Text;
    if (lvServers->Selected)
      Address = lvServers->Selected->Caption;
  }
}

void __fastcall TfrmServers::btnLocateClick(TObject *)
{

  Screen->Cursor = crHourGlass;

  btnLocate->Enabled = false;

  try
  {
    pbServers->Position = 0;
    pbServers->Max = 100;
    lvMessages->Items->Clear();

    ServerEnumerator se;
    se.OnMessage = doNetworkMessage;
    se.OnServer = doNetworkServer;
    se.OnProgress = doNetworkProgress;
    se.enumerateServers();

    addLocal();

    pbServers->Position = 100;


    btnTest->Enabled = true;
  }
  __finally
  {
    btnLocate->Enabled = true;
    Screen->Cursor = crDefault;
    pbServers->Position = 0;
  }
}



void __fastcall TfrmServers::lvServersClick(TObject *)
{
  btnOK->Enabled =(lvServers->Selected != NULL );
}


void __fastcall TfrmServers::StartTest(TObject *)
{

  AbortTest = false;

  // validate the selected port
  CheckPort();
  // now this is OK

  lvMessages->Items->Clear();
  btnLocate->Enabled = false;
  btnOK->Enabled = false;
  btnCancel->Enabled = false;

  btnTest->Caption = sStop;
  btnTest->OnClick = StopTest;

  Screen->Cursor = crHourGlass;

  try
  {

      ServerTester st;
      st.OnResult = doTestResult;
      st.OnTest = doTestEvent;
      st.endPoint = ebEndPoint->Text;
      map<AnsiString, ServerInfo> servers;
      getServers(servers);
      st.testServers(servers);

  }
  __finally
  {
    Screen->Cursor = crDefault;
    pbServers->Position = 0;
    btnLocate->Enabled = true;
    btnOK->Enabled = false;
    btnCancel->Enabled = true;
    btnTest->OnClick = StartTest;
    btnTest->Caption = sTest;
  }

}



void __fastcall TfrmServers::StopTest(TObject *)
{

  AbortTest = true;

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

        doNetworkMessage(sIPLookup + lvServers->Selected->Caption, 1);
        doNetworkMessage(sAuthoritativeName + HostName, 1);

        if (Addresses->Count > 0 )
        {
          doNetworkMessage(sAddressesRetrieved, 1);
          for (int i = 0; i < Addresses->Count  ; i ++)
          {
            doNetworkMessage(sIPAddress + Addresses->Strings[i], 1);
          }
        }
        else
        {
          doNetworkMessage(sAddressesNotRetrieved, 2);
        }


        if (Aliases->Count > 0 )
        {
           doNetworkMessage(sAliasesRetrieved, 1);
          for (int i = 0; i < Aliases->Count  ; i ++)
          {
            doNetworkMessage(AnsiString(sIPAlias) + Aliases->Strings[i], 1);
          }
        }
        else
        {
          doNetworkMessage(sAliasesNotRetrieved, 2);
        }

      }
      catch (EIPException &E)
      {
        doNetworkMessage(sGetIPAddressFailed + E.Message, 3);
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


void  TfrmServers::addLocal()
{
  char szComputerName[MAX_COMPUTERNAME_LENGTH+1] = {0};
  DWORD dwSize;

  dwSize = sizeof(szComputerName);
  Win32Check(GetComputerName(szComputerName, &dwSize));
  AnsiString ComputerName = szComputerName;
  AnsiString localhost = "127.0.0.1";
  doNetworkServer(ComputerName.c_str(), sLocalMachine.c_str(), localhost);

}

void TfrmServers::doNetworkServer(const AnsiString& RemoteName, const AnsiString& Comment, const AnsiString& ip)
{
  TListItem * ListItem = findServerItem(RemoteName);

  ListItem->Caption = RemoteName;
  ListItem->SubItems->Clear();
  ListItem->SubItems->Add(Comment);
  ListItem->SubItems->Add(ip);
  ListItem->SubItems->Add(sServerUntested);
  ListItem->ImageIndex = 0;

}

void TfrmServers::doNetworkMessage(const AnsiString& Message, const int Level)
{
    addProcessMessage(Message, Level);
}

void TfrmServers::doNetworkProgress(const float progress)
{
    pbServers->Position = progress * pbServers->Max;
}


void TfrmServers::doTestEvent(const AnsiString& remoteName,
                                          const AnsiString& data,
                                          const int level)
{
    addProcessMessage(remoteName + ":" + data, level);
    TListItem * ListItem = findServerItem(remoteName);
    ListItem->SubItems->Strings[2] = data;
}

void TfrmServers::doTestResult(const AnsiString& remoteName,
                                           const bool success,
                                           bool& abort)
{
    TListItem * ListItem = findServerItem(remoteName);
    ListItem->ImageIndex = (success)?2:1;
    Application->ProcessMessages();
    abort = AbortTest;
}

void TfrmServers::addProcessMessage(const AnsiString & Message, const int Level)
{
    TListItem *ListItem = lvMessages->Items->Add();
    ListItem->Caption = Message;
    ListItem->ImageIndex = Level - 1;
    lvMessages->Selected = ListItem;
    lvMessages->Update();
}

TListItem* TfrmServers::findServerItem(const AnsiString& RemoteName)
{
  TListItem * ListItem;
  for (int i = 0; (i < lvServers->Items->Count) ; i++)
  {
      ListItem = lvServers->Items->Item[i];
      if (ListItem->Caption == RemoteName)
          return ListItem;
  }

      return lvServers->Items->Add();
}

void TfrmServers::getServers(map<AnsiString, ServerInfo>& servers)
{
  if (lvServers->Selected)
    {
      servers[lvServers->Selected->Caption].status = SI_UNTESTED;
      return;
    }

  for (int i = 0; (i < lvServers->Items->Count); i++)
    {
      servers[lvServers->Items->Item[i]->Caption].status = SI_UNTESTED;
  }
}

