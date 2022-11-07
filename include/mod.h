#pragma once

#include <Windows.h>

#include "vec.h"

const bool DEBUG = true;

DWORD WINAPI mod(HMODULE hModule);

vec3 getPlayerPositionFromId(int playerId);
bool handleKeyPresses();
void updateStreetNames();