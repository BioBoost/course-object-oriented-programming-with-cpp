#include "television.h"
#include <iostream>

Television::Television(double inputVoltage)
    : power(inputVoltage, 12) {

    std::cout << "Constructing Television"<< std::endl;
}
