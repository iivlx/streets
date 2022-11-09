#pragma once

#include <string>

#include <d3d9.h>
#include <d3dx9.h>


class Interface {
public:
  std::string street1 = "street1";
  std::string street2 = "street2";
  std::string zone = "ZONE";

  int x = 1000;;
  int y = 200;
  int width = 400;
  int height = 600;
  int text_x = 0;
  int text_y = 0;

  Interface();
  void display(IDirect3DDevice9* pDevice);
  void displayText();
  void drawBackground();
  void drawText(std::string text);
  void loadFont();
  void textNextLine();

private:
  LPD3DXFONT font;
  IDirect3DDevice9* device;
};
