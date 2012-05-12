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

WinampServer::WinampServer(HWND winamp_hwnd)
{
	// TODO at best a no-op right now, but allows the class to be inserted right now
	setWinampHwnd(winamp_hwnd);
}

WinampServer::~WinampServer()
{
	// delete any owner resources if required
}

string WinampServer::WinampVersion()
{
    return WinampVersionString(QueryInt(IPC_GETVERSION, 0));
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
