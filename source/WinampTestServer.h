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

struct PlaylistItem
{
	string title;
	string filename;

	PlaylistItem(string title_, string filename_): title(title_), filename(filename_) {};
};

class WinampTestServer: public WinampRemote::Server::IWinampServer
{
public:
	WinampTestServer();
	virtual ~WinampTestServer();

	string WinampVersion();

	void ExecuteCommand(WinampCommand MessageToExecute);

	void ExecuteStringCommand(const char * CommandString, WinampCommand Command);

	int QueryInt(WinampCommand Command, int Data);

	string QueryString(WinampCommand Command, int Data);
private:
	// playback status
	WAPlaybackStatus m_playbackStatus;
	// internal playlist
	vector<PlaylistItem> m_playList;
	// playlist position
	int m_playlistPosition;
	// volume
	int m_volume;
	// time position in song
	int m_songPosition;
	// repeat, shuffle
	bool m_repeat, m_shuffle;
	byte m_eqdata[12];
	int m_eqindex;
	byte m_panning;

	void wrapPlaylistIndex(int increment);
};

} /* namespace Server */
} /* namespace WinampRemote */
#endif /* WINAMPTESTSERVER_H_ */
