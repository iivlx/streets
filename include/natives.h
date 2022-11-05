#pragma once

// version 1.0.4.0

typedef  int(__cdecl* _GET_PLAYER_ID)(void);
typedef  int(__cdecl* _CONVERT_INT_TO_PLAYERINDEX)(int);
typedef  void(__cdecl* _GET_CHAR_COORDINATES)(int charId, float* x, float* y, float* z);
typedef  void(__cdecl* _GET_PLAYER_CHAR)(int charId, void* pChar);
typedef  void(__cdecl* _FIND_STREET_NAME_AT_POSITION)(float x, float y, float z, int* street1, int* street2);
typedef  char* (__cdecl* _GET_STRING_FROM_HASH_KEY)(int hashkey);
typedef  void(__cdecl* _DISPLAY_TEXT)(float x, float y, char* text);
typedef  void(__cdecl* _DISPLAY_TEXT_WITH_NUMBER)(float x, float y, char* text, int number);
typedef  void(__cdecl* _DISPLAY_AREA_NAME)(int display);
typedef  void(__cdecl* _CREATE_CAR)(int modelHash, float x, float y, float z, int* pCar, int bAlways1);
typedef  void(__cdecl* _REQUEST_MODEL)(int* modelHash);
typedef  void(__cdecl* _CHANGE_CAR_COLOUR)(int vehicleId, int color1, int color2);
typedef  void(__cdecl* _CLEAR_WANTED_LEVEL)(int charId);

typedef  void(__thiscall* _updateCarColor)(void* pCar);

static _GET_PLAYER_ID GET_PLAYER_ID;
static _CONVERT_INT_TO_PLAYERINDEX CONVERT_INT_TO_PLAYERINDEX;
static _GET_CHAR_COORDINATES GET_CHAR_COORDINATES;
static _GET_PLAYER_CHAR GET_PLAYER_CHAR;
static _FIND_STREET_NAME_AT_POSITION FIND_STREET_NAME_AT_POSITION;
static _GET_STRING_FROM_HASH_KEY GET_STRING_FROM_HASH_KEY;
static _DISPLAY_TEXT DISPLAY_TEXT;
static _DISPLAY_TEXT_WITH_NUMBER DISPLAY_TEXT_WITH_NUMBER;
static _DISPLAY_AREA_NAME DISPLAY_AREA_NAME;
static _CREATE_CAR CREATE_CAR;
static _REQUEST_MODEL REQUEST_MODEL;
static _CHANGE_CAR_COLOUR CHANGE_CAR_COLOUR;
static _CLEAR_WANTED_LEVEL CLEAR_WANTED_LEVEL;

static _updateCarColor updateCarColor;

void registerFunctions(uintptr_t moduleBase) {

	GET_PLAYER_ID = (_GET_PLAYER_ID)(moduleBase + 0x5F6110);
	CONVERT_INT_TO_PLAYERINDEX = (_CONVERT_INT_TO_PLAYERINDEX)(moduleBase + 0x5F6140);
	GET_CHAR_COORDINATES = (_GET_CHAR_COORDINATES)(moduleBase + 0x5FB910);
	GET_PLAYER_CHAR = (_GET_PLAYER_CHAR)(moduleBase + 0x5F7ED0);
	FIND_STREET_NAME_AT_POSITION = (_FIND_STREET_NAME_AT_POSITION)(moduleBase + 0x5CE540);
	GET_STRING_FROM_HASH_KEY = (_GET_STRING_FROM_HASH_KEY)(moduleBase + 0x6116D0);
	DISPLAY_TEXT = (_DISPLAY_TEXT)(moduleBase + 0x611B50);
	DISPLAY_TEXT_WITH_NUMBER = (_DISPLAY_TEXT_WITH_NUMBER)(moduleBase + 0x611EA0);
	DISPLAY_AREA_NAME = (_DISPLAY_AREA_NAME)(moduleBase + 0x615F90);
	CREATE_CAR = (_CREATE_CAR)(moduleBase + 0x5E4C90);
	REQUEST_MODEL = (_REQUEST_MODEL)(moduleBase + 0x5D2000);
	CHANGE_CAR_COLOUR = (_CHANGE_CAR_COLOUR)(moduleBase + 0x5DEDF0);
	CLEAR_WANTED_LEVEL = (_CLEAR_WANTED_LEVEL)(moduleBase + 0x5F6F60);

	updateCarColor = (_updateCarColor)(moduleBase + 0x4B1AB0);

}
