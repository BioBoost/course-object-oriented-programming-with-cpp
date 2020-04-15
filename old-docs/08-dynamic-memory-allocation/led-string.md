Left over that needs to be refactored for next year.

## An RGB Led String Class

But what if we wanted to create a string of LED's where the size will be determined at runtime (for example by the user of the application). In this case an option would be to make use of the vector class of standard libraries. This is an array-like container class that allows elements to be added on the fly. The advantage of a vector is that it can grow dynamically as elements are added to it.

More information on the vector class can be found at [http://en.cppreference.com/w/cpp/container/vector](http://en.cppreference.com/w/cpp/container/vector).

The `LedString` class looks like this:

```cpp
#pragma once

#include <vector>
#include "rgbled.h"

// DO NOT DO THIS
//using namespace std;

namespace Rgb {

  class LedString {

    // Constructors and destructors
    public:
      LedString(int size);
      ~LedString(void);

    // Getters
    public:
      RgbLed * get_led(int index);

    private:
      std::vector<RgbLed *> leds;

  };

};
```

This is very similar to LedBar, except for the fact that the led pointers are stored in a vector.

A special note on that is required. When the vector attribute is declared we must provide the type that it will house. In this case it will need to store pointers to RgbLed objects. Note the special syntax; this is called a **template**. It allows a programmer to create classes that will make use of objects of unknown types at the moment he/she is creating an implementation for the class. This is however material for a chapter on its own, so more on this later.

```cpp
std::vector<RgbLed *> leds;
```

The implementation of the LedString class is shown below.

```cpp
#include "ledstring.h"

namespace Rgb {

  LedString::LedString(int size) {
    for (int i = 0; i < size; i++) {
      leds.push_back(new RgbLed());
    }
  }

  LedString::~LedString(void) {
    for (int i = 0; i < leds.size(); i++) {
      delete leds[i];
    }
    leds.clear();   // Remove all elements
  }

  RgbLed * LedString::get_led(int index) {
    if (index >= leds.size()) {
      return nullptr;
    }

    return leds[index];
  }

};
```

Again very similar to the LedBar class. Except that the RgbLed object pointer are pushed at the back of the vector using the `push_back()` method. The destructor frees all the RgbLed instances and then clears the vector to remove all elements themselves. Note that calling `clear()` alone would not have been enough. We need to explicitly delete the objects.

Let's take a look at another usage example where we create an object on the stack. In this case we ask the user how many LED's he/she would like in his/her string of leds. This can be done using `cin` which works similar to `cout` but for input.

```cpp
#include <iostream>
#include "ledstring.h"

using namespace std;

int main() {
  // Ask user how many leds to add to string
  int sizeOfString = 0;
  cout << "How many leds would you require?: ";
  cin >> sizeOfString;

  cout << "Creating led string of " << sizeOfString << " leds" << endl;
  Rgb::LedString ledstring(sizeOfString);

  for (int i = 0; i < sizeOfString; i++) {
    cout << "[" << i << "]: " << "(R, G, B) = (";
    cout << ledstring.get_led(i)->get_red() << ", ";
    cout << ledstring.get_led(i)->get_green() << ", ";
    cout << ledstring.get_led(i)->get_blue() << ")" << endl;
  }

  return 0;
}
```

This would output something like this:

```text
How many leds would you require?: 14
Creating led string of 14 leds
[0]: (R, G, B) = (0, 0, 0)
[1]: (R, G, B) = (0, 0, 0)
[2]: (R, G, B) = (0, 0, 0)
[3]: (R, G, B) = (0, 0, 0)
[4]: (R, G, B) = (0, 0, 0)
[5]: (R, G, B) = (0, 0, 0)
[6]: (R, G, B) = (0, 0, 0)
[7]: (R, G, B) = (0, 0, 0)
[8]: (R, G, B) = (0, 0, 0)
[9]: (R, G, B) = (0, 0, 0)
[10]: (R, G, B) = (0, 0, 0)
[11]: (R, G, B) = (0, 0, 0)
[12]: (R, G, B) = (0, 0, 0)
[13]: (R, G, B) = (0, 0, 0)
```
