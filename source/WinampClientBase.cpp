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
//  TODO SendList()
}

void winampGetList(void)
{
//  TODO GetList()
}

namespace WinampRemote
{
namespace Client
{

WinampClientBase::WinampClientBase()
{
	GetIdent();
}

int WinampClientBase::winampVersion(void)
{
	return IntegerResult(IdentBuf, IPC_GETVERSION, 0);
}

void WinampClientBase::sendString(std::string msg)
{
	SendString(IdentBuf);
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

// TODO this implementation should ultimately be replaced with the bulk version
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

void WinampClientBase::playlistStart()
{
	ExecuteMessage(IdentBuf, WINAMP_STARTOFPLAYLIST);
}

void WinampClientBase::playlistEnd()
{
	ExecuteMessage(IdentBuf, WINAMP_ENDOFPLAYLIST);
}

void WinampClientBase::setPlaylistIndex(int index)
{
	IntegerResult(IdentBuf, IPC_SETPLAYLISTPOS, index);
}

void WinampClientBase::startPlaylist(void)
{
	IntegerResult(IdentBuf, IPC_STARTPLAY, 0);
}

void WinampClientBase::deletePlaylist(void)
{
	IntegerResult(IdentBuf, IPC_DELETE, 0);
}

void WinampClientBase::stopWithFade(void)
{
	ExecuteMessage(IdentBuf, WINAMP_STOPFADE);
}

void WinampClientBase::stopAfterCurrent(void)
{
	ExecuteMessage(IdentBuf, WINAMP_STOPAFTERCURRENT);
}

void WinampClientBase::forward5(void)
{
	ExecuteMessage(IdentBuf, WINAMP_FORWARD5S);
}

void WinampClientBase::back5(void)
{
	ExecuteMessage(IdentBuf, WINAMP_BACK5S);
}

void WinampClientBase::volumeUp(void)
{
	setVolume(51);
}

void WinampClientBase::volumeDown(void)
{
	setVolume(49);
}

void WinampClientBase::setVolume(int volume)
{
	IntegerResult(IdentBuf, IPC_SETVOLUME, volume);
}

void WinampClientBase::toggleShuffle(void)
{
//	int shuffle = IntegerResult(IdentBuf, IPC_GETSHUFFLEOPTION, 0);
	ExecuteMessage(IdentBuf, WINAMP_FILE_SHUFFLE);;
}

void WinampClientBase::toggleRepeat(void)
{
//	int repeat = IntegerResult(IdentBuf, IPC_GETREPEATOPTION, 0);
	ExecuteMessage(IdentBuf, WINAMP_FILE_REPEAT);

}

void WinampClientBase::toggleAutoload(void)
{
	int autoLoad = IntegerResult(IdentBuf, IPC_GETEQDATA, 11);
	IntegerResult(IdentBuf, IPC_SETEQDATA, !autoLoad );
}

void WinampClientBase::getTimes(int& songLength, int& songPos)
{

	int songS = IntegerResult(IdentBuf, IPC_GETOUTPUTTIME, 1);
	int posMS = IntegerResult(IdentBuf, IPC_GETOUTPUTTIME, 0);

	songLength = songS;
	songPos =  posMS;

}

} // end of namespace Client
} // end of namespace WinampRemote

