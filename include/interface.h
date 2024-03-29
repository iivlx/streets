#pragma once

#include <string>

#include <d3d9.h>
#include <d3dx9.h>

#include "colors.h"
#include "vec.h"

class Interface {
 public:
  Interface();

  void display(IDirect3DDevice9* pDevice);

  IDirect3DDevice9* pDevice;

  vec3 markerPosition;
  int markerId;
  int* pMarker;

  vec3 playerPosition;
  bool updating = false;
  std::string street1 = "street1";
  std::string street2 = "street2";
  std::string zone = "ZONE";
  
 private:
  void displayBackground();
  void displayInfo();
  void displayGPS();
  void displayText(std::string text);
  void displayText(std::string text, D3DCOLOR color);

  void drawNewLine();
  void drawRect(int x, int y, int w, int h, D3DCOLOR color);

  void setTextPosition();
  void setTextPosition(int y, int x);
  
  int x = 1600;
  int y = 20;
  int w = 300;
  int h = 300;
  int padding = 10;

  int text_x = 0;
  int text_y = 0;
  
  int backGroundOpacity = 120;
  D3DCOLOR backgroundColor = LIGHT_GREY(backGroundOpacity);
};
