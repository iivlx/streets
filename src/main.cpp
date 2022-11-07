#include <iostream>
#include <Windows.h>
#include <tchar.h>

#include "interface.h"
#include "mod.h"

Interface* iface = new Interface();

void DllProccessAttach(HMODULE hModule) {
  HANDLE hThread;
  hThread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)mod, hModule, 0, nullptr);
  if (DEBUG) OutputDebugString(_T("[+] Loaded ASI"));
  if (hThread != 0) CloseHandle(hThread);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD nReason, LPVOID lpReserved) {
  HANDLE hThread;
  
  switch (nReason) {
	  case DLL_PROCESS_ATTACH:
      if (DEBUG) OutputDebugString(_T("PROCESS_ATTACH: Creating Thread"));
      DllProccessAttach(hModule);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
      break;
  }
  
  return TRUE;
}
