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

### Order

**Difficulty:** Low

Implement the `order()` function so it swaps the `a` and `b` if `a` is bigger then `b`. In other words the function will always return with `a` the smallest value and `b` the largest.

```c++
#include <iostream>

using namespace std;

void order(int * a, int * b) {
  if (*a > *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
}

int main() {
  int valueA = 12;
  int valueB = 8;

  order(&valueA, &valueB);
  cout << valueA << " is the smallest while "
    << valueB << " is the largest" << endl;

  return 0;
}
```

### Largest and Smallest

**Difficulty:** Medium

The function `find_range()` determined the smallest and largest values inside the array (assuming) no duplicate values are allowed inside the array.

```c++
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void find_range(int * array, unsigned int size,
  int * minimum, int * maximum) {

  for (unsigned int i = 0; i < size; i++) {
    if (i == 0) {
      *minimum = *maximum = array[i];
    }
    if (*minimum > array[i]) {
      *minimum = array[i];
    }
    if (array[i] > *maximum) {
      *maximum = array[i];
    }
  }
}

int main() {
  // The array
  int values[] = {4, 32, 3, -23, 0, 11, 34, 2};
  int minimum;
  int maximum;
  find_range(values, sizeof(values)/sizeof(int), &minimum, &maximum);

  cout << "The minimum is " << minimum << endl;
  cout << "The maximum is " << maximum << endl;

  return 0;
}
```

### Randomize

**Difficulty:** High

Below is a function that takes an array as its argument. It fills the array with random values. It also returns the minimum and maximum value that it put inside the array via pointers. Complete the implementation.

```c++
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fill_with_random(int * array, unsigned int size,
  int * minimum, int * maximum) {

  // Needs implementation
}

int main() {
  // Init random seed
  srand (time(NULL));

  // The array
  int values[10];
  int minimum;
  int maximum;
  fill_with_random(values, 10, &minimum, &maximum);

  for (auto const& value : values) {
    cout << value << " ";
  }
  cout << endl;
  cout << "The minimum is " << minimum << endl;
  cout << "The maximum is " << maximum << endl;

  return 0;
}
```