#include "transportation_device.h"
#include <iostream>

TransportationDevice::TransportationDevice(std::string name){
    this->name = name;
    std::cout << "Constructing TransportationDevice: " << name << std::endl;
}
