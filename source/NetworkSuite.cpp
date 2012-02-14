/*
 * NetworkSuite.cpp
 *
 *  Created on: 11 Feb 2012
 *      Author: Patrick
 */

#include "NetworkSuite.h"

#include "ServerEnumerator.h"
#include "ServerTester.h"

#include <iostream.h>

using std::cout;
using std::endl;
using std::boolalpha;

NetworkSuite::NetworkSuite()
{
  // TODO Auto-generated stub
}

NetworkSuite::~NetworkSuite()
{
  // TODO Auto-generated stub
}

char * NetworkSuite::levelString(const int level)
{
  switch (level)
  {
    case 0: return "message";
    case 1: return "info";
    case 2: return "warning";
    case 3: return "error";
    default:
      return AnsiString().sprintf("ERROR unknown level %d", level).c_str();
  }
}


void NetworkSuite::doNetworkServer(const AnsiString& remoteName, const AnsiString& comment)
{
  _servers.push_back(remoteName);
  cout << "Network Server: " << remoteName.c_str() << " \"" << comment.c_str() << " \"" << endl;
}

void NetworkSuite::doNetworkMessage(const AnsiString& message, const int level)
{
  cout << "Network Message: " << levelString(level) << " " << message.c_str() << " " << endl;
}

void NetworkSuite::doNetworkProgress(const float complete)
{
  cout << "Network Progress: " << 100 * complete << "%" << endl;
}


void NetworkSuite::doTestEvent(const AnsiString& remoteName,
                                          const AnsiString& data,
                                          const int level)
{
  cout << "Test Event: " << levelString(level) << " " << remoteName.c_str() << " " << data.c_str() << endl;
}

void NetworkSuite::doTestResult(const AnsiString& remoteName,
                                           const bool success)
{
  cout << "Test Result: " << remoteName.c_str() << " result " << boolalpha << success << endl;
}


void NetworkSuite::testEnumeration()
{
    ServerEnumerator se;
    se.OnMessage = doNetworkMessage;
    se.OnServer = doNetworkServer;
    se.OnProgress = doNetworkProgress;
    se.enumerateServers();
}

void NetworkSuite::testServerTest()
{
    ServerTester st;
    st.OnResult = doTestResult;
    st.OnTest = doTestEvent;
    // TODO: locate this endpoint constant appropriately
    st.testServers(_servers, "\\pipe\\winampremote");
}

void NetworkSuite::run()
{

    testEnumeration();
    // TODO: dependency upon prior test
    testServerTest();

}
