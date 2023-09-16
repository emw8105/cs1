// Specification file for BasicShape base class
#ifndef BASICSHAPE_H
#define BASICSHAPE_H
#include <string>
using namespace std;

class BasicShape
{
private:
    double area;

public:
    class NegativeValue // Exception class
    {};

    double getArea() const
    {
        return area;
    }

    virtual double calcArea() const = 0;

    void setArea(double area_)
    {
        area = area_;
    }
};

#endif
