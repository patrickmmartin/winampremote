//---------------------------------------------------------------------------

#ifndef remoteDMH
#define remoteDMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TdmRemote : public TDataModule
{
__published:	// IDE-managed Components
        TActionList *alRemote;
private:	// User declarations
public:		// User declarations
        __fastcall TdmRemote(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TdmRemote *dmRemote;
//---------------------------------------------------------------------------
#endif
