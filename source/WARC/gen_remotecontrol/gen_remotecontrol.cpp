// gen_remotecontrol.cpp : Defines the entry point for the DLL application.

#include "windows.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID /* lpReserved */)
{
	// TODO: might be handy to log some events here
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH :		  
		  DisableThreadLibraryCalls(hModule);
		break;

		case DLL_THREAD_ATTACH :
		break;

		case DLL_THREAD_DETACH :
		break;

		case DLL_PROCESS_DETACH :
		break;
    }
	return TRUE;
}

