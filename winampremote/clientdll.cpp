//---------------------------------------------------------------------------
#pragma hdrstop

#include <vcl.h>
#include <windows.h>

// force the RPC functions unit to use a non-VCL exception
#define NO_VCL_EXCEPTION
// get the nice wrappers in the RPC functions unit
#include "RPCFuncsU.cpp"
// RPC error descriptions
#include "RPCErrors.cpp"
// winamp interface declarations
#include "waint.cpp"
// the auto-generated RPC stubs actually used
#include "winampinterface_c.c"


#pragma resource "clientdll.res"

//---------------------------------------------------------------------------
extern "C"
{

__declspec(dllexport) __stdcall void Bind(unsigned char * NetworkAddress, unsigned char * EndPoint);
__declspec(dllexport) __stdcall void UnBind(void);

__declspec(dllexport) __stdcall void SendString(char * pszString);
__declspec(dllexport) __stdcall void ExecuteMessage(char * pszString, int command);
__declspec(dllexport) __stdcall void ExecuteStringMessage(char * pszString, char * pszParam, int command);
__declspec(dllexport) __stdcall int StringResult(char * pszString, int command, int data);
__declspec(dllexport) __stdcall int IntegerResult(char * pszString, int command, int data);
__declspec(dllexport) __stdcall void Shutdown(void);


}



//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
        return 1;
}
//---------------------------------------------------------------------------

