
#ifndef rpcthreadH
#define rpcthreadH

#include "ICallObserver.h"

using namespace WinampRemote::Remoting;

/**
 * class to implement the mock test functionality
 */
class TTestRPCServer
{

public:
	static void resetStubObserver();

    static void Execute(ICallObserver& callObserver);

	/**
	 * stub implementation of ICallObserver that does nothing
	 */
    class StubCallObserver : public ICallObserver  {
	public:
		virtual ~StubCallObserver() {};
		virtual void notifyStatus(const char * status){ }
		virtual void notifyMessage(const char * msg){ }

	};
};


#endif
