//---------------------------------------------------------------------------
#ifndef rpcthreadH
#define rpcthreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TRPCServerThread : public TThread
{
private:
protected:
    void __fastcall Execute();
public:
    __fastcall TRPCServerThread(bool CreateSuspended);
};


/*the actual RPC interface procedures*/

void WAMessageProc(
    /* [string][out][in] */ unsigned char __RPC_FAR *pszString);

void WAExecuteMessage(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [in] */ int command);

void WAExecuteMessageString(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [string][in] */ unsigned char __RPC_FAR *pszParam,
    /* [in] */ int command);

int WAIntegerResult(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    int command,
    int data);

int WAStringResult(
    /* [size_is][string][out][in] */ unsigned char __RPC_FAR *pszString,
    int command,
    int data);

void WAShutdown( void);



void __fastcall MainMessage(char * msgString);
void __fastcall MainStatus(char * msgString);


//---------------------------------------------------------------------------
#endif
