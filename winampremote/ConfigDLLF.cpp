//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ConfigDLLF.h"
#include "AboutF.h"
#include "ServerDLLF.h"
#include "RFC1060U.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TConfigForm *ConfigForm;



//---------------------------------------------------------------------------
__fastcall TConfigForm::TConfigForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::btnAboutClick(TObject *Sender)
{
    frmAbout = new TfrmAbout(NULL);
    frmAbout->Caption = "About winamp remote control server";
    OutText->Clear();
    OutText->Add("winamp");
    OutText->Add("remote");
    OutText->Add("control");
    OutText->Add("RPC");
    OutText->Add("server");
    frmAbout->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::chkVisibleClick(TObject *Sender)
{
  frmMain->Visible = chkVisible->Checked;
  ebEndPoint->Text = frmMain->EndPoint;
}
//---------------------------------------------------------------------------


void __fastcall TConfigForm::btnChangeEndpointClick(TObject *Sender)
{
// shutdown

//watch for infringing upon RFC 1060 (Assigned Numbers) ports

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

  if (!usedport ||
        Application->MessageBox((AnsiString().sprintf(
                               "The port chosen:\n"
                               "%d [%s] - %s\n"
                               "is a well known port number.\n"
                               "This choice of port could lead to serious problems if it is already in use on the server.\n"
                               "Proceed with this choice?"
                               , port, RFC1060ports[i].service, RFC1060ports[i].description)
                               ).c_str(),
                               "Alert - Well-known port number chosen!",
                               MB_OKCANCEL | MB_DEFBUTTON2 | MB_ICONWARNING) == IDOK){


    frmMain->Show();
    frmMain->Refresh();
    frmMain->pgMain->ActivePage = frmMain->tbsMessages;
    frmMain->StopThread(this);
    // need to wait, apparently not easy to determine how
    Sleep(2000);
    //create new
    frmMain->EndPoint = port;
    frmMain->CreateThread(this);
    Application->ProcessMessages();
    frmMain->Refresh();
    this->SetFocus();
    frmMain->Visible = chkVisible->Checked;
    }
  ebEndPoint->Text = frmMain->EndPoint;

}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::FormShow(TObject *Sender)
{
  chkVisible->Checked = frmMain->Visible;
  ebEndPoint->Text = frmMain->EndPoint;
}
//---------------------------------------------------------------------------

