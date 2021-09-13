#pragma once

#include "rgb_led.h"
#include <string>

namespace Hardware {
  class RgbLedBar {

    // Constructors
    public:
      RgbLedBar(void);
      RgbLedBar(unsigned int numberOfLeds);

    // Destructors
    // - Required for freeing dynamically allocated memory
    public:
      ~RgbLedBar(void);

    // Getters
    public:
      RgbLed * get_led(unsigned int index);
      unsigned int get_length(void);

    // Other
    public:
      std::string to_string(void);

    // Attributes
    private:
      static const unsigned int DEFAULT_SIZE = 8;
      unsigned int numberOfLeds;
      RgbLed * leds;
  };
};