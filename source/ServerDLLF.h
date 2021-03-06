
#ifndef ServerDLLFH
#define ServerDLLFH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <checklst.hpp>
#include <ExtCtrls.hpp>
#include <CheckLst.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>

#include "RPCExecutor.h"

using namespace WinampRemote::Server;

const int WM_THREAD_MESSAGE = (WM_APP + 2000);
const int WM_THREAD_STATUS  = (WM_APP + 2001);
const int WM_THREAD_IDENT = (WM_APP + 2002);

const int QUERY_STRING = 0;
const int QUERY_INTEGER = 1;
const int COMMAND_STRING = 2;
const int COMMAND_INTEGER = 3;
const int EXCEPTIONS = 4;


class TfrmPluginMain : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *sbrMain;
    TImageList *imlUsers;
    TTimer *timerMain;
        TPageControl *pgMain;
        TTabSheet *tbsClients;
        TTabSheet *tbsConfig;
        TPanel *pnlMain;
        TListView *lvUsers;
        TBevel *Bevel1;
        TToolBar *tbConfig;
        TToolButton *btnConfig;
        TToolButton *btnAbout;
        TToolButton *ToolButton2;
    void __fastcall FormCreate(TObject *Sender);
    
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    
    void __fastcall FormShow(TObject *Sender);
    void __fastcall timerMainTimer(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall btnConfigClick(TObject *Sender);
        void __fastcall btnAboutClick(TObject *Sender);
protected:
private:	// User declarations
      void __fastcall AppException(TObject *Sender, Exception *E);
protected:


public:		// User declarations
        __fastcall TfrmPluginMain(TComponent* Owner);

      void __fastcall CreateThread();
      void __fastcall StopThread(TObject *Sender);
};

extern PACKAGE TfrmPluginMain *frmPluginMain;


#endif
