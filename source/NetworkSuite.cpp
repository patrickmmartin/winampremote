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
  _servers[remoteName].comment = comment;

  std::string msg = "Network Server located: ";
  msg += remoteName.c_str();
  msg += comment.c_str();
  INFO(msg);
}

void NetworkSuite::doNetworkMessage(const AnsiString& message, const int level)
{
  std::string msg = "Network message: ";
  msg += message.c_str();
  // TODO update the server status
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
  // TODO update the server status
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
  // TODO update the server status
  INFO(msg);

}



bool NetworkSuite::testLocalServer()
{
    ServerTester st;
    st.OnResult = doTestResult;
    st.OnTest = doTestEvent;
    st.testServer("localhost");
    // TODO: return the result for that server
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
    return true;
}

bool NetworkSuite::testServerTestAbort()
{
    bool prior_abort_test = _abort_test;
    _abort_test = true;
    ServerTester st;
    st.OnResult = doTestResult;
    st.OnTest = doTestEvent;
    map<AnsiString, ServerInfo> servers;
    servers["localhost"].comment = "local machine";
    servers["__invalid__"].comment = "should not exist";
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
    st.testServer("__invalid__");
    // TODO: validate some state
    return true;
}
