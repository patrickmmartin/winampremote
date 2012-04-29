//---------------------------------------------------------------------------
#ifndef rpcthreadH
#define rpcthreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------

 #include "ICallObserver.h"

using namespace WinampRemote::Remoting;


class TRPCServerThread : public TThread
{
private:
protected:
    void __fastcall Execute();
public:
    __fastcall TRPCServerThread(bool CreateSuspended);
    static ICallObserver& CallObserver;

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

long WAIntegerResult(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    int command,
    int data);

long WAStringResult(
    /* [size_is][string][out][in] */ unsigned char __RPC_FAR *pszString,
    int command,
    int data);

void WAShutdown( void);



void __fastcall MainMessage(char * msgString);
void __fastcall MainStatus(char * msgString);


//---------------------------------------------------------------------------
#endif
