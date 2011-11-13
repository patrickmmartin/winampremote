//---------------------------------------------------------------------------
#include <WebBroker.hpp>
#include <ISAPIApp.hpp>
#include <Isapi2.hpp>
#pragma hdrstop

USEFORM("MainWM.cpp", wmMain); /* TWebModule: File Type */
USEUNIT("winampinterface_c.c");
USEUNIT("RPCFuncsU.cpp");
USEUNIT("Waint.cpp");
//---------------------------------------------------------------------------
#define Application Webbroker::Application

#pragma link "isapiapp.obj"
#pragma link "cgiapp.obj"
#pragma link "webbroker.obj"
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TwmMain), &wmMain);
                 Application->Run();
	}
	catch (Exception &exception)
	{
	}
	return 1;
}
//---------------------------------------------------------------------------
extern "C"
{
  BOOL __declspec(dllexport) WINAPI GetExtensionVersion(Isapi2::THSE_VERSION_INFO &Ver)
  {
      return Isapiapp::GetExtensionVersion(Ver);
  }
  //---------------------------------------------------------------------------
  unsigned __declspec(dllexport) WINAPI HttpExtensionProc(Isapi2::TEXTENSION_CONTROL_BLOCK &ECB)
  {
      return Isapiapp::HttpExtensionProc(ECB);
  }
  //---------------------------------------------------------------------------
  BOOL __declspec(dllexport) WINAPI TerminateExtension(int dwFlags)
  {
      return Isapiapp::TerminateExtension(dwFlags);
  }
}
//---------------------------------------------------------------------------
#undef Application
//---------------------------------------------------------------------------
