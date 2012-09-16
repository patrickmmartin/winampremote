
#ifndef DetailsFH
#define DetailsFH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>


class TfrmDetails : public TForm
{
__published:	// IDE-managed Components
        TListView *lvDetails;
        TPanel *pnlCaption;
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmDetails(TComponent* Owner);
};

extern PACKAGE TfrmDetails *frmDetails;

#endif
