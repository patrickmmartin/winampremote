#ifndef IWINAMP_H
#define IWINAMP_H

#include <vector>
#include <string>

#include "waint.h"

// abstract interface defining the operations Winamp supports

namespace WinampRemote {

  namespace Client {

  class IWinamp {

    public:

      // virtual destructor
      virtual ~IWinamp() {}

      // TODO: perhaps all the command functions should return the status -
      // best implemented in the plugin

      // move to next song
      virtual void nextSong(void) = 0;

      // move to prior song
      virtual void previousSong(void) = 0;

      // play the current item in playlist
      virtual void playSong(void) = 0;

      // stop playing
      virtual void stopSong(void) = 0;

      // pause playing
      virtual void pause(void) = 0;

      // query playback status
      virtual WAPlaybackStatus getPlaybackStatus(void) = 0;

      // return the playlist
      virtual vector<string>* getPlayList(void) = 0;

      // return the hosting winamp version
      virtual int winampVersion(void) =0;

  };

  }  // end of namespace
}  // end of namespace
#endif // end of IWINAMP_
