// Implementation file Circle.cpp
// This is the implementation of the Circle class
// The interface for the class is in the header file Circle.h
// Circle is a derived class of Shape, found in Shape.h
// VERSION: 2020-03-09

#include "Circle.h"

namespace HENLEYSHAPE
{
    // Initializes a new object of type Circle, with name "Circle" and default radius = 0
    Circle::Circle() : Shape("Circle"), radius(0)
    {}

    // Constructs a new object of type Circle, with name "Circle", and the specified radius
    Circle::Circle(int theRadius) : Shape("Circle"), radius(theRadius)
    {}

    // Postcondition:  The radius of the calling object has been set to newRadius
    void Circle::setRadius(int newRadius) {
        this->radius = newRadius;
    }

    // Precondition:  The calling object has been given a value
    // Returns the radius of the calling object
    double Circle::getRadius() const {
        return radius;
    }

    // Precondition:  The calling object has been given a value
    // Returns the area calculated with the objects radius and pi = 3.14159
    double Circle::getArea() const {
        return 3.14159 * radius * radius;
    }
}