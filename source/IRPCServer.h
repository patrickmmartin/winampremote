/*
 * IRPCServer.h
 *
 *  Created on: 4 Nov 2012
 *      Author: Patrick
 */

#ifndef IRPCSERVER_H_
#define IRPCSERVER_H_

#include "IWinamp.h"
#include "ICallObserver.h"

namespace WinampRemote
{
namespace Server
{

/**
 * class to wrap up handling the RPC runtime call-backs
 */
class IRPCServer
{
public:
	virtual ~IRPCServer();

	virtual void setCallObserver(WinampRemote::Remoting::ICallObserver * callObserver) = 0;
	virtual void Execute() = 0;

};

} /* namespace Server */
} /* namespace WinampRemote */


#endif /* IRPCSERVER_H_ */
