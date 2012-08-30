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
//  TODO implement SendList()
}

void winampGetList(void)
{
//  TODO implement GetList()
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

void WinampClientBase::sendString()
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


string WinampClientBase::getPlayListItem(int index, bool title)
{
	char buffer[MAX_PATH] = "";
	strcpy(buffer, IdentBuf);
	StringResult(buffer, (title)?IPC_GETPLAYLISTTITLE:IPC_GETPLAYLISTFILE, index);
	string result = buffer;
	return result;
}

int WinampClientBase::getCurrentPlayPosition(void)
{
    return IntegerResult(IdentBuf, IPC_GETLISTPOS, 0);
}

int WinampClientBase::getPlaylistLength(void)
{
	return IntegerResult(IdentBuf, IPC_GETLISTLENGTH, 0);
}

string WinampClientBase::getCurrentPlayListItem(int& index, bool title)
{
    index = IntegerResult(IdentBuf, IPC_GETLISTPOS, 0);
	return getPlayListItem(index, title);
}


// TODO this implementation should ultimately be replaced with the bulk version
vector<string>* WinampClientBase::getPlayList(bool title)
{
	vector<string> * result = new vector<string>();
	char buffer[MAX_PATH] = "";

	int lastlength = getPlaylistLength();

	for (int i = 0; i < lastlength; i++)
	{
		strcpy(buffer, IdentBuf);
                if (title)
		        StringResult(buffer, IPC_GETPLAYLISTTITLE, i);
                else
                        StringResult(buffer, IPC_GETPLAYLISTFILE, i);
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

void WinampClientBase::setTime(int time)
{
	IntegerResult(IdentBuf, IPC_JUMPTOTIME, time);
}

int WinampClientBase::getTime()
{
	return IntegerResult(IdentBuf, IPC_GETOUTPUTTIME, 0);
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
	setVolume(getVolume() + 1);
}

void WinampClientBase::volumeDown(void)
{
	setVolume(getVolume() - 1);
}

void WinampClientBase::setVolume(int volume)
{
	IntegerResult(IdentBuf, IPC_SETVOLUME, volume);
}

int WinampClientBase::getVolume()
{
	return IntegerResult(IdentBuf, IPC_SETVOLUME, -666);
}

void WinampClientBase::toggleShuffle(void)
{
//	int shuffle = IntegerResult(IdentBuf, IPC_GETSHUFFLEOPTION, 0);
	ExecuteMessage(IdentBuf, WINAMP_FILE_SHUFFLE);
}

int WinampClientBase::getShuffle()
{
	return IntegerResult(IdentBuf, IPC_GETSHUFFLEOPTION, 0);
}

void WinampClientBase::toggleRepeat(void)
{
//	int repeat = IntegerResult(IdentBuf, IPC_GETREPEATOPTION, 0);
	ExecuteMessage(IdentBuf, WINAMP_FILE_REPEAT);

}

int WinampClientBase::getRepeat()
{
	return IntegerResult(IdentBuf, IPC_GETREPEATOPTION, 0);
}

void WinampClientBase::toggleAutoload(void)
{
	int autoLoad = getAutoload();
	setAutoload(!autoLoad);
}

int WinampClientBase::getAutoload()
{
	return getEQData(11);
}

void WinampClientBase::setAutoload(bool value)
{
	return setEQData(11, value);
}

WinampClientBase::getEQData(int eqindex)
{
	return IntegerResult(IdentBuf, IPC_GETEQDATA, eqindex);
}

void WinampClientBase::setEQData(int eqindex, int eqvalue)
{
	getEQData(eqindex);
	IntegerResult(IdentBuf, IPC_SETEQDATA, eqvalue );
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

