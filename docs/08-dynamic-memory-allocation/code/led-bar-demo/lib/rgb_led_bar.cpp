#include "rgb_led_bar.h"

namespace Hardware {

  RgbLedBar::RgbLedBar(void)
    : RgbLedBar(DEFAULT_SIZE) {
  }

  RgbLedBar::RgbLedBar(unsigned int numberOfLeds) {
    this->numberOfLeds = numberOfLeds;
    // Dynamically allocate memory for the array of leds
    leds = new RgbLed[this->numberOfLeds];
  }

  RgbLedBar::~RgbLedBar(void) {
    delete[] leds;
    leds = nullptr;
  }

  RgbLed * RgbLedBar::get_led(unsigned int index) {
    if (index >= numberOfLeds) {
      return nullptr;
    }

    return &leds[index];
  }

  unsigned int RgbLedBar::get_length(void) {
    return numberOfLeds;
  }

  std::string RgbLedBar::to_string(void) {
    std::string output = "RGB Led Bar: ";
    for (unsigned int i = 0; i < numberOfLeds; i++) {
      output += leds[i].to_string();
      if (i < numberOfLeds-1) {
         output += " <=> ";
      }
    }
    return output;
  }

};