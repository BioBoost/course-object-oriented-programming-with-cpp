## Chapter 03 - Arrays - Challenges

### Sum of all integers

Implement the necessary code in the function `make_sum()` so it returns the sum of all the elements inside `list`.

```c++
#include <iostream>

using namespace std;

int make_sum(int values[], unsigned int length) {
  // Return sum of all values

}

int main(int argc, char * argv[]) {

  int values[] = {4, 54, 23, 33, 0, 11, -123};
  cout << "Sum of all values = " << make_sum(values, sizeof(values)) << endl;

  return 0;
}
```

### Die Throwing

Create an application that throws a 6 sided die 100'000 times. Keep count of how many times each side is thrown using a frequency table. Generated the thrown values using the `rand()` function.

Does each value have an equal chance? If so, the random generator is distributed uniformly.