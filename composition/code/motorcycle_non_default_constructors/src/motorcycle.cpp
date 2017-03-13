#include "motorcycle.h"
#include <iostream>

Motorcycle::Motorcycle(std::string name, int numberOfCilinders, int numberOfGears)
    : MotorizedVehicle(name, numberOfCilinders), gearbox(numberOfGears) {

   std::cout << "Constructing Motorcycle" << std::endl;
}
