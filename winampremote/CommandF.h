//---------------------------------------------------------------------------
#ifndef CommandFH
#define CommandFH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TfrmCommands : public TForm
{
__published:	// IDE-managed Components
        TToolBar *tbCommands;
    TToolButton *tbtnPrevious;
    TToolButton *tbtnPlay;
    TToolButton *tbtnPause;
    TToolButton *tbtnStop;
    TToolButton *tbtnNext;
    void __fastcall tbtnPreviousClick(TObject *Sender);
    void __fastcall tbtnPlayClick(TObject *Sender);
    void __fastcall tbtnPauseClick(TObject *Sender);
    void __fastcall tbtnStopClick(TObject *Sender);
    void __fastcall tbtnNextClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmCommands(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCommands *frmCommands;
//---------------------------------------------------------------------------
#endif
