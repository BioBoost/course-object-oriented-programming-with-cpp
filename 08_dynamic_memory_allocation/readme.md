---
description: Dynamic memory allocation allows our application to request memory on the fly.
---

# Chapter 08 - Dynamic Memory Allocation

C++ will store objects in different places based on how they were created. The programmer is given the choice based on efficiency and necessity. For maximum runtime speed, the storage and lifetime can be determined by the programmer while the program is being written.

## Static allocation on the Stack

All the variables, arguments and objects shown in the code below are placed on the stack, it is said they are placed in *static storage*:

```c++
void foo(int x) {
  SomeClass object;
  int numbers[100];

  // ....
}
```

The stack is an area in memory that is used directly by the processor to store data during program execution. Variables on the stack are also called **automatic** or **scoped variables**.

The stack memory is a fixed size memory region that is allocated before the program is used. Allocating static storage is much more speed-optimized, which can be important in certain situations.

It does however require you to know the exact quantity, lifetime and type of the objects when you are writing the program. More complex program will be able to be satisfied with this. Besides that the stack is also limited in size. This means that you can overflow the stack, especially on smaller embedded systems.

> **WARNING** - **Stack Overflow**
>
> A stack overflow occurs if the call stack pointer exceeds the stack bound. The call stack may consist of a limited amount of address space, often determined at the start of the program. The size of the call stack depends on many factors, including the programming language, machine architecture, multi-threading, and amount of available memory. When a program attempts to use more space than is available on the call stack (that is, when it attempts to access memory beyond the call stack's bounds, which is essentially a buffer overflow), the stack is said to overflow, typically resulting in a program crash.

## Dynamic allocation on the Heap

If you don't know until runtime how many objects you will need, what their lifetime is or what their exact type is, you will need to allocate your objects on the heap.

The heap is memory set aside for dynamic allocation. Unlike the stack, there's no enforced pattern to the **allocation** and **deallocation** of blocks from the heap; you can allocate a block at any time and free it at any time. This makes it much more complex to keep track of which parts of the heap are allocated or free at any given time.

The size of the heap is set on application startup, but can grow as space is needed (the allocator requests more memory from the operating system), so as long as the operating system is willing to provide memory, the heap can grow.

Another important difference between dynamic and static allocation is the fact that the compiler can automatically destroy objects that were created on the stack. This because the exact lifetime of those objects is known. This is not the case for objects that are created on the heap; the compiler has no knowledge of their lifetime. In C++ this is the responsibility of the programmer. If done incorrectly or not at all, the application will contain memory leaks.

<!-- note on valgrind? -->

### Creating and Destroying Objects on the Heap

To create objects on the heap, memory must be requested by using the `new` keyword as shown in the example code below:

```c++
Foo * myObject = new Foo();
```

Note how the actual variable is now a pointer to an object of type *Foo*. This is necessary because the `new` operator returns a pointer to a memory region, on the heap, occupying a Foo object.

As mentioned before, the compiler cannot automatically destroy the memory that is reserved on the heap as it does not know the lifetime of the objects. This is a responsibility of the programmer. This can be accomplished by freeing the memory once the application has no more use for it. For this the `delete` operator can be used.

```c++
Foo * myObject = new Foo();

// .... use the object

// Free the memory
delete myObject;
```

A `new` must **always** be accompanied by a `delete` somewhere in your application. If not, your application creates memory leaks.

> **WARNING** - **Memory Leak**
>
> A memory leak is created when memory is allocated but not released causing an application to consume memory reducing the available memory for other applications and eventually causing the system to page virtual memory to the hard drive slowing the application or crashing the application when than the computer memory resource limits are reached. The system may stop working as these limits are approached.

**Never access a pointer to an object after deleting it.** The resulting behavior is undefined, and if you are lucky the program just crashes.

<!-- Delete of uninitialized pointer is undefined behaviour !!! nullptr should be ok to delete -->

### Destructors

Now what if an object of a class that you created needs internal dynamic memory. In many cases this memory only needs to be freed when the object is actually destroyed.

This is where destructors come in to play. They are similar to constructors but instead of being responsible for the creation of an object of the class, they are **responsible for the destruction** of it.

A destructor has the following properties:

* it is a member method of the class
* it had the exact same name as the class, prefixed with a `~`
* it does not take any arguments; this also means it cannot be overloaded
* it has no return type, not even void

For example:

```c++
Foo::~Foo(void) {
  // Do destruction stuff such as freeing memory
}
```

## An RGB Led Class

Let's take a look at a more complete example where all these things come together.

The following implementation models an RgbLed class that holds the three color components that make up a colored led.

```c++
#pragma once

namespace Rgb {
  class RgbLed {

    // Constructors
    public:
      RgbLed(void);
      RgbLed(int red, int green, int blue);

    // Setters
    public:
      void set_color(int red, int green, int blue);

    // Getters
    public:
      int get_red(void);
      int get_green(void);
      int get_blue(void);

    // Attributes
    private:
      int red;
      int green;
      int blue;
  };
};
```

Note that the `RgbLed` class has two constructors (constructor overloading):

* a default constructor (that takes no arguments)
* a second constructor that allows us to initialize the led to a certain color

The implementation that belongs to the previous header file is shown below.

```c++
#include "rgbled.h"

namespace Rgb {

  RgbLed::RgbLed(void)
    : RgbLed(0, 0, 0) {
  }

  RgbLed::RgbLed(int red, int green, int blue) {
    set_color(red, green, blue);
  }

  void RgbLed::set_color(int red, int green, int blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
  }

  int RgbLed::get_red(void) {
    return red;
  }

  int RgbLed::get_green(void) {
    return green;
  }

  int RgbLed::get_blue(void) {
    return blue;
  }

};
```

While most of the code is self-explanatory, the default constructor does need some explanation.

```c++
RgbLed::RgbLed(void)
    : RgbLed(0, 0, 0) {
}
```

The part after the colon `:` is called the **constructor-initialization list** an is executed before the body of the constructor. Here it allows us to call another constructor of the same class before executing the code of the current constructor. This allows us to keep the code as DRY as possible.

In other words, the default constructor here first calls the other constructor with all colors set to zero (remember that everything needs to be initialized) before it executes its own code (nothing in this case).

Let's take a look at a usage example where we create an object on the stack.

```c++
#include <iostream>
#include "rgbled.h"

using namespace std;

int main() {
  Rgb::RgbLed aliveLed;

  cout << "Red = " << aliveLed.get_red() << endl;
  cout << "Green = " << aliveLed.get_green() << endl;
  cout << "Blue = " << aliveLed.get_blue() << endl;

  aliveLed.set_color(12, 233, 88);

  cout << "Red = " << aliveLed.get_red() << endl;
  cout << "Green = " << aliveLed.get_green() << endl;
  cout << "Blue = " << aliveLed.get_blue() << endl;

  return 0;
}
```

## An RGB Led Bar Class

<!-- Maybe we should refactor this code to make use of array of led objects instead of pointers -->

A led bar is a bar with a certain number of leds. A typical led bar consists of eight leds.

So let's model an RGB led bar.

```c++
#pragma once

#include "rgbled.h"

namespace Rgb {

  class LedBar {

    // Constructors and destructors
    public:
      LedBar(void);
      ~LedBar(void);

    // Getters
    public:
      RgbLed * get_led(int index);

    // Static Class Variables
    public:
      const static int NUMBER_OF_LEDS = 8;

    // Attributes
    private:
      RgbLed * bar[NUMBER_OF_LEDS];
  };

};
```

The number of LED's is not implemented as magic number. We however created a constant as a static class variable. This is more clear, more DRY and will allow us to easily change it if ever required. it was also made public so it can be accessed by the user of the class.

Most of this code is quite basic. Note that the LedBar contains an attribute `bar` which is actually an array of pointers to objects of type `RgbLed`. As this is a simple array, its size is predetermined. So once we state that a LED bar contains 8 LED's it cannot be changed unless we change the code and recompile it. The constructor will create RgbLed objects on the heap and the destructor will destroy them again as shown in the implementation below:

```c++
#include "ledbar.h"

#include <cstddef>

namespace Rgb {

  LedBar::LedBar(void) {
    for (int i = 0; i < NUMBER_OF_LEDS; i++) {
      bar[i] = new RgbLed();
    }
  }

  LedBar::~LedBar(void) {
    for (int i = 0; i < NUMBER_OF_LEDS; i++) {
      delete bar[i];
    }
  }

  RgbLed * LedBar::get_led(int index) {
    if (index >= NUMBER_OF_LEDS) {
      return nullptr;
    }

    return bar[index];
  }

};
```

Something new here. The `get_led()` method returns a pointer to an RgbLed object of the LED bar. Some mechanism should prevent that memory outside the array is accessed. Here a simple if-construct prevents this. However it is not the best option; better would of been to throw an Exception. However this is course material for later.

Do note that it is mandatory for the `get_led()` method to return a pointer in every case, so also when index goes outside of bound. However we have no actual valid pointer to return here. For this we can make use of a special C++ keyword `nullptr` which is what is called a null-pointer. It actually points to nothing and is often used in cases where no valid pointer can be returned. Trying to use this null-pointer as it were a valid pointer does result in an application crash.

Let's take a look at another usage example where we create an object on the stack.

```c++
#include <iostream>
#include "ledbar.h"

using namespace std;

int main() {
  Rgb::LedBar bar;

  for (int i = 0; i < Rgb::LedBar::NUMBER_OF_LEDS; i++) {
    cout << "[" << i << "]: " << "(R, G, B) = (";
    cout << bar.get_led(i)->get_red() << ", ";
    cout << bar.get_led(i)->get_green() << ", ";
    cout << bar.get_led(i)->get_blue() << ")" << endl;
  }

  return 0;
}
```

This would output something like this:

```text
[0]: (R, G, B) = (0, 0, 0)
[1]: (R, G, B) = (0, 0, 0)
[2]: (R, G, B) = (0, 0, 0)
[3]: (R, G, B) = (0, 0, 0)
[4]: (R, G, B) = (0, 0, 0)
[5]: (R, G, B) = (0, 0, 0)
[6]: (R, G, B) = (0, 0, 0)
[7]: (R, G, B) = (0, 0, 0)
```

Note that when the main function terminates (closing curly brace is reached), the `bar` object goes out of scope and the destructor is automatically called (as this object was created on the stack).

## An RGB Led String Class

But what if we wanted to create a string of LED's where the size will be determined at runtime (for example by the user of the application). In this case an option would be to make use of the vector class of standard libraries. This is an array-like container class that allows elements to be added on the fly. The advantage of a vector is that it can grow dynamically as elements are added to it.

More information on the vector class can be found at [http://en.cppreference.com/w/cpp/container/vector](http://en.cppreference.com/w/cpp/container/vector).

The `LedString` class looks like this:

```c++
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

```c++
std::vector<RgbLed *> leds;
```

The implementation of the LedString class is shown below.

```c++
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

```c++
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

## Summary

**Stack**:

* Stored in computer RAM just like the heap.
* Variables created on the stack will go out of scope and automatically deallocated.
* Much faster to allocate in comparison to objects on the heap.
* Implemented with an actual stack data structure.
* Stores local data, return addresses, used for parameter passing
* Can have a stack overflow when too much of the stack is used. (mostly from infinite (or too much) recursion, very large allocations)
* Data created on the stack can be used without pointers.
* You would use the stack if you know exactly how much data you need to allocate before compile time and it is not too big.
* Usually has a maximum size already determined when your program starts

**Heap**:

* Stored in computer RAM just like the stack.
* In C++, variables on the heap must be destroyed manually and never fall out of scope. The data is freed with delete or delete[]
* Slower to allocate in comparison to variables on the stack.
* Used on demand to allocate a block of data for use by the program.
* Can have fragmentation when there are a lot of allocations and deallocations
* In C++, data created on the heap will be pointed to by pointers and allocated with new.
* Can have allocation failures if too big of a buffer is requested to be allocated.
* You would use the heap if you don't know exactly how much data you will need at run time or if you need to allocate a lot of data.
* Responsible for memory leaks

```c++
int foo() {
  char *pBuffer; // nothing allocated yet (excluding the pointer itself, which is allocated on the stack).
  bool b = true; // Allocated on the stack.

  if(b) {
    // Create 500 chars on the stack
    char buffer[500];

    // Create 500 chars on the heap
    pBuffer = new char[500];

   } // buffer is deallocated here, pBuffer is not
} // oops there's a memory leak, should have called delete[] pBuffer;
```
