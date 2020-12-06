// Provided by:    Justin Henley
// Email Address:  jahenley@mail.fhsu.edu
// FILE: Rectangle.h
// VERSION: 2020-03-09
// REQUIRES: Shape.h
// PROVIDES: A derived class to handle rectangle shapes.
// Each Rectangle object contains a width and height, as well as constructors, accessors, and mutators.
// Redefines the getArea() public member function from the parent class Shape.h to return a result relevant to
// rectangles.
//
// CONSTRUCTORS in the class Rectangle:
//    Rectangle()
//        Initializes a new object of type Rectangle, with name "Rectangle" and default height = 0 and width = 0
//
//    Rectangle(int width, int height)
//        Constructs a new object of type Rectangle, with name "Rectangle", and the specified width and height
//
// FUNCTIONS in the class Rectangle:
//    void setWidth(int newWidth)
//        Postcondition:  The width of the calling object has been set to newWidth
//
//    void setHeight(int newHeight);
//        Postcondition:  The height of the calling object has been set to newHeight
//
//    double getWidth() const;
//        Precondition:  The calling object has been given a value
//        Returns the width of the calling object
//
//    double getHeight() const;
//        Precondition:  The calling object has been given a value
//        Returns the height of the calling object
//
//    virtual double getArea() const
//        Precondition:  The calling object has been given a value
//        Returns the area calculated with the objects width and height
//
// INHERITED FUNCTIONS in the class Rectangle
//    void setName(string name)
//        Postcondition:  The name of the calling object has been set to the specified name
//
//    double getName() const;
//        Precondition:  The calling object has been given a value
//        Returns the name of the calling object

#ifndef CSCI_221_PROJ6_RECTANGLE_H
#define CSCI_221_PROJ6_RECTANGLE_H

#include "Shape.h"

namespace HENLEYSHAPE
{
    class Rectangle : public Shape{
    public:
        Rectangle();
        Rectangle(int width, int height);
        void setWidth(int newWidth);
        void setHeight(int newHeight);
        double getWidth() const;
        double getHeight() const;
        virtual double getArea() const;
    private:
        int width;
        int height;
    };
}

#endif //CSCI_221_PROJ6_RECTANGLE_H
