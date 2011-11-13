//---------------------------------------------------------------------------
#include <condefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SysUtils.hpp>
#include <WebBroker.hpp>
#include <CGIApp.hpp>
#pragma hdrstop
USEFORM("MainWM.cpp", wmMain); /* TWebModule: File Type */
USERES("WARC.res");
USEUNIT("winampinterface_c.c");
USEUNIT("RPCFuncsU.cpp");
USEUNIT("Waint.cpp");
//---------------------------------------------------------------------------
#define Application Webbroker::Application
#pragma link "cgiapp.obj"
#pragma link "isapiapp.obj"
#pragma link "webbroker.obj"
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TwmMain), &wmMain);
                 Application->Run();
	}
	catch (Exception &exception)
	{
		Sysutils::ShowException(&exception, Sysutils::ExceptAddr());
	}
	return 0;
}
//---------------------------------------------------------------------------
