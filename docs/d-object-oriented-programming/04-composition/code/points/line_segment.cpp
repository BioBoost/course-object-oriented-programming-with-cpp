// line_segment.cpp
#include "line_segment.h"
#include <cmath>    // for sqrt

namespace Geometry {

  LineSegment::LineSegment(void) {
    // No need to do anything. Point's default constructors
    // will automatically be called
  }

  LineSegment::LineSegment(double x1, double y1, double x2, double y2)
    : start(x1, y1), end(x2, y2) {
      // Call specific constructors of the points.

      // We also could of called the move method here but
      // code is cleaner like this
  }

  LineSegment::LineSegment(Point start, Point end) {
    // Calling setters is cleanest here
    set_start(start);
    set_end(end);
  }

  void LineSegment::set_start(Point start) {
    this->start = start;
  }

  void LineSegment::set_end(Point end) {
    this->end = end;
  }

  double LineSegment::length(void) {
    return sqrt(
      (start.get_x() - end.get_x()) * (start.get_x() - end.get_x())
      +
      (start.get_y() - end.get_y()) * (start.get_y() - end.get_y())
    );
  }

};