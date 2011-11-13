//---------------------------------------------------------------------------
#ifndef AnimFH
#define AnimFH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TImageList *ImageList1;
    TListView *ListView1;
    TTimer *Timer1;
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall ListView1Click(TObject *Sender);
    void __fastcall ListView1DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
