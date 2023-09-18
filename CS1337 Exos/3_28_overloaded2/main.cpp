// 3_28_overloaded2

/*
To enable multi-assignment statements with the overloaded=,
e.g. stu1 = stu2 = stu3;
stu1 = stu2.operator=(stu3);
the overloaded=, when called by stu2, should return stu2
To do that, use return *this;
"this" is a predefined hidden pointer that points to the calling
object.
"this" is automatically passed as an argument to every non-static
member function
"this" is not available in a static member function
Most operators can be overloaded: <, ==, !=, <=, ++(postfix and
prefix), --(postfix and prefix), etc.
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

    bool operator==(const Pt2D & rhs)
    {
        return((x == rhs.x) && (y == rhs.y));
    }
    bool operator<(const Pt2D & rhs)
    {
        return((x+y) < (rhs.x+rhs.y));
    }
    bool operator>(const Pt2D & rhs)
    {
        return((x+y) > (rhs.x+rhs.y));
    }
    Pt2D operator=(const Pt2D & rhs)
    {
        x = rhs.x;
        y = rhs.y;
        return *this; // returns the calling object
    }
    bool operator<=(const Pt2D & rhs)
    {
        return ((*this < rhs) || (*this == rhs));
    }
    Pt2D operator++() // Prefix increment
    {
        ++x;
        ++y;
        return *this;
    }
    Pt2D operator++(int) // "int" is a dummy parameter
    // to indicate Postfix increment
    {
        Pt2D temp (x, y); // Pt2D temp = *this
        x++;
        y++;
        return temp;
    }
    void printPt2D() const
    {
        cout << "x = " << x << ", y = " << y << endl;
    }
};

int main()
{
    Pt2D p1(10, 100), p2(20, 200), p3(30, 300);

    cout << "p1:\n";
    p1.printPt2D();
    cout << "p2:\n";
    p2.printPt2D();
    cout << "p3:\n";
    p3.printPt2D();

    // Multi-assignment
    p3 = p2 = p1;
    cout << endl << "p3 after p3 = p2 = p1:\n";
    p3.printPt2D();

    // Overloaded <
    if (p1 < p2)
        cout << "\n(p1 < p2) is true\n";
    else
        cout << "\n(p1 < p2) is false\n";

    // p2 = ++p1;
    p2 = ++p1;
    cout << "\np1 after p2 = ++p1:\n";
    p1.printPt2D();
    cout << "p2:\n";
    p2.printPt2D();

    // p2 = p1++;
    p2 = p1++;
    cout << "\np1 after p2 = p1++:\n";
    p1.printPt2D();
    cout << "p2:\n";
    p2.printPt2D();

    // Overloaded <=
    if (p1 <= p2)
        cout << "(p1 <= p2) is true\n";
    else
        cout << "(p1 <= p2) is false\n";

    return 0;
}
