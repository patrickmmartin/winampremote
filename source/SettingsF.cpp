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

void __fastcall TfrmSettings::tbVolumeChange(TObject *)
{
  dmRemote->client->setVolume(tbVolume->Position);
}


void __fastcall TfrmSettings::tbBalanceChange(TObject *)
{
  dmRemote->client->setPanning(tbBalance->Position);
}


void __fastcall TfrmSettings::FormClose(TObject *, TCloseAction &)
{
	// TODO: form manager - should be hooked
  dmRemote->ViewVolume->Execute();
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

}


void __fastcall TfrmSettings::FormDestroy(TObject *)
{
  delete Bars;
}


void __fastcall TfrmSettings::UpdateBars(void)
{

  for (int i = 0; i < Bars->Count ; i++)
  {
    ( (TTrackBar *) Bars->Items[i])->Position = dmRemote->client->getEQData(i);
  }

  // last one...
  dmRemote->Autoload->Checked = dmRemote->client->getAutoload();
  dmRemote->EQOn->Checked = dmRemote->client->getEQOn();

}


void __fastcall TfrmSettings::BarsChange(TObject *Sender)
{

  int Index = Bars->IndexOf(Sender);
  if (Index > -1)
  {
    dmRemote->client->setEQData(Index, (byte) ((TTrackBar *)Sender)->Position );
  }

}


void __fastcall TfrmSettings::FormStartDock(TObject *Sender,
      TDragDockObject *&DragObject)
{
	// TODO: form manager - should be hooked
  frmMain->StartDock(Sender, DragObject);
}



void __fastcall TfrmSettings::FormShow(TObject *)
{

  // extend glass on Aero
  // this would need a bit of a UI overhaul
  /*
  GlassExtender * ge = new GlassExtender(this);
  if (ge->isCompositionActive())
  {
        Color = clNone;
  }
  */

}


