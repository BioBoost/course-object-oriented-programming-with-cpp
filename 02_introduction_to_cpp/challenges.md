## Chapter 02 - Introduction to C++

## Displaying variable value

Develop an application that defines a variable of type integer and displays its value. Change the value after displaying it and display the updated value.

## Invoice VAT

Create an application that determines the 21% VAT (BTW) of a given number (floating point). Display both the value with and without VAT like you would see on an invoice. Use a second variable to store the actual VAT value.

Can you change the application so the number is requested from the user. Checkout [http://www.cplusplus.com/doc/tutorial/basic_io/](http://www.cplusplus.com/doc/tutorial/basic_io/) for more info on input and input to STDOUT and from STDIN.

## Generating random numbers

Checkout the following code: [http://www.dreamincode.net/forums/topic/14057-producing-random-numbers/](http://www.dreamincode.net/forums/topic/14057-producing-random-numbers/)

Is uses some functions and libraries to generate random numbers.

Now change the code to print out 10 random numbers while calculating the sum and average of the randomly generated numbers.

Use a for-loop construct for this (see chapter C++ Language Constructs).

## Side effects

Can you guess the output of the following construct:

```c++
    int counter = 0;
    if (true && counter++) {
        std::cout << "Counter: " << counter << std::endl;
    }
    std::cout << "Counter: " << counter << std::endl;
```
