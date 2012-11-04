// plugin.cpp : Defines the exported functions for the DLL application.
//

#include "plugin.h"


/*
winamp remote control suite ©Patrick Michael Martin 2000, 2001, 2012

Copyright (C) 2000,2001,2012  Patrick M. Martin

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

#pragma hdrstop

char VerString[MAX_PATH + 1] = "";

winampGeneralPurposePlugin plugin =
{
	GPPHDR_VER,
	VerString,
	init,
	config,
	quit,
    0,
    0
};


void config();
void quit();
int init();



extern "C" __declspec(dllexport) winampGeneralPurposePlugin *   __cdecl winampGetGeneralPurposePlugin()
{

  strncpy_s(VerString,
          "Winamp Remote Control Suite remote control",
          MAX_PATH);

  OutputDebugString("gen_remotecontrol get config");
  return &plugin;
}




void config(void)
{
  OutputDebugString("gen_remotecontrol config");
}



void quit(void)
{
  OutputDebugString("gen_remotecontrol quit");
}



int init()
{
  OutputDebugString("gen_remotecontrol init");
  return 0;
}