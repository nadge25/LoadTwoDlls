// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <string>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec (dllexport) bool backboneDll(LPCSTR _str)
{
	std::string message("backboneDll2 called from " + std::string(_str));
	MessageBoxA(NULL, message.c_str(), "test", NULL);
	return true;
}