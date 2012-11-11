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
	if (_statusEvent)
		_statusEvent(status);
}

void CallReflector::notifyMessage(const char * msg)
{
	if (_infoEvent)
		_infoEvent(msg);
}

void CallReflector::notifyException(const char * msg)
{
	// TODO implement
}


} /* namespace Remoting */
} /* namespace WinampRemote */
