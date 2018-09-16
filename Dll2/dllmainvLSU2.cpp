// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <string>

//extern "C" bool __cdecl backboneDll(LPCSTR);

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		OutputDebugString(L"DLL 2 out\n");
		break;
	}
    return TRUE;
}

extern "C" __declspec (dllexport) bool vLSUDll2(LPCSTR _str)
{
	HMODULE hModule2 = LoadLibraryEx(
		TEXT("vLSUClient/Backbone.dll"),
		NULL,
		LOAD_LIBRARY_SEARCH_APPLICATION_DIR
	);
	typedef bool(*testFunction)(LPCSTR);

	testFunction backboneDll = (testFunction)GetProcAddress(hModule2, "backboneDll");
	backboneDll("vLSU2");

	std::string message("vlsu2 called from " + std::string(_str));
	MessageBoxA(NULL, message.c_str(), "test", NULL);
	return true;
}
