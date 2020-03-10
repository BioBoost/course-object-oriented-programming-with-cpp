---
description: Dynamic memory allocation allows our application to request memory on the fly.
title: 08 - Dynamic Memory Allocation
---

# Chapter 08 - Dynamic Memory Allocation

C++ will store objects in different places based on how they were created. The programmer is given the choice based on efficiency and necessity. For maximum runtime speed, the storage and lifetime can be determined by the programmer while the program is being written.

## Allocation on the Stack

<!-- Static allocation -->

All the variables, arguments and objects shown in the code below are placed on the stack. Even the return value of a function/method is passed via the stack.

```cpp
double foo(int x) {
  SomeClass object;
  int numbers[100];
  double sum = 0;

  // ....
  return sum;
}
```

The stack is an area in memory that is used directly by the processor to store data during program execution. Variables on the stack are also called **automatic** or **scoped variables**.

The stack memory is a fixed size memory region that is allocated before the program is used. Allocating static storage is much more speed-optimized, which can be important in certain situations.

It does however require you to know the exact quantity, lifetime and type of the objects when you are writing the program. Besides that the stack is also limited in size. This means that you can overflow the stack, especially on smaller embedded systems.

::: warning Stack Overflow
A stack overflow occurs if the call stack pointer exceeds the stack bound. The call stack may consist of a limited amount of address space, often determined at the start of the program. The size of the call stack depends on many factors, including the programming language, machine architecture, multi-threading, and amount of available memory. When a program attempts to use more space than is available on the call stack (that is, when it attempts to access memory beyond the call stack's bounds, which is essentially a buffer overflow), the stack is said to overflow, typically resulting in a program crash.
:::

## Dynamic allocation on the Heap

If you don't know how many objects you will need until runtime, what their lifetime is or what their exact type is, you will need to allocate your objects on the heap.

The heap is memory set aside for dynamic allocation. Unlike the stack, there's no enforced pattern to the **allocation** and **deallocation** of blocks from the heap; you can allocate a block at any time and free it at any time. This makes it much more complex to keep track of which parts of the heap are allocated or free at any given time.

The size of the heap is set on application startup, but can grow as space is needed (the allocator requests more memory from the operating system), so as long as the operating system is willing to provide memory, the heap can grow.

Another important difference between dynamic and static allocation is the fact that the compiler can automatically destroy objects that were created on the stack. This because the exact lifetime of those objects is known. This is not the case for objects that are created on the heap; the compiler has no knowledge of their lifetime. In C++ this is the responsibility of the programmer. If done incorrectly or not at all, the application will contain memory leaks.

<!-- note on valgrind? -->
<!-- Difference heap and stack on embedded system? Shared heap and own stack for example for threads on mbed -->

### Creating and Destroying Objects on the Heap

To create objects on the heap, memory must be requested by using the `new` keyword as shown in the next code snippet:

```cpp
Foo * myObject = new Foo();
```

Note how the actual variable is now a pointer to an object of type `Foo`. This is necessary because the `new` operator returns a pointer to a memory region, on the heap, occupying a `Foo` object.

As mentioned before, the compiler cannot automatically destroy the memory that is reserved on the heap as it does not know the lifetime of the objects. This is a responsibility of the programmer. This can be accomplished by freeing the memory once the application has no more use for it. For this the `delete` operator can be used.

```cpp
Foo * myObject = new Foo();

// .... use the object

// Free the memory
delete myObject;
```

A `new` must **always** be accompanied by a `delete` somewhere in your application. If not, your application creates memory leaks.

::: warning Memory Leak
A memory leak is created when memory is allocated but not released causing an application to consume memory reducing the available memory for other applications and eventually causing the system to page virtual memory to the hard drive slowing the application or crashing the application when than the computer memory resource limits are reached. The system may stop working as these limits are approached.
:::

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

```cpp
Foo::~Foo(void) {
  // Do destruction stuff such as freeing memory
}
```

## An RGB Led Class

Let's take a look at a more complete example where all these things come together.

The following implementation models an `RgbLed` class that contains (is composed of) a `Color` object, modeling the three color components that make up a colored led.

::: tip Color class
The implementation of the `Color` class can be found in [04 - Basics of Classes](../04-basics-of-classes/README.md).
:::

```cpp
#pragma once

#include "color.h"

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

    // Attributes
    private:
      Visual::Color color;
  };
};
```

Note that the `RgbLed` class has two constructors (constructor overloading):

* a default constructor (that takes no arguments)
* a second constructor that allows us to initialize the led to a certain color

The implementation that belongs to the previous header file is shown below.

```cpp
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

};
```

While most of the code is self-explanatory, the default constructor does need some explanation.

```cpp
RgbLed::RgbLed(void)
  : RgbLed(Color(255, 0, 0)) {
}
```

The part after the colon `:` is called the **constructor-initialization list** an is executed before the body of the constructor. Here it allows us to call another constructor of the same class before executing the code of the current constructor. This allows us to keep the code as DRY as possible.

In other words, the default constructor here first calls the other constructor with all color components set to zero except the `red` one (remember that everything needs to be initialized) before it executes its own code (nothing in this case).

<!-- Maybe next year explain full process:
- default constructor of RgbLED is called
- this calls other contructor of RGBLED
- before the actual init constructor of RGBLED is called, the default constructor of color is called and executed
- now init constructor of rgbled executes (setting color to red)
- last default constructor of rgbled does its things -->

Let's take a look at a usage example where we create an object on the stack.

```cpp
#include <iostream>
#include "rgb_led.h"

using namespace std;

int main() {
  Hardware::RgbLed aliveLed;

  cout << "Red = " << aliveLed.get_color().get_red() << endl;
  cout << "Green = " << aliveLed.get_color().get_green() << endl;
  cout << "Blue = " << aliveLed.get_color().get_blue() << endl;

  cout << "Setting the color of the led to yellow:" << endl;
  aliveLed.set_color(Visual::Color(88, 88, 0));

  cout << "Red = " << aliveLed.get_color().get_red() << endl;
  cout << "Green = " << aliveLed.get_color().get_green() << endl;
  cout << "Blue = " << aliveLed.get_color().get_blue() << endl;

  return 0;
}
```

## An RGB Led Bar Class

<!-- Maybe we should refactor this code to make use of array of led objects instead of pointers -->

A led bar is a bar with a certain number of leds. A typical led bar consists of eight leds. But what if we requested the number of LEDs from the user. In that case we do not know how many LEDs we initially need to provide. One could say, reserve enough, but what is enough? `255`? If the user then only wanted 4 LEDs, it would be extremely inefficient.

So let's model an RGB led bar that can dynamically allocate the number of LEDs that is requested by the user at runtime.

```cpp
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
```

The actual led objects will be stored in an array `leds` which is declared as a pointer in the `RgbLedBar` class and not as an actual array using the `[]` notation. This because if we were to declare it as an array, we would need to supply the size and we also would not be able to assign it a new memory block afterwards (remember that an array is constant pointer). The actual memory for this array will be allocated dynamically at runtime in the constructor.

The number of LED's for the default constructor is not implemented as a magic number. A constant `DEFAULT_SIZE` under the form of a `static` class variable is added. This is more clear, more DRY and will allow us to easily change it if ever required.

Since objects of this class will be allocating dynamic memory (the array of leds), a destructor `~RgbLedBar()` needs to be provided to free the memory after an object of this class is destroyed or goes out of scope.

```cpp
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
```

Something new here. The destructor needs to use the `delete[]` operator since `leds` is an array of objects and not a single object.

The `get_led()` method returns a pointer to an RgbLed object of the LED bar. Some mechanism should prevent that memory outside the array is accessed. Here a simple if-construct prevents this. Another option would of been to to throw an Exception. However this is course material for later.

Do note that it is mandatory for the `get_led()` method to return a pointer in every case, so also when index goes outside of bound. However we have no actual valid pointer to return here. For this we can make use of a special C++ keyword `nullptr` which is what is called a null-pointer. It actually points to nothing and is often used in cases where no valid pointer can be returned. Trying to use this null-pointer as it were a valid pointer does result in an application crash.

::: tip Why does `get_led()` return a pointer?
The method `get_led()` returns a pointer to the original object because we want the user of our class to be able to change the color of the leds. If we were to return the object itself, a copy would be returned (this is because functions and methods return by-value). Changing the color of this copy would not effect the origal led.
:::

The next code snippet shows a usage example where the number of leds is requested from the user.

```cpp
#include <iostream>
#include "rgb_led_bar.h"

using namespace std;

int main() {

  cout << "Welcome to LED Bar Demo ..." << endl;

  unsigned int numberOfLeds = 0;
  cout << "How many leds would you like to add to the ledbar? ";
  cin >> numberOfLeds;

  cout << endl << "Creating a ledbar with " << numberOfLeds << " leds" << endl;
  Hardware::RgbLedBar bar(numberOfLeds);
  cout << bar.to_string() << endl;

  cout << endl << "Let us set some random colors:" << endl;

  srand(time(0));
  for (unsigned int i = 0; i < bar.get_length(); i++) {
    bar.get_led(i)->set_color(Visual::Color(rand()%255, rand()%255, rand()%255));
  }
  cout << bar.to_string() << endl;

  return 0;
}
```

::: codeoutput
<pre>
Welcome to LED Bar Demo ...
How many leds would you like to add to the ledbar? 5

Creating a ledbar with 5 leds
RGB Led Bar: [255, 0, 0] <=> [255, 0, 0] <=> [255, 0, 0] <=> [255, 0, 0] <=> [255, 0, 0]

Let us set some random colors:
RGB Led Bar: [74, 117, 143] <=> [99, 30, 182] <=> [168, 100, 228] <=> [253, 179, 253] <=> [148, 162, 84]
</pre>
:::

Note that when the main function terminates (closing curly brace is reached), the `bar` object goes out of scope and the destructor is automatically called (as the `RgbLedBar` object itself was actually created on the stack).

## Detecting Memory Leaks using Valgrind

A good tool to check for memory leaks and many other bugs is `valgrind`. While this is a pure Linux tool, it can be used on the `Windows Subsystem for Linux`.

Just start valgrind and point it to your binary by executing the command as follows: `valgrind -s <binary>`.

::: codeoutput
<pre>
==15053== Memcheck, a memory error detector
==15053== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==15053== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==15053== Command: ./bin/ledbar
==15053== 
Welcome to LED Bar Demo ...
How many leds would you like to add to the ledbar? 5

Creating a ledbar with 5 leds
RGB Led Bar: [255, 0, 0] &lt;=&gt; [255, 0, 0] &lt;=&gt; [255, 0, 0] &lt;=&gt; [255, 0, 0] &lt;=&gt; [255, 0, 0]

Let us set some random colors:
RGB Led Bar: [199, 159, 128] &lt;=&gt; [144, 124, 160] &lt;=&gt; [215, 72, 61] &lt;=&gt; [207, 153, 122] &lt;=&gt; [0, 123, 92]
==15053== 
==15053== HEAP SUMMARY:
==15053==     in use at exit: 0 bytes in 0 blocks
==15053==   total heap usage: 10 allocs, 10 frees, 75,238 bytes allocated
==15053== 
==15053== All heap blocks were freed -- no leaks are possible
==15053== 
==15053== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
</pre>
:::

::: codeurl
[https://github.com/BioBoost/course-object-oriented-programming-with-cpp/tree/master/docs/08-dynamic-memory-allocation/code/led-bar-demo](https://github.com/BioBoost/course-object-oriented-programming-with-cpp/tree/master/docs/08-dynamic-memory-allocation/code/led-bar-demo)
:::

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

```cpp
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
