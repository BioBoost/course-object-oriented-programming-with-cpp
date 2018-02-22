## Class Definition

<!-- Declaration is when we specify the name of the class but no definition - typical used for forward declaration -->

To define a class is to create a sort of blueprint for objects of that class. It does not actually reserve any memory to define a class. It does however tell the compiler what the name of the class is and what an object of the class will consist of and what operations can be performed on such an object.

A class in C++ follows this template:

```c++
class <name_of_class> {

};
```

A class definition consists of the following important parts:
* the **class** keyword
* the **name of the class**
  * PascalCased starting with capital letter
  * Use sane names ! => Good programming skill
  * Mostly a Noun (Car, Point, Student, Record, Cat, Animal, ...)
* Two **curly brace** `{}`
  * We will place the rest of our code between these
* A termination **semicolon** `;`
