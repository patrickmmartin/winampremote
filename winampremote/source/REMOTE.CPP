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
#include "SplashF.h"

USEFORM("AboutF.cpp", frmAbout);
USEFORM("SettingsF.cpp", frmSettings);
USEFORM("CommandF.cpp", frmCommands);
USEFORM("ServersF.cpp", frmServers);
USEFORM("DetailsF.cpp", frmDetails);
USEFORM("PlaylistF.cpp", frmPlaylist);
USEFORM("SplashF.cpp", frmSplash);
USEFORM("MainF.cpp", frmMain);
USEFORM("messageF.cpp", frmMessage);
USEUNIT("waintstrs.pas");
USEUNIT("remotestrs.pas");
USEUNIT("winampinterface_c.c");
USEUNIT("RPCFuncsU.cpp");
USEUNIT("binding.c");
USEUNIT("WAINT.CPP");
USEUNIT("ColourU.cpp");
USEUNIT("RFC1060U.CPP");
USEUNIT("IPAddressU.cpp");
USEUNIT("VersionInfoU.cpp");
//---------------------------------------------------------------------------
#include "remotestrs.hpp"
#include "waintstrs.hpp"
//---------------------------------------------------------------------------
HINSTANCE g_hinst;

WINAPI WinMain(HINSTANCE, HINSTANCE hInstance, LPSTR, int)
{
  g_hinst = hInstance;
    try
    {
    Application->Title = Remotestrs_sWinampRemoteClient;
    frmSplash = new TfrmSplash(Application);
    try{
        frmSplash->Show();
        frmSplash->Update();
        frmSplash->lblMessage->Caption = Remotestrs_sInitialisingApplication;
        frmSplash->lblMessage->Update();
        Application->Initialize();
        frmSplash->lblMessage->Caption = Remotestrs_sCreatingMainForm;
        frmSplash->lblMessage->Update();
        Application->CreateForm(__classid(TfrmMain), &frmMain);
                 Application->CreateForm(__classid(TfrmPlaylist), &frmPlaylist);
                 Application->CreateForm(__classid(TfrmCommands), &frmCommands);
                 Application->CreateForm(__classid(TfrmSettings), &frmSettings);
                 frmSplash->lblMessage->Caption = Remotestrs_sReadyToRun;
        frmSplash->lblMessage->Update();
        delete frmSplash;
        frmSplash = NULL;
        Application->Run();
        frmSplash = new TfrmSplash(Application);
        frmSplash->lblMessage->Caption = Remotestrs_sClosing;
        frmSplash->lblMessage->Update();
        Sleep(200);
        }
      __finally{
        delete frmSplash;
        }
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
