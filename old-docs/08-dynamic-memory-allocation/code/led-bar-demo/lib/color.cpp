#include "color.h"

namespace Visual {

  Color::Color(void) {
  }

  Color::Color(int red, int green, int blue) {
    set_color(red, green, blue);
  }

  void Color::set_color(int red, int green, int blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
  }

  int Color::get_red(void) {
    return red;
  }

  int Color::get_green(void) {
    return green;
  }

  int Color::get_blue(void) {
    return blue;
  }

};