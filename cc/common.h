#ifndef __GIFX_COMMON_H__
#define __GIFX_COMMON_H__

#include <stdint>

struct Color {
  bool valid;
  uint8_t r, g, b;

  Color () : valid(false) {}
  Color (uint8_t rr, uint8_t gg, uint8_t bb, bool isValid=true) :
      r(rr), g(gg), b(bb), valid(isValid) {}
};

struct Point {
  int x, y;

  Point () {}
  Point (int x_, int y_): x(x_), y(y_) {}
};

struct Rect {
  int x, y, w, h;

  Rect () {}
  Rect (int x_, int y_, int w_, int h_) : x(x_), y(y_), w(w_), h(h_) {}
  bool isZero () {
    return w == 0 && h == 0;
  }
}
