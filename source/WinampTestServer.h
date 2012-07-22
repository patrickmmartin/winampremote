/*
 * WinampTestServer.h
 *
 *  Created on: 22 Jul 2012
 *      Author: Patrick
 */

#ifndef WINAMPTESTSERVER_H_
#define WINAMPTESTSERVER_H_

#include "IWinamp.h"

namespace WinampRemote
{
namespace Server
{

class WinampTestServer: public WinampRemote::Server::IWinampServer
{
public:
	WinampTestServer();
	virtual ~WinampTestServer();

	string WinampVersion();

	void ExecuteCommand(WinampCommand MessageToExecute);

	void ExecuteStringCommand(char * CommandString, WinampCommand Command);

	int QueryInt(WinampCommand Command, int Data);

	string QueryString(WinampCommand Command, int Data);


};

} /* namespace Server */
} /* namespace WinampRemote */
#endif /* WINAMPTESTSERVER_H_ */
