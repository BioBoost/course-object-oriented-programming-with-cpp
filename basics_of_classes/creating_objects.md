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
