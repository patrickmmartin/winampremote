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

/**
 * item for storing the playlist entries
 */
struct PlaylistItem
{
	string title;
	string filename;

	/**
	 * constructor taking the title and filename
	 * @param title_
	 * @param filename_
	 */
	PlaylistItem(string title_, string filename_): title(title_), filename(filename_) {};
};

/**
 * mock server for use in the test project, implementing the IWinampServer interface
 */
class WinampTestServer: public WinampRemote::Server::IWinampServer
{
public:
	/**
	 * constructor
	 */
	WinampTestServer();
	/**
	 * virtual destructor
	 */
	virtual ~WinampTestServer();

	/**
	 * obtains and formats the winamp version number
	 * @return the string representation
	 */
	string WinampVersion();

	/**
	 * execute the passed command ID
	 * @param MessageToExecute
	 */
	void ExecuteCommand(WinampCommand MessageToExecute);

	/**
	 * executes the passed command with the string parameter
	 * @param CommandString
	 * @param Command
	 */
	void ExecuteStringCommand(const char * CommandString, WinampCommand Command);

	/**
	 * returns the result for the given command and data
	 * @param Command
	 * @param Data
	 * @return the result
	 */
	int QueryInt(WinampCommand Command, int Data);

	/**
	 * queries the string value for the given command and data
	 * @param Command
	 * @param Data
	 * @return the result
	 */
	string QueryString(WinampCommand Command, int Data);
private:
	// playback status
	WAPlaybackStatus m_playbackStatus;
	// internal playlist
	vector<PlaylistItem> m_playList;
	// playlist position
	int m_playlistPosition;
	// volume 0-255
	int m_volume;
	// time position in song
	int m_songPosition;
	// repeat, shuffle
	bool m_repeat, m_shuffle;
	// eq data
	byte m_eqdata[13];
	// eq index is stashed to remember for when the values are queried
	int m_eqindex;
	// panning value 0 - 255
	byte m_panning;

	void wrapPlaylistIndex(int increment);
};

} /* namespace Server */
} /* namespace WinampRemote */
#endif /* WINAMPTESTSERVER_H_ */
