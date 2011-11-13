// winamp remote control suite ©Patrick Michael Martin 2000
//
// ServersF.cpp
//
// form displaying local machines and allowing testing
//

#include <vcl.h>
#pragma hdrstop
#include <time.h>

#include "ServersF.h"
#include "messageF.h"
#include "MainF.h"
#include "RFC1060U.h"
#include "IPAddressU.h"
#include "RPCFuncsU.h"

// winamp IPC declarations
#include "waint.h"

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

void __fastcall TfrmServers::DisplayStruct(LPNETRESOURCE NetResource)
{

  if (NetResource->dwDisplayType == RESOURCEDISPLAYTYPE_SERVER)
  {
    AnsiString RemoteName = NetResource->lpRemoteName;
    // strip out the UNC prefix
    RemoteName.Delete(1, 2);
    AddServer(RemoteName.c_str(), NetResource->lpComment);
  }
}

//---------------------------------------------------------------------------

void __fastcall TfrmServers::NetErrorHandler(DWORD dwErrorCode, AnsiString Function)
{
    DWORD dwWNetResult, dwLastError;
    char szDescription[256];
    char szProvider[256];

    // The following code performs standard error-handling.

    if (dwErrorCode != ERROR_EXTENDED_ERROR)
    {
        // warning
        AddMessage(Function + " failed ", 2);
        AddMessage(SysErrorMessage(dwErrorCode) + ".", 0);
    }
    else
    {
        dwWNetResult = WNetGetLastError(&dwLastError,
            (LPSTR) szDescription,  sizeof(szDescription),
            (LPSTR) szProvider,   sizeof(szProvider));

        if(dwWNetResult != NO_ERROR) {
         // error
        AddMessage(AnsiString().sprintf("WNetGetLastError failed; error %ld.", dwWNetResult), 3);
        }
      // warning
      AddMessage(AnsiString().sprintf("%s failed with code %ld; %s.", szProvider, dwLastError, szDescription),  3);
    }
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
     AddMessage("Starting to enumerate network.",  1);
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
              DisplayStruct(&lpnrLocal[i]);
             if ( (RESOURCEUSAGE_CONTAINER == (lpnrLocal[i].dwUsage & RESOURCEUSAGE_CONTAINER))
                    && !(lpnrLocal[i].dwDisplayType == RESOURCEDISPLAYTYPE_SERVER) )
            {

              AnsiString ObjectName;

              if (lpnrLocal[i].lpRemoteName)
                ObjectName = lpnrLocal[i].lpRemoteName;
              else
                ObjectName = lpnrLocal[i].lpProvider;

              AddMessage(AnsiString().sprintf("Enumerating container %s.", ObjectName),  1);
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

void __fastcall TfrmServers::btnLocateClick(TObject *Sender)
{

//?    TCHAR           szComputerName[MAX_COMPUTERNAME_LENGTH+1];
  char szComputerName[MAX_COMPUTERNAME_LENGTH+1];
  DWORD dwSize;

  Screen->Cursor = crHourGlass;
//  pgcServers->ActivePage = tbsMessages;

  btnLocate->Enabled = false;

  try
  {
    pbServers->Position = 0;
    pbServers->Max = 100;
    lvMessages->Items->Clear();
    EnumerateFunc(NULL);
    pbServers->Position = 100;
    dwSize = sizeof(szComputerName);
    ZeroMemory(szComputerName, dwSize);
    Win32Check(GetComputerName(szComputerName, &dwSize));
    AnsiString ComputerName = AnsiString(szComputerName);
    AddServer(ComputerName.c_str(), "local machine");
    btnTest->Enabled = true;
//    pgcServers->ActivePage = tbsServers;
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
   ListItem->SubItems->Add("unknown");
   ListItem->ImageIndex = 0;

   // in the event of duplicate names, I imagine there will be big trouble

}

//---------------------------------------------------------------------------

void __fastcall TfrmServers::FormCreate(TObject *Sender)
{
  lvServers->Items->Clear();
  imgInformation->Picture->Icon->Handle = LoadIcon(NULL, IDI_ASTERISK);
  imgWarning->Picture->Icon->Handle = LoadIcon(NULL, IDI_EXCLAMATION);
  imgError->Picture->Icon->Handle = LoadIcon(NULL, IDI_HAND);

  imlEvents->AddIcon(imgInformation->Picture->Icon);
  imlEvents->AddIcon(imgWarning->Picture->Icon);
  imlEvents->AddIcon(imgError->Picture->Icon);

  pgcServers->ActivePage = tbsServers;

}
//---------------------------------------------------------------------------
void __fastcall TfrmServers::lstMessagesMeasureItem(TWinControl *Control,
      int Index, int &Height)
{
  TListBox * ListBox =  dynamic_cast<TListBox *>(Control);

  Height = imlEvents->Height + 2;
  if (Control)
    Height = max(Height, ListBox->Canvas->TextHeight("W") + 2);

}
//---------------------------------------------------------------------------

void __fastcall TfrmServers::lstMessagesDrawItem(TWinControl *Control,
      int Index, TRect &Rect, TOwnerDrawState State)
{

  int Offset = 2;

  // note that we draw on the listbox’s canvas, not on the form
  TListBox * ListBox = dynamic_cast<TListBox *> (Control);
  if (ListBox)
  {
    ListBox->Canvas->FillRect(Rect); // clear the rectangle

    if (ListBox->Items->Objects[Index])
      imlEvents->Draw(ListBox->Canvas, Rect.Left + Offset, Rect.Top, ((int) ListBox->Items->Objects[Index]) - 1 ,true);

    Offset += imlEvents->Width + 4;   // add four pixels between bitmap and text
    // display the text
    ListBox->Canvas->TextOut(Rect.Left + Offset, Rect.Top, ((TListBox *)Control)->Items->Strings[Index]);
  }
  // can't do much else!

}
//---------------------------------------------------------------------------

void __fastcall TfrmServers::lvServersClick(TObject *Sender)
{
  btnOK->Enabled =(lvServers->Selected != NULL );
  btnGetIp->Enabled =(lvServers->Selected != NULL );
}
//---------------------------------------------------------------------------

void __fastcall TfrmServers::StartTest(TObject *Sender)
{

  bool AbortTest = false;

  CheckPort();
  // now this is OK

  lvMessages->Items->Clear();
  btnLocate->Enabled = false;
  btnOK->Enabled = false;
  btnGetIp->Enabled = false;
  btnCancel->Enabled = false;

  btnTest->Caption = "Stop";
  btnTest->OnClick = StopTest;

  Screen->Cursor = crHourGlass;
  int retval;

  clock_t start, end;

  try
  {
//    pgcServers->ActivePage = tbsMessages;
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
            AddMessage(AnsiString().sprintf("Attempting to contact %s.", lvServers->Items->Item[i]->Caption.c_str()),   1);
            AddMessage("This may take a very long time.",   2);
            start = clock();
            retval = IntegerResult(IdentChars, IPC_GETVERSION,  0);
            end = clock();
            pbServers->StepIt();
            AddMessage(AnsiString().sprintf("Response received. Took %.3f s.", (end - start) / CLK_TCK), 1);
            lvServers->Items->Item[i]->ImageIndex = 2;
            lvServers->Items->Item[i]->SubItems->Strings[1] = WinampVersion(retval);
            Application->ProcessMessages();
            if (AbortTest)
              break;
          }
          catch( ERPCException &E)
          {
            pbServers->StepIt();
            AddMessage(AnsiString("Call Failed: "  + E.Message),   3);
            lvServers->Items->Item[i]->ImageIndex = 1;
            lvServers->Items->Item[i]->SubItems->Strings[1] = "not found";
          }
       }
       __finally
       {
         UnBind();
       }
    }
    lvServers->Selected = NULL;

    StopTest(this);
//    pgcServers->ActivePage = tbsServers;

  }
  __finally
  {
    Screen->Cursor = crDefault;
    pbServers->Position = 0;
  }

}
//---------------------------------------------------------------------------

