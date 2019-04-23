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