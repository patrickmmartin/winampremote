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

/**
 * concrete class to implement the IWinampServer interface
 * for use in-process in Winamp to pass on the messages based API calls
 */
class WinampServer: public IWinampServer
{
private:
	/**
	 * handle to the Winamp main instance passed in plugin initialisation
	 */
	HWND m_winamphwnd;

public:
	WinampServer(HWND winamp_hwnd);
	virtual ~WinampServer();

	string WinampVersion();

	void ExecuteCommand(WinampCommand MessageToExecute);

	void ExecuteStringCommand(const char * CommandString, WinampCommand Command);

	int QueryInt(WinampCommand Command, int Data);

	string QueryString(WinampCommand Command, int Data);

};

} /* namespace Server */
} /* namespace WinampRemote */
#endif /* WINAMPSERVERIMPL_H_ */
