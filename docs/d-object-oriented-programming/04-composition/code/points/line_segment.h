// line_segment.h
#pragma once
#include "point.h"

namespace Geometry {

  class LineSegment {
  public:
    LineSegment(void);
    LineSegment(double x1, double y1, double x2, double y2);
    LineSegment(Point start, Point end);

  public:
    void set_start(Point start);
    void set_end(Point end);

  public:
    double length(void);

  private:
    Point start;
    Point end;
  };

};