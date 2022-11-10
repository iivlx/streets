#pragma once

#include <d3d9.h>

#include "interface.h"

#define TEXT_WIDTH 100
#define TEXT_HEIGHT 100

typedef HRESULT(__stdcall* endScene)(IDirect3DDevice9* pDevice);

namespace DX {

static LPD3DXFONT font;
static LPDIRECT3DVERTEXBUFFER9 pVB;
static LPDIRECT3DINDEXBUFFER9 pIB;
static endScene pEndScene;

void drawRect(IDirect3DDevice9* pDevice, int x, int y, int w, int h, D3DCOLOR color);
void drawText(IDirect3DDevice9* pDevice, int x, int y, std::string text, D3DCOLOR color);
void hookEndScene();
HRESULT __stdcall hookedEndScene(IDirect3DDevice9* pDevice);
void loadFont(IDirect3DDevice9* pDevice);

}
