// winamp remote control suite ©Patrick Michael Martin 2000
//
// SettingsF.cpp
//
// form displaying and allowing editing of volume and EQ
//

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
  IntegerResult(IdentChars, IPC_SETVOLUME, tbVolume->Position);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::tbBalanceChange(TObject *Sender)
{
  IntegerResult(IdentChars, IPC_SETPANNING, tbBalance->Position);
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
      IntegerResult(IdentChars, IPC_GETEQDATA, i);
  }

  // last one...
  frmMain->Autoload->Checked = IntegerResult(IdentChars, IPC_GETEQDATA, 11);
  EQUpdateNeeded = false;

}
//---------------------------------------------------------------------------

void __fastcall TfrmSettings::BarsChange(TObject *Sender)
{

  int Index = Bars->IndexOf(Sender);
  if (Index > -1)
  {
    IntegerResult(IdentChars, IPC_GETEQDATA, Index);
    IntegerResult(IdentChars, IPC_SETEQDATA,  ( (TTrackBar *)Sender)->Position );
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

