#pragma hdrstop

#include "RPCExecutor.h"

#include "WinampTestServer.h"
#include "ConsoleCallObserver.h"

#pragma argsused
int main(int argc, char* argv[])
{

  WinampRemote::Remoting::ConsoleCallObserver cco;

  // this code is only used in the out of process test process
  WinampRemote::Server::WinampTestServer localWinamp;

  cco.notifyStatus("testserver starting");

  // for this mock server, no need for another thread, simply block on this
  WinampRemote::Server::RPCExecutor::instance().setWinampServer(&localWinamp);
  WinampRemote::Server::RPCExecutor::instance().setCallObserver(&cco);
  WinampRemote::Server::RPCExecutor::instance().Execute();
  cco.notifyStatus("RPC loop terminated: testserver exiting");

  return 0;

}

