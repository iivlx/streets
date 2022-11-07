#pragma once

#include <string>

#include <d3d9.h>
#include <d3dx9.h>

class Interface {
public:
  std::string lastkey = "a";

  Interface();
  void display(IDirect3DDevice9* pDevice);
  void drawBackground(IDirect3DDevice9* pDevice);
  void drawText(IDirect3DDevice9* pDevice);
  void loadFont(IDirect3DDevice9* pDevice);
private:
  LPD3DXFONT font;
};
