/*
 * NetworkSuite.h
 *
 *  Created on: 11 Feb 2012
 *      Author: Patrick
 */

#ifndef NETWORKSUITE_H_
#define NETWORKSUITE_H_

#include <vcl.h>

class NetworkSuite
{
public:
  NetworkSuite();
  virtual
  ~NetworkSuite();
  void run();
private:

  void __fastcall DoNetworkServer(const AnsiString& remoteName, const AnsiString& comment);
  void __fastcall DoNetworkMessage(const AnsiString& message, const int level);
  void __fastcall DoNetworkProgress(const float complete);

  void __fastcall DoTestEvent(const AnsiString& remoteName,
                                            const AnsiString& data,
                                            const int level);
  void __fastcall DoTestResult(const AnsiString& remoteName,
                                             const bool success);

};

#endif /* NETWORKSUITE_H_ */
