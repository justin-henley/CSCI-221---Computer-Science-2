// AUTHOR: Justin Henley
// EMAIL: jahenley@mail.fhsu.edu
// COURSE: CSCI 221 VB, Spring 2020, FHSU
// PROJECT: Proj6 (Unit 15, Inheritance)
// Practice Program 3, page 884
// A program to explore inheritance through a provided base class Shape, and a provided derived class Circle.
// Project is to add a new derived class from Shape, named Rectangle. Class must be defined and well-tested

#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;
using namespace HENLEYSHAPE;

const double PI = 3.14159;

int main() {
    // Textbook test of Circle class
    Circle c(2);
    cout << c.getName() << " has a radius " << c.getRadius() << " and area " << c.getArea() << endl;

    // Textbook test of Rectangle class
    Rectangle r(3, 4);
    cout << r.getName() << " has width " << r.getWidth() << " and height " << r.getHeight()
         << " and area " << r.getArea() << endl << endl;

    // More testing of the Circle class
    {
        Circle c(1);  // Test object

        cout << "TEST OF CIRCLE CLASS\n\n";
        cout << "Circle with radius(1)\n";

        // Testing Circle Accessors
        cout << "Name of shape is \"Circle\"? ";
        c.getName() == "Circle" ? cout << "YES\n" : cout << "NO\n";

        cout << "Area of Circle is 1*1*PI = PI? ";
        c.getArea() == PI ? cout << "YES\n" : cout << "NO\n";

        // Testing Circle mutators
        // Changing the name
        c.setName("Apple");
        cout << "\nRenaming the shape to \"Apple\"...\n";
        cout << "Name of shape is \"Apple\"? ";
        c.getName() == "Apple" ? cout << "YES\n" : cout << "NO\n";

        // Changing the radius
        c.setRadius(2);
        cout << "\nResizing the Circle to radius(2)...\n";
        cout << "Area of Circle is 2*2*PI = 4*PI? ";
        c.getArea() == 4*PI ? cout << "YES\n" : cout << "NO\n";

        // Testing Circle object access through a Shape pointer
        cout << "\nTesting access of a Circle shape through a Shape pointer\n\n";

        typedef Shape *ShapePtr; // A pointer definition for Shape objects
        ShapePtr pointToShape = new Circle(5);

        cout << "Name of pointed-to Circle is Circle? ";  // Checking the name is accessible
        pointToShape->getName() == "Circle" ? cout << "YES\n" : cout << "NO\n";

        cout << "Area of pointed-to Circle is 5*5*PI = 25*PI? ";
        pointToShape->getArea() == 25*PI ? cout << "YES\n" : cout << "NO\n";

        // free memory
        delete pointToShape;
    }

    // More testing of the Rectangle class
    {
        Rectangle r(3, 4);  // Test object

        cout << "\nTEST OF RECTANGLE CLASS\n\n";
        cout << "Rectangle with width(3) and height(4)\n";

        // Testing Rectangle Accessors
        cout << "Name of shape is \"Rectangle\"? ";
        r.getName() == "Rectangle" ? cout << "YES\n" : cout << "NO\n";

        cout << "Area of Rectangle is 3*4 = 12? ";
        r.getArea() == 12 ? cout << "YES\n" : cout << "NO\n";

        // Testing Rectangle mutators
        // Changing the name
        r.setName("House");
        cout << "\nRenaming the shape to \"House\"...\n";
        cout << "Name of shape is \"House\"? ";
        r.getName() == "House" ? cout << "YES\n" : cout << "NO\n";

        // Changing the width and height
        r.setWidth(10);
        r.setHeight(20);
        cout << "\nResizing the rectangle to width(10) and height(20)...\n";
        cout << "Area of Rectangle is 10*20 = 200? ";
        r.getArea() == 200 ? cout << "YES\n" : cout << "NO\n";

        // Testing Rectangle object access through a Shape pointer
        cout << "\nTesting access of a Rectangle shape through a Shape pointer\n\n";

        typedef Shape *ShapePtr; // A pointer definition for Shape objects
        ShapePtr pointToShape = new Rectangle(5, 6);

        cout << "Name of pointed-to Rectangle is Rectangle? ";  // Checking the name is accessible
        pointToShape->getName() == "Rectangle" ? cout << "YES\n" : cout << "NO\n";

        cout << "Area of pointed-to Rectangle is 5*6 = 30? ";
        pointToShape->getArea() == 30 ? cout << "YES\n" : cout << "NO\n";

        // free memory
        delete pointToShape;
    }
}

