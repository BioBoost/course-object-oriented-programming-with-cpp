#pragma once

#include "power_supply.h"

class Television
{
    private:
        PowerSupply power;

    public:
        Television(double inputVoltage);
};
