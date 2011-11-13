//---------------------------------------------------------------------------
#ifndef ServerDLLFH
#define ServerDLLFH
//---------------------------------------------------------------------------
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

#include "gen_plugin.h"         //config()
#include "waint.h"            //FAIL_TIMEOUT
#include "rpcthreadDLL.h"       //TRPCServerThread


//---------------------------------------------------------------------------


const int WM_THREAD_MESSAGE = (WM_APP + 2000);
const int WM_THREAD_STATUS  = (WM_APP + 2001);
const int WM_THREAD_IDENT = (WM_APP + 2002);

const int QUERY_STRING = 0;
const int QUERY_INTEGER = 1;
const int COMMAND_STRING = 2;
const int COMMAND_INTEGER = 3;
const int EXCEPTIONS = 4;


class TfrmMain : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *sbrMain;
    TImageList *imlUsers;
    TTimer *timerMain;
        TPageControl *pgMain;
        TTabSheet *tbsMessages;
        TLabel *lblMessages;
        TListBox *lstMessages;
        TTabSheet *tbsClients;
        TTabSheet *tbsConfig;
        TLabel *lblItems;
        TCheckListBox *chkListEvents;
        TLabel *lblClients;
        TPanel *pnlMain;
        TListView *lvUsers;
        TBevel *Bevel1;
        TButton *btnConfig;
    void __fastcall FormCreate(TObject *Sender);

    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall chkListEventsClickCheck(TObject *Sender);

    void __fastcall FormShow(TObject *Sender);
    void __fastcall timerMainTimer(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall btnConfigClick(TObject *Sender);
protected:
  void __fastcall TfrmMain::ThreadMessage(TMessage &Message);
  void __fastcall TfrmMain::ThreadStatus(TMessage &Message);
  void __fastcall TfrmMain::ThreadIdent(TMessage &Message);
BEGIN_MESSAGE_MAP
  MESSAGE_HANDLER(WM_THREAD_MESSAGE, TMessage, ThreadMessage)
  MESSAGE_HANDLER(WM_THREAD_STATUS, TMessage, ThreadStatus)
  MESSAGE_HANDLER(WM_THREAD_IDENT, TMessage, ThreadIdent)
END_MESSAGE_MAP(TControl)

private:	// User declarations
      void __fastcall AppException(TObject *Sender, Exception *E);
public:		// User declarations
      TRPCServerThread * serverThread;
        __fastcall TfrmMain(TComponent* Owner);
      int EndPoint;
      bool requestlog[5];
      void __fastcall CreateThread(TObject *Sender);
      void __fastcall StopThread(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;

//---------------------------------------------------------------------------
#endif
