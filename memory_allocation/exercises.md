# Exercises

## A Dynamic ArrayList

Create a class `ArrayList` that manages a dynamically allocated array of integers.

Provide three constructors:
* a default one that creates an empty list
* one that takes a size and creates a list of zeroed elements of the given size
* one that copies an array of integers

Add the following methods:
* `add(int value)` to add an element to the back of the list
* `void replace(int value, int index)` to replace an existing element
* `std::string to_string(void)` to create a string representation of the list

Make sure to implement the destructor to free the dynamic memory once an object of the `ArrayList` is destroyed.