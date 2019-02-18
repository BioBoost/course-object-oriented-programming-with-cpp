#include "motor.h"
#include <iostream>

Motor::Motor(int numberOfCilinders){
    this->numberOfCilinders = numberOfCilinders;
    std::cout << "Constructing Motor with " << numberOfCilinders;
    std::cout << " cilinders" << std::endl;
}
