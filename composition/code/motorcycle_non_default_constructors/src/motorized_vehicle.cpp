#include "motorized_vehicle.h"
#include <iostream>

MotorizedVehicle::MotorizedVehicle(std::string name, int numberOfCilinders)
    : TransportationDevice(name), motor(numberOfCilinders) {

   std::cout << "Constructing MotorizedVehicle" << std::endl;
}
