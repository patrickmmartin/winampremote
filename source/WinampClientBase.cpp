#include <sstream>
#include "windows.h"
#include "stddef.h"

#include "RPCFuncsU.h" // the only use of this header
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

namespace WinampRemote
{
namespace Client
{

WinampClientBase::WinampClientBase()
{
	GetIdent();
}

int WinampClientBase::winampVersion(void) const
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

WAPlaybackStatus WinampClientBase::getPlaybackStatus(void) const
{
	return (WAPlaybackStatus) IntegerResult(IdentBuf, IPC_ISPLAYING, 0);
}


string WinampClientBase::getPlayListItem(int index, bool title) const
{
	char buffer[MAX_PATH] = "";
	strcpy(buffer, IdentBuf);
	StringResult(buffer, (title)?IPC_GETPLAYLISTTITLE:IPC_GETPLAYLISTFILE, index);
	string result = buffer;
	return result;
}

int WinampClientBase::getCurrentPlayPosition(void) const
{
    return IntegerResult(IdentBuf, IPC_GETLISTPOS, 0);
}

int WinampClientBase::getPlaylistLength(void) const
{
	return IntegerResult(IdentBuf, IPC_GETLISTLENGTH, 0);
}

string WinampClientBase::getCurrentPlayListItem(int& index, bool title) const
{
    index = IntegerResult(IdentBuf, IPC_GETLISTPOS, 0);
	return getPlayListItem(index, title);
}


vector<string> WinampClientBase::getPlayList(bool title) const
{
    vector<string> result;

    std::string playlist;
    if (title)
        playlist = getStringList(IPC_GETPLAYLISTTITLE);
    else
        playlist = getStringList(IPC_GETPLAYLISTFILE);


    std::stringstream input(playlist);
    std::string line;

    while ( std::getline( input, line ) )
    {
        result.push_back(line);
    }

    return result;

}

void WinampClientBase::setPlayList(const vector<string>& playlist)
{

	stringstream sstr;

	for (unsigned int i = 0  ; i <  playlist.size() ; i++ )
	{
		sstr << playlist.at(i).c_str() << endl;
	}

 	deletePlaylist();
	string list = sstr.str();
	setStringList(list, IPC_PLAYFILE);

}


void WinampClientBase::insertPlayList(const vector<string>& playlist, int position)
{
	vector<string> newPlaylist = getPlayList(false);

	vector<string>::iterator it;

	it = newPlaylist.begin();

	newPlaylist.insert (it + position , playlist.begin(),playlist.end());

	setPlayList(newPlaylist);

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

int WinampClientBase::getTime() const
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

int WinampClientBase::getVolume() const
{
	return IntegerResult(IdentBuf, IPC_SETVOLUME, -666);
}

void WinampClientBase::setPanning(int panning)
{
	IntegerResult(IdentBuf, IPC_SETPANNING, panning);
}

int WinampClientBase::getPanning() const
{
	return IntegerResult(IdentBuf, IPC_SETPANNING, -666);
}


void WinampClientBase::toggleShuffle(void)
{
	ExecuteMessage(IdentBuf, WINAMP_FILE_SHUFFLE);
}

int WinampClientBase::getShuffle() const
{
	return IntegerResult(IdentBuf, IPC_GETSHUFFLEOPTION, 0);
}

void WinampClientBase::setShuffle(bool shuffle)
{
	IntegerResult(IdentBuf, IPC_SETSHUFFLEOPTION, shuffle);
}

void WinampClientBase::toggleRepeat(void)
{
//	int repeat = IntegerResult(IdentBuf, IPC_GETREPEATOPTION, 0);
	ExecuteMessage(IdentBuf, WINAMP_FILE_REPEAT);

}

int WinampClientBase::getRepeat() const
{
	return IntegerResult(IdentBuf, IPC_GETREPEATOPTION, 0);
}

/**
 * sets the repeat option
 */
void WinampClientBase::setRepeat(bool repeat)
{
	IntegerResult(IdentBuf, IPC_SETREPEATOPTION, repeat);
}


void WinampClientBase::toggleEQOn(void)
{
	setEQOn(!getEQOn());
}

int WinampClientBase::getEQOn() const
{
	return getEQData(11);
}

void WinampClientBase::setEQOn(bool value)
{
	setEQData(11, value);
}

void WinampClientBase::toggleAutoload(void)
{
	setAutoload(!getAutoload());
}

int WinampClientBase::getAutoload() const
{
	return getEQData(12);
}

void WinampClientBase::setAutoload(bool value)
{
	return setEQData(12, value);
}

int WinampClientBase::getEQData(int eqindex) const
{
	return IntegerResult(IdentBuf, IPC_GETEQDATA, eqindex);
}

void WinampClientBase::setEQData(int eqindex, byte eqvalue)
{
	getEQData(eqindex);
	IntegerResult(IdentBuf, IPC_SETEQDATA, eqvalue );
}

void WinampClientBase::getTimes(int& songLength, int& songPos) const
{

	int songS = IntegerResult(IdentBuf, IPC_GETOUTPUTTIME, 1);
	int posMS = IntegerResult(IdentBuf, IPC_GETOUTPUTTIME, 0);

	songLength = songS;
	songPos =  posMS;

}

std::string WinampClientBase::getStringList(WinampCommand Command) const
{

	std::string result = "";
	BUFFER returnBuf;

	returnBuf.BufferLength = 0;
	returnBuf.Buffer = NULL;

	WAGetStringList( (unsigned char *) IdentBuf, &returnBuf, Command);

	result = (char *) returnBuf.Buffer;
	MIDL_user_free(returnBuf.Buffer);

	return result;

}

void WinampClientBase::setStringList(const std::string& list, WinampCommand Command)
{

    WASetStringList( (unsigned char *) IdentBuf, (unsigned char *) list.c_str(), list.size() + 1, Command);

}

} // end of namespace Client
} // end of namespace WinampRemote

