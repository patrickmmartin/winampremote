
#ifndef rpcthreadDLLH
#define rpcthreadDLLH

#include <Classes.hpp>



// problem with definition of __try - this gets round without too many issues
#define __try try
#include "winampinterface.h"    // header file generated by MIDL compiler
#include "ServerDLLF.h"         // WAExecutionStatus

// bring the Winamp interfaces
#include "WinampServerImpl.h"

#include "ICallObserver.h"

using namespace WinampRemote::Remoting;

class TRPCServerDLLThread : public TThread
{
protected:
    void __fastcall Execute();
public:
    __fastcall TRPCServerDLLThread(bool CreateSuspended);
    AnsiString Endpoint;
    static ICallObserver& CallObserver;


};


extern TRPCServerDLLThread *serverThread;


#endif
