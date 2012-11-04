#pragma hdrstop

#include <iostream>

#include "TestRPCServer.h"

#include "ConsoleCallObserver.h"


#pragma argsused
int main(int argc, char* argv[])
{

  ConsoleCallObserver cco;
  cco.notifyStatus("testserver starting");

  // for this mock server, no need for another thread, simply block on this
  TTestRPCServer::Execute(cco);
  cco.notifyStatus("RPC loop terminated: testserver exiting");

  return 0;

}

