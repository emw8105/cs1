#include <iostream>
#include <iomanip>

using namespace std;

#include "Rectangle.h"

Rectangle::Rectangle(double w, double l) : BasicShape()
{
    // if any arguments are negative, throw NegativeValue exception class
    if (w < 0 || l < 0)
    {
        throw NegativeValue();
    }
    width = w;
    length = l;
    // call calcArea to calc area, then call setArea to initialize area
    double rectArea = calcArea();
    setArea(rectArea);
}
double Rectangle::calcArea() const
{
    return (width*length); // calculate using rectangle area formula l*w
}
