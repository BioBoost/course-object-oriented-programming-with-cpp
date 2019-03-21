## Chapter 04 - Basics of Classes - Challenges

### Die Throwing (continued)

Take the "Die Throwing" application from the challenges of chapter 3.

Refactor the code to make use of a class `Die`. Make sure to add a `roll()` method to your class.

If you change the number of sides on your die from `6` to `20`. Do you need to change your implementation of `Die`? If so, refactor the class to be independent of the lower and upper limit. You should even be able to create a `Die` that can generate values from `10` to `16` for example.

### Prime Checker

Below is some code that needs a serious refactor. Refactor the code to make use of a class `PrimeChecker`. Also refactor the code formatting.

```c++
#include <iostream>
using namespace std;

int is_p  (unsigned int v)

{
  bool prime = true;
  unsigned int div = 2;

  while (prime && div <= v/2) {
    int rem = v % div;
    if (rem == 0) {
      prime = prime && false;
    } else {
      prime = prime && true;
    }
    div = div + 1;
  }

  if (prime == true) return true;
  else return false;
}

int
main()
{
  int number;

  cout << "Enter a positive integer: ";     cin >> number;

  if(is_p(number) == true)
    cout << number << " is a prime number.";
  else if (is_p(number) == false)
    cout << number << " is not a prime number.";

  return 0;

}
```