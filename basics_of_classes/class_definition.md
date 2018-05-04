## Class Definition

To define a class is to create a sort of blueprint for objects of that class. A class definition does not actually reserve any memory. It does however inform the compiler:
* what the name of the class is;
* what data an object of the class will hold;
* and what operations can be performed on objects of the class.

A class definition in C++ is constructed using the format shown below:

```c++
class <name_of_class> {
};
```

For example:

```c++
class Apple {
};
```

A class definition consists of the following important parts:
* the **class** keyword
* the **name of the class**
  * *PascalCased* starting with capital letter
  * Make sure to use sane and clear names for your classes. This is considered a good programming skill
  * Most often a Noun (Car, Point, Student, Record, Cat, Animal, ...)
* Two **curly brace** `{}`
  * Data and behavior will be defined between these curly braces.
* A termination **semicolon** `;`

<!-- Declaration is when we specify the name of the class but no definition - typical used for forward declaration -->
