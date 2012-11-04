#pragma hdrstop

#include "TestRPCServer.h"

#include <iostream>

#pragma argsused
int main(int argc, char* argv[])
{

  std::cout << "testserver starting" << std::endl;

  // for this mock server, no need for another thread, simply block on this
  TTestRPCServer::Execute();
  std::cout << "RPC loop terminated: testserver exiting" << std::endl;

  return 0;

}

