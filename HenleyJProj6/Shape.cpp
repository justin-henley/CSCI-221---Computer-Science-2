// Implementation file Shape.cpp
// This is the implementation of the Shape class
// The interface for the class is in the header file Shape.h
// VERSION: 2020-03-09

#include "Shape.h"
#include <string>

namespace HENLEYSHAPE
{
    using namespace std;

    // Initializes a new object of type Circle, with name ""
    Shape::Shape(){
        name = "";
    }

    // Constructs a new object of type Shape, with the specified name
    Shape::Shape(string name){
        this->name = name; // NOLINT(performance-unnecessary-value-param)
    }

    // Precondition:  The calling object has been given a value
    // Returns the name of the calling object
    string Shape::getName() const {
        return this->name;
    }

    // void setName(string name)
    // Postcondition:  The name of the calling object has been set to the specified name
    void Shape::setName(string newName){
        this->name = newName; // NOLINT(performance-unnecessary-value-param)
    }

    // Returns 0; serves as a placeholder for derived classes
    double Shape::getArea() const {
        return 0;
    }
}