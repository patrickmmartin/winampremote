#pragma hdrstop

#include "testimp.h"

#include <iostream>

#pragma argsused
int main(int argc, char* argv[])
{


  std::cout << "testserver starting" << std::endl;

  // we can just have the RPC loop block here, much more directly
  TTestRPCServer::Execute();
  std::cout << "thread exited: testserver exiting" << std::endl;

  return 0;

}

