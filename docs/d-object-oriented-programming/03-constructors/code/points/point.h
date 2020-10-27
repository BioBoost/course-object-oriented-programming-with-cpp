// point.h
#pragma once

namespace Geometry {

  class Point {

    // Constructors
    public:
      Point(void);    // Default constructor
      Point(double x, double y);

    // Methods
    public:
      void move_to(double x, double y);
      void move_by(double deltaX, double deltaY);

    public:
      double get_x(void) const;
      double get_y(void) const;

    // Attributes (instance variables)
    private:
      double x = 0;
      double y = 0;

  };

};