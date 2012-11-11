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

namespace WinampRemote
{
namespace Server
{

/**
 * Class to wrap up handling the RPC runtime call-backs.
 * The RPC functions are linked in statically as a link demand from the
 * generated stubs.
 * The handler for the winamp methods implements generic behaviour,
 * and for different implementations the correct handler needs to be
 * invoked for the mocked winamp or the actual winamp process
 */
class RPCExecutor
{
private:
	WinampRemote::Server::IWinampServer * m_winamp;
	WinampRemote::Remoting::ICallObserver * m_callObserver;
public:
	/**
	 * constructor
	 */
	RPCExecutor();
	/**
	 * virtual destructor
	 */
	virtual ~RPCExecutor();

	/**
	 *  return the winamp server instance
	 * @see IWinampServer
	 * @return the server instance
	 */
	virtual WinampRemote::Server::IWinampServer * getWinampServer();

	/**
	 * sets the winamp server implementation
	 * @see IWinampServer
	 * @param winampServer
	 */
	virtual void setWinampServer(WinampRemote::Server::IWinampServer * winampServer);

	/**
	 * return the call observer instance
	 * @see ICallObserver
	 * @return the observer
	 */
	virtual WinampRemote::Remoting::ICallObserver * getCallObserver();

	/**
	 * sets the call observer for the instance
	 * @see ICallObserver
	 * @param callObserver
	 */
	virtual void setCallObserver(WinampRemote::Remoting::ICallObserver * callObserver);

	/**
	 * execute function - sets up and begins the main loop
	 */
	virtual void Execute();

	/**
	 * returns a singleton instance of RPCExecutor
	 * @return the instance
	 */
	static RPCExecutor& instance();

};

} /* namespace Server */
} /* namespace WinampRemote */
#endif /* RPCSERVER_H_ */
