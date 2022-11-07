#include <Windows.h>

#include <d3d9.h>
#include <d3dx9.h>

#include <detours.h>

#include "directx.h"
#include "interface.h"
#include "mod.h"

endScene pEndScene;

extern Interface* iface;

void hookEndScene() {

  OutputDebugString("[+] Hooking DX9");

  IDirect3D9* pD3D = Direct3DCreate9(D3D_SDK_VERSION);
  if (!pD3D) return;

  IDirect3DDevice9* pDevice = nullptr;

  D3DPRESENT_PARAMETERS d3dparams = { 0 };
  d3dparams.SwapEffect = D3DSWAPEFFECT_DISCARD;
  d3dparams.hDeviceWindow = GetForegroundWindow();
  d3dparams.Windowed = TRUE;
  HRESULT result = pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, d3dparams.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dparams, &pDevice);

  if (FAILED(result) || !pDevice) {
    OutputDebugString("[-] Create Device Failed");
    OutputDebugString("[-] Hook failed");
    pD3D->Release();
    return;
  }
  else {
    OutputDebugString("[+] Create Device Success");
  }

  DWORD* vTable = *reinterpret_cast<DWORD**>(pDevice);
  pEndScene = (endScene)(DWORD)vTable[42];

  DetourTransactionBegin();
  DetourUpdateThread(GetCurrentThread());
  DetourAttach(&(PVOID&)pEndScene, (PBYTE)hookedEndScene);
  DetourTransactionCommit();

  OutputDebugString("[+] Attached Detour");
  OutputDebugString("[+] Hook successful");
  pDevice->Release();
  pD3D->Release();
}

HRESULT __stdcall hookedEndScene(IDirect3DDevice9* pDevice) {
  iface->display(pDevice);
  return pEndScene(pDevice);
}
