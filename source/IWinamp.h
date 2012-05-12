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
	 * returns the playlist
	 * @return the playlist
	 */
	virtual vector<string>* getPlayList(void) = 0;

	/**
	 * return the hosting winamp version
	 * @return the winamp version number
	 */
	virtual int winampVersion(void) =0;

};

} // end of namespace Client

/**
 * interface defining the operations Winamp supports for clients
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

	string WinampVersion();

	void ExecuteCommand(WinampCommand MessageToExecute);

	void ExecuteStringCommand(char * CommandString, WinampCommand Command);

	int QueryInt(WinampCommand Command, int Data);

	string QueryString(WinampCommand Command, int Data);

};

} // end of namespace Server
} // end of namespace WinampRemote

#endif // end of IWINAMP_
