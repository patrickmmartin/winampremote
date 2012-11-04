
#include "WinampTestServer.h"

namespace WinampRemote
{
namespace Server
{


WinampTestServer::WinampTestServer() :
		m_playbackStatus(WA_NOT_PLAYING),
		m_playList(),
		m_playlistPosition(-1),
		m_volume(0),
		m_songPosition(0),
		m_repeat(false), m_shuffle(false),
		m_eqdata(),
		m_panning(0)
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

			m_playbackStatus = WA_PLAYING;
			break;
		case WINAMP_PLAYENTRY:
		case IPC_PLAYFILE:
			m_playbackStatus = WA_PLAYING;
			m_playlistPosition = (-1 == m_playlistPosition)? 0 : m_playlistPosition;
			break;

		case WINAMP_STOPAFTERCURRENT:
		case WINAMP_STOPFADE:
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
			m_playList.clear();
			m_playlistPosition = 0;
			break;
		case WINAMP_FILE_REPEAT:
			m_repeat = !m_repeat;
			break;
		case WINAMP_FILE_SHUFFLE:
			m_shuffle = !m_shuffle;
			break;
		case WINAMP_STARTOFPLAYLIST:
			m_playlistPosition = 0;
			break;
		case WINAMP_ENDOFPLAYLIST:
			m_playlistPosition = m_playList.size() - 1;
			break;
		case WINAMP_FORWARD5S:
			m_songPosition += 5000;
			break;
		case WINAMP_BACK5S:
			m_songPosition -= 5000;
			break;
	}

//		throw std::runtime_error("WinampTestServer::ExecuteCommand not implemented");

}

void WinampTestServer::ExecuteStringCommand(const char * CommandString, WinampCommand Command)
{
	throw std::runtime_error("WinampTestServer::ExecuteStringCommand not implemented");
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
			if (Data == 0)
				return m_songPosition;
			return 202; // 3 minutes 22 seconds
		case IPC_GETLISTLENGTH:
			return m_playList.size();
		case IPC_GETLISTPOS:
			return m_playlistPosition;
		case IPC_GETEQDATA:
			if ((Data >= 0 ) && (Data < 12))
			{
				  m_eqindex = Data;
				  return m_eqdata[m_eqindex];

			}
			return 0;
		case IPC_GETSHUFFLEOPTION:
			return m_shuffle;
		case IPC_GETREPEATOPTION:
			return m_repeat;
		case IPC_SETVOLUME:
		{
			if (Data == -666)
				return m_volume;
			m_volume = Data;
			return 0;
		}
		case IPC_JUMPTOTIME:
			m_songPosition = Data;
			return 0;
		case IPC_STARTPLAY:
			m_playbackStatus = WA_PLAYING;
			m_playlistPosition = (-1 == m_playlistPosition)? 0 : m_playlistPosition;
			break;
		case IPC_SETEQDATA:
			m_eqdata[m_eqindex] = Data;
			break;
		case IPC_SETSHUFFLEOPTION:
			m_shuffle = Data;
			break;
		case IPC_SETREPEATOPTION:
			m_repeat = Data;
			break;
		case IPC_SETPANNING:
		{
			if (Data == -666)
				return m_panning;
			m_panning = Data;
			return 0;
		}
	}

	return 0;
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
