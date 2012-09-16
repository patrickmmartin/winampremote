
#ifndef messageFH
#define messageFH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>

class TfrmMessage : public TForm
{
__published:	// IDE-managed Components
        TTimer *tmrAnimate;
        TPanel *pnlMain;
        TImage *imgIcon;
        TMemo *memMessage;
        TMemo *memTitle;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall tmrAnimateTimer(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
  int StartCount;
public:		// User declarations
virtual __fastcall TfrmMessage(TComponent* Owner);
};

extern PACKAGE TfrmMessage *frmMessage;

#endif
