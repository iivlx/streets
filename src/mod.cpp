#include <iostream>
#include <Windows.h>
#include <tchar.h>

#include "vec.h"
#include "natives.h"
#include "colors.h"

#include "directx.h"
#include "interface.h"
#include "mod.h"

extern Interface* iface;

vec3 getPlayerPositionFromId(int playerId) {
  float x, y, z;
  int* playerChar = nullptr;
  int playerIndex = CONVERT_INT_TO_PLAYERINDEX(playerId);
  GET_PLAYER_CHAR(playerIndex, &playerChar);
  GET_CHAR_COORDINATES((int)playerChar, &x, &y, &z);
  return { x, y, z };
}

bool handleKeyPresses() {
  if (GetAsyncKeyState(VK_END) & 1) {
    if (DEBUG) OutputDebugString(_T("Received END key"));
    return false;
  }
  else if (GetAsyncKeyState(VK_HOME) & 1) {
    if (DEBUG) OutputDebugString(_T("Received HOME key"));
    updateStreetNames();
  }
  else if (GetAsyncKeyState(VK_PRIOR) & 1) {
    if (DEBUG) OutputDebugString(_T("Received PAGEUP key"));
    PAUSE_GAME();
  }
  else if (GetAsyncKeyState(VK_NEXT) & 1) {
    if (DEBUG) OutputDebugString(_T("Received PAGEDOWN key"));
    UNPAUSE_GAME();
  }
  return true;
}

DWORD WINAPI mod(HMODULE hModule) {
  registerFunctions((uintptr_t)GetModuleHandleW(L"GTAIV.exe"));
  hookEndScene();
  
  bool mod_running = true;

  while (mod_running) {
    mod_running = handleKeyPresses();
    Sleep(10);
  }

  if (DEBUG) OutputDebugString(_T("[-] Unloaded ASI"));
  FreeLibraryAndExitThread(hModule, 0);
}

void updateStreetNames() {
  int street1, street2;
 
  vec3 playerPosition = getPlayerPositionFromId(GET_PLAYER_ID());
  
  FIND_STREET_NAME_AT_POSITION(playerPosition.x, playerPosition.y, playerPosition.z, &street1, &street2);
  iface->street1 = GET_STRING_FROM_HASH_KEY(street1);
  iface->street2 = GET_STRING_FROM_HASH_KEY(street2);

  GIVE_PLAYER_HELMET(CONVERT_INT_TO_PLAYERINDEX(GET_PLAYER_ID()));

  return;
}
