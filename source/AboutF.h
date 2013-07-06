
#ifndef AboutFH
#define AboutFH

#include <Forms.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>

#include "AboutGLDisplay.h"

class TfrmAbout : public TForm
{
__published:	// IDE-managed Components
        TPanel *TheControl;
        TTimer *tmrMain;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall FormKeyPress(TObject *Sender, char &Key);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    
    void __fastcall IdleHandler(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations

  HDC hDC;
  HPALETTE hPalette;

  void resize();
  void redraw();

  AboutGLDisplay* m_aboutDisplay;

protected:
  void __fastcall WMPaletteChanged(TMessage& Msg);
  void __fastcall WMQueryNewPalette(TMessage& Msg);

public:		// User declarations
    __fastcall TfrmAbout(TComponent* Owner);

BEGIN_MESSAGE_MAP
MESSAGE_HANDLER(WM_PALETTECHANGED,TMessage,WMPaletteChanged)
MESSAGE_HANDLER(WM_QUERYNEWPALETTE,TMessage,WMQueryNewPalette)
END_MESSAGE_MAP(TForm)

};

extern PACKAGE TfrmAbout *frmAbout;



#endif
