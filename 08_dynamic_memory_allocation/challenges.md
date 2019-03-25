## Chapter 08 - Dynamic Memory Allocation - Challenges

### Joining Arrays

Complete the implementation so the `join_arrays` method returns a new array where the `first` and `second` array are joined together in a single array.

```c++
#include <iostream>

using namespace std;

int * join_arrays(int * first, unsigned int lengthOfFirst,
    int * second, unsigned int lengthOfSecond) {

  // Needs implementation

}

int main() {

  int firstArray[] = {1, 2, 3, 4, 5};
  int secondArray[] = {-11, -22, -33, -44, -55, -66, -77};

  int * joined = join_arrays(firstArray, sizeof(firstArray)/sizeof(int),
    secondArray, sizeof(secondArray)/sizeof(int));

  unsigned int joinedLength = sizeof(firstArray)/sizeof(int) + sizeof(secondArray)/sizeof(int);

  for (unsigned int i = 0; i < joinedLength; i++) {
    cout << joined[i] << " ";
  }

  return 0;
}
```

### Star String Creator

**Difficulty:** High

Complete the code below so the `create_stars` method returns a dynamically allocated `char` array of the given size filled with stars `*`. Make sure that the array is actually 1 character bigger than requested which is filled with the termination character `\0` as a last character. This will turn the `char` array in a *null-terminated C string*.

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
  char * stars = new char[size+1];
  if (stars) {
    for (unsigned int i = 0; i < size; i++) {
      stars[i] = '*';
    }
    stars[size] = '\0';
  }
  return stars;
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
