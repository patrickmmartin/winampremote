#ifndef IWINAMP_H
#define IWINAMP_H

#include <vector>
#include <string>

#include "waint.h" // for WAPlaybackStatus, etc.
#include "winampinterface.h" // for byte

using namespace std;

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
	virtual int winampVersion(void) const = 0;

	/**
	 * send a string to the server
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
	virtual WAPlaybackStatus getPlaybackStatus(void) const = 0;


	/**
	 * returns the playlist item, either title or filename
	 * @return the playlist item property
	 */
	virtual string getPlayListItem(int index, bool title = true) const = 0;


	/**
	 * returns the current playlist position
	 * @return the index
	 */
	virtual int getCurrentPlayPosition(void) const = 0;

	/**
	 * returns the current playlist length
	 * @return the length
	 */
	virtual int getPlaylistLength(void) const = 0;

	/**
	 * returns the current playlist item and current index, either title or filename
	 * @param index
	 * @param title
	 * @return
	 */
	virtual string getCurrentPlayListItem(int& index, bool title = true) const = 0;

	/**
	 * returns the playlist
	 * @return the playlist
	 */
	virtual vector<string> getPlayList(bool title = true) const = 0;

	/**
	 * sets the playlist on the server
	 * @param playlist
	 */
	virtual void setPlayList(const vector<string>& playlist) = 0;


	/**
	 * inserts the passed playlist into the existing playlist,
	 * beginning from the passed position
	 * @param playlist
	 * @param position
	 */
	virtual void insertPlayList(const vector<string>& playlist, int position) = 0;

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
	 * sets the current song time position
	 * @param time
	 */
	virtual void setTime(int time) = 0;


	/**
	 * gets the current song time position
	 */
	virtual int getTime() const = 0;


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
	 * returns the volume
	 */
	virtual int getVolume() const = 0;

	/**
	 * sets the panning
	 * @param panning
	 */
	virtual void setPanning(int panning) = 0;

	/**
	 * returns the panning
	 */
	virtual int getPanning() const = 0;

	/**
	 * toggles the shuffle option
	 */
	virtual void toggleShuffle(void) = 0;

	/**
	 * returns the shuffle option
	 */
	virtual int getShuffle(void) const = 0;

	/**
	 * set the shuffle option
	 * @param shuffle
	 */
	virtual void setShuffle(bool shuffle) = 0;

	/**
	 * toggles the repeat option
	 */
	virtual void toggleRepeat(void) = 0;

	/**
	 * returns the repeat option
	 */
	virtual int getRepeat(void) const = 0;

	/**
	 * sets the repeat option
	 */
	virtual void setRepeat(bool repeat) = 0;

	/**
	 * toggles the EQ On option
	 */
	virtual void toggleEQOn(void) = 0;

	/**
	 * returns the EQ On option
	 */
	virtual int getEQOn(void) const = 0;

	/**
	 * sets the EQ On option
	 * @param value
	 */
	virtual void setEQOn(bool value) = 0;

	/**
	 * toggles the autoload option
	 */
	virtual void toggleAutoload(void) = 0;

	/**
	 * returns the autoload option
	 */
	virtual int getAutoload(void) const = 0;

	/**
	 * sets the autoload options
	 * @param value
	 */
	virtual void setAutoload(bool value) = 0;

	/**
	 * returns the eq data
	 */
	virtual int getEQData(int eqindex) const = 0;

	/**
	 * sets the eq data
	 */
	virtual void setEQData(int eqindex, byte eqvalue) = 0;

	/**
	 * returns the current song times for length and position
	 * in seconds and milliseconds respectively
	 * @param songLength
	 * @param songPos
	 */
	virtual void getTimes(int& songLength, int& songPos) const = 0;


	/**
	 * returns the string list run over all the playlist for the given StringResult command
	 * @param Command
	 * @return the returns in TStrings format
	 */
	virtual std::string getStringList(WinampCommand Command) const = 0;


	/**
	 * apply the passed list of string values in TStrings format with the passed command
	 * @param list
	 * @param Command
	 */
	virtual void setStringList(const std::string& list, WinampCommand Command) = 0;




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
	virtual void ExecuteStringCommand(const char * CommandString, WinampCommand Command) = 0;

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
