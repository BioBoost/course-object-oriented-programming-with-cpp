## Chapter 02 - Introduction to C++ - Challenges

### Displaying variable value

Develop an application that defines a variable of type integer and displays its value. Change the value after displaying it and display the updated value.

### Invoice VAT

Create an application that determines the 21% VAT (BTW) of a given number (floating point). Display both the value with and without VAT like you would see on an invoice. Use a second variable to store the actual VAT value.

Can you change the application so the number is requested from the user. Checkout [http://www.cplusplus.com/doc/tutorial/basic_io/](http://www.cplusplus.com/doc/tutorial/basic_io/) for more info on input and input to STDOUT and from STDIN.

### Side effects

Can you guess the output of the following construct:

```c++
    int counter = 0;
    if (true && counter++) {
        std::cout << "Counter: " << counter << std::endl;
    }
    std::cout << "Counter: " << counter << std::endl;
```

### Roots of a Quadratic Equation

The code below should determine the roots of a quadratic equation. However there are some syntax errors and maybe even a bug in the code. Fix the code so its compiles and works correctly. Also make sure that the output is consistent.

```c++
#include <iostream>
#include <cmath>

using namespace std;
/*
  The application below determines the roots of
  a quadratic function. Just fill in the 3 coefficients.
/
int main() {
    double a, b, c;

    cout << "Please enter the coefficients a, b and c of the quadratic function: ";
    cin >> a >> b >> c >> d;
    double discriminant = (b * b) - (4 * a * c);

    if (abs(discriminant) <= 0.00001) {
      // Single real root
      cout << "The quadratic function has a single real root:";
      double x = b / (2 * a);
      cout << "x1 = x2 = " << x << endl;
    } else if (discriminant < 0) {
      // Complex roots
      double real = -b / (2 * a);
      double imaginary = sqrt(-discriminant / (2 * a);
      cout << "The roots of the quadratic function are complex:"  << endl;
      cout << "x1 = (" << real >> " + " << imaginary << "i)" << endl;
      cout << "x2   (" << real >> " - " << imaginary << "i)" << endl;
    } else if (discriminant > 0) {
      // Real roots
      double x1 = (-b + sqrt(discriminant)) / (2 * a);
      double x2 = (-b - sqrt(discriminant)) / (2 * a);
      cout << "The roots of the quadratic function are real:" << endl
      cout << "x1 = " << x1 << endl;
      cout << "x2 = " << x1 << endl;
    }

    return 0;
}
```
