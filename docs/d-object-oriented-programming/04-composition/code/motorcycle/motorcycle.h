// motorcycle.h
#pragma once

#include <iostream>
#include "motor.h"
#include "gearbox.h"
#include "battery.h"

class Motorcycle {
  public:
    Motorcycle(void) {
      std::cout << "Constructing Motorcycle" << std::endl;
    }

  private:
    Motor motor;
    GearBox gearbox;
    Battery battery;
};