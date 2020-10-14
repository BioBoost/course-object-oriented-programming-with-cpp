---
description: needs to be done
---

# Constructors

Constructor overloading
Default and non-default constructors
Copy constructor


## Constructors

The attributes in the Color example class have already been initialized to a default value of 0. However when creating a `Color` object it would be much cleaner if it could be initialized on creation with the correct color.

This is where constructors come into play. Constructors are

* methods that carry the **exact same name as the class**
* have **no return type**

The main purpose of a constructor is to **initialize new objects and put them in a valid state, ready for first use**.

Let's create a basic constructor for the `Color` class that initializes the color components to a given. First a prototype needs to be added to the class definition.

```cpp
// color.h
#pragma once

namespace Visual {

  class Color {

    // Constructors
    public:
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

  };

};
```

The constructor here takes three arguments, namely the color components. While it is not mandatory to split up the constructors and methods, it often creates a clearer image for the user of the class.

The implementation of the constructor can actually use the `set_color()` method to implement it behavior. That's DRY!

```cpp
// color.cpp
#include "color.h"

namespace Visual {

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
```

Now when creating `Color` objects, the components can be set when the object is instanciated.

```cpp
#include <iostream>
#include "color.h"

using namespace std;
using namespace Visual;

int main()
{
    cout << "Creating the color yellow" << endl;

    Color yellow(255, 255, 0);

    cout << "Yellow has the following components:" << endl;
    cout << "R: " << yellow.get_red() << endl;
    cout << "G: " << yellow.get_green() << endl;
    cout << "B: " << yellow.get_blue() << endl;

    return 0;
}
```

### Default Constructors

There is one thing missing from this implementation and that is a default constructor.

Just as in Java, C++ generates a default constructor (one without arguments) for you if you do not define any constructor yourself. At the moment you define a constructor inside the class, even if not a default constructor, you lose this functionality from the compiler.

This means that before we created the constructor with the color compoments, the C++ compiler generated a constructor for us, which we lost when we added our own constructor.

This basically means that the original instantiation of a `Color` object will fail:

```cpp
Color white;        // Fails, no default constructor
```

Luckily in C++, a class can have more than one constructor, as long as each has a different list of arguments. This concept is known as **constructor overloading** and is quite similar to method/function overloading.

* Overloaded constructors essentially have the same name (name of the class) and different number of arguments.
* A constructor is called depending upon the number and type of arguments passed.
* While creating the object, arguments must be passed to let compiler know, which constructor needs to be called.

So to add a default constructor to the `Color` class we first need to declare it in the class:

```cpp
// color.h
#pragma once

namespace Visual {

  class Color {

    // Constructors
    public:
      Color(void);    // Default constructor
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

  };

};
```

The implementation of the default constructor can actually be left empty because the attributes are already being initialized to zero. It can however be argued that it's cleaner to call the `set_color()` method using three zero values.

<!-- Should we introduce constructor initialization list here or how to call other constructors? -->

```cpp
// color.cpp
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
```

Now both constructors can be used to create objects of the class `Color`:

```cpp
Color yellow(255, 255, 0);      // Init constructor
Color white;                    // Default constructor
```

::: warning Default Constructor Parentheses
Don't place parenthes `()` after the object name when creating an instance using the default constructor. This will throw off the C++ compiler and make it think you are declaring a function `white()` that returns an object of type `Color`. Welcome to the world of C++ :).
:::
