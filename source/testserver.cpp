


#pragma hdrstop

#include "testimp.h"

#include <iostream>






#pragma argsused
int main(int argc, char* argv[])
{


  std::cout << "testserver starting" << std::endl;
  TRPCServerThread * serverThread =  new TRPCServerThread(false);
  std::cout << "thread created: entering wait" << std::endl;

  serverThread->WaitFor();
  std::cout << "thread exited: testserver exiting" << std::endl;

  return 0;

}

