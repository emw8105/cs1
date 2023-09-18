// 3_28_overloaded

/*
Operators such as +, -, etc. can be redefined through overloading
when used with objects

Overloaded operators must have the same number of operands as
the original operator, e.g. overloaded+ must have two operands

To define an overloaded operator, define a member function
when name starts with "operator", followed by the symbol
that you want to overload, e.g. "operator+"
Then obj1.operator+(obj2) is the same as obj1 + obj2
*/

#include <iostream>
#include <cmath>

using namespace std;

class Pt2D
{
private:
    double x, y;
public:
    Pt2D(double x_, double y_)
    {
        x = x_;
        y = y_;
    }
    double operator-(const Pt2D & rhs) // Overloaded -
    {
        return (sqrt((x - rhs.x)*(x - rhs.x) +(y - rhs.y)*(y - rhs.y)));
    }
};

int main()
{
    Pt2D p1(0, 10), p2(0, 15);

    cout << p1.operator-(p2) << endl;
    cout << p1 - p2 << endl;
    cout << p2.operator-(p1) << endl;
    cout << p2 - p1 << endl;

    return 0;
}
