#pragma once

#include <Windows.h>

DWORD WINAPI mod(HMODULE hModule);

vec3 getPlayerPositionFromId(int playerId);
bool handleKeyPresses();
void updateStreetNames();