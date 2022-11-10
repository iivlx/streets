#include <iostream>

#include <d3d9.h>
#include <d3dx9.h>

#include "directx.h"
#include "interface.h"
#include "vec.h"

Interface::Interface() {}

void Interface::display(IDirect3DDevice9* pDevice) {
  this->pDevice = pDevice;
  this->displayBackground();
  this->displayInfo();
}

void Interface::displayBackground() {
  this->drawRect(this->x, this->y, this->w, this->h, this->backgroundColor);
}

void Interface::displayInfo() {
  setTextPosition();

  if (!DX::font) DX::loadFont(this->pDevice);

  displayText("Location: ", WHITE(255));
  displayText(" " + this->street1 + ", " + this->street2 + " - " + this->zone, GREEN(255));
  drawNewLine();
  displayText("Targets: ", WHITE(255));
  displayText(" None", GREEN(255)); // TODO: Add list of targets... 
}

void Interface::displayText(std::string text) {
  displayText(text, DEFAULT_COLOR_TEXT(255));
}

void Interface::displayText(std::string text, D3DCOLOR color) {
  DX::drawText(this->pDevice, this->text_x, this->text_y, text, color);
  drawNewLine();
}

void Interface::drawNewLine() {
  this->text_y += 20;
}

void Interface::drawRect(int x, int y, int w, int h, D3DCOLOR color) {
  DX::drawRect(this->pDevice, x, y, w, h, color);
}

void Interface::setTextPosition() {
  this->text_x = this->x + this->padding;
  this->text_y = this->y + this->padding;
}
