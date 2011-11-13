//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("winampclient.res");
USEFORM("ClientF.cpp", frmMain);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->Title = "Winamp Remote Control Test";
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
