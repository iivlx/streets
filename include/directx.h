#pragma once

#include <d3d9.h>

typedef HRESULT(__stdcall* endScene)(IDirect3DDevice9* pDevice);

void hookEndScene();
HRESULT __stdcall hookedEndScene(IDirect3DDevice9* pDevice);
