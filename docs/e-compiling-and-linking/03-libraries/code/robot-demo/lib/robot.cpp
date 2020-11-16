#include "robot.h"

Robot::Robot(std::string name) {
  this->name = name;
}

std::string Robot::to_string(void) {
  return "Robot is called " + name;
}
