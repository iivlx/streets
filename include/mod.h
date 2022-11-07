#pragma once

#include <Windows.h>

const bool DEBUG = true;

DWORD WINAPI mod(HMODULE hModule);

vec3 getPlayerPositionFromId(int playerId);
bool handleKeyPresses();
void updateStreetNames();