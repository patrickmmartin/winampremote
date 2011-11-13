//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
USERES("gen_RPCinterface.res");
USEFORM("AboutF.cpp", frmAbout);
USEUNIT("gen_plugin.cpp");
USEUNIT("RPCErrors.cpp");
USEUNIT("rpcthreadDLL.cpp");
USEUNIT("waint.cpp");
USEFORM("ServerDLLF.cpp", frmMain);
USEFORM("ConfigDLLF.cpp", ConfigForm);
USEUNIT("winampinterface_s.c");
USEUNIT("RFC1060U.cpp");
//---------------------------------------------------------------------------
HINSTANCE g_hinst;
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{

/* need to catch any and all exceptions here
  as under win95 winamp gets very flaky
  if exceptions are allowed to escape*/

  g_hinst = hinst;

  switch(reason){
    case DLL_PROCESS_ATTACH :
    OutputDebugString("gen_RPCinterface.dll process attach");
    break;

    case DLL_THREAD_ATTACH :
    OutputDebugString("gen_RPCinterface.dll thread attach");
    break;

    case DLL_THREAD_DETACH :
    OutputDebugString("gen_RPCinterface.dll thread detach");
    break;

    case DLL_PROCESS_DETACH :
    OutputDebugString("gen_RPCinterface.dll process detach");
    }

  return 1;
}
//---------------------------------------------------------------------------
