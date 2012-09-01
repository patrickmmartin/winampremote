/*
 * ClientBinder.cpp
 *
 *  Created on: 15 Jul 2012
 *      Author: Patrick
 */

#include "ClientBinder.h"

#include "RPCFuncsU.h" // TODO: only needed for Bind()

namespace WinampRemote
{
namespace Client
{

ClientBinder::ClientBinder(const char * address, const char * port)
{
	Bind(address, port);

}

ClientBinder::~ClientBinder()
{
	UnBind();
}

} /* namespace Client */
} /* namespace WinampRemote */
