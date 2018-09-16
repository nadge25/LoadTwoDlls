// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <string>


extern "C" bool __cdecl backboneDll(LPCSTR);
//extern "C" bool __cdecl vLSUDll2(LPCSTR);


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		backboneDll("vLSU");
		break;
    case DLL_THREAD_ATTACH:
		break;
    case DLL_THREAD_DETACH:
		break;
    case DLL_PROCESS_DETACH:
		OutputDebugString(L"DLL 1 out\n");
		break;
    }
    return TRUE;
}

extern "C" __declspec (dllexport) bool vLSUDll(LPCSTR _str)
{
	std::string message("vlsu called from " + std::string(_str));
	MessageBoxA(NULL, message.c_str(), "test", NULL);

	HMODULE hModule2 = LoadLibraryEx(
		TEXT("vLSUClient/vLSUClientNew.dll"),
		NULL,
		LOAD_LIBRARY_SEARCH_APPLICATION_DIR
	);
	typedef bool(*testFunction)(LPCSTR);

	testFunction vLSUDll2 = (testFunction)GetProcAddress(hModule2, "vLSUDll2");
	vLSUDll2("vlsu");

	return true;
}