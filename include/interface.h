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

  Interface();
  void display(IDirect3DDevice9* pDevice);
  void drawBackground(IDirect3DDevice9* pDevice);
  void drawText(IDirect3DDevice9* pDevice);
  void loadFont(IDirect3DDevice9* pDevice);
private:
  LPD3DXFONT font;
};
