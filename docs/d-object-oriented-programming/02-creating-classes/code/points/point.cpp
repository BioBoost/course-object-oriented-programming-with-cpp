// point.cpp
#include "point.h"

namespace Geometry {

  void Point::move_to(double x, double y) {
    this->x = x;
    this->y = y;
  }
  
  void Point::move_by(double deltaX, double deltaY) {
    this->x += deltaX;
    this->y += deltaY;
  }

  double Point::get_x(void) const {
    return x;
  }

  double Point::get_y(void) const {
    return y;
  }

};