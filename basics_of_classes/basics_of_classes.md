<!-- toc -->

# Basics of Classes

Classes are the central feature of C++ that support the Object Oriented Programming. They are often called user-defined types.
Classes are the representation of elements from the problem space inside the solution space. They combine both data and methods into one neat package (also knows as encapsulation).

The data and methods within a class are called members of the class.

## Class definitions

To define a class is to create a sort of blueprint for objects of that class. It does not actually reserve any memory to define a class. It does however tell the compiler what the name of the class is and what an object of the class will consist of and what operations can be performed on such an object.

A class in C++ follows this template:

```c++
class <name_of_class> {
    // Attributes

    // Methods
};
```

A class definition consists of the following important parts:
* the **class** keyword
* the **name of the class**
  * CamelCase starting with capital letter
  * Use sane names ! => Good programming skill
  * Mostly a Noun (Car, Point, Student, Record, Cat, Animal, ...)
* Two **curly brace**
  * We will place the rest of our code between these
* A termination **simicolon** (;)

### Header files

You can place this class definition before your main function in C++ but this will make for a terrible mess once your program starts to be come bigger. Secondly, it is not possible to share classes like that between different programs without copy pasting the code from one main to another. And that's a big no-no.

For these reasons, class definitions will always be placed in separate files called header files. These files carry the same name as the class, though mostly in lower case letters (although not mandatory), and have the extension ".h".

Take for example a class called "RgbLed":

```c++
class RgbLed {
    // Attributes

    // Methods
};
```

This would be placed inside a file called "rgb_led.h".

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

Now what happens if you include the same header file multiple times? Actually C++ states that a variable, a function, a class, ... can only be defined once in your program. This is also knows as the One-Definition Rule (ODR). When the linker is uniting all the object modules, it will complain if it finds more than one definition for the same variable/function/class.

This is where **include guards** come to play. These are a safety mechanism that will make the preprocessor only include header files that have not been included yet. A typical include guard looks something like this:

```c++
#ifndef _HEADER_RGB_LED_
#define _HEADER_RGB_LED_

class RgbLed {
    // Attributes

    // Methods
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
    // Attributes

    // Methods
};
```

### Class Attributes

Class attributes or class instance variables are the ways to store data inside an object of that particular class.

Defining class attributes is very similar to creating a variable inside a method or function. Let's add RGB colors to the RgbLed class.

```c++
#pragma once

class RgbLed {
    // Attributes
  private:
    int red;
    int green;
    int blue;

    // Methods
};
```

Notice that an access modifier (such as private, public and protected), followed by a colon `:`, can be specified for all the attributes/methods that follow it. Default access in C++ classes is *private*, so not specify anything would have had the same effect. However it is always safer to explicitly declare the attributes as private as it may lead to leaks when adding public things before the attributes.

From the moment a different modifier is listed below the current one, the new modifier is applied to all methods/attributes that follow it.

```c++

class Foo {
  private:
    //... all private here

  public:
    //... all public here

  protected:
    //... all protected here

  public:
    //... again public
};
```

### Class Methods

While attributes store the data of our objects, methods allow objects to have behavior. In C++ the declaration and actual definition of methods in separated. Inside the class definition we put the declaration of method, also known as the method **prototype**.

The prototype of a method takes on the following form:

```c++
<return_type> <name>(<comma_separated_argument_list);
```

This consists of:
* The return type of a method can be `void` (nothing to return), a primitive type such as `int`, `char`, `double`, ..., a pointer, a custom type such as a class, an enum, ...
* The name of a method should be a very clear and indicating name of what the actual method does. There are no real naming conventions in C++ as there are in Java. The most important rule is to stay consistent.
* A comma separated list of the arguments, and for the prototype the only thing that is mandatory are the types. This means that you actually don't have to state the names. However most of the time is good practice to do it anyway. Especially to a user of your class.

