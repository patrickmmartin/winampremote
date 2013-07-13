
#ifndef SettingsFH
#define SettingsFH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include "IWinamp.h"

class TfrmSettings : public TForm
{
__published:	// IDE-managed Components
        TPageControl *pgcSettings;
        TTabSheet *tbsVol;
        TTabSheet *tbsEQ;
        TTrackBar *TrackBar1;
        TTrackBar *TrackBar2;
        TTrackBar *TrackBar3;
        TTrackBar *TrackBar4;
        TTrackBar *TrackBar5;
        TTrackBar *TrackBar6;
        TTrackBar *TrackBar7;
        TTrackBar *TrackBar8;
        TTrackBar *TrackBar9;
        TTrackBar *TrackBar10;
        TTrackBar *TrackBar11;
        TLabel *lblPreamp;
        TLabel *lblEQ;
        TLabel *lblVol;
        TLabel *lblBal;
        TTrackBar *tbVolume;
        TTrackBar *tbBalance;
        TBevel *bvlVolume;
        TBevel *bvlEQ;
        TToolBar *tbEQ;
        TToolButton *btnAutoload;
        TToolButton *btnEQOn;
    void __fastcall tbVolumeChange(TObject *Sender);
    void __fastcall tbBalanceChange(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall BarsChange(TObject *Sender);
        void __fastcall FormStartDock(TObject *Sender,
          TDragDockObject *&DragObject);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    TList * Bars;
public:		// User declarations
    __fastcall TfrmSettings(TComponent* Owner);
   void __fastcall UpdateBars(void);

};

extern PACKAGE TfrmSettings *frmSettings;

#endif
