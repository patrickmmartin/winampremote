//---------------------------------------------------------------------------
#ifndef AboutFH
#define AboutFH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>

//---------------------------------------------------------------------------


class TfrmAbout : public TForm
{
__published:	// IDE-managed Componentsvoid __fastcall FormShow(TObject *Sender);
    TTimer *Timer1;
    TPanel *TheControl;
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
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormKeyPress(TObject *Sender, char &Key);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    
    void __fastcall IdleHandler(TObject *Sender);
        
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormHide(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations

  void CreateFontList(void);
  void CreateDisplayLists(void);
  void drawText(void);
  void drawCube(void);
  void drawTorus(void);
  void drawSphere(void);
  void setCheckTexture(void);
  void setProjection(void);
  void setMaterial();
  void init(void);
  void resize(void);
  void doRedraw(void);
  void idleRedraw(void);
  void redraw(void);
  void ptov(int x, int y, int width, int height, float v[3]);
  void startMotion(DWORD time, int button, int x, int y);
  void stopMotion(DWORD time, int button, int x, int y);
  void trackMotion(DWORD time, int x, int y);
  void setupPalette(HDC hDC);
  void setupPixelformat(HDC hDC);

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
//---------------------------------------------------------------------------
extern PACKAGE TfrmAbout *frmAbout;
extern TStringList *OutText;


//---------------------------------------------------------------------------
#endif
