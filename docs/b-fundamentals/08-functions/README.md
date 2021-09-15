---
description: needs to be done
---

# Functions

<!-- TODO: Explain local variables, returning a local variable (actually copy of its value) -->

A function **groups together a block of statements that inherently belong together**. A function performs a **single well defined task**. Every C++ program has at least one function, namely `main()`. By grouping together statements as a function we also **allow the reuse of functionality** inside our applications, which contributes to the DRYness of our code.

The C++ standard library provides numerous built-in functions that your program can call. Take a look at the reference of the standard C++ library at [http://www.cplusplus.com/reference/](http://www.cplusplus.com/reference/).

Functions are given a symbolic name, allowing for easy calling of the functions and also making it more clear what the function does exactly (of course if the creator of the function gives it a clear and understandable name).

## Calling Existing Functions

To call a function, you need to pass the required parameters along with the function name. If the function returns a value, then you can also store the returned value for later use. When a program calls a function, program control is transferred to the called function. A called function performs a defined task and when it is finished it returns program control back to the code that called the function, ready to execute the statement following the function call.

<!-- TODO: UML flow diagram? -->

For example the `max()` function in the standard `algorithm` library compares the two arguments and returns the greatest of the two:

```cpp
#include <iostream>
#include <algorithm>

int main() {
  double biggest = std::max(3.14, 15.12);
  std::cout << "max(3.14, 15.12) => " << biggest << std::endl;
  return 0;
}
```

The `max()` function takes two arguments and returns the result. While the above code example shows an example with two literal values, it is also perfectly possible to pass variables. It is also possible to directly use the return value (without using the `biggest` variable in this case).

```cpp
#include <iostream>
#include <algorithm>

int main() {
  double pi = 3.14;
  double someNumber = 15.12;

  std::cout << "max(" << pi << ", " << someNumber
    << ") => " << std::max(pi, someNumber) << std::endl;

  return 0;
}
```

But how does one know how to call a certain function? Simple: by reading the online reference or documentation and by trying to understand the examples. Start by taking a look at the documentation of the `max()` function: [http://www.cplusplus.com/reference/algorithm/max/](http://www.cplusplus.com/reference/algorithm/max/).

## Creating Custom Functions

To create custom functions two components are required:

* A function declaration (also called the prototype), which tells the compiler about a function's name, return type, and its parameters;
* A function definition, which provides the actual body (implementation) of the function.

### Defining a Function

The general form of a C++ function definition looks like the template below

```cpp
<return_type> function_name( <comma_separated_parameter_list> ) {
  // Statements (body / implementation)
  return <value>;  // In case of a non-void function
}
```

A C++ function definition consists of a function header (same as the prototype) and a function body:

* **The return type**: A function may return a value. The return type is the data type of the value the function returns. Some functions perform the desired operations without returning a value. In this case, the return type is the keyword `void`.
* **The function name**: This is the actual name of the function.
* **Comma separated parameter list**: A parameter is like a special local variable to the function. When a function is invoked, you pass a value to the parameter. This value is referred to as an **actual parameter** or argument. The parameter list refers to the type, order, and number of the parameters of a function. Parameters are optional; that is, a function may contain no parameters.
* **Function body**: The function body contains a collection of statements that together define what the function does.

The function name and the parameter list together constitute the **function signature**. Note that the return type is not part of the function signature. As the standard says in a footnote, "Function signatures do not include return type, because that does not participate in overload resolution".

::: tip Overload resolution
A function signature is the parts of the function declaration that the compiler uses to perform overload resolution. Since multiple functions might have the same name (ie., they're overloaded), the compiler needs a way to determine which of several possible functions with a particular name a function call should resolve to. The signature is what the compiler considers in that overload resolution.
:::

If a function is to use arguments, it must declare variables that accept the values of the arguments. These variables are called the **formal parameters** of the function. The formal parameters behave like other local variables inside the function and are created upon entry into the function and destroyed upon exit.

Consider the function `sum()` shown below that determines the sum of two integral values.

```cpp
int sum(int a, int b) {
  return a + b;
}
```

Some things to note:

* The name of the function is `sum`
* The return value of the function is `int` so it needs to have a return statement that returns an integer value
* It takes two parameters, namely `a` of type `int` and `b` also of type `int`. Each parameter needs an explicit type specification.

### Declaring a Function

A function declaration tells the compiler about a functions name and how to call the function. The actual body of the function can be defined separately.

A function declaration has the following parts:

```cpp
<return_type> function_name( <comma_separated_parameter_list> );
```

In other words the function declaration is exactly the same as the function header but without the attached body found with the actual definition.

For the previous defined function `sum()`, the function declaration would be:

```cpp
int sum(int a, int b);
```

Parameter names are not important in function declaration only their type is required, so the following is also a valid declaration:

```cpp
int sum(int, int);
```

A separate function declaration is required when you

* define a function below the point where you call the function (for example using a custom function in `main()` that is defined below main)
* define a function in one source file and you call that function in another file. In such case, you should declare the function at the top of the file calling the function.

### Putting it all together

Below is an example of the `sum()` function being called from the `main()` function. Note that no declaration (prototype) is required as the `sum()` function is defined before main.

```cpp
#include <iostream>

int sum(int a, int b) {
  return a + b;
}

int main() {
  std::cout << "sum of 12 and 15 = " << sum(12, 15) << std::endl;
  return 0;
}
```

Now if one were to place the `sum()` function below main, the compiler would generate the error: `error: 'sum' was not declared in this scope`. This can be fixed by adding a declaration of the `sum()` function before `main()`.

```cpp
#include <iostream>

// Function declaration, comment out to see the compiler error
int sum(int a, int b);

int main() {
  std::cout << "sum of 12 and 15 = " << sum(12, 15) << std::endl;
  return 0;
}

int sum(int a, int b) {
  return a + b;
}
```

## Default parameter values

When you define a function, you can specify a default value for each of the **last parameters**. This value will be used if the corresponding argument is left blank when the function is called.

This is done by using the assignment operator and assigning values for the arguments in the function definition. If a value for that parameter is not passed when the function is called, the default value is used, but if a value is specified, this default value is ignored and the passed value is used instead.

Let us consider a function `print_terminal()` that prints out the terminal sign of a console (for example `>` in powershell).

```cpp
void print_terminal(char sign = '>') {
  std::cout << sign;
}
```

If no argument is passed, the default `>` is printed. In the other case the passed symbol is outputted.

```cpp
#include <iostream>

void print_terminal(char sign = '>') {
  std::cout << sign;
}

int main() {
  // Using the default symbol
  print_terminal();
  std::cout << std::endl;

  // Passing another symbol
  print_terminal('$');
  std::cout << std::endl;
  return 0;
}
```

Default parameter values can be placed in the declaration and in the definition of a function but not in both. The most logical place is the declaration as this is most likely the only thing the user sees (the definition may be hidden as we will see later).

## Functions versus methods

A **function** is a piece of code that is called by name. It can be passed data to operate on (i.e., the parameters) and can optionally return data (the return value). All data that is passed to a function is passed explicitly.

A **method** is a piece of code that is called by name that is **associated with an object**. In most respects it is identical to a function except for two key differences.

* It is implicitly passed a reference to the object for which it was called.
* It is able to operate on data that is contained within the class (remembering that an object is an instance of a class - the class is the definition, the object is an instance of that class).

## Pass by value, by pointer or by reference

While calling a function, there are three ways that arguments can be passed to a function

* **Pass by value**: This copies the actual value of an argument into the formal parameter of the function. In this case, changes made to the parameter inside the function have no effect on the argument
* **Pass by pointer**: This copies the address of an argument into the formal parameter. Inside the function, the address is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument.
* **Pass by reference**: This copies the reference of an argument into the formal parameter. Inside the function, the reference is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument.

By default, C++ uses pass by value to pass arguments. In general, this means that code within a function cannot alter the arguments used to call the function as it gets a copy of the value.

Take for example the code below where a `swap()` function tries to swap the values of two variables.

```cpp
#include <iostream>
using namespace std;

void swap(int x, int y) {
  int temp = x;
  x = y;
  y = temp;
}

int main() {
  int a = 10;
  int b = 136;

  cout << "Before call to swap:" << endl;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;

  swap(a, b);

  cout << "\nAfter call to swap:" << endl;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;

  return 0;
}
```

As C++ passes arguments by value, a copy of `a` and `b` is created and placed inside the local parameter variables `x` and `y`. Because of this changes to `x` and `y` are local to the scope of the function itself. Luckily enough because otherwise every function would be able to alter the original variables which would lead to a lot of bugs and hard to solve problems.

::: output
<pre>
Before call to swap:
a: 10
b: 136

After call to swap:
a: 10
b: 136
</pre>
:::

But what if we wanted this to work. Well then you need to pass the data using pointers or references. More on this later.

::: insight Key Insight - Return by Value
When returning a local variable from a function/method, the same applies. A copy of the local variable is returned (via the stack as we will see later on) after which the actual local variable goes out of scope and ceases to exist.
:::

## Passing an Array to a Function

In C++, just as any other datatypes, arrays can also be passed to functions.

However, when you pass an array to a function, the array will decay (it will be implicitly converted to a pointer that points to the first element of the array). This means that using the `sizeof` operator on an array passed to a function will result in the size of the pointer, which is usually 4 or 8 bytes (depending on the architecture of your machine). More on this later.

Basically this means if we pass an array to a function, we will only know where the first element lies in memory but we will not be able to tell how many elements there are from the array variable alone. That is why, when passing an array to a function, one will always need to pass the length as well.

Study the following code example which calculates the sum of all values in an array and returns the result.

```cpp
#include <iostream>
using namespace std;

int sum(int values[], size_t size) {
  int result = 0;
  for(unsigned int i = 0; i < size; i++) {
    result += values[i];
  }
  return result;
}

int main() {

  int numbers[] = { 2, 8, 15 };

  cout << "Sum of numbers: "
    << sum(numbers, sizeof(numbers)/sizeof(numbers[0])) << endl;

  return 0;
}
```

::: output
<pre>
Sum of numbers: 25
</pre>
:::

Note how the `sizeof` operator can be used in the `main` function because that is where the array was declared. `size_t` is datatype that is often used for array size, the result of `sizeof`, indexing, ...

::: tip Use std::vector where Possible
Modern C++ beste practices include using an `std::vector` instead of an array where possible. This because `std::vector` is a class which allows for dynamically adding elements. It also tracks the number of elements currently residing in the vector. More on this later.
:::

### Passing a Multidimensional Array to a Function

For passing a multidimensional array to a function in C++ one will need to specify all dimensions except the first when declaring the parameter. This is quitte an inconvenience:

```cpp
#include <iostream>

using namespace std;

void print_matrix(int matrix[][4], size_t rows, size_t cols) {
  cout << "Matrix: " << endl;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      cout << "[" << matrix[r][c] << "] ";
    }
    cout << endl;
  }
}

int main() {

  int matrix[2][4] = {  
    {0, 1, 2, 3},
    {4, 5, 6, 7}
  };

  print_matrix(matrix, 2, 4);

  return 0;
}
```

Passing a multidimensional array in C++ is not pretty. There are a lot of caveats and things to consider. Later on in this course we will see some more advanced techniques using pointers and templates. Or by God, just use a wrapper class around the array.

<!-- Later on: https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function/17569578#17569578 -->

## Exercises

Try to solve the exercises yourself. Don't go copy pasting other people's solutions.

Mark the exercises using a ✅ once they are finished.

### ❌ Fail and Ignore

*The code snippet belows reads a number from the user between `1` and `10`. However if the user provides an unparsable value, such as a string, the application becomes unusable. Fix this by using the `cin` functions `fail()`, `clear()` and `ignore()`.*

```cpp
#include <iostream>

using namespace std;

int main() {

  int number = 0;
  do {
    cout << "Please enter a number between 1 and 10: ";
    cin >> number;
  } while (number < 1 || number > 10);

  return 0;
}
```

### ❌ Foreach

*What is wrong with the code below?*

```cpp
#include <iostream>
using namespace std;

int sum(int values[]) {
  int result = 0;
  for(auto value : values) {
    result += value;
  }
  return result;
}

int main() {

  int numbers[] = { 2, 8, 15 };

  cout << "Sum of numbers: "
    << sum(numbers) << endl;

  return 0;
}
```

### ❌ Sizeof Array

*What is happening here? Why is the output of this code snippet wrong?*

```cpp
#include <iostream>
using namespace std;

int sum(int values[]) {
  int result = 0;
  for(unsigned int i = 0; i < sizeof(values); i++) {
    result += values[i];
  }
  return result;
}

int main() {

  int numbers[] = { 2, 8, 15 };

  cout << "Sum of numbers: "
    << sum(numbers) << endl;

  return 0;
}
```

### ❌ Changing Array Values

*What is going on here? Why can the `mess_it_up` function change the values of the passed array?*

```cpp
#include <iostream>
using namespace std;

void mess_it_up(int numbers[], size_t size) {
  for (unsigned int i = 0; i < size; i++) {
    numbers[i] = numbers[i] * 1337;
  }
}

int main() {

  int numbers[] = { 2, 8, 15 };

  mess_it_up(numbers, sizeof(numbers)/sizeof(numbers[0]));

  for (unsigned int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;

  return 0;
}
```
