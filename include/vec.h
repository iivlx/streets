#pragma once

#include <d3d9.h>

struct vec3 {
  float x, y, z;
};

struct vertex {
    FLOAT x, y, z, rhw;
    D3DCOLOR color;
};
