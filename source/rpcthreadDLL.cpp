/*
winamp remote control suite ©Patrick Michael Martin 2000, 2001, 2002

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

// bring in the Winamp interfaces
#include "WinampServerImpl.h"

#include "gen_plugin.h"

#include "CallReflector.h"

#include "RPCExecutor.h"

using namespace WinampRemote::Server;

void __fastcall MainMessage(char * msgString);
static void inline MainStatus(WAExecutionStatus Status);



WinampRemote::Server::IWinampServer * localWinamp = NULL;

using namespace WinampRemote::Remoting;

class StubCallObserver : public ICallObserver  {

    public:

    virtual ~StubCallObserver() {};

    virtual void notifyStatus(const char * status){
    }

    virtual void notifyMessage(const char * msg){
    }

    virtual void notifyException(const char * msg){
    }

};


TRTLCriticalSection fCriticalSection ;

// here follow the previously prototyped functions implemented

__fastcall TRPCServerDLLThread::TRPCServerDLLThread(bool CreateSuspended, HWND mainhwnd, const char * protocolSequence)
    : TThread(CreateSuspended), m_mainhwnd(mainhwnd), m_protocolSequence(protocolSequence)
{
}



void __fastcall TRPCServerDLLThread::Execute()
{
	  // supply the in-process winamp implementation
	  WinampRemote::Server::WinampServer localWinamp(plugin.hwndParent);
	  // TODO: implement notification to the UI
	  StubCallObserver observer;

	  observer.notifyStatus("testserver starting");

	  // for this mock server, no need for another thread, simply block on this
	  WinampRemote::Server::RPCExecutor::instance().setWinampServer(&localWinamp);
	  WinampRemote::Server::RPCExecutor::instance().setCallObserver(&observer);
	  WinampRemote::Server::RPCExecutor::instance().Execute();

}

void __fastcall MainMessage(char * msgString)
{
  TRPCServerDLLThread::CallObserver.notifyMessage(msgString);
}



static void inline MainStatus(WAExecutionStatus Status)
{
  char * statusStrings[] =
  	  	  	  	  	  {"Server Starting",
                       "Server Started",
                       "Listening",
                       "Executing",
                       "Server Stopped",
                       "Initialise Failed"};

  std::string statusStr = "status: ";
  statusStr += statusStrings[Status];
  TRPCServerDLLThread::CallObserver.notifyStatus(statusStr.c_str());
}



void TRPCServerDLLThread::MainIdent(char * msgString)
{
  PostMessage(m_mainhwnd, WM_THREAD_IDENT, 0, (long) strdup(msgString));
}

WinampRemote::Remoting::CallReflector cr;
ICallObserver& TRPCServerDLLThread::CallObserver = cr;

