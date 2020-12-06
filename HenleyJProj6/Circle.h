// Provided by:    "Problem Solving with C++", Savitch/Mock
// FILE: Circle.h
// VERSION: 2020-03-09
// REQUIRES: Shape.h
// PROVIDES: A derived class to handle circle shapes.
// Each Circle object contains a shape name and a radius, as well as constructors, accessors, and mutators.
// Redefines the getArea() public member function from the parent class Shape.h to return a result relevant to
// circles.
//
// CONSTRUCTORS in the class Circle:
//    Circle()
//        Initializes a new object of type Circle, with name "Circle" and default radius = 0
//
//    Circle(int radius)
//        Constructs a new object of type Circle, with name "Circle", and the specified radius
//
// FUNCTIONS in the class Circle:
//    void setRadius(int newRadius)
//        Postcondition:  The radius of the calling object has been set to newRadius
//
//    double getRadius() const;
//        Precondition:  The calling object has been given a value
//        Returns the radius of the calling object
//
//    virtual double getArea() const
//        Precondition:  The calling object has been given a value
//        Returns the area calculated with the objects radius and pi = 3.14159
//
// INHERITED FUNCTIONS in the class Circle
//    void setName(string name)
//        Postcondition:  The name of the calling object has been set to the specified name
//
//    double getName() const;
//        Precondition:  The calling object has been given a value
//        Returns the name of the calling object

#ifndef CSCI_221_PROJ6_CIRCLE_H
#define CSCI_221_PROJ6_CIRCLE_H

#include "Shape.h"

namespace HENLEYSHAPE
{
    class Circle : public Shape {
    public:
        Circle();

        explicit Circle(int theRadius);
        void setRadius(int newRadius);
        double getRadius() const;
        virtual double getArea() const;
    private:
        int radius;
    };
}

#endif //CSCI_221_PROJ6_CIRCLE_H
