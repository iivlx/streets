#include <Windows.h>

#include <d3d9.h>
#include <d3dx9.h>

#include <detours.h>

#include "directx.h"
#include "interface.h"
#include "mod.h"

extern Interface* iface;

LPD3DXFONT DX::font = nullptr;

void DX::drawRect(IDirect3DDevice9* pDevice, int x, int y, int w, int h, D3DCOLOR color) {
  D3DXVECTOR2 p[] = { D3DXVECTOR2(x, y), D3DXVECTOR2(x + w, y + h) };
  vertex v[4];
  
  v[0].color = v[1].color = v[2].color = v[3].color = color;

  v[0].z = v[1].z = v[2].z = v[3].z = 0;
  v[0].rhw = v[1].rhw = v[2].rhw = v[3].rhw = 0;
  
  v[0].x = x;
  v[0].y = y;
  v[1].x = x + w;
  v[1].y = y;
  v[2].x = x + w;
  v[2].y = y + h;
  v[3].x = x;
  v[3].y = y + h;

  unsigned short indices[] = {0, 1, 3, 1, 2, 3};

  pDevice->CreateVertexBuffer(4*sizeof(vertex), D3DUSAGE_WRITEONLY, D3DFVF_XYZRHW|D3DFVF_DIFFUSE, D3DPOOL_DEFAULT, &DX::pVB, NULL);
  pDevice->CreateIndexBuffer(2*sizeof(short), D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &DX::pIB, NULL);
 
  VOID* pVertices;
  DX::pVB->Lock(0, sizeof(v), (void**)&pVertices, 0);
  memcpy(pVertices, v, sizeof(v));
  DX::pVB->Unlock();
 
  VOID* pIndex;
  DX::pIB->Lock(0, sizeof(indices), (void**)&pIndex, 0);
  memcpy(pIndex, indices, sizeof(indices));
  DX::pIB->Unlock();
 
  pDevice->SetTexture(0, NULL);
  pDevice->SetPixelShader(NULL);
  pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
  pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
  pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
 
  pDevice->SetStreamSource(0, pVB, 0, sizeof(vertex));
  pDevice->SetFVF(D3DFVF_XYZRHW|D3DFVF_DIFFUSE);
  pDevice->SetIndices(pIB);
 
  pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);
 
  DX::pVB->Release();
  DX::pIB->Release();
}

void DX::drawText(IDirect3DDevice9* pDevice, int x, int y, std::string text, D3DCOLOR color) {
  RECT r;
  SetRect(&r, x, y, TEXT_WIDTH, TEXT_HEIGHT);
  DX::font->DrawText(NULL, text.c_str(), -1, &r, DT_NOCLIP | DT_LEFT, color);
}

void DX::hookEndScene() {

  if (DEBUG) OutputDebugString("[+] Hooking DX9");

  IDirect3D9* pD3D = Direct3DCreate9(D3D_SDK_VERSION);
  if (!pD3D) return;

  IDirect3DDevice9* pDevice = nullptr;

  D3DPRESENT_PARAMETERS d3dparams = { 0 };
  d3dparams.SwapEffect = D3DSWAPEFFECT_DISCARD;
  d3dparams.hDeviceWindow = GetForegroundWindow();
  d3dparams.Windowed = TRUE;
  HRESULT result = pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, d3dparams.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dparams, &pDevice);

  if (FAILED(result) || !pDevice) {
    if (DEBUG) OutputDebugString("[-] Create Device Failed");
    if (DEBUG) OutputDebugString("[-] Hook failed");
    pD3D->Release();
    return;
  }

  if (DEBUG) OutputDebugString("[+] Create Device Success");

  DWORD* vTable = *reinterpret_cast<DWORD**>(pDevice);
  DX::pEndScene = (endScene)(DWORD)vTable[42];

  DetourTransactionBegin();
  DetourUpdateThread(GetCurrentThread());
  DetourAttach(&(PVOID&)DX::pEndScene, (PBYTE)DX::hookedEndScene);
  DetourTransactionCommit();

  if (DEBUG) OutputDebugString("[+] Attached Detour");
  if (DEBUG) OutputDebugString("[+] Hook successful");
  pDevice->Release();
  pD3D->Release();
}

HRESULT __stdcall DX::hookedEndScene(IDirect3DDevice9* pDevice) {
  iface->display(pDevice);
  return DX::pEndScene(pDevice);
}

void DX::loadFont(IDirect3DDevice9* pDevice){
  D3DXCreateFont(pDevice, 16, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &DX::font);
}
