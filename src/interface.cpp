#include <iostream>

#include <d3d9.h>
#include <d3dx9.h>

#include "directx.h"
#include "interface.h"
#include "vec.h"

LPD3DXFONT font;

Interface::Interface() : font(nullptr) {}

void Interface::display(IDirect3DDevice9* pDevice) {
  this->device = pDevice;
  this->displayBackground();
  this->displayText();
}

void Interface::displayBackground() {
  this->drawRect(this->x, this->y,
                 this->x + this->w, this->y + this->h, this->backgroundColor);
}

void Interface::displayText() {
  this->text_x = this->x + this->padding;
  this->text_y = this->y + this->padding;

  if (!this->font)
    this->loadFont();

  drawText("Location: ", WHITE(255));
  drawText(" " + this->street1 + ", " + this->street2 + " - " + this->zone, GREEN(255));
  drawNewLine();
  drawText("Targets: ", WHITE(255));
  drawText(" None", GREEN(255)); // TODO: Add list of targets... 
}

void Interface::drawRect(int x, int y, int w, int h, D3DCOLOR color) {
  DX::drawRect(this->device, x, y, w, h, color);
}

void Interface::drawNewLine() {
  this->text_y += 20;
}

void Interface::drawText(std::string text) {
  drawText(text, DEFAULT_COLOR_TEXT(255));
}

void Interface::drawText(std::string text, D3DCOLOR color) {
  RECT r;
  SetRect(&r, this->text_x, this->text_y, 100, 100);
  font->DrawText(NULL, text.c_str(), -1, &r, DT_NOCLIP | DT_LEFT, color);
  drawNewLine();
}

void Interface::loadFont(){
  D3DXCreateFont(this->device, 16, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &this->font);
}
