// Include std c++ library
#include <iostream>

////////////////////////////////////////////////////////////////////
////////// Note: used example with namespace. Maybe we should
////////// put the same example in the course. Explains what 
////////// needs to be put inside of namespace
////////////////////////////////////////////////////////////////////

// Include own library
// #include "robot.h"

// Open std namespace for usage
using namespace std;

// Prototypes
namespace MyMath {
  int sum(int left, int right);
};

// Entry point
int main() {

  // Console output
  cout << "Hello World " << 15 << endl;

  std::cout << "Bye Bye" << std::endl;

  // Variables
  int number = 15;
  int notInitialized;

  cout << "Not initialized: " << notInitialized << endl;

  char x = 'x';
  char k = '\n';    // Escape char newline

  double radius = 3.5566;

  // Constants
  const int SIZE = 32;
  #define STUDENTS 42

  // Math
  int sum = 0;
  int a = 1;
  int b = 2;

  sum = a + b;
  
  // Integer devision
  int quotient = a / b;   // 0
  double result = a / b;  // 0.0

  // Real division
  double realDevision = (double)a / b;
  double anotherRealDevision = a / (b * 1.0);

  cout << "Real division: " << anotherRealDevision << endl;

  // Compound operators
  int p = 0;
  p += 4;   // Compound, same as p = p + 4
  p %= 2;   // % = modulo operator (remainder - rest bij deling)

  int i = 5;
  int y = 3;

  i++;    
  ++i;
  // i = 7

  y = i++;    // y = 7, i = 8
  cout << "y: " << y << endl;

  y = ++i;    // y = 9, i = 9
  cout << "y: " << y << endl;

  // Comparison
  bool isTrue = true;
  bool isFalse = false;

  cout << "true? " << isTrue << endl;

  if (15) {
    cout << "15 is actually true" << endl;
  }

  if (15 <= 32 && 46 > 27) {
    cout << "life is good" << endl;
  } else {
    cout << "Something is wrong" << endl;
  }

  int age = 16;
  if (age < 18) {
    cout << "Underage" << endl;
  } else if (age <= 75) {
    cout << "Adult" << endl;
  } else {
    cout << "Sorry, no grandpa's" << endl;
  }

  int dayOfWeek = 1;

  if (dayOfWeek == 1) {
    cout << "Monday" << endl;
  } else if (dayOfWeek == 2) {
    cout << "Tuesday" << endl;
  } // ...
  else {
    int bye = 15;
    cout << "Not a valid day" << endl;
  }

  switch(dayOfWeek) {
    case 1: {
      cout << "Monday" << endl;
      break;
    }
    case 2:
      cout << "Tuesday" << endl;
      break;
    // ...
    default:
      cout << "Not a valid day" << endl;
  }

  // Looping
  for (int i = 0; i < 10; i+=3) {
    cout << "i = " << i << endl;
  }

  // for (;;) {
  //   // Endless loop
  // }

  // // Endless loop
  // while(true) {

  // }

  // bool keepRunning = true;
  // while(keepRunning) {
  //   // ..
  // }

  int d = 0;
  do {
    d += 2;
    cout << "d = " << d << endl;
  } while (d < 0);

  cout << " The sum = " << MyMath::sum(4, 12) << endl;

  // Arrays
  const int SIZE_OF_ARRAY = 10;

  int numbers[SIZE_OF_ARRAY] = {};    // All zeros

  for (int i = 0; i < SIZE_OF_ARRAY; i++) {
    numbers[i] = i * i;
    cout << numbers[i] << endl;
  }

  // Does numbers contain 12?
  // i = 0;
  // while(i < SIZE_OF_ARRAY && numbers[i] != 12) {
  //   i++;
  //   // cout << "Not 12" << endl;
  // }

  // Same
  i = 0;
  while(i < SIZE_OF_ARRAY && numbers[i++] != 12);

  if (numbers[i] == 12) {
    cout << "Found 12" << endl;
  }

  int primes[] = { 1, 2, 3, 5, 7 };

  int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
  };

  // Arrays => lazy eval
  // Arrays i++ and ++i

 
  return 0;   // Status code
}


// namespace MyMath {

//   int sum(int left, int right) {
//     return left + right;
//   }

// };

int MyMath::sum(int left, int right) {
  return left + right;
}