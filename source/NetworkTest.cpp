/*
 * NetworkTest.cpp
 *
 *  Created on: 7 Feb 2013
 *      Author: Patrick
 */

#include "catch.hpp"

#include "ServerEnumerator.h"
#include "ServerTester.h"


#include "NetworkTest.h"

NetworkTest::NetworkTest() :  _servers(), _abort_test(false)
{
}

NetworkTest::~NetworkTest()
{
  // clean up any owned resources
}

char * NetworkTest::levelString(const int level)
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

void NetworkTest::doNetworkServer(const AnsiString& remoteName, const AnsiString& comment, const AnsiString& ip)
{
  _servers[remoteName].comment = comment;

  std::string msg = "Network Server located: ";
  msg += remoteName.c_str();
  msg += comment.c_str();
  INFO(msg);
}

void NetworkTest::doNetworkMessage(const AnsiString& message, const int level)
{
  std::string msg = "Network message: ";
  msg += message.c_str();
  INFO(msg);
}

void NetworkTest::doNetworkProgress(const float complete)
{
  std::string msg = "Network Progress: ";
  msg += complete;
  INFO(msg);
}


void NetworkTest::doTestEvent(const AnsiString& remoteName,
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

void NetworkTest::doTestResult(const AnsiString& remoteName,
                                           const bool success,
                                           bool& abort)
{

  std::string msg = "Test Result: ";
  msg += remoteName.c_str();
  msg += " result ";
  msg += success?"true":"false";
  INFO(msg);

}



bool NetworkTest::testLocalServer()
{
    ServerTester st;
    st.OnResult = doTestResult;
    st.OnTest = doTestEvent;
    ServerInfo si;
    st.testServer("localhost", si);
    return (si.status == SI_SUCCESS);
}

bool NetworkTest::testEnumeration()
{
    ServerEnumerator se;
    se.OnMessage = doNetworkMessage;
    se.OnServer = doNetworkServer;
    se.OnProgress = doNetworkProgress;
    se.enumerateServers();
    return true;
}

bool NetworkTest::testServerTest()
{
    ServerTester st;
    st.OnResult = doTestResult;
    st.OnTest = doTestEvent;
    st.testServers(_servers);
    return true;
}

bool NetworkTest::testServerTestAbort()
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
    return true;
}

bool NetworkTest::testServerInvalid()
{
    ServerTester st;
    st.OnResult = doTestResult;
    st.OnTest = doTestEvent;
    ServerInfo ss;
    st.testServer("__invalid__", ss);
    return true;
}


