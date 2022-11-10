#pragma once

#include <d3d9.h>

typedef HRESULT(__stdcall* endScene)(IDirect3DDevice9* pDevice);

namespace DX {

static endScene pEndScene;

void hookEndScene();
HRESULT __stdcall hookedEndScene(IDirect3DDevice9* pDevice);

}

