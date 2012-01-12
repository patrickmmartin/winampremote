/*
winamp remote control suite ©Patrick Michael Martin 2000, 2001, 2002

Copyright (C) 2000,2001,2002  Patrick M. Martin

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Patrick M. Martin may be reached by email at patrickmmartin@gmail.com.
*/

// required for USEUNIT macro to work
#include"condefs.h"

//
#include "stddef.h"

#include <iostream.h>
#include "windows.h"

#include "winampinterface.h"

#ifndef WAINT_NO_VCL
  #include <vcl.h>
#endif

// to force the RPC functions unit to use a non-VCL exception #define NO_VCL_EXCEPTION
#include "RPCFuncsU.h"

// to force the waint unit to unit non-VCL, non localised, #define WAINT_NO_VCL
#include "waint.h"

#include <iostream.h>

#include "RPCFuncsU.h"

#include "ConsoleWinampClient.h"

int main(int argc , char* argv[] )
{


char * address;
char * port;

  switch (argc)
  {
    case 2:
      port = argv[1];
      address = "127.0.0.1";
      break;

    case 3:
      port = argv[1];
      address = argv[2];
      break;

    default:
      address = "127.0.0.1";
      port = "\\pipe\\winampremote";
  }


  try
  {

    Bind(address, port);

    WinampRemote::Client::ConsoleWinampClient * cwc = new WinampRemote::Client::ConsoleWinampClient();

    cout << "playback status " << cwc->getPlaybackStatus() << endl;
    cwc->getPlaybackStatus();
    std::auto_ptr< vector<string> > playList (cwc->getPlayList() );
    if (playList.get())
      cout << "playlist size " << playList->size() << std::endl;

    cout << "next song" << std::endl;
    cwc->nextSong();
    cout << "previous song"  << std::endl;
    cwc->previousSong();
    cout << "pause"  << std::endl;
    cwc->pause();
    cout << "play" << std::endl;
    cwc->playSong();
    cout << "stop" << std::endl;
    cwc->stopSong();

    UnBind();
    return 0;
  }

  catch (ERPCException& E)
  // the errors I understand
  {
    UnBind();
    cout << endl << "RPC failure : " <<E.Message.c_str();
  }

  catch (...)
  // TODO: all the rest, and provide some explanation, ideally
  {
    perror("Unhandled error ");
  }


}

