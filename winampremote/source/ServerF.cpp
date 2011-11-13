//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ServerF.h"
#include "rpcthread.h"
#include "AboutF.h"
#include "ConfigF.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
TRPCServerThread *serverThread;
HWND mainhwnd;

bool isExe = false;

//---------------------------------------------------------------------------
void __fastcall TfrmMain::ThreadMessage(TMessage &Message)

{
  if (  memMessages->Lines->Add( (char *) Message.LParam) > 1000){
    memMessages->Lines->Clear();
    }
// act upon the passed message

  delete ((char *) Message.LParam);

}


//---------------------------------------------------------------------------
void __fastcall TfrmMain::ThreadStatus(TMessage &Message)

{
  sbrMain->Panels->Items[0]->Text = ( (char *) Message.LParam);
  delete ((char *) Message.LParam);

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


  /*
  Get the computer name. */
  cchBuff = 32;
  success = GetComputerName(Computername, &cchBuff);

  if (success){
      sbrMain->Panels->Items[1]->Text = Computername;
      sbrMain->Panels->Items[2]->Text = 8000;

      mainhwnd = this->Handle;

      serverThread =  new TRPCServerThread(false);

        }
  else{
      this->memMessages->Lines->Add("computer name not obtained");
      this->memMessages->Lines->Add("rpc service not starting");
      }


}
//---------------------------------------------------------------------------







void __fastcall TfrmMain::mnuHelpAboutClick(TObject *Sender)
{
    frmAbout = new TfrmAbout(this);
    try{
      frmAbout->Caption = "About winamp remote control server";
      OutText->Clear();
      OutText->Add("winamp");
      OutText->Add("remote");
      OutText->Add("control");
      OutText->Add("server");
      frmAbout->ShowModal();
      }
    __finally{
      delete frmAbout;
      }

}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuConfigurationClick(TObject *Sender)
{
     TConfigForm * frmConfig = new TConfigForm(NULL);
    try{
      frmConfig->ShowModal();
      }
    __finally{
      delete frmConfig;
      }

}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuFileExitClick(TObject *Sender)
{
  Close();    
}
//---------------------------------------------------------------------------

