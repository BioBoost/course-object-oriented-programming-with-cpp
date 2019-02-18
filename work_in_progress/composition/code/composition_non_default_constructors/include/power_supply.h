#pragma once

class PowerSupply
{
    private:
        double inputVoltage;
        double outputVoltage;

    public:
        PowerSupply(double inputVoltage, double outputVoltage);
};
