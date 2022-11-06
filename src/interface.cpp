#include <d3d9.h>
#include <d3dx9.h>

#include "interface.h"

void display(IDirect3DDevice9* pDevice) {
  int padding = 2;
  int rectx1 = 50, rectx2 = 800, recty1 = 50, recty2 = 800;
  D3DRECT rectangle = { rectx1, recty1, rectx2, recty2 };
  pDevice->Clear(1, &rectangle, D3DCLEAR_TARGET, D3DCOLOR_ARGB(100, 50, 50, 50), 0.0f, 0);
}
