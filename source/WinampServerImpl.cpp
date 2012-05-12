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

WinampServer::WinampServer(HWND winamp_hwnd) : m_winamphwnd(winamp_hwnd)
{
}

WinampServer::~WinampServer()
{
	// delete any owned resources if required
}

string WinampServer::WinampVersion()
{
    return WinampVersionString(QueryInt(IPC_GETVERSION, 0));
}

void WinampServer::ExecuteCommand(WinampCommand MessageToExecute)
{
	LocalExecuteCommand(m_winamphwnd, MessageToExecute);
}

void WinampServer::ExecuteStringCommand(char * CommandString, WinampCommand Command)
{
	LocalExecuteStringCommand(m_winamphwnd, CommandString, Command);
}

int WinampServer::QueryInt(WinampCommand Command, int Data)
{
	return LocalQueryInt(m_winamphwnd, Command, Data);
}

string WinampServer::QueryString(WinampCommand Command, int Data)
{
	return LocalQueryString(m_winamphwnd, Command, Data);
}


} /* namespace Server */
} /* namespace WinampRemote */
