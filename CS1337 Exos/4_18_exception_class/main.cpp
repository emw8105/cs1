// 4_18_exception_class

/*
An exception class can be defined in a class and thrown
as an exception by a member function

If the exception class has no member variables, it's used
only to signal and error condition, with no additional info
*/

#include <iostream>

using namespace std;

class Rectangle
{
private:
    double width, length;
public:
    class NegativeLength // Exception class
    {
    };
    void setLength(double length_)
    {
        if (length_ < 0)
        {
            throw NegativeLength();
        }
        else
            length = length_;
    }
};

int main()
{
    Rectangle r;
    double length;

    cout << "Enter length: ";
    cin >> length;

    try
    {
        r.setLength(length);
        cout << "Length successfully set to " << length << endl;
    }
    catch(Rectangle::NegativeLength)
    {
        cout << "Error, length cannot be negative\n";
    }
    return 0;
}
