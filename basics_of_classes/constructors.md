## Constructors

The attributes in the RgbLed example class have not been initialized. This means that the actual values will be undefined and more particular just junk, depending the previous values of the assigned memory. This is why it is so extremely important to **initialize everything in C++ before actually using it**.

This is where constructors come into play. Constructors are
* methods that carry the same name as the class
* have no return type

The main purpose of a constructor is to **initialize new objects and put them in a valid state, ready for first use**.

Let's create a basic constructor for the RgbLed class that initializes the color components to zero. First a prototype needs to be added to the class definition.

```c++
// rgb_led.h
#pragma once

class RgbLed {
    // Attributes
  private:
    int red;
    int green;
    int blue;

    // Constructors
  public:
    RgbLed(void);

    // Methods
  public:
    void set_color(int red, int green, int blue);
    int get_red(void);
    int get_green(void);
    int get_blue(void);
};
```

The constructor here does not take any arguments; that is also called a default constructor. While it is not mandatory to split up the constructors and methods, it often creates a clearer image for the user of the class.

The implementation of the constructor could look like this.

```c++
// rgb_led.cpp
#include "rgb_led.h"

RgbLed::RgbLed(void) {
  this->red = 0;
  this->green = 0;
  this->blue = 0;
}

void RgbLed::set_color(int red, int green, int blue) {
  this->red = red;
  this->green = green;
  this->blue = blue;
}

//...
```

However if you take a good look at this code, you may notice that we could have create a shorter implementation for the constructor by re-using the `set_color` method in stead of duplicating it's implementation. So let's refactor this.

```c++
// rgb_led.cpp
#include "rgb_led.h"

RgbLed::RgbLed(void) {
  set_color(0, 0, 0);
}

void RgbLed::set_color(int red, int green, int blue) {
  this->red = red;
  this->green = green;
  this->blue = blue;
}

//...
```
