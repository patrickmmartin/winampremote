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

//
// conremote.cpp
// example minimal straight console mode program
// uses same units as somewhat large window program
// note absence of:
// make file

// uses
//
// RPCFuncsU.cpp         - wrappers for RPC stubs
// RPCFuncsU.h
// RPCErrors.cpp         - helper functions for RPC errors
// RPCErrors.h
// waint.cpp             - helper functions for winamp interface
// waint.h
// winampinterface_c.c   - interface stubs generated from IDL file
// winampinterface.h
//
//
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

//---------------------------------------------------------------------------
USERES("conremote.res");
USEUNIT("waint.cpp");
USEUNIT("RPCFuncsU.cpp");
USEOBJ("bin\winampinterface_c.obj");
//---------------------------------------------------------------------------
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


void winampStatus(void)
{

  switch (IntegerResult(IdentBuf, IPC_ISPLAYING, 0))
  {
    case 0:  cout << "winamp stopped" << endl; break;
    case 1:  cout << "winamp playing" << endl; break;
    case 3:  cout << "winamp paused" << endl; break;
  }
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
      port = "8000";
  }


  try
  {
    GetIdent();

    Bind(address, port);

    cout << endl;
    cout << "\t\t****************************************" << endl;
    cout << "\t\t*   console mode winamp remote client  *" << endl;
    cout << "\t\t*       (C) patrick m martin 2000        *" << endl;
    cout << "\t\t****************************************" << endl << endl;
    cout << "\t\ttalking on " << address << ":" << port  << endl << "\t\tserver: " ;

    cout << "\t\t" << WinampVersion(IntegerResult(IdentBuf, IPC_GETVERSION,  0)) << endl;

    cout << "\t\tcommands: " << endl;
    cout << "\t\tp, s, h, <, >: play, stop, (un)pause, back, forward" << endl;
    cout << "\t\tw, l, x: status, playlist, exit" << endl << endl;

    winampStatus();

    while (loop)
    {
      cout << endl << "command?";
      cin >> inkey;

      switch (inkey)
      {

        case 'l':
          playList();
          break;

        case '>':
          winampNext();
          break;

        case '<':
          winampPrevious();
          break;

        case 'w':
          winampStatus();
          break;

        case 'p':
          winampPlay();
          winampStatus();
          break;

        case 's':
          winampStop();
          winampStatus();
          break;

        case 'h':
          winampPause();
          winampStatus();
          break;

        case 'x':
          cout << "bye...";
          loop = false;
          break;

        case 'g':
          winampGetList();
          break;

        case 't':
          winampSendList();
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

