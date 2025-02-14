// this is malicious dll

#include <windows.h>
#pragma comment(lib, "user32.lib");

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID LpReserved){
    switch (dwReason) 
    {
    case DLL_PROCESS_ATTACH:
       MessageBoxW(NULL, L"Hello, El-Noir", L"Cosmodium", MB_ICONEXCLAMATION | MB_OK); 
        break;
    }
    return TRUE;
}