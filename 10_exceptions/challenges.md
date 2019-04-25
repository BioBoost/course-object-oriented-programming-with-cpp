# Chapter 10 - Exceptions - Challenges

## Circle Class

Create a basic class `Circle` that satisfies the following UML diagram:

```uml
####################################
- radius
####################################
+ Circle()
+ Circle(double radius)

+ get_radius(): double
+ set_radius(radius: double)

+ area(): double
+ circumference(): double
####################################
```

Make the methods `area()` and `circumference()` calculate the area and circumference of the circle and return the result.

Create a small demo app that demonstrates the `Circle` class. Request a radius from the user via the terminal.

Next create a class `NegativeRadiusException` and throw an instance in the method `set_radius()` if the argument of the method is negative. Refactor the main function of the application to try and catch the exception.