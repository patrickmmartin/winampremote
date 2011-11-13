//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "AnimF.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  ListView1->Items->Item[0]->ImageIndex++;
  ListView1->Items->Item[0]->ImageIndex = ListView1->Items->Item[0]->ImageIndex % ImageList1->Count;
  ListView1->Items->Item[0]->Caption = ListView1->Items->Item[0]->ImageIndex;

  ListView1->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListView1Click(TObject *Sender)
{
  Timer1Timer(this);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListView1DblClick(TObject *Sender)
{
  Timer1->Enabled = ! Timer1->Enabled;

}
//---------------------------------------------------------------------------

