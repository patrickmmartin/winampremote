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

#include <vector.h>


class NetworkSuite
{
public:
  NetworkSuite();
  virtual
  ~NetworkSuite();
  void run();
private:

  vector<AnsiString> _servers;
  bool _abort_test;
  void testServerInvalid();
  void testServerTestAbort();

  char * levelString(const int level);


  /**
   * test method for network enumeration
   */
  void testEnumeration();

  /**
   * test method for server testing
   */
  void testServerTest();

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

};

#endif /* NETWORKSUITE_H_ */
