//---------------------------------------------------------------------------


#pragma hdrstop

#include "rpcthread.h"

HWND mainhwnd = 0;


//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{

  TRPCServerThread * serverThread =  new TRPCServerThread(false);

  serverThread->WaitFor();

}
//---------------------------------------------------------------------------
