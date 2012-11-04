/*
 * RPCServer.h
 *
 *  Created on: 4 Nov 2012
 *      Author: Patrick
 */

#ifndef RPCSERVER_H_
#define RPCSERVER_H_


#include "IWinamp.h"
#include "ICallObserver.h"

#include "IRPCServer.h"

namespace WinampRemote
{
namespace Server
{

/**
 * Class to wrap up handling the RPC runtime call-backs.
 * The RPC functions are linked in statically as a link demand from the
 * generated stubs, for generic behaviour, the correct handler needs to be
 * invoked for the mocked winamp or the actual winamp process
 */
class RPCServer : public IRPCServer
{
private:
	WinampRemote::Client::IWinamp * m_winamp;
	WinampRemote::Remoting::ICallObserver * m_callObserver;
public:
	/**
	 * constructor - requires a valid winamp handler and optional
	 * observer for call events
	 * @param winamp
	 * @param callObserver
	 */
	RPCServer(WinampRemote::Client::IWinamp * winamp, WinampRemote::Remoting::ICallObserver * callObserver);
	/**
	 * virtual destructor
	 */
	virtual ~RPCServer();

	/**
	 * sets the call observer for the instance
	 * @param callObserver
	 */
	virtual void setCallObserver(WinampRemote::Remoting::ICallObserver * callObserver);
	/**
	 * execute function - sets up and begins the main loop
	 */
	virtual void Execute();

};

} /* namespace Server */
} /* namespace WinampRemote */
#endif /* RPCSERVER_H_ */
