// color.h
#pragma once

#include <string>

namespace Visual {

  class Color {

    // Constructors
    public:
      Color(void);
      Color(int red, int green, int blue);

    // Methods
    public:
      void set_color(int red, int green, int blue);

    public:
      int get_red(void);
      int get_green(void);
      int get_blue(void);

    // Attributes
    private:
      int red = 0;
      int green = 0;
      int blue = 0;

    public:
    std::string to_string(void) {
      return "[" + std::to_string(red) + ", "
        + std::to_string(green) + ", "
        + std::to_string(blue) + "]";
    }

  };

};


