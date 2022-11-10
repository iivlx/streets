#pragma once

#include <d3d9.h>

#include "interface.h"

typedef HRESULT(__stdcall* endScene)(IDirect3DDevice9* pDevice);

namespace DX {

static LPDIRECT3DVERTEXBUFFER9 pVB;
static LPDIRECT3DINDEXBUFFER9 pIB;
static endScene pEndScene;

void drawRect(IDirect3DDevice9* pDevice, int x, int y, int w, int h, D3DCOLOR color);
void hookEndScene();
HRESULT __stdcall hookedEndScene(IDirect3DDevice9* pDevice);

}
