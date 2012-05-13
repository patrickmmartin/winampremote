
#ifndef rpcthreadH
#define rpcthreadH

#include <Classes.hpp>


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


void __fastcall MainMessage(char * msgString);
void __fastcall MainStatus(char * msgString);



#endif
