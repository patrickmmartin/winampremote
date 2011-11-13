// winamp remote control suite ©Patrick Michael Martin 2000
//
// ConfigDLLF.cpp
//
// form for configuring dll
//

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

  try
  {
    frmAbout->Caption = "About winamp remote control client";
    OutText->Text = "winamp\n\rremote\n\rcontrol\n\rRPC\n\rserver";
    frmAbout->ShowModal();
  }
  __finally
  {
    delete frmAbout;
  }

}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::chkVisibleClick(TObject *Sender)
{
  frmMain->Visible = chkVisible->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::FormCreate(TObject *Sender)
{
  chkVisible->Checked = frmMain->Visible;
  ebEndPoint->Text = frmMain->EndPoint;
}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::btnChangeEndpointClick(TObject *Sender)
{
// shutdown

//watch for infringing upon RFC 1060 (Assigned Numbers) ports


  unsigned short port = (unsigned short ) ebEndPoint->Text.ToInt();
  bool usedport = false;
  int i;

  for (i = 0  ; i < RFC1060portscount ; i++)
  {
    if (RFC1060ports[i].port == port)
    {
      usedport = true;
      break;
    }
  }

  if (!usedport ||
        MessageBox(this->Handle,
                   (AnsiString("The port chosen: ") + port + " (" + RFC1060ports[i].service + "), is a well known port number.\n"
                               "This choice of port could lead to serious problems if it is already in use on the server.\n"
                               "Proceed with this choice?").c_str(),
                               "Alert - Well-known port number chosen!",
                               MB_ICONASTERISK | MB_OKCANCEL | MB_DEFBUTTON2) == IDOK){


    frmMain->Show();
    frmMain->Refresh();
    frmMain->StopThread(this);

    // need to wait, apparently not easy to determine how

    Sleep(2000);

  //create new

    frmMain->sbrMain->Panels->Items[2]->Text = "endpoint: " + ebEndPoint->Text;

    frmMain->CreateThread(port);

    Application->ProcessMessages();
    frmMain->Refresh();
    Sleep(2000);
    frmMain->Visible = chkVisible->Checked;
    this->BringToFront();
    }
  else
  {
    ebEndPoint->Text = frmMain->sbrMain->Panels->Items[2]->Text;
  }
  btnChangeEndpoint->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::ebEndPointChange(TObject *Sender)
{
  int PortNum = ebEndPoint->Text.ToIntDef(-1);
  btnChangeEndpoint->Enabled = ( ( PortNum > -1) && ( PortNum < 65536) && ( PortNum != frmMain->EndPoint));

}
//---------------------------------------------------------------------------

