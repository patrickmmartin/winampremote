/*
 * ServerTester.cpp
 *
 *  Created on: 12 Feb 2012
 *      Author: Patrick
 */

#include "ServerTester.h"
#include "RPCFuncsU.h"
#include "waint.h"

ServerTester::ServerTester() : _serverMessageEvent(NULL),
                               _serverResultEvent(NULL),
                               _endPoint("\\pipe\\winampremote"),
                               _abort(false)
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
  if (_serverMessageEvent)
    _serverMessageEvent(remoteName, data, level);
}

void ServerTester::DoResult(const AnsiString& remoteName, const bool success)
{
  if (_serverResultEvent)
    _serverResultEvent(remoteName, success, _abort);
}

void ServerTester::testServers(vector<AnsiString>& servers)
{

  int retval;

  clock_t start, end;

  char title[MAX_PATH] = "";

      for (vector<AnsiString>::iterator i = servers.begin();
           !_abort && (i != servers.end());
           ++i)
        {
          AnsiString remote = *i;

          // static method from RPCFuncs
          Bind(remote.c_str(), _endPoint.c_str());
          try
          {
            DoMessage(remote, "beginning", 1);
            DoMessage(remote, "may take some time", 2);
            start = clock();

            retval = IntegerResult("probe", IPC_GETVERSION, 0);
            StringResult(title, IPC_GETPLAYLISTTITLE, 0);

            end = clock();
            DoMessage(remote, AnsiString().sprintf("response after %.2fs ", (end - start) / CLK_TCK), 1);
            DoResult(remote, true);
            DoMessage(remote, WinampVersionString(retval), 1);
          }
          catch( ERPCException &E)
          {
            DoMessage(remote, AnsiString("failed: " ) + E.Message, 3);
            // TODO fire server event
            DoResult(remote, false);
          }
       }
  }

