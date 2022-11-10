#pragma once

#define DEFAULT_COLOR_TEXT(alpha) D3DCOLOR_ARGB(alpha, 255, 255, 255)
#define WHITE(alpha)              D3DCOLOR_ARGB(alpha, 255, 255, 255)
#define GREEN(alpha)              D3DCOLOR_ARGB(alpha, 153, 255, 153)
#define LIGHT_GREY(alpha)         D3DCOLOR_ARGB(alpha, 50, 50, 50)

enum GC_COLORS {
  GC_BLACK,
  GC_GREY,
  GC_GREY2,
  GC_DARKPURPLE = 99,
  GC_DARKPURPLE2 = 100,
  GC_DARKPURPLE3 = 101,
  GC_PURPLE = 121,
};