Let's for example declare a method called `set_color` that does not return anything (the return type is therefore `void`). It does however take 3 arguments, more specifically the red, green and blue colors. Again as with the attribute, we can specify the access modifier for all method declarations following.

```c++
#pragma once

class RgbLed {
    // Attributes
  private:
    int red;
    int green;
    int blue;

    // Methods
  public:
    void set_color(int red, int green, int blue);
};
```

#### Separating method declaration from definition

The header file contains the class definition and the class contains both the attribute definitions and method declarations. This makes for a clear separation between method declaration and actual implementation (definition).

Why? Because when we supply a class to a user of that class we may not want to provide the actual implementation as readable code. We may just wish to provide the compiled object code. However for the compiler and linker of the user to be able to use our class it will actually need to know what the class looks like (the compiler performs all sort of checks to make sure you use the class as intended). This is where the header file comes into play. The user of the class will provide both the header file and the object file to the compiler and linker, allowing it to be integrated into his/her program.

> #### Alert::Inline methods
>
> Do note that it is also possible to place the definition of a method inside the header file. This is called inline methods. The inline methods are a C++ enhancement feature to increase the execution time of a program. Methods can be instructed to compiler to make them inline so that compiler can replace those method definition wherever they are being called.
> This does not mean that it is a good idea to make every method inline, as this will be a burden on the actual memory usage of your class.
> Actually, compilers these days are smart enough to decide for themselves if they should make methods inline or not.

Let us start by implementing a method that allows us to change the color of an RgbLed object. This is called a **setter method** because it does nothing else but set a part of the state of the object. To actually implement the `set_color` method, we will need to create a file with the same name as the header file, excluding the extension, which should now be *.cpp*.

```c++
// rgb_led.cpp
#include "rgb_led.h"

void RgbLed::set_color(int red, int green, int blue) {
  this->red = red;
  this->green = green;
  this->blue = blue;
}
```
A lot can be said about the code above, so let's start.

In the example above, the name of the file is specified in comments. While some programmers do this, mostly it is a bad idea. It is a comment that may become misleading and stand in the way of change (changing the name of file if ever needed). Every decent editor will display the name of file. It is only done here to make it more clear to you as a reader of this course.

The first actual line of code is `#include "rgb_led.h"`, an include directive. It is necessary to include the class definition when defining the methods of that class.

Next is the method definition. The signature is almost the same as the prototype except for the **scope resolution operator** `::` prefixed with the name of the class. This tells the compiler that the method definition that follows belongs together with the class. Here the names of the arguments are mandatory, contrary the method prototype.

The last part of this definition is a C++ block indicated by the parentheses `{}`. Inside of these parentheses the implementation of the method is specified. Here we just save the values provided as arguments to the method, inside the attributes that we defined in our class definition. Because both the arguments and the attributes have the same names, we need to use `this->` when we want to use the attributes.

If we had used `red = red`, it would have resulted in the arguments being assigned to themselves. This because of the fact that the scope of the arguments is closer by and would of overruled the attributes. See [todo @ chapter TODO] for more info on scope.

No access modifier needs to be specified for the definition of the methods. This is only done inside the class definition.

Let us expand this example with methods that return the values of the different colors. Since these methods do not change the state of the object and just return a part of it's state to the outside world, they are called **getter methods**. Note how we named the methods with a prefix of 'get_' to indicate that they are getters.

```c++
// rgb_led.h
#pragma once

class RgbLed {
    // Attributes
  private:
    int red;
    int green;
    int blue;

    // Methods
  public:
    void set_color(int red, int green, int blue);
    int get_red(void);
    int get_green(void);
    int get_blue(void);
};
```

As a next step it is required to give the methods an implementation.

```c++
// rgb_led.cpp
#include "rgb_led.h"

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
```

Note that for the getters there is no ambiguity for the attributes. Therefore, we do not need to explicitly specify `this->`, however it is not wrong to do so. Just more typing work.

