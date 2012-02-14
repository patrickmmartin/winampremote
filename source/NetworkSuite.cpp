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



NetworkSuite::NetworkSuite()
{
  // TODO Auto-generated stub
}

NetworkSuite::~NetworkSuite()
{
  // TODO Auto-generated stub
}

void __fastcall NetworkSuite::DoNetworkServer(const AnsiString& remoteName, const AnsiString& comment)
{
  cout << "Network Server: " << remoteName.c_str() << " \"" << comment.c_str() << " \"" << endl;
}

void __fastcall NetworkSuite::DoNetworkMessage(const AnsiString& message, const int level)
{
  cout << "Network Message: " << message.c_str() << " " << level << endl;
}

void __fastcall NetworkSuite::DoNetworkProgress(const float complete)
{
  cout << "Network Progress: " << 100 * complete << "%" << endl;
}


void __fastcall NetworkSuite::DoTestEvent(const AnsiString& remoteName,
                                          const AnsiString& data,
                                          const int level)
{
  cout << "Test Event: " << remoteName.c_str() << " " << data.c_str() << level<< endl;
}

void __fastcall NetworkSuite::DoTestResult(const AnsiString& remoteName,
                                           const bool success)
{
  cout << "Test Result: " << remoteName.c_str() << " " << success << endl;
}


void NetworkSuite::run()
{

  ServerEnumerator se;
  se.OnMessage = DoNetworkMessage;
  se.OnServer = DoNetworkServer;
  se.OnProgress = DoNetworkProgress;
  se.enumerateServers();

  ServerTester st;
  st.OnResult = DoTestResult;
  st.OnTest = DoTestEvent;
  vector<AnsiString> nodes;
  nodes.push_back("localhost");
  st.testServers(nodes, "\\pipe\\winampremote");

}
