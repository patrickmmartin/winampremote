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
        TPageControl *pgcServers;
        TTabSheet *tbsServers;
        TListView *lvServers;
        TTabSheet *tbsMessages;
        TListView *lvMessages;
        TPanel *pnlTop;
        TLabel *lblEndPoint;
        TEdit *ebEndPoint;
        TPanel *pnlButtons;
        TButton *btnCancel;
        TButton *btnOK;
        TButton *btnTest;
        TButton *btnLocate;
        TButton *btnGetIp;
        void __fastcall btnLocateClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall lstMessagesMeasureItem(TWinControl *Control,
          int Index, int &Height);
        void __fastcall lstMessagesDrawItem(TWinControl *Control,
          int Index, TRect &Rect, TOwnerDrawState State);
        void __fastcall lvServersClick(TObject *Sender);
        void __fastcall StartTest(TObject *Sender);
        void __fastcall StopTest(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnOKClick(TObject *Sender);
        void __fastcall GetServerIp(TObject *Sender);
private:	// User declarations

void __fastcall NetErrorHandler(DWORD dwErrorCode, AnsiString Function);
void __fastcall DisplayStruct(LPNETRESOURCE NetResource);
BOOL __fastcall EnumerateFunc(LPNETRESOURCE lpnr);
void __fastcall AddServer(char * RemoteName, char * Comment);
void __fastcall AddMessage(AnsiString Message, int Level);
bool AbortTest;
int ResourcesEnumerated;
int ResourcesToEnumerate;
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
