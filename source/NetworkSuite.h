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
  void __fastcall DoServer(const AnsiString& remoteName, const AnsiString& comment);
  void __fastcall DoMessage(const AnsiString& message, const int level);
  void __fastcall DoProgress(const float complete);

};

#endif /* NETWORKSUITE_H_ */
