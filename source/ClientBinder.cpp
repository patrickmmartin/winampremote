/*
 * ClientBinder.cpp
 *
 *  Created on: 15 Jul 2012
 *      Author: Patrick
 */

#include "ClientBinder.h"

#include "RPCFuncsU.h"

namespace WinampRemote
{
namespace Client
{

ClientBinder::ClientBinder(char * address, char * port)
{
	Bind(address, port);

}

ClientBinder::~ClientBinder()
{
	UnBind();
}

} /* namespace Client */
} /* namespace WinampRemote */
