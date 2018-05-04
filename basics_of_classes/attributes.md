## Adding Data - Attributes

**Attributes** or **class instance variables** are the ways to **store data inside an object** of that particular class.

Defining attributes is very similar to creating a variable inside a method or function. Let's add red, green and blue components to the `RgbLed` class.

```c++
#pragma once

class RgbLed {
  // Attributes
  private:
    int red;
    int green;
    int blue;
};
```

Notice that an **access modifier** (such as `private`, `public` and `protected`), followed by a colon `:`, can be specified for all the attributes/methods that follow it. Default access in C++ classes is *private*. This means that not specifying anything would have had the same effect in the previous example. However it is always safer to explicitly declare the attributes as private as it may lead to leaks when adding public things before the attributes.

**Data hiding** is an important feature of OOP. It allows developers to prevent direct access to internal representation of a class. In other words access to class members can be restricted making only the available those that are needed by the user of the class. This is facilitated by the access modifiers.

C++ has the following definitions for the access modifiers inside a class definition:
* `public`: A public member is accessible from anywhere outside the class. Attributes should almost never be made public, to prevent direct access from outside the class. Methods such as getters, setters, constructors and such are often made public as they need to be accessible.
* `private`: A private member cannot be accessed (not even read - in case of an attribute) from outside the class. Only the class and friend functions/methods can access private members. Not even an inherited class can access it's parent private attribute/methods.
* `protected`: A protected attribute or method is very similar to a private member but it provided one additional benefit - that is that they can be accessed in child classes (aka derived classes).

A class can have multiple `public`, `protected`, or `private` access modifiers. Each modifier remains in effect until either another modifier or the closing brace of the class body is seen. The default access for members and classes is `private`.

Analyze the example below. The comments show what access is granted to each section.

```c++
class Foo {
  //... default is private here

  protected:
    //... all protected here

  private:
    //... all private here

  public:
    //... all public here

  protected:
    //... all protected here

  public:
    //... again public
};
```
