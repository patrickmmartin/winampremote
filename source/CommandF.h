
#ifndef CommandFH
#define CommandFH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>

class TfrmCommands : public TForm
{
__published:	// IDE-managed Components
        TToolBar *tbCommands;
    TToolButton *tbtnPrevious;
    TToolButton *tbtnPlay;
    TToolButton *tbtnPause;
    TToolButton *tbtnStop;
    TToolButton *tbtnNext;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmCommands(TComponent* Owner);
};

extern PACKAGE TfrmCommands *frmCommands;

#endif
