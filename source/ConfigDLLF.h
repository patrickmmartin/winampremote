
#ifndef ConfigDLLFH
#define ConfigDLLFH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>




class TConfigForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *pnlIcon;
    TCheckBox *chkVisible;
    TLabel *lblEndPoint;
    TButton *btnAbout;
        TMemo *memInfo;
        TImage *imgIcon;
        TButton *Details;
	TEdit *ebEndPoint;
    void __fastcall btnAboutClick(TObject *Sender);
    void __fastcall chkVisibleClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
        void __fastcall DetailsClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TConfigForm(TComponent* Owner);
};

extern PACKAGE TConfigForm *ConfigForm;

#endif
