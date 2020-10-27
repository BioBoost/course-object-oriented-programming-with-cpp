// television.h
#pragma once
#include "power_supply.h"

class Television {
  public:
    Television(double inputVoltage);

  private:
    PowerSupply embeddedPower;
    PowerSupply display;
};