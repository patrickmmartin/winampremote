//---------------------------------------------------------------------------
#ifndef SplashFH
#define SplashFH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TfrmSplash : public TForm
{
__published:	// IDE-managed Components
    TBevel *bvlMain;
    TLabel *lblAppname;
    TLabel *lblMessage;
    TImage *imgSplash;
private:	// User declarations
public:		// User declarations
    __fastcall TfrmSplash(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSplash *frmSplash;
//---------------------------------------------------------------------------
#endif
