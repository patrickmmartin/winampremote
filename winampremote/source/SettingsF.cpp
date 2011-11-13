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

Patrick M. Martin may be reached by email at patrickmmartin@freenet.co.uk.
*/

#include <vcl.h>
#pragma hdrstop

#include "SettingsF.h"
#include "MainF.h"
#include "waint.h"
#include "RPCFuncsU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"




TfrmSettings *frmSettings;
//---------------------------------------------------------------------------
__fastcall TfrmSettings::TfrmSettings(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::tbBalanceEnter(TObject *Sender)
{

  if (Sender == lblL){
    tbBalance->Position = tbBalance->Min;
    }

  if (Sender == lblR){
    tbBalance->Position = tbBalance->Max;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::tbVolumeChange(TObject *Sender)
{
  IntegerResult(frmMain->IdentChars, IPC_SETVOLUME, tbVolume->Position);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::tbBalanceChange(TObject *Sender)
{
  IntegerResult(frmMain->IdentChars, IPC_SETPANNING, tbBalance->Position);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  frmMain->ViewVolume->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::FormCreate(TObject *Sender)
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
  EQUpdateNeeded = true;

}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::FormDestroy(TObject *Sender)
{
  delete Bars;
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::UpdateBars(void)
{

  for (int i = 0; i < Bars->Count ; i++)
  {
    ( (TTrackBar *) Bars->Items[i])->Position =
      IntegerResult(frmMain->IdentChars, IPC_GETEQDATA, i);
  }

  // last one...
  frmMain->Autoload->Checked = IntegerResult(frmMain->IdentChars, IPC_GETEQDATA, 11);
  EQUpdateNeeded = false;

}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::BarsChange(TObject *Sender)
{

  int Index = Bars->IndexOf(Sender);
  if (Index > -1)
  {
    IntegerResult(frmMain->IdentChars, IPC_GETEQDATA, Index);
    IntegerResult(frmMain->IdentChars, IPC_SETEQDATA,  ( (TTrackBar *)Sender)->Position );
  }
  EQUpdateNeeded = true;


}
//---------------------------------------------------------------------------







void __fastcall TfrmSettings::FormStartDock(TObject *Sender,
      TDragDockObject *&DragObject)
{
  frmMain->StartDock(Sender, DragObject);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::FormEndDock(TObject *Sender, TObject *Target,
      int X, int Y)
{
  frmMain->EndDock(Sender, Target, X, Y);
}
//---------------------------------------------------------------------------

