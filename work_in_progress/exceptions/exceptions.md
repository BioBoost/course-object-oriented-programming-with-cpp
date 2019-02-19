<!-- toc -->

# Exceptions

Some errors in code can be caught early on by for example the compiler.
Most of the time these are **syntax errors**, such as forgetting to terminate a statement
with a semicolon `;`. These are easy errors to fix.

<!-- Should we give an overview of all types of errors ? -->

## Types of Errors

A program in C++ will go through various phases when compiling your source code to an
a useable and executable application:

![The Compilation Process of a C++ Program](../hello_universe/img/the_compilation_process.png)

So, the compiler compiles expanded source code to assembly source code successfully
if the syntax or meaning of program is correctly written.
The compiler's job is to analyze the program code for *correctness*.
If the it does not detect any errors, then the syntax of the program is correct,
otherwise it may detect different types of errors.

### Syntax Errors

These errors occurs when the rules of the programming language are not followed,
or when a grammatical rule of C++ is violated. Syntax rules refer to the set of rules,
that governs the construction of valid statements in a programming language.

The following code contains some typical syntax errors:

```c++
int main(void) {
  integer x = 25;   // The correct type is int and not integer
  std::cout "Hello world" ; std::endl;    // The correct separator for cout is << and not ;
  return 0,     // Should be terminated by ;
}
```

The compiler will give errors similar to `error: 'integer' was not declared in this scope`,
`error: statement cannot resolve address of overloaded function` and
`error: expected ';' before '}' token`.

### Semantics Errors

Semantic errors occur when statements are not meaningful.
For example, "Dog eats food" is syntactically (syntax rules of English Grammar)
and semantically (semantic rules of English grammar) correct as it has some meaning.
But "Food eats Dog", is syntactically correct but semantically wrong.

In other words, semantics refers to the set of rules which give meaning to a statement.

A typical example is when you assign a left-hand statement to a right-hand statement:

```c++
int main(void) {
  int x = 25;
  int y = 30;
  (x / y) + 11 = x;
  return 0;
}
```

The compiler will give an error similar to `error: lvalue required as left operand of assignment`.

### Type Errors

C++ has associated data types for all primitive types of data
(of course this can be extended with the types we create through classes and those included with external libraries).

For storing whole numbers, C++ has integer data type, For character and string – char and string data type, For fractional data float and double data type is provided.
So a type error is signaled by the compiler if a value of a wrong or unexpected type is passed or assigned.

```c++
int main(void) {
    return "All went well";           // Returning string instead of int
}
```

The compiler will give an error similar to `error: invalid conversion from 'const char*' to 'int' [-fpermissive]`.

### Runtime Errors

A runtime error is a program error that occurs while the program is running.

There are many different types of runtime errors. One example is a **logic error**, which produces the wrong output. For example, a miscalculation in the source code. Another type of runtime error is a **memory leak**. This type of error causes a program to continually use up more RAM while the program is running. A memory leak may be due to an infinite loop, not deallocating unused memory, or other reasons.

A program crash is the most noticeable type of runtime error, since the program unexpectedly quits while running. Crashes can be caused by memory leaks or other programming errors. Common examples include dividing by zero, referencing missing files, calling invalid functions, or not handling certain input correctly.

NOTE: Runtime errors are commonly called referred to as **bugs** and are often found during the debugging process, before the software is released. When runtime errors are found after a program has been distributed to the public, developers often release patches, or small updates, designed fix the errors.

## Handling runtime errors

Some runtime errors can be caught while a program is executing.

Take for example a division-by-zero error; this can often be caught by checking the operands for valid values. If they are invalid the code can handle this case by throwing an error to the user, by skipping the calculation for that set of values, ...

In the old days of C, many functions would return an integer or a boolean indicating of the function was able to perform its action or an error occurred (the main function is an example of this). This would lead to a list of error codes (just integral values) that were a hell to debug and were ever worse for the user of the application as they would often get a message like "Could not complete action, error 54788 occurred".

The more modern way of handling errors is by using exceptions. If your application detects an erroneous condition and cannot handle it at that particular place in the code, you throw an exception and allow the calling code to handle the error or throw the exception again.

## Exceptions

