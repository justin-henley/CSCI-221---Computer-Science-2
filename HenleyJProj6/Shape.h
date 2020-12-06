// Provided by:    "Problem Solving with C++", Savitch/Mock
// FILE: Shape.h
// VERSION: 2020-03-09
// PROVIDES: A base class to handle shapes.
// Each Shape object contains a name of the shape, as well as constructors, accessor, and mutator.
//
// CONSTRUCTORS in the class Circle:
//    Shape()
//        Initializes a new object of type Circle, with name ""
//
//    Shape(int radius)
//        Constructs a new object of type Shape, with the specified name
//
// FUNCTIONS in the class Circle:
//    void setName(string name)
//        Postcondition:  The name of the calling object has been set to the specified name
//
//    double getName() const;
//        Precondition:  The calling object has been given a value
//        Returns the name of the calling object
//
//    virtual double getArea() const
//        Returns 0; serves as a placeholder for derived classes

#ifndef CSCI_221_PROJ6_SHAPE_H
#define CSCI_221_PROJ6_SHAPE_H

#include <string>

namespace HENLEYSHAPE
{
    using namespace std;
    class Shape {
    public:
        Shape();
        explicit Shape(string name);
        string getName() const;
        void setName(string newName);
        virtual double getArea() const;
    private:
        string name;
    };
}

#endif //CSCI_221_PROJ6_SHAPE_H
