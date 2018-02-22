## Header files

The class definition can be placed before your main function in C++ but this will make for a terrible mess once your program starts to become bigger. Secondly, it is not possible to share classes like that between different programs without copy pasting the code from one application to another. And that's a big no-no.

For these reasons, class definitions will always be placed in separate files called header files. These files carry the same name as the class, though mostly in lower case letters (prefered snake_case, although not mandatory), and have the extension ".h".

Take for example a class called `RgbLed`:

```c++
class RgbLed {

};
```

This would be placed inside a file called `rgb_led.h`.

However if you want to create objects of your class somewhere else you will need to tell the compiler where to find the class definition. This can be achieved by including the header file using a pre-processor `#include` directive.

```c++
#include <iostream>     // Include standard/external libraries
#include "rgb_led.h"    // Include project header files

using namespace std;

//...
```

As can be seen from the example code, there are different ways to use an `#include` directive.
* When using `<....>` with a `#include` directive you are telling the compiler to search for the header file within the standard libraries of C++ and within the include paths made available to the compiler (for example externally installed libraries).
* When using `"...."` with a `#include` directive you are telling the compiler to search for the header file within the current project directory.

The preprocessor will actually take the content from the header-file and replace the `#include` directive with it.

### Include Guards

Now what happens if you include the same header file multiple times? Actually C++ states that a variable, a function, a class, ... can only be defined once in a single application. This is also known as the **One-Definition Rule (ODR)**. When the linker is uniting all the object modules, it will complain if it finds more than one definition for the same variable/function/class.

This is where **include guards** come into play. These are a safety mechanism that will make the preprocessor only include header files that have not been included yet. A typical include guard looks something like this:

```c++
#ifndef _HEADER_RGB_LED_
#define _HEADER_RGB_LED_

class RgbLed {

};

#endif
```

Basically it does as the directives state. If the label `_HEADER_RGB_LED_` has not yet been defined, then define it, include the class definition and end it. If the label has already been defined than the class definition is not included anymore.

These include guards are only of importance for the preprocessor, therefore they are prefixed with a hashtag (#).

This example also shows that the preprocessor needs several passes to process everything. The first pass it will just replace the `#include ...` with the exact content of the header file. With the second pass it will process the `#ifndef` directives.

One disadvantage of the include guards as shown above it that you need to declare a label which must be unique throughout your whole program (including all libraries you include). For this a new system was introduced using the `#pragma once` directive. This directive tells the preprocessor to only include the file once. It also makes the code shorter and more clear.

```c++
#pragma once

class RgbLed {

};
```
