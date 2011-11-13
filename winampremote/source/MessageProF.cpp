// winamp remote control suite ©Patrick Michael Martin 2000
//
// messageF.cpp
//
// simple message form
//

#include <vcl.h>
#pragma hdrstop

#include "MessageProF.h"
#include "ColourU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMessage *frmMessage;

const TRect FinalSize = TRect(0, 0, 350, 150);

float startcount = 0;
//---------------------------------------------------------------------------
__fastcall TfrmMessage::TfrmMessage(TComponent* Owner)
    : TForm(Owner)
{
}

//---------------------------------------------------------------------------

void __fastcall TfrmMessage::FormShow(TObject *Sender)
{
  Timer1->Enabled = true;
  StartCount = GetTickCount();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMessage::Timer1Timer(TObject *Sender)
{
//

  int TicksCount = GetTickCount() - StartCount;
  memTitle->Font->Color = RainbowColour(TicksCount);
  if (TicksCount > 3000)
  {
    Timer1->Enabled = false;
    Close();
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMessage::FormActivate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------




