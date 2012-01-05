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

#include "ServersF.h"
#include "messageF.h"
#include "MainF.h"
#include "RFC1060U.h"
#include "IPAddressU.h"
#include "RPCFuncsU.h"

// winamp IPC declarations
#include "waint.h"
#include "remotestrs.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"



TfrmServers *frmServers;
//---------------------------------------------------------------------------
__fastcall TfrmServers::TfrmServers(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmServers::HandleResource(NETRESOURCE NetResource)
{

  if (NetResource.dwDisplayType == RESOURCEDISPLAYTYPE_SERVER)
  {
    AnsiString RemoteName = NetResource.lpRemoteName;
    // strip out the UNC prefix
    RemoteName.Delete(1, 2);
    AddServer(RemoteName.c_str(), NetResource.lpComment);
    AddMessage(AnsiString().sprintf("\tFound node %s",
                                  RemoteName.c_str()), 0);
  }
}

//---------------------------------------------------------------------------

void __fastcall TfrmServers::NetErrorHandler(DWORD dwErrorCode, AnsiString Function)
{
    DWORD dwWNetResult, dwLastError;
    char szDescription[256];
    char szProvider[256];
    AnsiString MessageStr;
    int MessageSeverity;

    // The following code performs standard error-handling.

    if (dwErrorCode != ERROR_EXTENDED_ERROR)
    {
        // warning
        AddMessage(Function + sFailed, 2);
        MessageStr = SysErrorMessage(dwErrorCode) + ".";
        MessageSeverity = 0;
    }
    else
    {
        dwWNetResult = WNetGetLastError(&dwLastError,
            (LPSTR) szDescription,  sizeof(szDescription),
            (LPSTR) szProvider,   sizeof(szProvider));

        if(dwWNetResult != NO_ERROR)
        {
           // error
          MessageStr = AnsiString().sprintf(sWNetGetLastErrorFailedFmt.c_str(), dwWNetResult);
        }
      // warning

      MessageSeverity = 3;
      MessageStr = AnsiString().sprintf(sWNetFailedFmt.c_str(), szProvider, dwLastError, szDescription);
    }

  int Index = MessageStr.Pos("\r\n");
  while (Index > 0)
  {
    MessageStr.Delete(Index, 2);
    MessageStr.Insert(" ", Index);
    Index = MessageStr.Pos("\r\n");
  }

  AddMessage(MessageStr, MessageSeverity);

}

//---------------------------------------------------------------------------


BOOL __fastcall TfrmServers::EnumerateFunc(LPNETRESOURCE lpnr)
{
    DWORD dwResult, dwResultEnum;
    HANDLE hEnum;
    DWORD cbBuffer = 16384;      // 16K is a good size
    DWORD cEntries = 0xFFFFFFFF; // enumerate all possible entries
    LPNETRESOURCE lpnrLocal;     // pointer to enumerated structures
    DWORD i;

   // first time
   if (lpnr == NULL)
   {
     // so far
     ResourcesEnumerated = 0;
     // the whole net
     ResourcesToEnumerate = 1;
     AddMessage(sStartEnumerateNetwork,  1);
   }

   // update
   pbServers->Position = pbServers->Max *  ((float) ResourcesEnumerated / (float) ResourcesToEnumerate);

   ResourcesEnumerated++;

    dwResult = WNetOpenEnum(RESOURCE_GLOBALNET,
        RESOURCETYPE_ANY,

        0,                 // enumerate all resources
        lpnr,              // NULL first time this function is called
        &hEnum);           // handle to resource

    if ( (dwResult != NO_ERROR )) {

        // An application-defined error handler is demonstrated in the
        // section titled "Retrieving Network Errors."

        NetErrorHandler(dwResult, (LPSTR)"WNetOpenEnum");
        return FALSE;
    }

    do {

        // Allocate memory for NETRESOURCE structures.

        lpnrLocal = (LPNETRESOURCE) GlobalAlloc(GPTR, cbBuffer);

        dwResultEnum = WNetEnumResource(hEnum, // resource handle
            &cEntries,               // defined locally as 0xFFFFFFFF
            lpnrLocal,               // LPNETRESOURCE
            &cbBuffer);              // buffer size

        if (dwResultEnum == NO_ERROR) {
            ResourcesToEnumerate += cEntries;
            for(i = 0; i < cEntries; i++)
            {
               HandleResource(lpnrLocal[i]);
               // recurse if it is a container of interest
               // would like a way to avoid Terminal Services and Web Client...
               if ( (RESOURCEUSAGE_CONTAINER == (lpnrLocal[i].dwUsage & RESOURCEUSAGE_CONTAINER))
                      && !(lpnrLocal[i].dwDisplayType == RESOURCEDISPLAYTYPE_SERVER) )
               {

                AnsiString ObjectName;

                if (lpnrLocal[i].lpRemoteName)
                  ObjectName = lpnrLocal[i].lpRemoteName;
                else
                  ObjectName = lpnrLocal[i].lpProvider;

                AddMessage(AnsiString().sprintf(sEnumeratingContainer.c_str(),
                                                ObjectName.c_str()),
                                                1);
                EnumerateFunc(&lpnrLocal[i]);
            }
          }
        }
        else if (dwResultEnum != ERROR_NO_MORE_ITEMS) {
            NetErrorHandler(dwResultEnum, (LPSTR)"WNetEnumResource");
            break;
        }
      GlobalFree((HGLOBAL) lpnrLocal);
    }
    while(dwResultEnum != ERROR_NO_MORE_ITEMS);


    dwResult = WNetCloseEnum(hEnum);

    if(dwResult != NO_ERROR) {
        NetErrorHandler(dwResult, (LPSTR)"WNetCloseEnum");

        return FALSE;
    }

    return TRUE;
}

//---------------------------------------------------------------------------

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
    EnumerateFunc(NULL);
    pbServers->Position = 100;
    dwSize = sizeof(szComputerName);
    Win32Check(GetComputerName(szComputerName, &dwSize));
    AnsiString ComputerName = szComputerName;
    AddServer(ComputerName.c_str(), sLocalMachine.c_str());
    btnTest->Enabled = true;
  }
  __finally
  {
    btnLocate->Enabled = true;
    Screen->Cursor = crDefault;
    pbServers->Position = 0;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmServers::AddServer(char * RemoteName, char * Comment)
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

//---------------------------------------------------------------------------

void __fastcall TfrmServers::FormCreate(TObject *)
{
  lvServers->Items->Clear();
  imgInformation->Picture->Icon->Handle = LoadIcon(NULL, IDI_ASTERISK);
  imgWarning->Picture->Icon->Handle = LoadIcon(NULL, IDI_EXCLAMATION);
  imgError->Picture->Icon->Handle = LoadIcon(NULL, IDI_HAND);

  imlEvents->AddIcon(imgInformation->Picture->Icon);
  imlEvents->AddIcon(imgWarning->Picture->Icon);
  imlEvents->AddIcon(imgError->Picture->Icon);

}


//---------------------------------------------------------------------------
void __fastcall TfrmServers::lvServersClick(TObject *)
{
  btnOK->Enabled =(lvServers->Selected != NULL );
  btnGetIp->Enabled =(lvServers->Selected != NULL );
}


//---------------------------------------------------------------------------
void __fastcall TfrmServers::StartTest(TObject *)
{

  bool AbortTest = false;

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
              AddMessage(AnsiString().sprintf(sAttemptingToContact.c_str(), lvServers->Items->Item[i]->Caption.c_str()),   1);
              AddMessage(sMayTakeTime,   2);
              start = clock();
              retval = IntegerResult(frmMain->IdentChars, IPC_GETVERSION,  0);
              end = clock();
              pbServers->StepIt();
              AddMessage(AnsiString().sprintf(sResponseReceivedFmt.c_str(), (end - start) / CLK_TCK), 1);
              lvServers->Items->Item[i]->ImageIndex = 2;
              lvServers->Items->Item[i]->SubItems->Strings[1] = WinampVersion(retval);
              if (AbortTest)
                break;
            }
            catch( ERPCException &E)
            {
              pbServers->StepIt();
              AddMessage(AnsiString(sCallFailed + E.Message),   3);
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


//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------

void __fastcall TfrmServers::AddMessage(AnsiString Message, int Level)
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


//---------------------------------------------------------------------------
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


//---------------------------------------------------------------------------
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

        AddMessage(sIPLookup + lvServers->Selected->Caption, 1);
        AddMessage(sAuthoritativeName + HostName, 1);

        if (Addresses->Count > 0 )
        {
          AddMessage(sAddressesRetrieved, 1);
          for (int i = 0; i < Addresses->Count  ; i ++)
          {
            AddMessage(sIPAddress + Addresses->Strings[i], 1);
          }
        }
        else
        {
          AddMessage(sAddressesNotRetrieved, 2);
        }


        if (Aliases->Count > 0 )
        {
           AddMessage(sAliasesRetrieved, 1);
          for (int i = 0; i < Aliases->Count  ; i ++)
          {
            AddMessage(AnsiString(sIPAlias) + Aliases->Strings[i], 1);
          }
        }
        else
        {
          AddMessage(sAliasesNotRetrieved, 2);
        }

      }
      catch (EIPException &E)
      {
        AddMessage(sGetIPAddressFailed + E.Message, 3);
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
//---------------------------------------------------------------------------

void __fastcall TfrmServers::spltMessagesCanResize(TObject * , int &NewSize, bool &Accept)
{
  Accept = (NewSize > 30);        
}
//---------------------------------------------------------------------------


