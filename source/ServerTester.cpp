/*
 * ServerTester.cpp
 *
 *  Created on: 12 Feb 2012
 *      Author: Patrick
 */

#include "ServerTester.h"
#include "RPCBind.h"
#include "RPCException.h"
#include "waint.h"
#include "WinampClientBase.h"

ServerTester::ServerTester() : _serverMessageEvent(NULL),
                               _serverResultEvent(NULL),
                               _endPoint("\\pipe\\winampremote"),
                               _abort(false),
                               OnResult(NULL), OnTest(NULL)

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

void ServerTester::testServers(map<AnsiString, ServerInfo>& servers)
{

      for (map<AnsiString, ServerInfo>::iterator i = servers.begin();
           !_abort && (i != servers.end());
           ++i)
        {
          pair<AnsiString, ServerInfo> remote = *i;
          testServer(remote.first, remote.second);

       }
  }

void ServerTester::testServer(const AnsiString& remote, ServerInfo& serverInfo)
{
	 int retval;

	clock_t start, end;
	bool result = false;
	string versionString;

    // static method from RPCFuncs
    Bind(remote.c_str(), _endPoint.c_str(), pszProtocolSequenceNP);
    try
    {
      DoMessage(remote, "beginning", 1);
      DoMessage(remote, "may take some time", 2);
      start = clock();

      WinampRemote::Client::WinampClientBase client;


      retval = client.winampVersion();

      end = clock();
      DoMessage(remote, AnsiString().sprintf("response after %.2fs ", (end - start) / CLK_TCK), 1);
      versionString = WinampVersionString(retval);
      DoMessage(remote, WinampVersionString(retval), 1);
      result = true;
    }
    catch( ERPCException& E)
    {
      DoMessage(remote, AnsiString("failed: " ) + E.what(), 3);
    }
    DoResult(remote, result);
    serverInfo.comment = versionString.c_str();
    serverInfo.status = (result)?SI_SUCCESS:SI_FAILED;

}
