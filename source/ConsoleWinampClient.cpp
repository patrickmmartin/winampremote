
#include <iostream.h>
#include "windows.h"
#include "stddef.h"

#include "RPCFuncsU.h"
#include "waint.h"
#include "ConsoleWinampClient.h"


char IdentBuf [2 * MAX_COMPUTERNAME_LENGTH + 2];

void GetIdent(void)
{

  char NameBuf [MAX_COMPUTERNAME_LENGTH + 1];
  char ComputerBuf [MAX_COMPUTERNAME_LENGTH + 1];

  unsigned long BufLen;
  BufLen = MAX_COMPUTERNAME_LENGTH + 1;
  GetComputerName(ComputerBuf, &BufLen);
  BufLen = MAX_COMPUTERNAME_LENGTH + 1;
  GetUserName(NameBuf, &BufLen);
  sprintf(IdentBuf, "%s@%s", NameBuf, ComputerBuf);

}




void playList(void)
{

  char title[MAX_PATH];

  int lastlength = IntegerResult(IdentBuf, IPC_GETLISTLENGTH, 0);
  int currentpos = IntegerResult(IdentBuf, IPC_GETLISTPOS, 0);

  cout << endl << "current playlist" << endl << "********" << endl;
  for (int i = 0 ; i < lastlength ; i++)
  {
    strcpy (title, IdentBuf );
    StringResult(title, IPC_GETPLAYLISTTITLE, i);
    cout << title;
    if (i == currentpos)
      cout << " <current>";
    cout << endl;
  }
  cout <<  "********" << endl;

}


WAPlaybackStatus winampStatus(void)
{
  WAPlaybackStatus status = (WAPlaybackStatus) IntegerResult(IdentBuf, IPC_ISPLAYING, 0);
  switch (status)
  {
    case WA_NOT_PLAYING:  cout << "winamp stopped" << endl; break;
    case WA_PLAYING:  cout << "winamp playing" << endl; break;
    case WA_PAUSED:  cout << "winamp paused" << endl; break;
  }
  return status;
}

void winampNext(void)
{
  ExecuteMessage(IdentBuf, WINAMP_NEXT);
}

void winampPrevious(void)
{
  ExecuteMessage(IdentBuf, WINAMP_PREVIOUS);
}

void winampPlay(void)
{
  ExecuteMessage(IdentBuf, WINAMP_PLAYENTRY);
}

void winampStop(void)
{
  ExecuteMessage(IdentBuf, WINAMP_STOP);
}

void winampPause(void)
{
  ExecuteMessage(IdentBuf, WINAMP_PAUSE);
}


void winampSendList(void)
{
//  SendList();
}


void winampGetList(void)
{
//  GetList();
}



ConsoleWinampClient::ConsoleWinampClient()
{
    GetIdent();
};

void ConsoleWinampClient::nextSong(void){
    ::winampNext();
};

void ConsoleWinampClient::previousSong(void){
    ::winampPrevious();
};

void ConsoleWinampClient::playSong(void){
    ::winampPlay();
};

void ConsoleWinampClient::stopSong(void){
    ::winampStop();
};

void ConsoleWinampClient::pause(void){
    ::winampPause();
};

WAPlaybackStatus ConsoleWinampClient::getPlaybackStatus(void){
    return ::winampStatus();
};

vector<string>* ConsoleWinampClient::getPlayList(void){
    ::playList();
    // TODO - port code into here
    return new vector<string>;

};

int ConsoleWinampClient::winampVersion(void){
    return IntegerResult(IdentBuf, IPC_GETVERSION,  0);
};






