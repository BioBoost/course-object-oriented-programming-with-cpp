# Demos

```cpp
#include <iostream>
#include <climits>

using namespace std;


int main() {
  cout << "Welcome to pointers" << endl;

  int integers[5];
  cout << "Integers:" << endl;
  cout << "#bytes for int: " << sizeof(int) << " bytes" << endl;
  cout << "max int value = " << INT_MAX << " = 2^31 - 1" << endl;
  for (int i = 0; i < sizeof(integers)/sizeof(int); i++) {
    cout << &integers[i] << endl;
  }

  long longs[5];
  cout << endl << "Longs:" << endl;
  cout << "#bytes for long: " << sizeof(long) << " bytes" << endl;
  cout << "max long value = " << LONG_MAX << " = 2^63 - 1" << endl;
  for (int i = 0; i < sizeof(longs)/sizeof(long); i++) {
    cout << &longs[i] << endl;
  }

  char chars[5] = { 0 };
  cout << endl << "Chars:" << endl;
  cout << "#bytes for char: " << sizeof(char) << " bytes" << endl;
  cout << "max char value = " << CHAR_MAX << " = 2^7 - 1" << endl;
  for (int i = 0; i < sizeof(chars)/sizeof(char); i++) {
    cout << (void*)&chars[i] << endl;
    // Need to cast to void pointer. << operator is overloaded for c-string
  }

  // Try with 32-bit: g++ main.cpp  -m32 -o pointers && ./pointers
  cout << endl << "Size of pointers is " << sizeof(int*) * 8 << " bits" << endl;

  int someNumber = 0xAABBCCDD;

  for (int i = 0; i < sizeof(int); i++) {
    cout << std::hex << ((someNumber >> 8*i) & 0xFF) << endl;
  }

  // Same
  cout << endl << "Or another approach:" << endl;
  char * bytesOfSomeNumber = (char*)&someNumber;
  for (int i = 0; i < sizeof(int); i++) {
    cout << std::hex << (bytesOfSomeNumber[i] & 0xFF) << endl;
  }

  return 0;
}

// Why are int's not 64 bit?

// Seriously, according to the standard, "Plain ints have the natural size suggested by the architecture of the execution environment", which does mean a 64 bit int on a 64 bit machine. One could easily argue that anything else is non-conformant. But in practice, the issues are more complex: switching from 32 bit int to 64 bit int would not allow most programs to handle large data sets or whatever (unlike the switch from 16 bits to 32); most programs are probably constrained by other considerations. And it would increase the size of the data sets, and thus reduce locality and slow the program down.

// Finally (and probably most importantly), if int were 64 bits, short would have to be either 16 bits or 32 bits, and you'ld have no way of specifying the other (except with the typedefs in <stdint.h>, and the intent is that these should only be used in very exceptional circumstances). I suspect that this was the major motivation.
```
