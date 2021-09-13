// television.cpp
#include "television.h"
#include <iostream>

Television::Television(double inputVoltage)
    : embeddedPower(inputVoltage, 3.3), display(inputVoltage, 12) {
    // Notice how we call the correct constructor
    // using the initialization list.
    // Multiple calls can be comma-separated

    std::cout << "Constructing Television"<< std::endl;
}