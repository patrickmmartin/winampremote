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

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
USEFORM("AboutF.cpp", frmAbout);
USEFORM("ServerDLLF.cpp", frmMain);
USEFORM("ConfigDLLF.cpp", ConfigForm);
USEFORM("DetailsF.cpp", frmDetails);
USEUNIT("gen_plugin.cpp");
USEUNIT("VersionInfoU.cpp");
USEUNIT("rpcthreadDLL.cpp");
USEUNIT("WAINT.CPP");
USEUNIT("RFC1060U.CPP");
USEUNIT("winampinterface_s.c");
USEUNIT("waintstrs.pas");
USEUNIT("remotestrs.pas");
//---------------------------------------------------------------------------
HINSTANCE g_hinst;
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{

  g_hinst = hinst;

  switch(reason){
    case DLL_PROCESS_ATTACH :
      DisableThreadLibraryCalls(hinst);
    break;

    case DLL_THREAD_ATTACH :
    break;

    case DLL_THREAD_DETACH :
    break;

    case DLL_PROCESS_DETACH :
    break;
    }

  return 1;
}
//---------------------------------------------------------------------------
