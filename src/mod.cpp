#include <iostream>
#include <Windows.h>
#include <tchar.h>

#include "vec.h"
#include "natives.h"
#include "colors.h"

vec3 getPlayerPositionFromId(int playerId) {
  float x, y, z;
  int* playerChar = nullptr;
  int playerIndex = CONVERT_INT_TO_PLAYERINDEX(playerId);
  GET_PLAYER_CHAR(playerIndex, &playerChar);
  GET_CHAR_COORDINATES((int)playerChar, &x, &y, &z);
  return { x, y, z };
}

void displayStreetNames(char* street1, char* street2) {
  char buffer[256];
  sprintf(buffer, _T("GET_STRING_FROM_HASH_KEY() : street1 = %s, street2 = %s"), street1, street2);
  OutputDebugString(buffer);
}

void showStreetNames() {
  int street1, street2;
  
  vec3 playerPosition = getPlayerPositionFromId(GET_PLAYER_ID());
  
  FIND_STREET_NAME_AT_POSITION(playerPosition.x, playerPosition.y, playerPosition.z, &street1, &street2);
  displayStreetNames(GET_STRING_FROM_HASH_KEY(street1), GET_STRING_FROM_HASH_KEY(street2));
  
  return;
}


DWORD WINAPI mod(HMODULE hModule) {
  BOOL createConsole;
  FILE* f = nullptr;
  uintptr_t moduleBase = (uintptr_t)GetModuleHandleW(L"GTAIV.exe");
  registerFunctions(moduleBase);
  
  while (TRUE) {
    if (GetAsyncKeyState(VK_END) & 1) {
      OutputDebugString(_T("Received END key"));
      break;
    }
    else if (GetAsyncKeyState(VK_HOME) & 1) {
      OutputDebugString(_T("Received HOME key"));
      showStreetNames();
    }
    else if (GetAsyncKeyState(VK_PRIOR) & 1) {
      OutputDebugString(_T("Received PAGEUP key"));
      ;
    }
    
    Sleep(10);
  }


  OutputDebugString(_T("[-] Unloaded ASI"));
  FreeLibraryAndExitThread(hModule, 0);
}