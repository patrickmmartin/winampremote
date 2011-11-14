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

#include "DetailsF.h"
#include "VersionInfoU.h"
#include "remotestrs.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"



TfrmDetails *frmDetails;
//---------------------------------------------------------------------------
__fastcall TfrmDetails::TfrmDetails(TComponent* Owner)
        : TForm(Owner)
{
}


//---------------------------------------------------------------------------
void __fastcall TfrmDetails::FormCreate(TObject *)
{

  Icon->Handle = Application->Icon->Handle;
  TModuleVersionInfo * VI;
  char FileName[MAX_PATH + 1];

  const AnsiString ExtraKeys[] = {"Expected Versions", NULL};

  GetModuleFileName(g_hinst, FileName, MAX_PATH);


  Caption = AnsiString().sprintf( Remotestrs_sDetailsCaptionFmt.c_str(), LowerCase(ExtractFileName(FileName)).c_str());

  VI = new TModuleVersionInfo(FileName);
  try
  {

    TListItem * ListItem;
    int i;
    for (i = 0; i < MaxVersionKeys ; i++)
    {
      ListItem = lvDetails->Items->Add();
      ListItem->Caption = VersionKeyNames[i];
      ListItem->SubItems->Add(VI->Key[VersionKeyNames[i]]);
    }

    for (i = 0; (ExtraKeys[i] != NULL) ; i++)
    {
      ListItem = lvDetails->Items->Add();
      ListItem->Caption = ExtraKeys[i];
      ListItem->SubItems->Add(VI->Key[ExtraKeys[i]]);
    }

  }
  __finally
  {
    delete VI;
  }  


}
//---------------------------------------------------------------------------
