#pragma once

#include <Windows.h>

#include "vec.h"

const bool DEBUG = true;

DWORD WINAPI mod(HMODULE hModule);

void addBlip();
void deleteBlip();
void moveBlipForward();
void moveBlipBackward();
void moveBlipRight();
void moveBlipLeft();
void moveBlipUp();
void moveBlipDown();
void redrawBlip();

vec3 getPlayerPositionFromId(int playerId);
bool handleKeyPresses();
void updateStreetNames();
void updatePlayerPosition();
