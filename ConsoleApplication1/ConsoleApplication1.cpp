// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*
use case :
I need to replace the calls of a dll linked at load time, that is depending on other dll linked at load time.

DDO --LT-->	vLSUClient.dll 
			 |--LT-->	Backbone.dll
	--LT-->	Backbone.dll
	--RT--> vLSUClient.dll

what I need :

DDO --LT-->	vLSUClient.dll (trampoline sur NEW/vlSUClient.dll)
				|--??-->	vlSUClientNew.dll
							 |--LT--> NEW/Backbone.dll
				|--LT-->	Backbone.dll
	--LT-->	Backbone.dll
	--RT--> vLSUClient.dll

*/

#include "stdafx.h"
#include <windows.h>
#include <libloaderapi.h>

extern "C" bool __cdecl vLSUDll(LPCSTR);
extern "C" bool __cdecl backboneDll(LPCSTR);

typedef bool(*testFunction)(LPCSTR);

int main()
{
	//HMODULE hModule = LoadLibraryEx(
	//		TEXT("Dll1.dll"),
	//		NULL,
	//	LOAD_LIBRARY_SEARCH_APPLICATION_DIR
	//	);
	
	HMODULE hModule = LoadLibraryA("VLSUClient.dll");
	testFunction dllFunction = (testFunction)GetProcAddress(hModule, "vLSUDll");
	dllFunction("1-DDO");

	vLSUDll("2-DDO");
	backboneDll("3-DDO");

	//HMODULE hModule2 = LoadLibraryA("Dll2/Dll1.dll");
	//dllFunction2 = (testFunction)GetProcAddress(hModule2, "example");
	//dllFunction2();

	//HMODULE hModule2 = LoadLibraryEx(
	//	TEXT("Dll2/Dll1.dll"),
	//	NULL,
	//	LOAD_LIBRARY_SEARCH_APPLICATION_DIR
	//);



    return 0;
}

