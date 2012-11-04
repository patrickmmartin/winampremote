
#ifndef rpcthreadH
#define rpcthreadH

#include "ICallObserver.h"

using namespace WinampRemote::Remoting;

class TTestRPCServer
{
public:
    static void Execute();
    static ICallObserver& CallObserver;

};


#endif
