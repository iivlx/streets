#include <iostream>

#include <d3d9.h>
#include <d3dx9.h>
#include <string>

#include "directx.h"
#include "interface.h"
#include "mod.h"
#include "vec.h"

using std::to_string;

Interface::Interface() {}

void Interface::display(IDirect3DDevice9* pDevice) {
  this->pDevice = pDevice;

  if (updating)
    updatePlayerPosition();

  this->displayBackground();
  //this->displayInfo();
  this->displayGPS();
}

void Interface::displayBackground() {
  this->drawRect(this->x, this->y, this->w, this->h, this->backgroundColor);
}

void Interface::displayGPS() {
  if (!DX::font) DX::loadFont(this->pDevice);

  setTextPosition(0, 0);
  if (this->playerPosition.y > 0)
    displayText("N: ", WHITE(255));
  else
    displayText("S: ", WHITE(255));

  setTextPosition(20, 0);
  displayText(to_string(abs(this->playerPosition.y)), GREEN(255));

  setTextPosition(40, 0);
  if (this->playerPosition.x > 0)
    displayText("E: ", WHITE(255));
  else
    displayText("W: ", WHITE(255));
    
  setTextPosition(60, 0);
  displayText(to_string(abs(this->playerPosition.x)), GREEN(255));
  
  setTextPosition(80, 0);
  displayText("Elevation: ", WHITE(255));
  
  setTextPosition(100, 0);
  displayText(to_string(this->playerPosition.z), GREEN(255));

  // Marker

  setTextPosition(120, 0);
  displayText("ID: ", WHITE(255));

  setTextPosition(140, 0);
  displayText(to_string(this->markerId), GREEN(255));

  setTextPosition(160, 0);
  displayText(to_string(this->markerPosition.x), GREEN(255));
  setTextPosition(180, 0);
  displayText(to_string(this->markerPosition.y), GREEN(255));
  setTextPosition(200, 0);
  displayText(to_string(this->markerPosition.z), GREEN(255));
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

void Interface::setTextPosition(int y, int x) {
  this->text_x = this->x + this->padding + x;
  this->text_y = this->y + this->padding + y;
}
