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

#include "ConfigDLLF.h"
#include "AboutF.h"
#include "ServerDLLF.h"
#include "RFC1060U.h"
#include "DetailsF.h"


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

  try
  {
    frmAbout->Caption = "About winamp remote control client";
    frmAbout->Icon->Handle = this->Icon->Handle;
    frmAbout->ShowModal();
  }
  __finally
  {
    delete frmAbout;
    frmAbout = NULL;
  }

}


void __fastcall TConfigForm::chkVisibleClick(TObject *Sender)
{
  frmPluginMain->Visible = chkVisible->Checked;
}


void __fastcall TConfigForm::FormCreate(TObject *Sender)
{
  chkVisible->Checked = frmPluginMain->Visible;
}

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


