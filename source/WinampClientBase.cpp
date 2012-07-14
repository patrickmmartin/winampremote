#include <iostream.h>
#include "windows.h"
#include "stddef.h"

#include "RPCFuncsU.h"
#include "waint.h"
#include "WinampClientBase.h"

static char IdentBuf[2 * MAX_COMPUTERNAME_LENGTH + 2];

/**
 * Function to obtain an identity "moniker"
 */
static void GetIdent(void)
{

	char NameBuf[MAX_COMPUTERNAME_LENGTH + 1];char ComputerBuf [MAX_COMPUTERNAME_LENGTH + 1];

	unsigned long BufLen;
	BufLen = MAX_COMPUTERNAME_LENGTH + 1;
	GetComputerName(ComputerBuf, &BufLen);
	BufLen = MAX_COMPUTERNAME_LENGTH + 1;
	GetUserName(NameBuf, &BufLen);
	sprintf(IdentBuf, "%s@%s", NameBuf, ComputerBuf);

}

void winampSendList(void)
{
//  SendList();
}

void winampGetList(void)
{
//  GetList();
}

namespace WinampRemote
{
namespace Client
{

WinampClientBase::WinampClientBase()
{
	GetIdent();
}

void WinampClientBase::nextSong(void)
{
	ExecuteMessage(IdentBuf, WINAMP_NEXT);
}

void WinampClientBase::previousSong(void)
{
	ExecuteMessage(IdentBuf, WINAMP_PREVIOUS);
}

void WinampClientBase::playSong(void)
{
	ExecuteMessage(IdentBuf, WINAMP_PLAYENTRY);
}

void WinampClientBase::stopSong(void)
{
	ExecuteMessage(IdentBuf, WINAMP_STOP);
}

void WinampClientBase::pause(void)
{
	ExecuteMessage(IdentBuf, WINAMP_PAUSE);
}

WAPlaybackStatus WinampClientBase::getPlaybackStatus(void)
{
	return (WAPlaybackStatus) IntegerResult(IdentBuf, IPC_ISPLAYING, 0);
}

vector<string>* WinampClientBase::getPlayList(void)
{
	vector<string> * result = new vector<string>();
	char buffer[MAX_PATH];

	int lastlength = IntegerResult(IdentBuf, IPC_GETLISTLENGTH, 0);

	for (int i = 0; i < lastlength; i++)
	{
		strcpy(buffer, IdentBuf);
		StringResult(buffer, IPC_GETPLAYLISTTITLE, i);
		result->push_back(buffer);
	}
	return result;
}

int WinampClientBase::winampVersion(void)
{
	return IntegerResult(IdentBuf, IPC_GETVERSION, 0);
}

} // end of namespace Client
} // end of namespace WinampRemote
