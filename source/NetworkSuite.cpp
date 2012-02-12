/*
 * NetworkSuite.cpp
 *
 *  Created on: 11 Feb 2012
 *      Author: Patrick
 */

#include "NetworkSuite.h"

#include "ServerEnumerator.h"

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

void __fastcall NetworkSuite::DoServer(const AnsiString& remoteName, const AnsiString& comment)
{
  cout << "Server: " << remoteName.c_str() << " \"" << comment.c_str() << " \"" << endl;
}
void __fastcall NetworkSuite::DoMessage(const AnsiString& message, const int level)
{
  cout << "Message: " << message.c_str() << " " << level << endl;
}
void __fastcall NetworkSuite::DoProgress(const float complete)
{
  cout << "Progress: " << 100 * complete << "%" << endl;
}


void NetworkSuite::run()
{

  ServerEnumerator se;
  se.OnMessage = DoMessage;
  se.OnServer = DoServer;
  se.OnProgress = DoProgress;
  se.enumerateServers();

}
