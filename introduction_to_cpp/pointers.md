## Pointers

A pointer is **a variable which holds the address to a location in memory**. C++ gives you the power to manipulate data in the computer's memory directly via a pointer. C++ pointers may seem complex at first, but when used correctly they can be fun and handy. In certain areas they cannot be avoided, such as for example for **dynamic memory allocation**.

As stated before, a variable is a symbolic name for a certain location inside your computer memory. This location is actually an address. Using the reference operator `&` one can determine the address of the variable. Consider the following example which will print the address of the variables `x` and `y`:

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

Like any variable or constant, you must declare a pointer before you can work with it. As C++ is a statically typed language, the type is required to declare a pointer. This is the type of data that will live at the memory address it points to. The general form of a pointer variable declaration is:

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

Pointers and arrays are strongly related. In fact, an array variable is nothing more than a **constant pointer pointing at the first element of the array**. Actually a pointer can be dereferenced using the indexing operator used on an array variable as shown in the example below:

```c++
#include <iostream>
using namespace std;
int main()
{
    const int SIZE = 5;
    int numbers[SIZE];
    int * pNumbers = numbers;

    for (unsigned int i = 0; i < SIZE; i++) {
        pNumbers[i] = 3 * i;
    }

    for (unsigned int i = 0; i < SIZE; i++) {
        cout << pNumbers[i] << endl;
    }

    return 0;
}
```

Also note that we do not need to request the address of the array to initialize the pointer. This because the array variable is already a pointer. Of course if you do wish to use the address-of operator you can use the following construct:

```c++
const int SIZE = 5;
int numbers[SIZE];
int * pNumbers = &(numbers[0]);
```

This would allow you to create a pointer to an element somewhere inside the boundaries of the array. For example for the second element:

```c++
const int SIZE = 5;
int numbers[SIZE];
int * pToElement = &(numbers[2]);
```

Since an array variable is actually a pointer, it is perfectly valid to dereference it using the dereference operator `*`.

```c++
const int SIZE = 5;
int numbers[SIZE];

(* numbers) = 15;      // Would change the first element to a value of 15
```

However do keep in mind that an array variable is **constant pointer**. This means that the array variable itself cannot be made to point to something else than the first element of the actual array in memory.

```c++
const int SIZE = 5;
int numbers[SIZE];
// Invalid !!!!!!
numbers = &(numbers[3])
```

#### Pointer Arithmetic

Since pointers hold addresses, it is perfectly legal to perform some arithmetic operations on the actual value held by the pointer. There are four arithmetic operators that can be performed on pointers:
* Increment: ++
* Decrement: --
* Addition: +
* Subtraction: -

To understand pointer arithmetic one needs to keep in mind that the size of the datatype to which the pointer refers to, is also put into account. This means that if you have a pointer that points to integer at memory address `5000` on a 32-bit computer and you add `1` you will end up at address `5004`, assuming that the integer is represented using 32 bits.

This can actually be used in combination with a pointer to an array. Take a close look at the example below where a pointer is incremented to index all the array elements:

```c++
#include <iostream>
using namespace std;
int main()
{
    const int SIZE = 5;
    int numbers[SIZE];
    int * pNumbers = numbers;

    for (unsigned int i = 0; i < SIZE; i++) {
        *(pNumbers++) = 3 * i;
    }

    pNumbers = numbers;
    for (unsigned int i = 0; i < SIZE; i++) {
        cout << "numbers[" << i << "] @ " << pNumbers << " = " << *(pNumbers++) << endl;
    }

    return 0;
}
```

<!-- Maybe also add example with simple addition -->

### Passing Pointers as Function Parameters

C++ allows you to pass a pointer as a parameter to a function. To do so, simply declare the function parameter as a pointer type.

Passing data to functions via pointers is often applied in the following situations:
* to allow the function to alter the actual value of the passed arguments
* to be able to return more than one value from a function (this is often used in C, less required in C++ as there we can use data objects)
* performance wise it is often done to pass larger and more complex objects (less memory usage)
* to pass an array to a function

Remember the `swap()` example from the "Functions" chapter. To get this to work we can actually use pointers to integers:

```c++
#include <iostream>
using namespace std;

void swap(int * x, int * y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 10;
    int b = 136;

    cout << "Before call to swap:" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    swap(&a, &b);

    cout << "\nAfter call to swap:" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}
```

While the parameters are still passed by value, this time the addresses to the actual memory are copied. However via that same address we have access to the original data.

```text
Before call to swap:
a: 10
b: 136

After call to swap:
a: 136
b: 10
```
