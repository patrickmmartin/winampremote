//---------------------------------------------------------------------------
#ifndef ConfigDLLFH
#define ConfigDLLFH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------




class TConfigForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TCheckBox *chkVisible;
    TEdit *ebEndPoint;
    TLabel *lblEndPoint;
    TButton *btnAbout;
    TButton *btnClose;
    TButton *btnChangeEndpoint;
        TMemo *Memo1;
        TImage *imgLogo;
        TBevel *Bevel1;
    void __fastcall btnAboutClick(TObject *Sender);
    void __fastcall chkVisibleClick(TObject *Sender);
    void __fastcall btnChangeEndpointClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TConfigForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConfigForm *ConfigForm;
//---------------------------------------------------------------------------
#endif
