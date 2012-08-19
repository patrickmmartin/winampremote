/*
 * NetworkSuite.h
 *
 *  Created on: 11 Feb 2012
 *      Author: Patrick
 */

#ifndef NETWORKSUITE_H_
#define NETWORKSUITE_H_

#include <vcl.h>
#pragma hdrstop

#include <map.h>
#include "ServerTester.h" // ServerInfo

/**
 * A class to wrap up testing the network utility functions.
 */
class NetworkSuite
{
public:
  NetworkSuite();
  virtual ~NetworkSuite();
private:

  map<AnsiString, ServerInfo> _servers;
  bool _abort_test;
  char * levelString(const int level);

  /**
   * handler for server found event
   * @param remoteName
   * @param comment
   */
  void doNetworkServer(const AnsiString& remoteName, const AnsiString& comment);
  /**
   * handler for network message
   * @param message
   * @param level
   */
  void doNetworkMessage(const AnsiString& message, const int level);
  /**
   *  handler for network progress
   * @param complete
   */
  void doNetworkProgress(const float complete);
  /**
   * handler for server test concluded event
   * @param remoteName
   * @param data
   * @param level
   */
  void doTestEvent(const AnsiString& remoteName,
                   const AnsiString& data,
                   const int level);
  /**
   * handler for test result event
   * @param remoteName
   * @param success
   * @param abort
   */
  void doTestResult(const AnsiString& remoteName,
                    const bool success,
                    bool& abort);

public:
  /**
   * test method for communication with an invalid server
   * @return was an invalid server trapped correctly in attempting to connect
   */
  bool testServerInvalid();

  /**
   * test method for abort
   * @return success of the abort
   */
  bool testServerTestAbort();

  /**
   * test method for test local server
   */
  bool testLocalServer();
  /**
   * test method for network enumeration
   */
  bool testEnumeration();

  /**
   * test method for server testing
   */
  bool testServerTest();

};

#endif /* NETWORKSUITE_H_ */
