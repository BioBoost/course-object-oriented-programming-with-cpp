#include "rgb_led.h"

using namespace Visual;

namespace Hardware {

  RgbLed::RgbLed(void)
    : RgbLed(Color(255, 0, 0)) {
  }

  RgbLed::RgbLed(Color color) {
    set_color(color);
  }

  void RgbLed::set_color(Color color) {
    this->color = color;
  }

  Color RgbLed::get_color(void) {
    return color;
  }

  std::string RgbLed::to_string(void) {
    return color.to_string();
  }

};