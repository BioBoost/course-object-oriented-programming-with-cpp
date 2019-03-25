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