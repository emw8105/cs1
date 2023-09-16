// Specification file for Rectangle derived class
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "BasicShape.h"

class Rectangle : public BasicShape
{
private:
    double width;
    double length;

public:
    Rectangle(double w, double l);
    double calcArea() const;
};

#endif
