## Chapter 08 - Dynamic Memory Allocation - Challenges

### Joining Arrays

**Difficulty:** Medium

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