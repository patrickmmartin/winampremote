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


	virtual int winampVersion(void) const;

	virtual void sendString();

	virtual void nextSong(void);

	virtual void previousSong(void);

	virtual void playSong(void);

	virtual void stopSong(void);

	virtual void pause(void);

	virtual WAPlaybackStatus getPlaybackStatus(void) const;

	virtual string getPlayListItem(int index, bool title = true) const;

	virtual int getCurrentPlayPosition(void) const;

	virtual int getPlaylistLength(void) const;

	virtual string getCurrentPlayListItem(int& index, bool title = true) const;

	virtual vector<string> getPlayList(bool title = true) const;

	virtual void setPlayList(const vector<string>& playlist);

	virtual void insertPlayList(const vector<string>& playlist, int position);

	virtual void playlistStart();

	virtual void playlistEnd();

	virtual void setPlaylistIndex(int index);

	virtual void startPlaylist(void);

	virtual void deletePlaylist(void);

	virtual void stopWithFade(void);

	virtual void stopAfterCurrent(void);

	virtual void setTime(int time);

	virtual int getTime() const;

	virtual void forward5(void);

	virtual void back5(void);

	virtual void volumeUp(void);

	virtual void volumeDown(void);

	virtual void setVolume(int volume);

	virtual int getVolume() const;

	virtual void setPanning(int panning);

	virtual int getPanning() const;

	virtual void toggleShuffle(void);

	virtual int getShuffle(void) const;

	virtual void setShuffle(bool shuffle);

	virtual void toggleRepeat(void);

	virtual int getRepeat(void) const;

	virtual void setRepeat(bool repeat);

	virtual void toggleEQOn(void);

	virtual int getEQOn(void) const;

	virtual void setEQOn(bool value);

	virtual void toggleAutoload(void);

	virtual int getAutoload(void) const;

	virtual void setAutoload(bool value);

	virtual int getEQData(int eqindex) const;

	void setEQData(int eqindex, byte eqvalue);

	virtual void getTimes(int& songLength, int& songPos) const;

	virtual std::string getStringList(WinampCommand Command) const;

	virtual void setStringList(const std::string& list, WinampCommand Command);



};
} // end of namespace Client
} // end of namespace WinampRemote

#endif // WINAMPCLIENTBASE_H
