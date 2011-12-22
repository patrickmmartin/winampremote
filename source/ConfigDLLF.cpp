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

#include "ConfigDLLF.h"
#include "AboutF.h"
#include "ServerDLLF.h"
#include "RFC1060U.h"
#include "DetailsF.h"

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
    frmAbout->Icon->Handle = this->Icon->Handle;
    frmAbout->ShowModal();
  }
  __finally
  {
    delete frmAbout;
    frmAbout = NULL;
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

    // need to wait, not easy to determine what for
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

void __fastcall TConfigForm::DetailsClick(TObject *Sender)
{

  TfrmDetails *DetailsForm = new TfrmDetails(this);
  try
  {
    DetailsForm->Icon->Handle = this->Icon->Handle;
    DetailsForm->ShowModal();
  }
  __finally
  {
    delete DetailsForm;
  }

}
//---------------------------------------------------------------------------

