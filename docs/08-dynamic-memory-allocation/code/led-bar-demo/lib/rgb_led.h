#pragma once

#include "color.h"
#include <string>

namespace Hardware {
  class RgbLed {

    // Constructors
    public:
      RgbLed(void);
      RgbLed(Visual::Color color);

    // Setters
    public:
      void set_color(Visual::Color color);

    // Getters
    public:
      Visual::Color get_color(void);

    // Other
    public:
      std::string to_string(void);

    // Attributes
    private:
      Visual::Color color;
  };
};