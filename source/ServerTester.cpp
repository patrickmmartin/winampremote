/*
 * ServerTester.cpp
 *
 *  Created on: 12 Feb 2012
 *      Author: Patrick
 */

#include "ServerTester.h"
#include "RPCFuncsU.h"
#include "waint.h"

ServerTester::ServerTester() : FServerMessageEvent(NULL), FServerResultEvent(NULL), FBindProc(NULL)
{
  // constructor

}

ServerTester::~ServerTester()
{
  // destructor
}

void ServerTester::DoMessage(const AnsiString& remoteName,
                             const AnsiString& data,
                            const int level)
{
  if (FServerMessageEvent)
    FServerMessageEvent(remoteName, data, level);
}

void ServerTester::DoResult(const AnsiString& remoteName, const bool success)
{
  if (FServerResultEvent)
    FServerResultEvent(remoteName, success);
}

void ServerTester::DoBind(const AnsiString& node, const AnsiString& endpoint)
{
  if (FBindProc)
    FBindProc(node, endpoint);
}

void ServerTester::testServers(const vector<string>& servers, const AnsiString& endpoint)
{

  // TODO should validate that the various mandatory callbacks are set..
  bool AbortTest = false;

  int retval;

  clock_t start, end;


    for ( int i = 0 ; i < 5 ; i++)
    {
        AnsiString remote = "localhost";

          DoBind(remote, endpoint);
          try
          {
            DoMessage(remote, "beginning", 1);
            DoMessage(remote, "may take some time", 2);
            start = clock();
            retval = IntegerResult("probe from", IPC_GETVERSION, 0);
            end = clock();
            DoMessage(remote, AnsiString().sprintf("response after *.2f", (end - start) / CLK_TCK), 1);
            DoResult(remote, true);
            DoMessage(remote, WinampVersion(retval), 1);

            // TODO: someone needs to be processing the message queue, or we use a different thread....
            if (AbortTest)
              break;
          }
          catch( ERPCException &E)
          {
            DoMessage(remote, AnsiString("failed") + E.Message, 3);
            // TODO fire server event
            DoResult(remote, false);
          }
       }
  }

