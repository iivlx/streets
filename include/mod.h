#pragma once

#include <Windows.h>

#include "vec.h"

const bool DEBUG = true;

DWORD WINAPI mod(HMODULE hModule);

void addBlip();
vec3 getPlayerPositionFromId(int playerId);
bool handleKeyPresses();
void updateStreetNames();
