# Chapter 10 - Exceptions

*This chapter is in early draft. Bit more of a slide deck*.

Exceptions are used to indicate exceptional situations that may fail the application.

## Return Codes

Returning negative values from a function/method is a common way of indicating an error has occurred.

```c++
int index_of_first_char(std::string text, char c) {
  for (unsigned int i = 0; i < text.length(); i++) {
    if (text[i] == c) {
      return i;
    }
  }
  return -1;    // Indicate not found
}
```

Same strategy as the return code of the applications itself (status code returned to operating system).

Advantages of this approach:

* Simple and low overhead

Disadvantages of this approach:

* Error codes are not always clear, often cryptic.
* Distinction between error code and valid value is not always clear.
* Functions can only return a single value.
* Hard/Messy to pass error codes upward if it cannot be handled.
* Often leads to nasty error handling code.
* This approach does not integrate well with constructors (do not return values).
* Error handling code is mixed with normal control flow of code.

Example in pseudocode:

```text
int read_file(filename, lines) {
  if (file_does_not_exist) {
    return -1;
  } elseif (could_not_readfile) {
    return -2;
  } elseif (file_empty) {
    return -3;
  } elseif (not_ascii_text) {
    return -4;
  } elseif (files_to_large) {
    return -5;
  } else {
    read into lines
    return number_of_lines
  }
  return -255;  // Unknown error occurred
}
```

Exceptions provide a mechanism to decouple error code from normal control flow of your application. They also provide a way to handle the errors when most appropriate (cfr. call stack).

## What are Exceptions

Exceptions (exceptional events) are problems that occur during the execution of an application, which disrupt the normal flow of the application's code. If the exception is not handled by the application code itself, the process terminates abnormally.

An exception can occur on many different occasions. Some common reasons are:

* A user has entered invalid data.
* A file that needs to be opened cannot be found.
* A network connection has been lost in the middle of communications.
* A number is being divided by zero.

Some of these exceptions are caused by user error, others by programmer error, and others by physical resources that have failed in some manner.

## Throwing an Exceptions

Throwing an exception is like giving the system a signal something abnormal has happened. This is also called **raising an exception**.

Achieved using the `throw` statement in C++.

In C++ almost anything can be thrown:

* an integer value (similar to the previous return codes).
* an enum value (internally also integral value but leads to more understandable code)
* a C-style character string
* an object of any class, often custom exception classes

Preferable the exception that was thrown should provide more info on the situation that has occurred.

Some examples:

```c++
throw -1;
throw "Cannot create new file";
throw std::string("Failed to open connection");
throw FileNotFoundException(filename);
```

## Catching and Handling Exceptions

When executing code that may throw an exception, it will need to be put inside a `try` block.

A try-block acts as an observer for the code inside of it and will look for exceptions being thrown.

To specify what to do in case of certain exceptions, a try-block is followed by one or multiple catch-blocks.

Example:

```c++
try {
  throw std::string("This will crash");
  // Comment out the above line
  // and uncomment the one below
  // throw -3;
} catch (const std::string &message) {
  std::cout << "Something went wrong" << std::endl;
} catch (int errorcode) {
  std::cout << "Failed with error code " << errorcode << std::endl;
}
```

The try-block will route the exception to the correct catch block, based on the type of the value that was thrown.