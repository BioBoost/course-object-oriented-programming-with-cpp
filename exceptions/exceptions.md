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
