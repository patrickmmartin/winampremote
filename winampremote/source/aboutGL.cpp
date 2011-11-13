//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("aboutGL.res");
USEFORM("AboutF.cpp", frmAbout);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TfrmAbout), &frmAbout);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
