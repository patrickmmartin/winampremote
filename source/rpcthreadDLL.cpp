/*
winamp remote control suite �Patrick Michael Martin 2000, 2001, 2002

Copyright (C) 2000,2001,2002  Patrick M. Martin

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Patrick M. Martin may be reached by email at patrickmmartin@gmail.com.
*/

#include <vcl.h>
#pragma hdrstop
#include <malloc.h>
#include <stdio.h>

#include "rpcthreadDLL.h"
#pragma package(smart_init)

// winamp interface definitions
#include "waint.h"

// call observer interface
#include "ICallObserver.h"

// bring in the Winamp interfaces
#include "WinampServerImpl.h"

#include "RPCExecutor.h"

using namespace WinampRemote::Server;

WinampRemote::Server::IWinampServer * localWinamp = NULL;

using namespace WinampRemote::Remoting;

__fastcall TRPCServerDLLThread::TRPCServerDLLThread(bool CreateSuspended, HWND pluginhwnd, const char * protocolSequence)
    : TThread(CreateSuspended), m_pluginhwnd(pluginhwnd), m_protocolSequence(protocolSequence)
{
}

void __fastcall TRPCServerDLLThread::Execute()
{
	  // supply the in-process winamp implementation
	  WinampRemote::Server::WinampServer localWinamp(m_pluginhwnd);
	  // TODO: implement notification to the UI
	  StubCallObserver observer;

	  observer.notifyStatus("testserver starting");

	  // for this server, no need for another thread, simply block on this
	  RPCExecutor &executor = WinampRemote::Server::RPCExecutor::instance();
	  executor.setWinampServer(&localWinamp);
	  executor.setCallObserver(&observer);
	  executor.Execute();

}
