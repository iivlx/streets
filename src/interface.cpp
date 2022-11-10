#include <iostream>

#include <d3d9.h>
#include <d3dx9.h>

#include "interface.h"

LPD3DXFONT font;

Interface::Interface() : font(nullptr) {}

void Interface::display(IDirect3DDevice9* pDevice) {
  this->device = pDevice;
  this->drawBackground();
  this->displayText();
}

void Interface::displayText() {
  this->text_x = this->x;
  this->text_y = this->y;

  if (!this->font)
    this->loadFont();

  drawText("Location: ");
  drawText(this->street1 + ", " + this->street2 + " - " + this->zone);
  drawNewLine();
  drawText("Targets: ");

}

void Interface::drawBackground() {
  D3DRECT r = { this->x, this->y, this->x + this->width, this->y + this->height };
  this->device->Clear(1, &r , D3DCLEAR_TARGET, D3DCOLOR_ARGB(100, 50, 50, 50), 0.0f, 0);
}

void Interface::drawText(std::string text) {
  RECT r;
  SetRect(&r, this->text_x, this->text_y, 100, 100);
  font->DrawText(NULL, text.c_str(), -1, &r, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 153, 255, 153));
  drawNewLine();
}

void Interface::loadFont(){
  D3DXCreateFont(this->device, 16, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &this->font);
}

void Interface::drawNewLine() {
  this->text_y += 20;
}
