/*
winamp remote control suite ©Patrick Michael Martin 2000-2011

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


#include <iostream.h>

#include "RPCBind.h"
#include "RPCException.h"

#include "WinampClientBase.h"

// TODO: hack for link failure
#include "sysutils.hpp"

int main(int argc , char* argv[] )
{


char inkey;
bool loop = true;
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

    default: // no break
      address = "127.0.0.1";
      port = "\\pipe\\winampremote";
      break;
  }


  try
  {

    Bind(address, port, pszProtocolSequenceNP);

    WinampRemote::Client::WinampClientBase * cwc = new WinampRemote::Client::WinampClientBase();

    cout << endl;
    cout << "\t\t****************************************" << endl;
    cout << "\t\t*   console mode winamp remote client  *" << endl;
    cout << "\t\t*       (C) patrick m martin 2000        *" << endl;
    cout << "\t\t****************************************" << endl << endl;
    cout << "\t\ttalking on " << address << ":" << port  << endl << "\t\tserver: " ;

    cout << "\t\t" << WinampVersionString(cwc->winampVersion()) << endl;

    cout << "\t\tcommands: " << endl;
    cout << "\t\tp, s, h, <, >: play, stop, (un)pause, back, forward" << endl;
    cout << "\t\tw, l, x: status, playlist, exit" << endl << endl;

    cwc->getPlaybackStatus();

    while (loop)
    {
      cout << endl << "command?";
      cin >> inkey;

      switch (inkey)
      {

        case 'l':
          cwc->getPlayList();
          break;

        case '>':
          cwc->nextSong();
          break;

        case '<':
          cwc->previousSong();
          break;

        case 'w':
          cwc->pause();
          break;

        case 'p':
          cwc->playSong();
          cwc->getPlaybackStatus();
          break;

        case 's':
          cwc->stopSong();
          cwc->getPlaybackStatus();
          break;

        case 'h':
          cwc->pause();
          cwc->getPlaybackStatus();
          break;

        case 'x':
          cout << "bye...";
          loop = false;
          break;

        case 't':
          /* nothing yet */
          break;


        default:
          cout << inkey << " not understood\r\n" ;

      }
    }

    UnBind();
    return 0;
  }

  catch (ERPCException& E)
  // the errors I understand
  {
    UnBind();
    cout << endl << "RPC failure : " <<E.what();
  }

  catch (...)
  // all the rest, and provide some explanation, hopefully
  {
    perror("Unhandled error ");
  }

  return 0;


}

