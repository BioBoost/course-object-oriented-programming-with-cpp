## Solutions to Exercises

### Adding Data - Attributes

#### Modeling a dog

```c++
// dog.h
#pragma once

#include <string>

class Dog {
  private:
    unsigned int age;
    std::string color;
    std::string breed;
    std::string name;
    double weight;
};
```

Remarks:
* Note the `#pragma once` directive
* The `string` library needs to be included since some of the attributes are of type `string`.
* The name of class starts with a capital
* Don't forget the termination character after the closing curly brace `}`
