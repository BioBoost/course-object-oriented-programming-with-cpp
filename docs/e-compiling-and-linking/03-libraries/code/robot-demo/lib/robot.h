#pragma once

#include <string>

class Robot {
  public:
    Robot(std::string name);

  public:
    std::string to_string(void);

  private:
    std::string name;
};