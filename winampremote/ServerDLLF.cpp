//---------------------------------------------------------------------------
#include <vcl.h>
#include <registry.hpp>
#pragma hdrstop

#include "ServerDLLF.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;


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
void __fastcall TfrmMain::ThreadStatus(TMessage &Message)
{

  switch ((WAExecutionStatus) Message.LParam)
  {
    case waListening:
      sbrMain->Panels->Items[0]->Text = "listening...";
      break;

    case waExecuting:
      sbrMain->Panels->Items[0]->Text = "working";
      break;

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

  sbrMain->Refresh();  
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::ThreadIdent(TMessage &Message)
{
//do something here

  int i;
  int pos = -1;
  char * Ident = (char *) Message.LParam;
  TListItem  *ListItem;

  for (i = 0 ; i < lvUsers->Items->Count ; i++){
    ListItem = lvUsers->Items->Item[i];
    if (ListItem->Caption == Ident){
      ListItem->Data = (void *) GetTickCount();
      if ((ListItem->ImageIndex == 0) || (ListItem->ImageIndex == imlUsers->Count - 1)){
        ListItem->ImageIndex = 1;
        }
      pos = i;
      }

    } // for

  if (pos == -1){
  //need new
    ListItem = lvUsers->Items->Add();
    ListItem->ImageIndex = 1;
    ListItem->Caption = Ident;
    ListItem->Data = (void *) GetTickCount();
    }
  delete ((char *) Message.LParam);

}

void __fastcall TfrmMain::timerMainTimer(TObject *Sender)
{

  int i;
  TListItem  *ListItem;
  int NowTickCount = GetTickCount();

  for (i = lvUsers->Items->Count - 1; i >= 0 ; i--){
    ListItem = lvUsers->Items->Item[i];

    //check for timed out clients
    if ((NowTickCount - (int ) ListItem->Data) > (1000 * FAIL_TIMEOUT)){
      // looks like it's timing out
      ListItem->ImageIndex = 0;
      }
    else{
      if (ListItem->ImageIndex == 0){
        ListItem->ImageIndex = 1;
        }
      }

   if ((ListItem->ImageIndex > 0) && (ListItem->ImageIndex < imlUsers->Count - 1)){
     ListItem->ImageIndex = ListItem->ImageIndex + 1;
     }



    if ((NowTickCount - (int ) ListItem->Data) > (2000 * FAIL_TIMEOUT)){
      // looks like it's timing out
      lvUsers->Items->Delete(i);
      }

    } // for


}
//---------------------------------------------------------------------------


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
TRegistry * reg;


  try{
      reg = new TRegistry();
      reg->OpenKey("software\\PMMSoft\\Winamp controller\\server settings", true);
      EndPoint = reg->ReadString("EndPoint").ToIntDef(PortDefault);
    }
  __finally {
    delete reg;
    }

  /*
  Get the computer name. */
  cchBuff = BufferSize;
  if (GetComputerName(Computername, &cchBuff))
    {
      sbrMain->Panels->Items[1]->Text = AnsiString("name: ") + Computername;
    }
    else
    {
      sbrMain->Panels->Items[1]->Text = AnsiString("could not obtain name");
    }


  Application->OnException = AppException;

  CreateThread(this);

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
void __fastcall TfrmMain::CreateThread(TObject *Sender)
{
  serverThread =  new TRPCServerThread(true);
  sbrMain->Panels->Items[2]->Text = AnsiString("endpoint: ") + EndPoint;
  serverThread->Endpoint = EndPoint;
  serverThread->Resume();
}

void __fastcall TfrmMain::StopThread(TObject *Sender)
{
  WAShutdown();
}


void __fastcall TfrmMain::FormCloseQuery(TObject *Sender, bool &CanClose)
{

TRegistry * reg;

  try{
      reg = new TRegistry();
      reg->OpenKey("software\\PMMSoft\\Winamp controller\\server settings", true);

      reg->WriteString("EndPoint", EndPoint);

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

