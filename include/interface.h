#pragma once

#include <string>

#include <d3d9.h>
#include <d3dx9.h>

#include "colors.h"

class Interface {
public:
  std::string street1 = "street1";
  std::string street2 = "street2";
  std::string zone = "ZONE";
  
  IDirect3DDevice9* pDevice;

  int x = 1600;
  int y = 20;
  int w = 300;
  int h = 300;
  int text_x = 0;
  int text_y = 0;
  int padding = 10;

  Interface();
  void display(IDirect3DDevice9* pDevice);
  void displayBackground();
  void displayInfo();
  void displayText(std::string text);
  void displayText(std::string text, D3DCOLOR color);
  void drawNewLine();
  void drawRect(int x, int y, int w, int h, D3DCOLOR color);
  void setTextPosition();

private:
  int backGroundOpacity = 120;
  D3DCOLOR backgroundColor = LIGHT_GREY(backGroundOpacity);
};
