#pragma once

// version 1.0.4.0

typedef void(__cdecl* _ADD_BLIP_FOR_COORD)(float x, float y, float z, void* pBlip);
typedef void(__cdecl* _CHANGE_CAR_COLOUR)(int vehicleId, int color1, int color2);
typedef void(__cdecl* _CLEAR_WANTED_LEVEL)(int charId);
typedef int(__cdecl* _CONVERT_INT_TO_PLAYERINDEX)(int);
typedef void(__cdecl* _CREATE_CAR)(int modelHash, float x, float y, float z, int* pCar, int bAlways1);
typedef void(__cdecl* _DISPLAY_CASH)(bool display);
typedef void(__cdecl* _DISPLAY_TEXT)(float x, float y, const char* text);
typedef void(__cdecl* _DISPLAY_TEXT_WITH_NUMBER)(float x, float y, char* text, int number);
typedef void(__cdecl* _DISPLAY_AREA_NAME)(int display);
typedef void(__cdecl* _FIND_STREET_NAME_AT_POSITION)(float x, float y, float z, int* street1, int* street2);
typedef int(__cdecl* _GET_BLIP_INFO_ID_TYPE)(int id);
typedef void(__cdecl* _GET_CHAR_COORDINATES)(int charId, float* x, float* y, float* z);
typedef int(__cdecl* _GET_FIRST_BLIP_INFO_ID)(int id);
typedef void(__cdecl* _GET_PLAYER_CHAR)(int charId, void* pChar);
typedef int(__cdecl* _GET_PLAYER_ID)(void);
typedef void(__cdecl* _GIVE_PLAYER_HELMET)(int playerIndex);
typedef char*(__cdecl* _GET_STRING_FROM_HASH_KEY)(int hashkey);
typedef void(__cdecl* _LOAD_ADDITIONAL_TEXT)(char* table, int unknown);
typedef void(__cdecl* _PAUSE_GAME)(void);
typedef void(__cdecl* _PRINT)(char* text, int x, int y);
typedef void(__cdecl* _REQUEST_MODEL)(int* modelHash);
typedef void(__cdecl* _SET_CHAR_MONEY)(int charId, int amount);
typedef void(__cdecl* _SET_TEXT_COLOUR)(char r, char g, char b, char a);
typedef void(__cdecl* _SET_TEXT_FONT)(int fontId);
typedef void(__cdecl* _UNPAUSE_GAME)(void);

typedef void(__thiscall* _updateCarColor)(void* pCar);

static _ADD_BLIP_FOR_COORD ADD_BLIP_FOR_COORD;
static _CHANGE_CAR_COLOUR CHANGE_CAR_COLOUR;
static _CLEAR_WANTED_LEVEL CLEAR_WANTED_LEVEL;
static _CONVERT_INT_TO_PLAYERINDEX CONVERT_INT_TO_PLAYERINDEX;
static _CREATE_CAR CREATE_CAR;
static _DISPLAY_AREA_NAME DISPLAY_AREA_NAME;
static _DISPLAY_CASH DISPLAY_CASH;
static _DISPLAY_TEXT DISPLAY_TEXT;
static _DISPLAY_TEXT_WITH_NUMBER DISPLAY_TEXT_WITH_NUMBER;
static _FIND_STREET_NAME_AT_POSITION FIND_STREET_NAME_AT_POSITION;
static _GET_BLIP_INFO_ID_TYPE GET_BLIP_INFO_ID_TYPE;
static _GET_CHAR_COORDINATES GET_CHAR_COORDINATES;
static _GET_FIRST_BLIP_INFO_ID GET_FIRST_BLIP_INFO_ID;
static _GET_PLAYER_CHAR GET_PLAYER_CHAR;
static _GET_PLAYER_ID GET_PLAYER_ID;
static _GET_STRING_FROM_HASH_KEY GET_STRING_FROM_HASH_KEY;
static _GIVE_PLAYER_HELMET GIVE_PLAYER_HELMET;
static _LOAD_ADDITIONAL_TEXT LOAD_ADDITIONAL_TEXT;
static _PAUSE_GAME PAUSE_GAME;
static _PRINT PRINT;
static _REQUEST_MODEL REQUEST_MODEL;
static _SET_CHAR_MONEY SET_CHAR_MONEY;
static _SET_TEXT_COLOUR SET_TEXT_COLOUR;
static _SET_TEXT_FONT SET_TEXT_FONT;
static _UNPAUSE_GAME UNPAUSE_GAME;

