// Compile using:
// g++ main.cpp point.cpp -o points

#include <iostream>
#include "point.h"

using namespace std;

int main() {
  cout << "Point demo" << endl;

  Geometry::Point center(8, 77);

  cout << "The point is at ["
    << center.get_x() << ", " << center.get_y()
    << "]" << endl;

  return 0;
}