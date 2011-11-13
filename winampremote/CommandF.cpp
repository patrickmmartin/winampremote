// winamp remote control suite ©Patrick Michael Martin 2000
//
// CommandF.cpp
//
// floating toolbar form for the remote 
//

#include <vcl.h>
#pragma hdrstop

#include "CommandF.h"
#include "MainF.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCommands *frmCommands;
//---------------------------------------------------------------------------
__fastcall TfrmCommands::TfrmCommands(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmCommands::tbtnPreviousClick(TObject *Sender)
{
  frmMain->mnuPreviousClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TfrmCommands::tbtnPlayClick(TObject *Sender)
{
  frmMain->mnuPlayClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TfrmCommands::tbtnPauseClick(TObject *Sender)
{
  frmMain->mnuPauseClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TfrmCommands::tbtnStopClick(TObject *Sender)
{
  frmMain->mnuStopClick(this);

}
//---------------------------------------------------------------------------
void __fastcall TfrmCommands::tbtnNextClick(TObject *Sender)
{
  frmMain->mnuNextClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TfrmCommands::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  frmMain->ViewToolBar->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TfrmCommands::FormStartDock(TObject *Sender,
      TDragDockObject *&DragObject)
{
  frmMain->StartDock(Sender, DragObject);
        
}
//---------------------------------------------------------------------------

void __fastcall TfrmCommands::FormEndDock(TObject *Sender, TObject *Target,
      int X, int Y)
{
  frmMain->EndDock(Sender, Target, X, Y);
}
//---------------------------------------------------------------------------

