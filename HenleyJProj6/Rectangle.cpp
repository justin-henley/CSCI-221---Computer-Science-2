// Implementation file Rectangle.cpp
// This is the implementation of the Rectangle class
// The interface for the class is in the header file Rectangle.h
// Rectangle is a derived class of Shape, found in Shape.h
// VERSION: 2020-03-09

#include "Rectangle.h"

namespace HENLEYSHAPE
{
    // Initializes a new object of type Rectangle, with name "Rectangle" and default height = 0 and width = 0
    Rectangle::Rectangle() : Shape("Rectangle"), height(0), width(0)
    {}

    // Constructs a new object of type Rectangle, with name "Rectangle", and the specified width and height
    Rectangle::Rectangle(int width, int height) : Shape("Rectangle"), height(height), width(width)
    {}

    // Postcondition:  The width of the calling object has been set to newWidth
    void Rectangle::setWidth(int newWidth){
        this->width = newWidth;
    }

    // Postcondition:  The height of the calling object has been set to newHeight
    void Rectangle::setHeight(int newHeight){
        this->height = newHeight;
    }

    // Precondition:  The calling object has been given a value
    // Returns the width of the calling object
    double Rectangle::getWidth() const {
        return width;
    }

    // Precondition:  The calling object has been given a value
    // Returns the height of the calling object
    double Rectangle::getHeight() const {
        return height;
    }

    // Precondition:  The calling object has been given a value
    // Returns the area calculated with the objects width and height
    double Rectangle::getArea() const {
        // Ensure that integer multiplication does not happen
        return static_cast<double>(height) * static_cast<double>(width);
    }
}