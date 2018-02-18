## Pointers

A pointer is **a variable whose value is the address of another variable**. C++ pointers may seem complex at first, but when used correctly they can be fun and handy. In certain areas they cannot be avoided, such as for example for **dynamic memory allocation**.

As stated before, a variable is a symbolic name for a certain location inside your computer memory. This location is actually an address. Using the ampersand `&` operator one can determine the address of the variable. Consider the following example which will print the address of the variables `x` and `y`:

```c++
#include <iostream>

int main() {
    int x = 15;
    int y = 0;

    std::cout << "x = " << x << " and has an address of " << &x << std::endl;
    std::cout << "y = " << y << " and has an address of " << &y << std::endl;

    return 0;
}
```

which would output something similar to:

```text
x = 15 and has an address of 0x6afefc
y = 0 and has an address of 0x6afef8
```

### Declaring a Pointer

Like any variable or constant, you must declare a pointer before you can work with it. The general form of a pointer variable declaration is:

```c++
<type> * variable_name;
```

Basically this can be translated to `variable_name` is a pointer which can hold the address of a memory location containing a `type`. The type can be any valid C++ type, such as the primitive types, classes, structs, ...

Take a look at the following examples:

```c++
int * pointerToInt;         // pointer to an integer
double * pointerToDouble;   // pointer to a double
float * pointerToFloat;     // pointer to a float
char * pointerToChar;       // pointer to character
```

The actual data type of the value of all pointers, whether integer, float, character, or otherwise, is the same, a long hexadecimal number that represents a memory address. The only difference between pointers of different data types is the data type of the variable or constant that the pointer actually points to.

### Initializing a Pointer

As with any other variable, a pointer needs to be initialized before it can be used. For this we need to assign the address of a variable to the pointer. As shown before, the address of a variable can be retrieved by placing an `&` before it. The resulting address can then be assigned to a pointer of the same type as the variable.

```c++
int x = 15;
int * pointerToX = &x;

double z = 25.3;
double * pointerToZ = &z;
```

### Using Pointers

Pointers are mainly used to directly access the memory they are pointing to. So in other words we need to be able to access the actual data and not the address inside the pointer. This can be achieved by dereferencing the pointer using the dereference operator `*`. Once the pointer is dereferenced, it can be threated as a normal variable.

An example where a pointer to an integer variable is used to change the actual value of the integer variable:

```c++
#include <iostream>

int main() {
    int x = 15;
    int * pointerToX = &x;      // Make pointer point to memory location of x

    (*pointerToX) = 22;

    std::cout << "x = " << x << " or via pointer = " << (*pointerToX) << std::endl;

    return 0;
}
```

While not strictly necessary to add parentheses around the dereferenced pointers (as the dereference operator has a high precedence), it often makes the code more clear.

### Pointers and Arrays

TODO

### Pointer Arithmetic

TODO

### Pointers to Pointers

TODO

### Passing Pointers as Function Parameters

TODO

<!-- Simple usage - a swap method -->
