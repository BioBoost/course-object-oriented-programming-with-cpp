#pragma once

#include "transportation_device.h"
#include "motor.h"

class MotorizedVehicle : public TransportationDevice {
    private:
        Motor motor;

    public:
        MotorizedVehicle(std::string name, int numberOfCilinders);
};
