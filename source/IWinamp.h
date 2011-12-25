#ifndef IWINAMP_H
#define IWINAMP_H

#include <vector>
#include <string>

#include "waint.h"

// abstract interface defining the operations Winamp supports

class IWinamp {

  public:

    virtual ~IWinamp() {}

    virtual void nextSong(void) = 0;

    virtual void previousSong(void) = 0;

    virtual void playSong(void) = 0;

    virtual void stopSong(void) = 0;

    virtual void pause(void) = 0;

    virtual WAPlaybackStatus getPlaybackStatus(void) = 0;

    virtual vector<string>* getPlayList(void) = 0;

    virtual int winampVersion(void) =0;


};

#endif // end of IWINAMP_
