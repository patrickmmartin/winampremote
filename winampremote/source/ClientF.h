//---------------------------------------------------------------------------
#ifndef ClientFH
#define ClientFH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
    TMemo *memMessages;
    TButton *btnMessageProc;
    TButton *btnExecuteMessage;
    TButton *btnExecuteStringMessage;
    TButton *btnIntegerResult;
    TButton *btnStringResult;
    TButton *btnShutdown;
    TButton *btnMessageProcLots;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall btnMessageProcClick(TObject *Sender);
    void __fastcall btnExecuteMessageClick(TObject *Sender);
    void __fastcall btnExecuteStringMessageClick(TObject *Sender);
    void __fastcall btnStringResultClick(TObject *Sender);
    void __fastcall btnIntegerResultClick(TObject *Sender);
    void __fastcall btnShutdownClick(TObject *Sender);



    void __fastcall btnMessageProcLotsClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmMain(TComponent* Owner);
};

void AddMessage(char * pszString);
//void SendString(unsigned char * pszString);
//void SendShutdown(void);


/* this binds to the interface before the RPC call*/
void Bind(void);
void UnBind(void);
void MessageProc(unsigned char * pszString);
void ExecuteMessage(unsigned char * pszString, int command);
void ExecuteStringMessage(unsigned char * pszString, unsigned char * pszParam, int command, int data);
int StringResult(unsigned char * pszString, int command, int data);
int IntegerResult(unsigned char * pszString, int command, int data);
//void Shutdown(void);


void  __RPC_FAR * __RPC_USER midl_user_allocate(size_t len);
void __RPC_USER midl_user_free(void __RPC_FAR * ptr);


//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
