## Chapter 08 - Dynamic Memory Allocation - Exercises

### Star String Creator

**Difficulty:** High

Complete the code below so the `create_stars` method returns a dynamically allocated `char` array (allocated in the `create_stars` method) of the given size filled with stars `*`. Make sure that the array is actually 1 character bigger than requested which is filled with the termination character `\0` as a last character. This will turn the `char` array in a *null-terminated C string*.

**star_creator.h**:

```c++
// star_creator.h
#pragma once

class StarCreator {
  public:
    char * create_stars(unsigned int size);
};
```

**star_creator.cpp**:

```c++
// star_creator.cpp
#include "star_creator.h"

char * StarCreator::create_stars(unsigned int size) {
  // Needs implementation
}
```

An example application could be:

```c++
#include <iostream>
#include "star_creator.h"

using namespace std;

int main() {
  StarCreator starCreator;
  for (unsigned int i = 0; i < 5; i++) {
    char * stars = starCreator.create_stars(i);
    if (stars) {
      cout << stars << endl;;
      delete[] stars;
    }
  }

  return 0;
}
```