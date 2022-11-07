#include <iostream>

#include <d3d9.h>
#include <d3dx9.h>

#include "interface.h"

LPD3DXFONT font;

Interface::Interface() : font(nullptr) {}

void Interface::drawBackground(IDirect3DDevice9* pDevice) {
  D3DRECT r = { this->x, this->y, this->x+this->width, this->y+this->height };
  pDevice->Clear(1, &r , D3DCLEAR_TARGET, D3DCOLOR_ARGB(100, 50, 50, 50), 0.0f, 0);
}

void Interface::drawText(IDirect3DDevice9* pDevice) {
  if (!this->font)
    this->loadFont(pDevice);

  RECT r;
  SetRect(&r, this->x, this->y, this->x + this->width, this->y + this->height);
  font->DrawText(NULL, "Location: ", -1, &r, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 153, 255, 153));

  SetRect(&r, this->x, this->y + 20, this->x + this->width, this->y + this->height);
  std::string location = this->street1 + " " + this->street2 + ", " + this->zone;

  font->DrawText(NULL, location.c_str() , -1, &r, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 153, 255, 153));

  SetRect(&r, this->x, this->y + 100 , this->x + this->width, this->y + this->height);
  font->DrawText(NULL, "Current Targets: ", -1, &r, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 153, 255, 153));
}

void Interface::display(IDirect3DDevice9* pDevice) {
  this->drawBackground(pDevice);
  this->drawText(pDevice);
}

void Interface::loadFont(IDirect3DDevice9* pDevice){
  D3DXCreateFont(pDevice, 16, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &this->font);
}
