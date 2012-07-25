
#include "WinampTestServer.h"

namespace WinampRemote
{
namespace Server
{


WinampTestServer::WinampTestServer() :
		m_playbackStatus(WA_NOT_PLAYING),
		m_playList(),
		m_playlistPosition(-1)
{
	char title[MAX_PATH] = "";
	char filename[MAX_PATH] = "";
	for (int i = 0 ; i < 20 ; i++)
	{
		sprintf(title, "playlist item %d", i);
		sprintf(filename, "c:\music\file%d", i);
		m_playList.push_back(PlaylistItem(title, filename));
	}
}

WinampTestServer::~WinampTestServer()
{
	// destroy any owned resources here
}

string WinampTestServer::WinampVersion()
{
    return "test server";
}

void WinampTestServer::wrapPlaylistIndex(int increment)
{
	m_playlistPosition += increment;
	int length = m_playList.size();
    m_playlistPosition = m_playlistPosition % length;
}

void WinampTestServer::ExecuteCommand(WinampCommand MessageToExecute)
{

	switch (MessageToExecute)
	{

		case WINAMP_FILE_PLAY:
			// TODO: Play file
		case WINAMP_PLAYENTRY:
                IPC_STARTPLAY:
		IPC_PLAYFILE:
			m_playbackStatus = WA_PLAYING;
			m_playlistPosition = (-1 == m_playlistPosition)? 0 : m_playlistPosition;
			break;


		case WINAMP_STOP:
			m_playbackStatus = WA_NOT_PLAYING;
			break;
		case WINAMP_PAUSE:
			m_playbackStatus = WA_PAUSED;
			break;

		case WINAMP_NEXT:
			wrapPlaylistIndex(1);
			break;
		case WINAMP_PREVIOUS:
			wrapPlaylistIndex(-1);
			break;


		case IPC_DELETE:
			// TODO: implement delete
		case IPC_CHDIR:
			// TODO: not currently implemented
		case IPC_JUMPTOTIME:
			// TODO: jump to time
		case IPC_SETVOLUME:
			// TODO: set volume
		case IPC_SETPANNING:
			// TODO: set panning
		case IPC_SETEQDATA:
			// TODO: set eq data
		case IPC_SETSHUFFLEOPTION:
			// TODO: set shuffle
		case IPC_SETREPEATOPTION:
			// TODO: set repeat option
		case WINAMP_FILE_REPEAT:
			// TODO: set repeat option
		case WINAMP_FILE_SHUFFLE:
			// TODO: set shuffle

		case WINAMP_VOLUMEUP:
			// TODO: volume up
		case WINAMP_VOLUMEDOWN:
			// TODO: volume down
		case WINAMP_FFWD5S:
			// TODO: forward 5s
		case WINAMP_REW5S:
			// TODO: rewind 5s
		return;
	}

//		throw std::runtime_error("WinampTestServer::ExecuteCommand not implemented");

}

void WinampTestServer::ExecuteStringCommand(char * CommandString, WinampCommand Command)
{
	//throw std::runtime_error("WinampTestServer::ExecuteStringCommand not implemented");
}

int WinampTestServer::QueryInt(WinampCommand Command, int Data)
{

	switch (Command)
	{

		case IPC_GETVERSION:
			return 0x123;
		case IPC_ISPLAYING:
			return m_playbackStatus;
		case IPC_SETPLAYLISTPOS:
			m_playlistPosition = Data;
			break;
		case IPC_GETOUTPUTTIME:
			return 360;
		case IPC_GETLISTLENGTH:
			return m_playList.size();
		case IPC_GETLISTPOS:
			return m_playlistPosition;
		case IPC_GETINFO:
			return 1;	// TODO: what does this do?
		case IPC_GETEQDATA:
			return 50;	// TODO: implement EQData
		case IPC_GETSHUFFLEOPTION:
			return 1;
		case IPC_GETREPEATOPTION:
			return 1;
	}

	return 0;
//	throw std::runtime_error("WinampTestServer::QueryInt not implemented");
}

string WinampTestServer::QueryString(WinampCommand Command, int Data)
{
	switch (Command)
	{
		case IPC_GETPLAYLISTTITLE :
			return m_playList[Data].title;
		case IPC_GETPLAYLISTFILE :
			return m_playList[Data].filename;
	}
	throw std::runtime_error("WinampTestServer::QueryString not implemented");
}

} /* namespace Server */
} /* namespace WinampRemote */