static _updateCarColor updateCarColor;

void registerFunctions(uintptr_t moduleBase) {
  ADD_BLIP_FOR_COORD = (_ADD_BLIP_FOR_COORD)(moduleBase + 0x6134B0);
  CHANGE_CAR_COLOUR = (_CHANGE_CAR_COLOUR)(moduleBase + 0x5DEDF0);
  CLEAR_WANTED_LEVEL = (_CLEAR_WANTED_LEVEL)(moduleBase + 0x5F6F60);
  CONVERT_INT_TO_PLAYERINDEX = (_CONVERT_INT_TO_PLAYERINDEX)(moduleBase + 0x5F6140);
  CREATE_CAR = (_CREATE_CAR)(moduleBase + 0x5E4C90);
  DISPLAY_AREA_NAME = (_DISPLAY_AREA_NAME)(moduleBase + 0x615F90);
  DISPLAY_CASH = (_DISPLAY_CASH)(moduleBase + 0x615FB0);
  DISPLAY_TEXT = (_DISPLAY_TEXT)(moduleBase + 0x611B50);
  DISPLAY_TEXT_WITH_NUMBER = (_DISPLAY_TEXT_WITH_NUMBER)(moduleBase + 0x611EA0);
  FIND_STREET_NAME_AT_POSITION = (_FIND_STREET_NAME_AT_POSITION)(moduleBase + 0x5CE540);
  GET_BLIP_INFO_ID_TYPE = (_GET_BLIP_INFO_ID_TYPE)(moduleBase + 0x613320);
  GET_CHAR_COORDINATES = (_GET_CHAR_COORDINATES)(moduleBase + 0x5FB910);
  GET_FIRST_BLIP_INFO_ID = (_GET_FIRST_BLIP_INFO_ID)(moduleBase + 0x613D20);
  GET_PLAYER_CHAR = (_GET_PLAYER_CHAR)(moduleBase + 0x5F7ED0);
  GET_PLAYER_ID = (_GET_PLAYER_ID)(moduleBase + 0x5F6110);
  GET_STRING_FROM_HASH_KEY = (_GET_STRING_FROM_HASH_KEY)(moduleBase + 0x6116D0);
  GIVE_PLAYER_HELMET = (_GIVE_PLAYER_HELMET)(moduleBase + 0x5F64E0);
  LOAD_ADDITIONAL_TEXT = (_LOAD_ADDITIONAL_TEXT)(moduleBase + 0x611380);
  PAUSE_GAME = (_PAUSE_GAME)(moduleBase + 0x60D850);
  PRINT = (_PRINT)(moduleBase + 0x610800);
  REQUEST_MODEL = (_REQUEST_MODEL)(moduleBase + 0x5D2000);
  SET_CHAR_MONEY = (_SET_CHAR_MONEY)(moduleBase + 0x5FD550);
  SET_TEXT_COLOUR = (_SET_TEXT_COLOUR)(moduleBase + 0x614F10);
  SET_TEXT_FONT = (_SET_TEXT_FONT)(moduleBase + 0x615910);
  UNPAUSE_GAME = (_UNPAUSE_GAME)(moduleBase + 0x60D870);
  
  updateCarColor = (_updateCarColor)(moduleBase + 0x4B1AB0);
}