Basically when a getter method of an object is called, a value is returned. When doing this, we will need to save that value somewhere or immediately use it.

## Creating Objects

To create objects on the stack, the same syntax can be used as for creating variables of a primitive type.

So to create two RgbLed class instances (aka objects), the following code can be used.

```c++
RgbLed aliveLed;
RbgLed busyLed;
```

Important to note is that you will need to include the header file that contains the class definition before this will work.

```c++
#include <iostream>
#include "rgb_led.h"

using namespace std;

int main()
{
    cout << "Creating LEDs" << endl;

    RgbLed aliveLed;
    RbgLed busyLed;

    return 0;
}
```

While this is pretty awesome, the code above doesn't do a lot. As stated before, an OOP program is collection of objects that send messages to each other. These messages are actual requests made to the objects to show of their behavior. So in other words, we need to make method calls to the objects to make them perform actions.

Let us set the color of a led using the setter method and retrieve it back using the getter methods.

```c++
#include <iostream>
#include "rgb_led.h"

using namespace std;

int main()
{
    RgbLed aliveLed;
    RgbLed busyLed;

    aliveLed.set_color(125, 88, 33);

    cout << "R: " << aliveLed.get_red() << endl;
    cout << "G: " << aliveLed.get_green() << endl;
    cout << "B: " << aliveLed.get_blue() << endl;

    return 0;
}
```

Methods of objects can be called by using the member operator `.`. The color of the led can be set by specifying **literal** values as arguments or by passing the names of variables that hold an integer value.

> #### Info::Literals
>
> A literal is some data that's presented directly in the code, rather than indirectly through a variable or method call. Some examples are `"Hello World"`, `15`, `0x05`, `'a'`, ... The data constituting a literal cannot be modified by a program, but it may be copied into a variable for further use.


The code below prints out the values of the colors by retrieving them via the getter methods. They could also have been saved in temporary variables first and then used for displaying.

```c++
cout << "R: " << aliveLed.get_red() << endl;
cout << "G: " << aliveLed.get_green() << endl;
cout << "B: " << aliveLed.get_blue() << endl;
```

## Necessary Optimizations

While the example code of RgbLed is a good start, it is far from perfect. There are definitely some **refactoring** steps that can be done to make the code **better**.

### Constructors

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

### Namespaces

[todo]

## Declaration versus definition

[todo]

<!-- Declarations:

extern int y;
class Robot;
void Robot::fight(Robot r);


Definitions
int y;
int y = 3;    // + initialization
class Robot { ...... };
void Robot::fight(Robot r) { r.decreaseHealth() ..... } -->


## Difference function and method

[todo]

## Including Standard Libraries

[todo]

<!-- <string> is the C++ standard library string header file containing std::string and its friends. <string.h> is a different header, from the C standard library, which has functions for manipulating C strings (null-terminated strings) and other related functions.

The two are entirely different and unrelated. In C++ (as in C), a header file can have any extension. The C++ standard library headers have no extension; the C standard library headers have a .h extension.  .hpp or .hxx are also common.


Everything James said is true. It's also interesting that in updated standard C++, the C string file has been renamed to <cstring> - in fact all of the C standard library, when promoted to the C++ standard library, have been renamed with a 'c' prefix and no '.h' extension, i.e., cstdlib, cstdio, etc. It's supposed to be the case that the C functions are moved into the std namespace, as well. Many compilers continue to support <string.h>, et al., and not to put the C standard library in std::, but I believe they are not required to do either anymore. – jwismar May 10 '10 at 0:27

@jwismar: All implementations are required to provide both the <cname> and <name.h> headers; the <cname> headers, as you say, put all their non-macro names into namespace std, and the <name.h> headers put all their non-macro names into the global namespace. In many implementations, the <cname> headers also put their names into the global namespace; this is technically not allowed in C++03, but will be permitted in the forthcoming C++0x. – James McNellis May 10 '10 at 0:32 -->
