//---------------------------------------------------------------------------
#ifndef ServerFH
#define ServerFH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>

//---------------------------------------------------------------------------

#define WM_THREAD_MESSAGE (WM_APP + 2000)
#define WM_THREAD_STATUS (WM_APP + 2001)

class TfrmMain : public TForm
{
__published:	// IDE-managed Components
        TMemo *memMessages;
        TStatusBar *sbrMain;
    TMainMenu *mnuMain;
    TMenuItem *mnuFile;
    TMenuItem *mnuFileExit;
    TMenuItem *mnuHelp;
    TMenuItem *mnuHelpAbout;
    TMenuItem *mnuView;
    TMenuItem *mnuConfiguration;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall mnuHelpAboutClick(TObject *Sender);
    void __fastcall mnuConfigurationClick(TObject *Sender);
    void __fastcall mnuFileExitClick(TObject *Sender);
protected:
  void __fastcall TfrmMain::ThreadMessage(TMessage &Message);
  void __fastcall TfrmMain::ThreadStatus(TMessage &Message);
BEGIN_MESSAGE_MAP
  MESSAGE_HANDLER(WM_THREAD_MESSAGE, TMessage, ThreadMessage)
  MESSAGE_HANDLER(WM_THREAD_STATUS, TMessage, ThreadStatus)
END_MESSAGE_MAP(TControl)

private:	// User declarations
public:		// User declarations
        __fastcall TfrmMain(TComponent* Owner);
        bool isExe;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
extern HWND mainhwnd;
//---------------------------------------------------------------------------
#endif
