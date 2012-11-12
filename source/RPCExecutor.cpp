/*
 * RPCServer.cpp
 *
 *  Created on: 4 Nov 2012
 *      Author: Patrick
 */

#include "RPCExecutor.h"
#include "RPCErrors.h"

// problem with definition of __try - this gets round out with no problems
#define __try try

#include "winampinterface.h"    // header file generated by MIDL compiler

// winamp interface
#include "waint.h"

//RPC errors
#include "RPCErrors.h"

#include "RPCExecutor.h"

#include <sstream>

using namespace std;

namespace WinampRemote
{
namespace Server
{

RPCExecutor::RPCExecutor() : m_callObserver(), m_winamp(),
							 m_protocolSequence("ncacn_np"),
							 m_endPoint("\\pipe\\winampremote")
{

}

RPCExecutor::~RPCExecutor()
{
	// as Execute blocks, given destruction happens on the same thread
	// no need to ensure shutdown was happened
}

RPCExecutor& RPCExecutor::instance()
{
	static RPCExecutor instance;

	return instance;
}

WinampRemote::Server::IWinampServer * RPCExecutor::getWinampServer()
{
	return m_winamp;
}


void RPCExecutor::setWinampServer(WinampRemote::Server::IWinampServer * winampServer)
{
	m_winamp = winampServer;
}

WinampRemote::Remoting::ICallObserver * RPCExecutor::getCallObserver()
{
	return m_callObserver;
}

void RPCExecutor::setCallObserver(WinampRemote::Remoting::ICallObserver * callObserver)
{
	m_callObserver = callObserver;
}

void RPCExecutor::Execute()
{
	// tempting to throw an exception here
	if (!m_callObserver)
		return;
	if (!m_winamp)
	{
		m_callObserver->notifyException("winamp implementation is not set");
		return;
	}

	std::string str;
    RPC_STATUS status;
    // "ncacn_np" for named pip
    // "ncacn_ip_tcp" for tcpip

    m_callObserver->notifyStatus("initialising...");

    m_callObserver->notifyMessage(m_winamp->WinampVersion().c_str());

    // TODO: need a property of the appropriate type for the endpoint
    status = RpcServerUseProtseqEp((unsigned char *) m_protocolSequence.c_str(),
                                   20,
                                   (unsigned char *) m_endPoint.c_str(),
                                   NULL);

    if (status == RPC_S_OK){
      status = RpcServerRegisterIf(winamp_v1_0_s_ifspec, NULL, NULL);
      if (status == RPC_S_OK){
    	  m_callObserver->notifyMessage("listening...");
        status = RpcServerListen(1, 20, FALSE);
        if (status != RPC_S_OK){
        	m_callObserver->notifyException("error in listening");
        	m_callObserver->notifyException(RPCError(status));
          }
        }
    else{
    	m_callObserver->notifyException("failed to register interface");
    	m_callObserver->notifyException(RPCError(status));
    	m_callObserver->notifyException("initialise failed");
      }
    }
  else{
	  m_callObserver->notifyException("failed to create protocol sequence");
	  m_callObserver->notifyException(RPCError(status));
	  m_callObserver->notifyException("initialise failed");
  }

}

} /* namespace Server */
} /* namespace WinampRemote */


static void inline MainMessage(const char * msgString)
{
	WinampRemote::Server::RPCExecutor::instance().getCallObserver()->notifyMessage(msgString);
}

static void inline MainStatus(const char * msgString)
{
	WinampRemote::Server::RPCExecutor::instance().getCallObserver()->notifyStatus(msgString);
}

static WinampRemote::Server::IWinampServer * winampServer()
{
   return WinampRemote::Server::RPCExecutor::instance().getWinampServer();
}

string queryLogFormat(char * strSender, long command, long data)
{

	stringstream sstr;
	sstr.str() = strSender;
	sstr << " sent  - query : " << WinampCommandDesc(command) << " - data : " << data;
	return sstr.str();

}

string commandLogFormat(char * strSender, long command, char * strParam = NULL)
{
	  stringstream sstr;
	  sstr.str() = (char *) strSender;
	  sstr << " sent  - command : " << WinampCommandDesc(command) << " - parameter : " << strParam;
	  return sstr.str();
}


/* __RPC_FAR is literally nothing, but is left in for consistency
- none of the MIDL generated code should need direct modification*/

void WAMessageProc(
    /* [string][in] */ unsigned char __RPC_FAR *pszString)
{

  std::string str = (char *) pszString;
  str += " sent hello";
  MainMessage(str.c_str());
  // TODO: need to implement WAExecutionStatus report status
  // MainStatus(waListening);

  // TODO: notification for exceptions

}


