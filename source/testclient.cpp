/*
winamp remote control suite �Patrick Michael Martin 2000, 2001, 2002

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

    default:
      address = "127.0.0.1";
      port = "\\pipe\\winampremote";
  }


  try
  {

    Bind(address, port);

    ConsoleWinampClient * cwc = new ConsoleWinampClient();

    cout << endl;
    cout << "\t\t****************************************" << endl;
    cout << "\t\t*   console mode winamp remote client  *" << endl;
    cout << "\t\t*       (C) patrick m martin 2000        *" << endl;
    cout << "\t\t****************************************" << endl << endl;
    cout << "\t\ttalking on " << address << ":" << port  << endl << "\t\tserver: " ;

    cout << "\t\t" << WinampVersion(cwc->winampVersion()) << endl;

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
    cout << endl << "RPC failure : " <<E.Message.c_str();
  }

  catch (...)
  // all the rest, and provide some explanation, hopefully
  {
    perror("Unhandled error ");
  }


}

