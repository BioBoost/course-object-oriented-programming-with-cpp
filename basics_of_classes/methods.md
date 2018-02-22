## Methods

While attributes store the data of our objects, methods allow objects to have behavior. In C++ the declaration and actual definition of methods are separated. Inside the class definition we put the declaration of method, also known as the method **prototype**.

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

### Separating method declaration from definition

The header file contains the class definition and the class contains both the attribute definitions and method declarations. This makes for a clear separation between method declaration and actual implementation (definition).

Why? Because when we supply a class to a user of that class we may not want to provide the actual implementation as readable code. We may just wish to provide the compiled object code. However for the compiler and linker of the user to be able to use our class it will actually need to know what the class looks like (the compiler performs all sort of checks to make sure you use the class as intended). This is where the header file comes into play. The user of the class will provide both the header file and the object file to the compiler and linker, allowing it to be integrated into his/her program.

> #### Alert::Inline methods
>
> Do note that it is also possible to place the definition of a method inside the header file. This is called inline methods. The inline methods are a C++ enhancement feature to increase the execution time of a program. Methods can be instructed to compiler to make them inline so that compiler can replace those method definition wherever they are being called.
> This does not mean that it is a good idea to make every method inline, as this will be a burden on the actual memory usage of your class.
> Actually, compilers these days are smart enough to decide for themselves if they should make methods inline or not.

Let us start by implementing a method that allows us to change the color of an `RgbLed` object. This is called a **setter method** because it does nothing else but set a part of the state of the object. To actually implement the `set_color` method, we will need to create a file with the same name as the header file, excluding the extension, which should now be *.cpp*.

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
