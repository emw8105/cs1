/*Author: Evan Wright
Compiler: GNU GCC
Date: 5/2/2022
Purpose of program:
Program utilizes exceptions and inheritance to calculate the area
of different shapes using input validation on user inputs.
If inputs are invalid, will reloop and have the user enter
new values until all arguments are valid, then uses the
overridden functions in the derived classes to calculate
the area of the different shapes. The base class is abstract,
so only the derived Rectangle and Circle classes can be used
to create objects, as they provide definitions for the calcArea,
which is a pure virtual function in the BasicShape base class.
*/
#include <iostream>
#include "BasicShape.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

int main()
{
    // Circle
    double xCoord;
    double yCoord;
    double radius;
    bool validArgs = false;

    cout << "================= Circle =================" << endl;
    while (!validArgs)
    {
        validArgs = true; // if no exception is thrown, will remain true and prevent another loop iteration

        // prompt user to enter x, y, and rad of circle
        cout << "Please enter the x coordinate of the circle's center: ";
        cin >> xCoord;
        cout << "Please enter the y coordinate of the circle's center: ";
        cin >> yCoord;
        cout << "Please enter the radius of the circle: ";
        cin >> radius;

        // try to statically create circle
        try
        {
            Circle myCirc {xCoord, yCoord, radius};
            // if successful, print circle area
            cout << "***** The area of the circle is " << myCirc.getArea() << "." << endl
             << endl;
        }
        catch (BasicShape::NegativeValue) // if any arguments are negative, exception is thrown
        {
            cout << "***** Negative input value" << endl << endl;
            validArgs = false; // set to false to reloop again and prompt user for new inputs
        }
    }

    // Rectangle
    double length;
    double width;
    validArgs = false;
    cout << "================= Rectangle =================" << endl;
    while (!validArgs)
    {
        validArgs = true; // if no exception is thrown, will remain true and prevent another loop iteration

        // prompt user to enter length and width of a rectangle
        cout << "Please enter the length of the rectangle: ";
        cin >> length;
        cout << "Please enter the width of the rectangle: ";
        cin >> width;

        // try to statically create rectangle
        try
        {
            Rectangle myRect {width, length};
            // if successful, print rectangle area
            cout << "***** The area of the rectangle is " << myRect.getArea() << ".";
        }
        catch (BasicShape::NegativeValue) // if any arguments are negative, exception is thrown
        {
            cout << "***** Negative input value" << endl << endl;
            validArgs = false; // set to false to reloop again and prompt user for new inputs
        }
    }
    return 0;
}
/*
main function is primarily responsible for input and dealing with exceptions.
First it loops on the circle inputs until they are valid and outputs the
area of the specified circle. Then it will loop on the rectangle inputs and do
the same, outputting the area when done.
*/
