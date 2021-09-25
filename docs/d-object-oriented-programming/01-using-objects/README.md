---
description: needs to be done
---

# Using Objects

*Warning! This chapter is in a very early draft state!*

Before we can *use* objects we need to create them based on a class. The standard library has some classes that we can instantiate in our applications.

## Creating Objects

One of the most used classes from the std library is the `string` class.

Let us create an instance of the `string` class.

```cpp
// Creating an object with a default constructor
std::string empty;

// Creating an object with an initialization constructor
std::string hello("Hello from C++");
```

Note the difference between object instantiation with a default constructor and instantiation with an initialization constructor.

In C++ we do not add parentheses `()` when using the default constructor. If you do, C++ thinks you are calling a function.

::: warning string vs String
Note that normally we will define class names using capital letters. This is a common practice in object oriented programming. Too bad C++ did not follow this convention. This results in std classes that start with lower case letters
:::

The `string` class is a bit special as it also allows you to create a string object using the following syntax:

```cpp
std::string myName = "Nico De Witte";
```

## Calling Methods

Once an object is created, one can start calling methods on the object using the `.` operator.

Let's take a look at an example where we call the `length()` method on an `std::string` object.

```cpp
std::string hello("Hello from C++");

cout << "Length of \"" << hello
  << "\" is " << hello.length() << endl;
```

::: output
<pre>
Length of "Hello from C++" is 14
</pre>
:::

The `std::string` class defines a lot of useful methods we can call on `std::string` objects. Make sure to take a look at them at [https::/cplusplus.com/reference/string/string](https::/cplusplus.com/reference/string/string).

### Passing Arguments

Some methods will require you to pass external information to the method so it can do its work.

Passing data to the method is achieved by passing a comma separated list of arguments.

Let's take the `find()` method of `std::string` as an example. It searches the string for a given substring:

```cpp
std::string text = "Hello from the cool world of C++";
std::string cool = "cool";

std::size_t positionCool = text.find(cool);
if (positionCool != std::string::npos) {
  cout << "Found \"" << cool << "\" at position " << positionCool << endl;
} else {
  cout << "Could not find \"" << cool << "\"" << endl;
}
```

As a second argument we an also supply the index of where to start searching from in the string.

```cpp
std::string text = "Hello from the cool world of C++";
std::string cool = "cool";

std::size_t positionCool = text.find(cool, 20);
if (positionCool != std::string::npos) {
  cout << "Found \"" << cool << "\" at position " << positionCool << endl;
} else {
  cout << "Could not find \"" << cool << "\"" << endl;
}
```

::: output
<pre>
Could not find "cool"
</pre>
:::
