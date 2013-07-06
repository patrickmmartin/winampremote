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

#include <vcl.h>
#pragma hdrstop

USEFORM("AboutF.cpp", frmAbout);
USEFORM("SettingsF.cpp", frmSettings);
USEFORM("CommandF.cpp", frmCommands);
USEFORM("ServersF.cpp", frmServers);
USEFORM("DetailsF.cpp", frmDetails);
USEFORM("PlaylistF.cpp", frmPlaylist);
USEFORM("MainF.cpp", frmMain);
USEFORM("messageF.cpp", frmMessage);
USEUNIT("RPCFuncsU.cpp");
USEUNIT("WAINT.CPP");
USEUNIT("ColourU.cpp");
USEUNIT("RFC1060U.CPP");
USEUNIT("VersionInfoU.cpp");
USELIB("..\lib\winampinterface.lib");
USEUNIT("remotestrs.cpp");
USE("remotestrs.h", File);
USERC("winampremote.rc");
USEUNIT("ServerEnumerator.cpp");
USEUNIT("ServerTester.cpp");
USERC("windowsthemes.rc");
USEUNIT("GlassExtender.cpp");
USERES("remote.RES");
USEUNIT("WinampClientBase.cpp");
USEUNIT("IPAddressResolver.cpp");
USEUNIT("CursorGuard.cpp");
USEUNIT("AboutGLDisplay.cpp");
//---------------------------------------------------------------------------
#include "remotestrs.h"

WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application->Title = sWinampRemoteClient;
    try{
        Application->Initialize();
        Application->CreateForm(__classid(TfrmMain), &frmMain);
                 Application->CreateForm(__classid(TfrmPlaylist), &frmPlaylist);
                 Application->CreateForm(__classid(TfrmCommands), &frmCommands);
                 Application->CreateForm(__classid(TfrmSettings), &frmSettings);
                 Application->Run();
        }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}

