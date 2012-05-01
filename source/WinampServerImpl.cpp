/*
 * WinampServerImpl.cpp
 *
 *  Created on: 1 May 2012
 *      Author: Patrick
 */

#include "WinampServerImpl.h"

namespace WinampRemote
{
namespace Server
{

WinampServer::WinampServer()
{
	// TODO Auto-generated constructor stub

}

WinampServer::~WinampServer()
{
	// TODO Auto-generated destructor stub
}


void WinampServer::ExecuteCommand(WinampCommand MessageToExecute)
{
	LocalExecuteCommand(MessageToExecute);
}

void WinampServer::ExecuteStringCommand(char * CommandString, WinampCommand Command)
{
	LocalExecuteStringCommand(CommandString, Command);
}

int WinampServer::QueryInt(WinampCommand Command, int Data)
{
	return LocalQueryInt(Command, Data);
}

string WinampServer::QueryString(WinampCommand Command, int Data)
{
	return LocalQueryString(Command, Data);
}


} /* namespace Server */
} /* namespace WinampRemote */
