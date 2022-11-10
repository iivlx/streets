#pragma once

#include <string>

#include <d3d9.h>
#include <d3dx9.h>


class Interface {
public:
  std::string street1 = "street1";
  std::string street2 = "street2";
  std::string zone = "ZONE";

  int x = 1600;
  int y = 20;
  int width = 300;
  int height = 300;
  int text_x = 0;
  int text_y = 0;

  Interface();
  void display(IDirect3DDevice9* pDevice);
  void displayText();
  void drawBackground();
  void drawNewLine();
  void drawText(std::string text);
  void loadFont();

private:
  LPD3DXFONT font;
  IDirect3DDevice9* device;
};
