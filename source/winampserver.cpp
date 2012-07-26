//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEUNIT("waint.cpp");
USEFORM("ConfigF.cpp", ConfigForm);
USEFORM("AboutF.cpp", frmAbout);
USEUNIT("rpcthread.cpp");
USEUNIT("RPCErrors.cpp");
USEFORM("ServerF.cpp", frmMain);
USELIB("..\lib\winampinterface.lib");
USEUNIT("ConsoleCallObserver.cpp");
USERC("winampremote.rc");
USEUNIT("WinampServerImpl.cpp");
USERES("winampserver.RES");
//---------------------------------------------------------------------------
#include "ServerF.h"
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->Title = "winamp remote server";
        Application->CreateForm(__classid(TfrmMain), &frmMain);
                 Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