An exception is a problem that arises during the execution of a program. A C++ exception is a response to an exceptional circumstance that arises while a program is running, such as an attempt to divide by zero.

Exceptions provide a way to transfer control from one part of a program to another. C++ exception handling is built upon three keywords: try, catch, and throw.

* `try`: A try block identifies a block of code for which particular exceptions will be activated. It's followed by one or more catch blocks.
* `catch`: A program catches an exception with an exception handler at the place in a program where you want to handle the problem. The catch keyword indicates the catching of an exception.
* `throw`: A program throws an exception when a problem shows up. This is done using a throw keyword.

Assuming a block will raise an exception, a method catches an exception using a combination of the try and catch keywords. A try/catch block is placed around the code that might generate an exception. Code within a try/catch block is referred to as protected code, and the syntax for using try/catch looks like the following:

```c++
try {
  // Code that can thrown an exception
} catch(const <type_of_exception>& <name>) {
   // Handle the exception
} catch(const <type_of_exception>& <name>) {
   // Handle the exception
} catch(const <type_of_exception>& <name>) {
   // Handle the exception
}
```

You can list down multiple catch statements to catch different type of exceptions in case your try block raises more than one exception in different situations.

### C++ Standard Exceptions

C++ provides a list of standard exceptions defined in <exception> which we can use in our programs. These are arranged in a parent-child class hierarchy shown below:

![C++ standard Exceptions](https://www.tutorialspoint.com/cplusplus/images/cpp_exceptions.jpg)

Here is the small description of each exception mentioned in the above hierarchy:

| Exception	| Description |
| ---------- | --------- |
| std::exception |	An exception and parent class of all the standard C++ exceptions. |
| std::bad_alloc |	This can be thrown by new. |
| std::bad_cast |	This can be thrown by dynamic_cast. |
| std::bad_exception |	This is useful device to handle unexpected exceptions in a C++ program |
| std::bad_typeid |	This can be thrown by typeid. |
| std::logic_error |	An exception that theoretically can be detected by reading the code. |
| std::domain_error |	This is an exception thrown when a mathematically invalid domain is used |
| std::invalid_argument |	This is thrown due to invalid arguments. |
| std::length_error |	This is thrown when a too big std::string is created |
| std::out_of_range |	This can be thrown by the at method from for example a std::vector and std::bitset<>::operator[](). |
| std::runtime_error |	An exception that theoretically can not be detected by reading the code. |
| std::overflow_error |	This is thrown if a mathematical overflow occurs. |
| std::range_error |	This is occured when you try to store a value which is out of range. |
| std::underflow_error |	This is thrown if a mathematical underflow occurs. |

### Catching possible exceptions

Let's take a look at a simple example where we index inside a string outside of its size.

[include](code/catching_exceptions/main.cpp)

<!-- http://stackoverflow.com/questions/12833241/difference-between-c03-throw-specifier-c11-noexcept/12833405#12833405 -->
<!-- When entering a catch clause, if its formal parameter is a base class of the exception type, it is copy-initialized from the base class subobject of the exception object. Otherwise, it is copy-initialized from the exception object (this copy is subject to copy elision). -->

Note how the catch statement takes the exception passed as a reference (`const exception& e` instead of `const exception e`).
This is a good practice as otherwise you do an implicit copy which can potentially result in an exception throw.

<!-- It also breaks the polymorphism: if you want to catch pure virtual interface implementation instance, you would need to use a reference. -->

## Custom exceptions

[include](code/custom_exceptions/main.cpp)

[include](code/custom_exceptions/include/cannot_divide_by_zero_exception.h)

The C++ Standard library provides a base class specifically designed to declare objects to be thrown as exceptions.
It is called `std::exception` and is defined in the `<exception>` header.
This class has a virtual member function called `what()` that returns a null-terminated character sequence (of type `char *`)
and that can be overwritten in derived classes to contain some sort of description of the exception.

## Catching all exceptions

The catch-all clause `catch (...)` matches exceptions of any type. If present, it has to be the last catch clause.

A catch-all block may be used to ensure that no uncaught exceptions can possibly escape.
<!-- from a function that offers nothrow exception guarantee -->


<!-- Why there is no finally ?
http://stackoverflow.com/questions/161177/does-c-support-finally-blocks-and-whats-this-raii-i-keep-hearing-about -->
