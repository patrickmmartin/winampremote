#ifndef IWINAMP_H
#define IWINAMP_H

#include <vector.h>
#include <string.h>

#include "waint.h"

/**
 * namespace for the WinampRemote project
 */
namespace WinampRemote
{

/**
 * interface defining the operations Winamp supports for clients
 */
namespace Client
{

using namespace std;

class IWinamp
{

public:

	// virtual destructor
	virtual ~IWinamp()
	{
	}

	/**
	 * return the hosting winamp version
	 * @return the winamp version number
	 */
	virtual int winampVersion(void) =0;

	/**
	 * send a string to the server
	 * TODO may be used for simple authorisation at some point
	 */
	virtual void sendString() = 0;

	/**
	 * move to next song
	 */
	virtual void nextSong(void) = 0;

	/**
	 * move to prior song
	 */
	virtual void previousSong(void) = 0;

	/**
	 *  play the current item in playlist
	 */
	virtual void playSong(void) = 0;

	/**
	 * stop playing
	 */
	virtual void stopSong(void) = 0;

	/**
	 * pause playing
	 */
	virtual void pause(void) = 0;

	/**
	 * query playback status
	 * @return the playback status
	 */
	virtual WAPlaybackStatus getPlaybackStatus(void) = 0;


	/**
	 * returns the playlist item, either title or filename
	 * @return the playlist item property
	 */
	virtual string getPlayListItem(int index, bool title = true) = 0;


	/**
	 * returns the current playlist position
	 * @return the index
	 */
	int getCurrentPlayPosition(void);

	/**
	 * returns the current playlist length
	 * @return the length
	 */
	int getPlaylistLength(void);

	/**
	 * returns the current playlist item and current index, either title or filename
	 * @param index
	 * @param title
	 * @return
	 */
	virtual string getCurrentPlayListItem(int& index, bool title = true) = 0;

	/**
	 * returns the playlist
	 * @return the playlist
	 */
	virtual vector<string>* getPlayList(bool title = true) = 0;

	/**
	 * go to start of playList
	 */
	virtual void playlistStart() = 0;

	/**
	 * go to end of playlist
	 */
	virtual void playlistEnd() = 0;

	/**
	 * sets the current playlist index
	 * @param index
	 */
	virtual void setPlaylistIndex(int index) = 0;

	/**
	 * sets current position to the start of the playlist
	 */
	virtual void startPlaylist(void) = 0;

	/**
	 * deletes the playlist
	 */
	virtual void deletePlaylist(void) = 0;

	/**
	 * performs a stop with fade
	 */
	virtual void stopWithFade(void) = 0;

	/**
	 * stops playback after the current
	 */
	virtual void stopAfterCurrent(void) = 0;

	/**
	 * advances the position in the playlist by 5
	 */
	virtual void forward5(void) = 0;

	/**
	 * rewinds the position in the playlist by 5
	 */
	virtual void back5(void) = 0;

	/**
	 * increments volume
	 */
	virtual void volumeUp(void) = 0;

	/**
	 * decrements volume
	 */
	virtual void volumeDown(void) = 0;

	/**
	 * sets the volume
	 * @param volume
	 */
	virtual void setVolume(int volume) = 0;

	/**
	 * toggles the shuffle option
	 */
	virtual void toggleShuffle(void) = 0;

	/**
	 * toggles the repeat option
	 */
	virtual void toggleRepeat(void) = 0;

	/**
	 * toggles the autoload option
	 */
	virtual void toggleAutoload(void) = 0;

	/**
	 * returns the current song times for length and position
	 * in seconds and milliseconds respectively
	 * @param songLength
	 * @param songPos
	 */
	virtual void getTimes(int& songLength, int& songPos) = 0;

};

} // end of namespace Client

/**
 * namespace for the Winamp server operations
 */
namespace Server
{

using namespace std;

/**
 * interface defining the operations the winamp server component supports
 */
class IWinampServer
{

public:

	// virtual destructor
	virtual ~IWinampServer()
	{
	}

	/**
	 * returns the winamp version rendered as string
	 * @return the winamp version
	 */
	virtual string WinampVersion() = 0;

	/**
	 * executes a Winamp API command
	 * @param MessageToExecute
	 */
	virtual void ExecuteCommand(WinampCommand MessageToExecute) = 0;

	/**
	 * executes a string command
	 * @param CommandString
	 * @param Command
	 */
	virtual void ExecuteStringCommand(char * CommandString, WinampCommand Command) = 0;

	/**
	 * queries an integer property
	 * @param Command
	 * @param Data
	 * @return the property value
	 */
	virtual int QueryInt(WinampCommand Command, int Data) = 0;

	/**
	 * queries a string property
	 * @param Command
	 * @param Data
	 * @return
	 */
	virtual string QueryString(WinampCommand Command, int Data) = 0;

};

} // end of namespace Server
} // end of namespace WinampRemote

#endif // end of IWINAMP_
