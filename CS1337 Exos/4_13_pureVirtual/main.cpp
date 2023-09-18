// 4_13_pureVirtual

/*
A pure virtual function is a virtual function that must be
overridden in the derived class, unless we want to inherit
the pure virtual function

A class which has one or more pure virtual function is an
abstract base class. You are not allowed to create an object
from an abstract base class

Pure virtual functions may be useful as a placeholder, when
the class is too generic to be able to come up with
a meaningful function definition
*/

#include <iostream>

using namespace std;

class Student // Abstract Base Class
{
protected:
    double avgScore;
public:
    virtual double calcGrade() const = 0; // pure virtual, can't provide definition

    void setAvgScore(double avgScore_)
    {
        avgScore = avgScore_;
    }
};

class UTDStudent : public Student // Abstract class
// Inherits the pure virtual function
{
private:
    int netID;
};

class UTDUGStudent : public UTDStudent // Not abstract
{
public:
    virtual double calcGrade() const //
    {
        double grade;
        if (avgScore > 95)
            grade = 4.5;
        else if (avgScore > 90)
            grade = 4.0;
        else if (avgScore > 85)
            grade = 3.5;
        else
            grade = 3.0;
        return grade;
    }
};

int main()
{
    UTDUGStudent utdug1;
    utdug1.setAvgScore(96);

    cout << "Grade of the UTD UG Student is " << utdug1.calcGrade() << endl;
    // UTDStudent utdstu1; // compiler error, can't create an object from an abstract class

    return 0;
}
