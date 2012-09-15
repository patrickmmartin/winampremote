/*
 * ClientBinder.cpp
 *
 *  Created on: 15 Jul 2012
 *      Author: Patrick
 */

#include "ClientBinder.h"

#include "RPCBind.h"


namespace WinampRemote
{
namespace Client
{

ClientBinder::ClientBinder(const char * address, const char * port)
{
	Bind(address, port, pszProtocolSequenceNP);

}

ClientBinder::~ClientBinder()
{
	UnBind();
}

} /* namespace Client */
} /* namespace WinampRemote */
