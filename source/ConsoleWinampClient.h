#ifndef CONSOLEWINAMPCLIENT_H
#define CONSOLEWINAMPCLIENT_H

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
class ConsoleWinampClient: public IWinamp
{

public:

	/**
	 * no - params constructor
	 */
	ConsoleWinampClient();

	/**
	 * destructor
	 */
	virtual ~ConsoleWinampClient()
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

#endif // CONSOLEWINAMPCLIENT_H
