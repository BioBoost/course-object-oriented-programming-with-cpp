#include "power_supply.h"
#include <iostream>

PowerSupply::PowerSupply(double inputVoltage, double outputVoltage) {
    this->inputVoltage = inputVoltage;
    this->outputVoltage = outputVoltage;

    std::cout << "Constructing PowerSupply: Input = " << this->inputVoltage;
    std::cout << " Output = " << this->outputVoltage << std::endl;
}
