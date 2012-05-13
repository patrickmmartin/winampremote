#ifndef WINAMPCLIENTBASE_H
#define WINAMPCLIENTBASE_H

#include "IWinamp.h"

/**
 * namespace for the WinampRemote project
 */
namespace WinampRemote
{

/**
 * namespace for the use of client classes
 */
namespace Client
{

/**
 * A concrete implementation of the a IWinamp client for console use
 */
class WinampClientBase: public IWinamp
{

public:

	/**
	 * no - params constructor
	 */
	WinampClientBase();

	/**
	 * destructor
	 */
	virtual ~WinampClientBase()
	{
	}

	virtual void nextSong(void);

	virtual void previousSong(void);

	virtual void playSong(void);

	virtual void stopSong(void);

	virtual void pause(void);

	virtual WAPlaybackStatus getPlaybackStatus(void);

	virtual vector<string>* getPlayList(void);

	virtual int winampVersion(void);

};
} // end of namespace Client
} // end of namespace WinampRemote

#endif // WINAMPCLIENTBASE_H
