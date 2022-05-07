// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <windows.h>
#include <shlobj.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        system("start calc");
        if (IsUserAnAdmin()) {
            MessageBoxA(NULL, "poxeked, i have admin privileges", "poxek", MB_ICONWARNING);
        }
        else {
            MessageBoxA(NULL, "poxeked, but i don\'t have admin privileges", "poxek", MB_ICONERROR);
        }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

