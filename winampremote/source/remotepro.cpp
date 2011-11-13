// winamp remote control suite ©Patrick Michael Martin 2000
//
// remote.cpp
//
// remote control client application using RPC interface 
//

//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

USERES("remotepro.res");
USEFORM("MessageProF.cpp", frmMessage);
USEFORM("AboutF.cpp", frmAbout);
USEFORM("PlaylistProF.cpp", frmPlaylist);
USEFORM("MainProF.cpp", frmMain);
USEUNIT("winampinterface_c.c");
USEUNIT("RFC1060U.cpp");
USEUNIT("IPAddressU.cpp");
USEUNIT("ColourU.cpp");
USEUNIT("RPCFuncsU.cpp");
USEFILE("frontend.txt");
USEUNIT("VersionInfoU.cpp");
USEFORM("DetailsF.cpp", frmDetails);
USEUNIT("waint.cpp");
//---------------------------------------------------------------------------
HINSTANCE g_hinst;

WINAPI WinMain(HINSTANCE, HINSTANCE hInstance, LPSTR, int)
{
  g_hinst = hInstance;
    try
    {
    Application->Title = "winamp remote PRO";
    Application->Initialize();
    Application->CreateForm(__classid(TfrmMain), &frmMain);
    Application->CreateForm(__classid(TfrmPlaylist), &frmPlaylist);
    Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
