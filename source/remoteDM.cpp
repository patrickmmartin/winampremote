//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "remoteDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TdmRemote *dmRemote;
//---------------------------------------------------------------------------
__fastcall TdmRemote::TdmRemote(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
