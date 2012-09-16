
#include <vcl.h>
#pragma hdrstop

#include "ConfigF.h"
#include "AboutF.h"
#include "ServerDLLF.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TConfigForm *ConfigForm;

__fastcall TConfigForm::TConfigForm(TComponent* Owner)
    : TForm(Owner)
{
}


void __fastcall TConfigForm::btnAboutClick(TObject *Sender)
{
    frmAbout = new TfrmAbout(NULL);
    try{
      frmAbout->Caption = "About winamp remote control server";
      OutText->Clear();
      OutText->Add("winamp");
      OutText->Add("remote");
      OutText->Add("control");
      OutText->Add("RPC");
      OutText->Add("server");
      OutText->Add("©");
      OutText->Add("pmmsoft");
      OutText->Add("2000");
      frmAbout->ShowModal();
      }
    __finally{
      delete frmAbout;
      }


}



void __fastcall TConfigForm::FormCreate(TObject *Sender)
{
  ebEndPoint->Text = "\\pipe\\winampremote";
}


