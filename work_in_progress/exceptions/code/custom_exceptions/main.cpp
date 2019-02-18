#include <iostream>
#include "cannot_divide_by_zero_exception.h"

using namespace std;

int divide(int divident, int divisor) {
    if (divisor == 0) {
        throw CustomExceptions::CannotDivideByZeroException();
    }
    return divident / divisor;
}

int main()
{
    try {
        int x = divide(12, 0);
    }
    catch (const CustomExceptions::CannotDivideByZeroException& cdbze) {
        cout << cdbze.what();
    }

    return 0;
}
