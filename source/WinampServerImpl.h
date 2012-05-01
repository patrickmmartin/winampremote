/*
 * WinampServerImpl.h
 *
 *  Created on: 1 May 2012
 *      Author: Patrick
 */

#ifndef WINAMPSERVERIMPL_H_
#define WINAMPSERVERIMPL_H_

#include "IWinamp.h"

namespace WinampRemote
{
namespace Server
{

class WinampServer: public IWinampServer
{
public:
	WinampServer();
	virtual ~WinampServer();


	void ExecuteCommand(WinampCommand MessageToExecute);

	void ExecuteStringCommand(char * CommandString, WinampCommand Command);

	int QueryInt(WinampCommand Command, int Data);

	string QueryString(WinampCommand Command, int Data);

};

} /* namespace Server */
} /* namespace WinampRemote */
#endif /* WINAMPSERVERIMPL_H_ */
