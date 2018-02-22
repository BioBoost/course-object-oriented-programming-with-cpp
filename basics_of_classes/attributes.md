## Attributes

Attributes or class instance variables are the ways to store data inside an object of that particular class.

Defining attributes is very similar to creating a variable inside a method or function. Let's add RGB components to the RgbLed class.

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

Notice that an access modifier (such as private, public and protected), followed by a colon `:`, can be specified for all the attributes/methods that follow it. Default access in C++ classes is *private*, so not specifying anything would have had the same effect. However it is always safer to explicitly declare the attributes as private as it may lead to leaks when adding public things before the attributes.

From the moment a different modifier is listed below the current one, the new modifier is applied to all methods/attributes that follow it.

```c++
class Foo {
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
