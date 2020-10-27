#include <iostream>
#include "line_segment.h"

using namespace std;

int main() {
  cout << "Line Segment demo" << endl;

  Geometry::Point start(7, 11);
  Geometry::Point end(-1, 5);

  Geometry::LineSegment line0;
  cout << "Line 0 has a length of " << line0.length() << endl;

  Geometry::LineSegment line1(start, end);
  cout << "Line 1 has a length of " << line1.length() << endl;

  Geometry::LineSegment line2(1, 3, -2, 9);
  cout << "Line 2 has a length of " << line2.length() << endl;

  return 0;
}