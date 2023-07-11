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

DWORD WINAPI mod(HMODULE hModule) {
  registerFunctions((uintptr_t)GetModuleHandleW(L"GTAIV.exe"));
  DX::hookEndScene();

  bool mod_running = true;

  while (mod_running) {
    mod_running = handleKeyPresses();
    Sleep(10);
  }

  if (DEBUG) OutputDebugString(_T("[-] Unloaded ASI"));
  FreeLibraryAndExitThread(hModule, 0);
}

bool handleKeyPresses() {
  if (GetAsyncKeyState(VK_END) & 1) {
    if (DEBUG) OutputDebugString(_T("Received END key"));

    vec3 p = iface->playerPosition;
    p.x += 10;
    p.y += 10;
    int pBlip;
    //ADD_BLIP_FOR_COORD(p.x, p.y, p.z, pBlip);

    addBlip();
    //return false;
  }
  else if (GetAsyncKeyState(VK_HOME) & 1) {
    if (DEBUG) OutputDebugString(_T("Received HOME key"));
    iface->updating = true;
    //updateStreetNames();
  }
  else if (GetAsyncKeyState(VK_PRIOR) & 1) {
    if (DEBUG) OutputDebugString(_T("Received PAGEUP key"));
    PAUSE_GAME();
  }
  else if (GetAsyncKeyState(VK_NEXT) & 1) {
    if (DEBUG) OutputDebugString(_T("Received PAGEDOWN key"));
    UNPAUSE_GAME();
  }
  else if (GetAsyncKeyState(VK_OEM_COMMA) & 1) {
    deleteBlip();
    moveBlipForward();
  }
  else if (GetAsyncKeyState(VK_OEM_PERIOD) & 1) {
    deleteBlip();
    moveBlipBackward();
  }
  else if (GetAsyncKeyState(VK_OEM_6) & 1) {
    deleteBlip();
    moveBlipRight();
  }
  else if (GetAsyncKeyState(VK_OEM_4) & 1) {
    deleteBlip();
    moveBlipLeft();
  }
  else if (GetAsyncKeyState(VK_OEM_1) & 1) {
    deleteBlip();
    moveBlipDown();
  }
  else if (GetAsyncKeyState(VK_OEM_7) & 1) {
    deleteBlip();
    moveBlipUp();
  }
  
  return true;
}

void addBlip() {
  vec3 p = getPlayerPositionFromId(GET_PLAYER_ID());
  p.x = int(p.x);
  p.y = int(p.y);
  p.z = int(p.z);
  iface->markerPosition = p;
  int pMarker;
  CREATE_OBJECT(0x28E5DB2C, p.x, p.y, p.z, &pMarker, 1);
  FREEZE_OBJECT_POSITION(pMarker, 1);
  iface->markerId = pMarker;
}

void deleteBlip() {
  int* pMarkerId = &iface->markerId;
  void* pMarkerData[] = {0, 0, &pMarkerId};
  DELETE_OBJECT(&pMarkerData);
}

void moveBlipForward() {
  iface->markerPosition.y += 0.1;
  redrawBlip();
}

void moveBlipBackward() {
  iface->markerPosition.y -= 0.1;
  redrawBlip();
}

void moveBlipRight() {
  iface->markerPosition.x += 0.1;
  redrawBlip();
}

void moveBlipLeft() {
  iface->markerPosition.x -= 0.1;
  redrawBlip();
}

void moveBlipUp() {
  iface->markerPosition.z += 0.1;
  redrawBlip();
}

void moveBlipDown() {
  iface->markerPosition.z -= 0.1;
  redrawBlip();
}




void redrawBlip(){
  vec3 p = iface->markerPosition;
  struct DataFormat {
    int hash;
    float x;
    float y;
    float z;
    int* pObject;
    int unk;
    int unk2;
  };

  int pObject;

  DataFormat data;
  data.hash = 0x28E5DB2C;
  data.x = p.x;
  data.y = p.y;
  data.z = p.z;
  data.pObject = &pObject;
  data.unk = 1;
  data.unk2 = 1;

  void* pData[] = {0, 0, &data};
  CREATE_OBJECT_CALL(&pData);
  FREEZE_OBJECT_POSITION(pObject, 1);
  iface->markerId = pObject;
}

vec3 getPlayerPositionFromId(int playerId) {
  float x, y, z;
  int* playerChar = nullptr;
  int playerIndex = CONVERT_INT_TO_PLAYERINDEX(playerId);
  GET_PLAYER_CHAR(playerIndex, &playerChar);
  GET_CHAR_COORDINATES((int)playerChar, &x, &y, &z);
  return { x, y, z };
}

void updatePlayerPosition() {
  iface->playerPosition = getPlayerPositionFromId(GET_PLAYER_ID());
}

void updateStreetNames() {
  int street1, street2;
 
  vec3 playerPosition = getPlayerPositionFromId(GET_PLAYER_ID());
  
  FIND_STREET_NAME_AT_POSITION(playerPosition.x, playerPosition.y, playerPosition.z, &street1, &street2);
  iface->street1 = GET_STRING_FROM_HASH_KEY(street1);
  iface->street2 = GET_STRING_FROM_HASH_KEY(street2);

  GIVE_PLAYER_HELMET(CONVERT_INT_TO_PLAYERINDEX(GET_PLAYER_ID()));
}
