## Chapter 07 - Pointers - Challenges

### Increment

**Difficulty:** Low

Fix the following piece of code so the `increment` function increments the value of the argument with `1`. You can stop the current application using `CTRL-C`.

```c++
#include <iostream>

using namespace std;

void increment(int value) {
  value++;
}

int main() {

  int counter = 0;
  while(counter < 10) {
    increment(counter);
    cout << counter << " ";
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
