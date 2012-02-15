//---------------------------------------------------------------------------
#ifndef ServersFH
#define ServersFH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ExtCtrls.hpp>

#include <vector.h>
//---------------------------------------------------------------------------
class TfrmServers : public TForm
{
__published:	// IDE-managed Components
        TImageList *imlServers;
        TImage *imgWarning;
        TImage *imgError;
        TImage *imgInformation;
        TImageList *imlEvents;
        TPanel *pnlPages;
        TProgressBar *pbServers;
        TPanel *pnlTop;
        TLabel *lblEndPoint;
        TEdit *ebEndPoint;
        TPanel *pnlButtons;
        TButton *btnCancel;
        TButton *btnOK;
        TButton *btnTest;
        TButton *btnLocate;
        TButton *btnGetIp;
        TStatusBar *StatusBar1;
        TListView *lvServers;
        TSplitter *spltMessages;
        TListView *lvMessages;
        void __fastcall btnLocateClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall lvServersClick(TObject *Sender);
        void __fastcall StartTest(TObject *Sender);
        void __fastcall StopTest(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnOKClick(TObject *Sender);
        void __fastcall GetServerIp(TObject *Sender);
        void __fastcall spltMessagesCanResize(TObject *Sender,
          int &NewSize, bool &Accept);
private:	// User declarations

void doNetworkServer(const AnsiString& RemoteName, const AnsiString& Comment);
void doNetworkMessage(const AnsiString& Message, const int Level);
void doNetworkProgress(const float complete);

void doTestEvent(const AnsiString& remoteName,
                 const AnsiString& data,
                 const int level);
void doTestResult(const AnsiString& remoteName,
                  const bool success,
                  bool& abort);

TListItem* findServerItem(const AnsiString& RemoteName);
void TfrmServers::getServers(vector<AnsiString>& servers);

bool AbortTest;
void __fastcall CheckPort(void);


public:		// User declarations
        __fastcall TfrmServers(TComponent* Owner);
        AnsiString EndPoint;
        AnsiString Address;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmServers *frmServers;
//---------------------------------------------------------------------------
#endif
