#include "gearbox.h"
#include <iostream>

GearBox::GearBox(int numberOfGears){
    this->numberOfGears = numberOfGears;
    std::cout << "Constructing GearBox with ";
    std::cout << numberOfGears << " gears" << std::endl;
}
