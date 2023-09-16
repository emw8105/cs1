#include <iostream>
#include <iomanip>

using namespace std;

#include "Circle.h"

Circle::Circle(double x, double y, double rad) : BasicShape()
{
    // if any arguments are negative, throw NegativeValue exception class
    if (x < 0 || y < 0 || rad < 0)
    {
        throw NegativeValue();
    }
    centerX = x;
    centerY = y;
    radius = rad;
    // call calcArea to calc area, then call setArea to initialize area
    double circArea = calcArea();
    setArea(circArea);
}
double Circle::calcArea() const
{
    return (3.14159*radius*radius); // calculate using circle area formula pi*r^2
}
