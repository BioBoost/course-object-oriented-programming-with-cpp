// Compile using:
// g++ main.cpp point.cpp -o points

#include <iostream>
#include "point.h"

using namespace std;

int main() {
  cout << "Point demo" << endl;

  Geometry::Point center;

  center.move_to(12.5, 23);

  cout << "The point is now at ["
    << center.get_x() << ", " << center.get_y()
    << "]" << endl;

  return 0;
}