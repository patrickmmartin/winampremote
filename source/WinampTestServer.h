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

	void ExecuteStringCommand(char * CommandString, WinampCommand Command);

	int QueryInt(WinampCommand Command, int Data);

	string QueryString(WinampCommand Command, int Data);
private:
	WAPlaybackStatus m_playbackStatus;
	vector<PlaylistItem> m_playList;
	int m_playlistPosition;

	void wrapPlaylistIndex(int increment);
};

} /* namespace Server */
} /* namespace WinampRemote */
#endif /* WINAMPTESTSERVER_H_ */
