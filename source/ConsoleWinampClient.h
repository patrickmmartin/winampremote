#ifndef CONSOLEWINAMPCLIENT_H
#define CONSOLEWINAMPCLIENT_H

#include "IWinamp.h"

// concrete implementation of IWinamp

class ConsoleWinampClient : public IWinamp  {

  public:

    ConsoleWinampClient();

    virtual ~ConsoleWinampClient() {}

    virtual void nextSong(void);

    virtual void previousSong(void);

    virtual void playSong(void);

    virtual void stopSong(void);

    virtual void pause(void);

    virtual WAPlaybackStatus getPlaybackStatus(void);

    virtual vector<string>* getPlayList(void);

    virtual int winampVersion(void);

};

#endif // CONSOLEWINAMPCLIENT_H 
