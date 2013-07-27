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

#include "SettingsF.h"
#include "MainF.h"
#include "waint.h"
#include "GlassExtender.h"
#include "remoteDM.h"

#pragma package(smart_init)
#pragma resource "*.dfm"




TfrmSettings *frmSettings;

__fastcall TfrmSettings::TfrmSettings(TComponent* Owner)
    : TForm(Owner)
{
}

void __fastcall TfrmSettings::FormCreate(TObject *)
{

  Bars = new TList;
  Bars->Add(TrackBar1);
  Bars->Add(TrackBar2);
  Bars->Add(TrackBar3);
  Bars->Add(TrackBar4);
  Bars->Add(TrackBar5);
  Bars->Add(TrackBar6);
  Bars->Add(TrackBar7);
  Bars->Add(TrackBar8);
  Bars->Add(TrackBar9);
  Bars->Add(TrackBar10);
  Bars->Add(TrackBar11);

  pgcSettings->ActivePage = tbsVol;

  dmRemote->registerForm(this);

}


void __fastcall TfrmSettings::FormDestroy(TObject *)
{
  dmRemote->unRegisterForm(this);
  delete Bars;
}

void __fastcall TfrmSettings::tbVolumeChange(TObject *)
{
  dmRemote->SetVolume(tbVolume->Position);
}


void __fastcall TfrmSettings::tbBalanceChange(TObject *)
{
  dmRemote->SetBalance(tbBalance->Position);
}

void __fastcall TfrmSettings::UpdateBars(bool autoLoad, bool EqOn, const vector<int>& bands)
{

  for (unsigned int i = 0; i < bands.size() ; i++)
  {
	( (TTrackBar *) Bars->Items[i])->Position = bands[i];
  }

  // last one...
  dmRemote->Autoload->Checked = autoLoad;
  dmRemote->EQOn->Checked = EqOn;

}


void __fastcall TfrmSettings::BarsChange(TObject *Sender)
{

  int Index = Bars->IndexOf(Sender);
  if (Index > -1)
  {
    dmRemote->BarChange(Index, (byte) ((TTrackBar *)Sender)->Position );
  }

}



