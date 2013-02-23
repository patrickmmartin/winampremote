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


	virtual int winampVersion(void);

	virtual void sendString();

	virtual void nextSong(void);

	virtual void previousSong(void);

	virtual void playSong(void);

	virtual void stopSong(void);

	virtual void pause(void);

	virtual WAPlaybackStatus getPlaybackStatus(void);

	virtual string getPlayListItem(int index, bool title = true);

	virtual int getCurrentPlayPosition(void);

	virtual int getPlaylistLength(void);

	virtual string getCurrentPlayListItem(int& index, bool title = true);

	virtual vector<string>* getPlayList(bool title = true);

	virtual void setPlayList(vector<string>& playlist);

	virtual void playlistStart();

	virtual void playlistEnd();

	virtual void setPlaylistIndex(int index);

	virtual void startPlaylist(void);

	virtual void deletePlaylist(void);

	virtual void stopWithFade(void);

	virtual void stopAfterCurrent(void);

	virtual void setTime(int time);

	virtual int getTime();

	virtual void forward5(void);

	virtual void back5(void);

	virtual void volumeUp(void);

	virtual void volumeDown(void);

	virtual void setVolume(int volume);

	virtual int getVolume();

	virtual void setPanning(int panning);

	virtual int getPanning();

	virtual void toggleShuffle(void);

	virtual int getShuffle(void);

	virtual void setShuffle(bool shuffle);

	virtual void toggleRepeat(void);

	virtual int getRepeat(void);

	virtual void setRepeat(bool repeat);

	virtual void toggleAutoload(void);

	virtual int getAutoload(void);

	virtual void setAutoload(bool value);

	virtual int getEQData(int eqindex);

	void setEQData(int eqindex, byte eqvalue);

	virtual void getTimes(int& songLength, int& songPos);

	virtual std::string getStringList(WinampCommand Command);

	virtual void setStringList(std::string list, WinampCommand Command);



};
} // end of namespace Client
} // end of namespace WinampRemote

#endif // WINAMPCLIENTBASE_H
