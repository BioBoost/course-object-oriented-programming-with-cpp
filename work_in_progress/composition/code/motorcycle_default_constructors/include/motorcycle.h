#pragma once

#include "motorized_vehicle.h"
#include "wheel.h"
#include "gearbox.h"
#include "battery.h"

class Motorcycle : public MotorizedVehicle {

    private:
        Wheel front;
        Wheel back;
        GearBox gearbox;
        Battery battery;

    public:
        Motorcycle(void);
};
