/*
 * CallReflector.cpp
 *
 *  Created on: 13 May 2012
 *      Author: Patrick
 */

#include "CallReflector.h"

namespace WinampRemote
{
namespace Remoting
{

void CallReflector::notifyStatus(const char * status)
{
	// TODO: this needs to be threadsafe, or the recipient is
	if (_statusEvent)
		_statusEvent(status);
}

void CallReflector::notifyMessage(const char * msg)
{
	// TODO: this needs to be threadsafe, or the recipient is
	if (_infoEvent)
		_infoEvent(msg);
}


} /* namespace Remoting */
} /* namespace WinampRemote */
