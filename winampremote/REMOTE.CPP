//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "SplashF.h"

USERES("remote.res");
USEFORM("messageF.cpp", frmMessage);
USEUNIT("waint.cpp");
USEFORM("AboutF.cpp", frmAbout);
USEUNIT("RPCErrors.cpp");
USEFORM("PlaylistF.cpp", frmPlaylist);
USEFORM("SettingsF.cpp", frmSettings);
USEFORM("MainF.cpp", frmMain);
USEFORM("CommandF.cpp", frmCommands);
USEFORM("SplashF.cpp", frmSplash);
USEUNIT("winampinterface_c.c");
USEFORM("ServersF.cpp", frmServers);
USEUNIT("RFC1060U.cpp");
USEUNIT("IPAddressU.cpp");
USEUNIT("ColourU.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE hInstance, LPSTR, int)
{
    try
    {
    Application->Title = "winamp remote client";
    frmSplash = new TfrmSplash(Application);
    try{
        frmSplash->Show();
        frmSplash->Refresh();
        frmSplash->lblMessage->Caption = "initialising application";
        frmSplash->lblMessage->Refresh();
        Application->Initialize();
        frmSplash->lblMessage->Caption = "creating main form";
        frmSplash->lblMessage->Refresh();
        Application->CreateForm(__classid(TfrmMain), &frmMain);
                 Application->CreateForm(__classid(TfrmMessage), &frmMessage);
                 Application->CreateForm(__classid(TfrmPlaylist), &frmPlaylist);
                 Application->CreateForm(__classid(TfrmSettings), &frmSettings);
                 Application->CreateForm(__classid(TfrmCommands), &frmCommands);
                 frmSplash->lblMessage->Caption = "ready to run";
        frmSplash->lblMessage->Refresh();
        frmSplash->Close();
        Application->Run();
        frmSplash->Show();
        frmSplash->lblMessage->Caption = "closing";
        frmSplash->lblMessage->Refresh();
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
