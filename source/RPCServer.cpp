/*
 * RPCServer.cpp
 *
 *  Created on: 4 Nov 2012
 *      Author: Patrick
 */

#include "RPCServer.h"
#include "RPCErrors.h"

namespace WinampRemote
{
namespace Server
{

RPCServer::RPCServer(WinampRemote::Client::IWinamp * winamp, WinampRemote::Remoting::ICallObserver * callObserver) :
					m_callObserver(), m_winamp()
{

}

RPCServer::~RPCServer()
{
	// TODO: ensure an orderly shutdown or complain?
}

void RPCServer::setCallObserver(WinampRemote::Remoting::ICallObserver * callObserver)
{
	m_callObserver = callObserver;
}

void RPCServer::Execute()
{

	std::string str;
    RPC_STATUS status;
    unsigned char * protocol_seq_np = (unsigned char *) "ncacn_np";
//    unsigned char * protocol_seq_ip_tcp = "ncacn_ip_tcp";

    m_callObserver->notifyStatus("initialising...");

    str = "winamp version : test";

    m_callObserver->notifyMessage(str.c_str());

    // should check status codes here for previously registered interfaces
    // need a property of the appropriate type for the endpoint
    status = RpcServerUseProtseqEp(protocol_seq_np,
                                   20,
                                   (unsigned char *) "\\pipe\\winampremote", NULL);

    if (status == RPC_S_OK){
      status = RpcServerRegisterIf(winamp_v1_0_s_ifspec, NULL, NULL);
      if (status == RPC_S_OK){
    	  m_callObserver->notifyMessage("listening...");
        status = RpcServerListen(1, 20, FALSE);
        if (status != RPC_S_OK){
        	m_callObserver->notifyMessage("error in listening");
        	m_callObserver->notifyMessage(RPCError(status));
          }
        }
    else{
    	m_callObserver->notifyMessage("failed to register interface");
    	m_callObserver->notifyMessage(RPCError(status));
    	m_callObserver->notifyStatus("initialise failed");
      }
    }
  else{
	  m_callObserver->notifyMessage("failed to create protocol sequence");
	  m_callObserver->notifyMessage(RPCError(status));
	  m_callObserver->notifyStatus("initialise failed");
  }

}

} /* namespace Server */
} /* namespace WinampRemote */