void __fastcall TfrmServers::StopTest(TObject *Sender)
{

  btnLocate->Enabled = true;
  btnOK->Enabled = false;
  btnGetIp->Enabled = false;
  btnCancel->Enabled = true;
  AbortTest = true;
  btnTest->OnClick = StartTest;
  btnTest->Caption = "Test";

}
//---------------------------------------------------------------------------

void __fastcall TfrmServers::AddMessage(AnsiString Message, int Level)
{

  TListItem * ListItem =  lvMessages->Items->Add();
  ListItem->Caption = Message;
  ListItem->ImageIndex = Level - 1;
  lvMessages->Selected = ListItem;
  lvMessages->Refresh();

}

void __fastcall TfrmServers::FormClose(TObject *Sender,
      TCloseAction &Action)
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
int port;

  try
  {
    port = ebEndPoint->Text.ToInt();
    if ((port < 0) || (port > 65535))
    {
      throw EConvertError(AnsiString().sprintf("port %d specified is out of range", port).c_str());
    }
  }
  catch (EConvertError &E)
  {
    MessageBox(this->Handle, E.Message.c_str(), "Endpoint port invalid", MB_OK | MB_ICONERROR);
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
        Application->MessageBox((AnsiString("The port chosen: ") + port + " (" + RFC1060ports[i].service + "), is a well known service.\n"
                               "This choice of port could lead to the application hanging\n"
                               "if it is already in use by another service on the server.\n"
                               "Proceed with this choice?").c_str(),
                               "Alert - Well-known port number chosen!",
                               MB_ICONEXCLAMATION + MB_OKCANCEL + MB_DEFBUTTON2) != IDOK)  throw EAbort("user cancellled bogus port");
  }
void __fastcall TfrmServers::btnOKClick(TObject *Sender)
{
  CheckPort();
  ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TfrmServers::GetServerIp(TObject *Sender)
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

        AddMessage("Results for ip address lookup on " + lvServers->Selected->Caption, 1);
        AddMessage("Authoritative name: " + HostName, 1);

        if (Addresses->Count > 0 )
        {
          AddMessage("Addresses were retrieved", 1);
          for (int i = 0; i < Addresses->Count  ; i ++)
          {
            AddMessage(AnsiString("ip address: ") + Addresses->Strings[i], 1);
          }
        }
        else
        {
          AddMessage("Addresses were not retrieved", 2);
        }


        if (Aliases->Count > 0 )
        {
           AddMessage("Aliases were retrieved", 1);
          for (int i = 0; i < Aliases->Count  ; i ++)
          {
            AddMessage(AnsiString("ip alias: ") + Aliases->Strings[i], 1);
          }
        }
        else
        {
          AddMessage("Aliases were not retrieved", 2);
        }

      }
      catch (EIPException &E)
      {
        AddMessage("Get IP address failed: " + E.Message, 3);
      }

    pgcServers->ActivePage = tbsMessages;
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

