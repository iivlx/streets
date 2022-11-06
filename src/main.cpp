#include <iostream>
#include <Windows.h>
#include <tchar.h>

#include "mod.h"

void DllProccessAttach(HMODULE hModule) {
  HANDLE hThread;
  OutputDebugString(_T("PROCESS_ATTACH: Creating Thread"));
  hThread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)mod, hModule, 0, nullptr);
  OutputDebugString(_T("[+] Loaded ASI"));
  if (hThread != 0) CloseHandle(hThread);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD nReason, LPVOID lpReserved) {
  HANDLE hThread;
  TCHAR pszMessage[1024] = { 0 };
  
  _stprintf_s(pszMessage, _T("hModule 0x%p, nReason %d\r\n"), hModule, nReason);
  
  switch (nReason) {
	  case DLL_PROCESS_ATTACH:
      DllProccessAttach(hModule);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
      break;
  }
  
  return TRUE;
}