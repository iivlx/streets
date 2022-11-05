#include <iostream>
#include <Windows.h>
#include <tchar.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD nReason, LPVOID lpReserved) {
	HANDLE hThread;
	TCHAR pszMessage[1024] = { 0 };

	_stprintf_s(pszMessage, _T("hModule 0x%p, nReason %d\r\n"), hModule, nReason);

	switch (nReason) {
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}

	return TRUE;
}