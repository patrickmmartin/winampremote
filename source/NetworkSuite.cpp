/*
 * NetworkSuite.cpp
 *
 *  Created on: 11 Feb 2012
 *      Author: Patrick
 */

#include "catch.hpp"

#include "NetworkSuite.h"

#include "ServerEnumerator.h"
#include "ServerTester.h"

NetworkSuite::NetworkSuite() :  _servers(), _abort_test(false)

{
}

NetworkSuite::~NetworkSuite()
{
  // clean up any owned resources
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

  std::string msg = "Network Server located: ";
  msg += remoteName.c_str();
  msg += comment.c_str();
  INFO(msg);
}

void NetworkSuite::doNetworkMessage(const AnsiString& message, const int level)
{
  std::string msg = "Network message: ";
  msg += message.c_str();
  INFO(msg);
}

void NetworkSuite::doNetworkProgress(const float complete)
{
  std::string msg = "Network Progress: ";
  msg += complete;
  INFO(msg);
}


void NetworkSuite::doTestEvent(const AnsiString& remoteName,
                                          const AnsiString& data,
                                          const int level)
{
  std::string msg = "Test Event: ";
  msg += levelString(level);
  msg += " ";
  msg += remoteName.c_str();
  msg += " ";
  msg += data.c_str();
  INFO(msg);

}

void NetworkSuite::doTestResult(const AnsiString& remoteName,
                                           const bool success,
                                           bool& abort)
{

  std::string msg = "Test Result: ";
  msg += remoteName.c_str();
  msg += " result ";
  msg += success?"true":"false";
  INFO(msg);

}



bool NetworkSuite::testLocalServer()
{
    _servers.clear();
    _servers.push_back("localhost");
    ServerTester st;
    st.OnResult = doTestResult;
    st.OnTest = doTestEvent;
    st.testServers(_servers);
    // TODO: validate some state
    return true;
}

bool NetworkSuite::testEnumeration()
{
    ServerEnumerator se;
    se.OnMessage = doNetworkMessage;
    se.OnServer = doNetworkServer;
    se.OnProgress = doNetworkProgress;
    se.enumerateServers();
    // TODO: validate some state
    return true;
}

bool NetworkSuite::testServerTest()
{
    ServerTester st;
    st.OnResult = doTestResult;
    st.OnTest = doTestEvent;
    st.testServers(_servers);
    // TODO: validate some state
    return true;
}

bool NetworkSuite::testServerTestAbort()
{
    bool prior_abort_test = _abort_test;
    _abort_test = true;
    ServerTester st;
    st.OnResult = doTestResult;
    st.OnTest = doTestEvent;
    vector<AnsiString> servers;
    servers.push_back("localhost");
    servers.push_back("localhost");
    st.testServers(servers);
    _abort_test = prior_abort_test;
    // TODO: validate some state
    return true;
}

bool NetworkSuite::testServerInvalid()
{
    ServerTester st;
    st.OnResult = doTestResult;
    st.OnTest = doTestEvent;
    vector<AnsiString> servers;
    servers.push_back("__invalid__");
    st.testServers(servers);
    // TODO: validate some state
    return true;
}
