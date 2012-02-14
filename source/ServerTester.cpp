/*
 * ServerTester.cpp
 *
 *  Created on: 12 Feb 2012
 *      Author: Patrick
 */

#include "ServerTester.h"
#include "RPCFuncsU.h"
#include "waint.h"

ServerTester::ServerTester() : FServerMessageEvent(NULL), FServerResultEvent(NULL)
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

void ServerTester::testServers(vector<AnsiString>& servers, const AnsiString& endpoint)
{

  // TODO should validate that the various mandatory callbacks are set..
  bool AbortTest = false;

  int retval;

  clock_t start, end;

      for (vector<AnsiString>::iterator i = servers.begin();
                                 i != servers.end();
                                 ++i)
        {
          AnsiString remote = *i;

          // static method from RPCFuncs
          Bind(remote.c_str(), endpoint.c_str());
          try
          {
            DoMessage(remote, "beginning", 1);
            DoMessage(remote, "may take some time", 2);
            start = clock();
            // static method from RPCFuncs
            retval = IntegerResult("probe from", IPC_GETVERSION, 0);
            end = clock();
            DoMessage(remote, AnsiString().sprintf("response after %.2fs ", (end - start) / CLK_TCK), 1);
            DoResult(remote, true);
            DoMessage(remote, WinampVersion(retval), 1);

            // TODO: someone needs to be processing the message queue, or we use a different thread....
            if (AbortTest)
              break;
          }
          catch( ERPCException &E)
          {
            DoMessage(remote, AnsiString("failed: " ) + E.Message, 3);
            // TODO fire server event
            DoResult(remote, false);
          }
       }
  }