void WAExecuteMessage(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [in] */ long command)
{

  MainMessage( commandLogFormat(pszString, command).c_str());
  winampServer()->ExecuteCommand( static_cast<WinampCommand>(command) );
  // TODO: need to implement WAExecutionStatus report status
  // MainStatus(waListening);

  // TODO: notification for exceptions

}

void WAExecuteMessageString(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [string][in] */ unsigned char __RPC_FAR *pszParam,
    /* [in] */ long command)
{

	MainMessage( commandLogFormat(pszString, command, pszParam).c_str());
	// TODO: eliminate the cast
	winampServer()->ExecuteStringCommand((const char *) pszParam, static_cast<WinampCommand>(command) );
	// TODO: need to implement WAExecutionStatus report status
	// MainStatus(waListening);

	// TODO: notification for exceptions


}

long WAIntegerResult(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [in] */ long command,
    /* [in] */ long data)
{

	MainMessage( queryLogFormat(pszString, command, data).c_str());

	return winampServer()->QueryInt( (WinampCommand) command, data);
	// TODO: need to implement WAExecutionStatus report status
	// MainStatus(waListening);

	// TODO: notification for exceptions

}

long WAStringResult(
    /* [string][out][in] */ unsigned char __RPC_FAR pszString[ 260 ],
    /* [in] */ long command,
    /* [in] */ long data)
{

  MainMessage( queryLogFormat(pszString, command, data).c_str());

  std::string str  = winampServer()->QueryString( static_cast<WinampCommand>(command), data).c_str();

  strcpy((char *) pszString, str.c_str());
  // TODO: need to implement WAExecutionStatus report status
  // MainStatus(waListening);

  // TODO: notification for exceptions

  // TODO: this obviously achieves nothing
  return 0;

}

// new functions

void WASetStringList(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [in][size_is] */ byte __RPC_FAR Buffer[  ],
    /* [in] */ unsigned long BufferLength,
    /* [in] */ long command)
{

	// TODO: implement logging
	stringstream sstr;
	sstr.str() = (char *) Buffer;
	string line;
	while (std::getline(sstr, line))
	{
		winampServer()->ExecuteStringCommand(line.c_str(), static_cast<WinampCommand>(command));
	}


	MainStatus("listening...");
	// TODO: need to implement WAExecutionStatus report status
	// MainStatus(waListening);

	// TODO: notification for exceptions

}


inline static void populateBuffer(BUFFER * pBuffer, std::string& buffer)
{

	pBuffer->BufferLength = 0;
	int strlen = buffer.size();
	// TODO check this results in the RPC RT returning the memory
	pBuffer->Buffer = (byte *) MIDL_user_allocate (strlen +1);
	if (pBuffer->Buffer)
	{
		pBuffer->BufferLength = strlen + 1;
		memcpy(pBuffer->Buffer, buffer.c_str(), pBuffer->BufferLength);
	}

}

void WAGetStringList(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [out] */ BUFFER __RPC_FAR *pBuffer,
    /* [in] */ long command)
{


	std::stringstream list;
	for (int i = 0 ; i < 20; i++ )
	{
		if (i)
			list << std::endl;
		list << "string #" << i;
	}

	populateBuffer(pBuffer, list.str());
  // TODO: no logging at all here
	MainStatus("listening...");
	// TODO: need to implement WAExecutionStatus report status
	// MainStatus(waListening);

	// TODO: notification for exceptions

}


void WAGetStringDataList(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [out] */ BUFFER __RPC_FAR *pBuffer,
    /* [in] */ long stringcommand,
    /* [in] */ long datacommand,
    /* [in] */ long datadata)
{

	std::stringstream list;
	for (int i = 0 ; i < 20; i++ )
	{
		if (i)
			list << std::endl;
		list << "string #" << i << std::endl;
		list << "value #" << i;
	}

	populateBuffer(pBuffer, list.str());
	MainStatus("listening...");
	// TODO: need to implement WAExecutionStatus report status
	// MainStatus(waListening);

	// TODO: notification for exceptions

}


void WAShutdown(void)
{
    RpcMgmtStopServerListening(NULL);
    RpcServerUnregisterIf(NULL, NULL, FALSE);
    MainStatus("not listening");
    MainMessage("asked to close");
	// TODO: need to implement WAExecutionStatus report status
	// MainStatus(waListening);

	// TODO: notification for exceptions
}



