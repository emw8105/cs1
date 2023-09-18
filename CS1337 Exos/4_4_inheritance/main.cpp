// 4_4_inheritance

/*
You can build a derived class from a base class
The derived class automatically inherits all the members
(variables and functions) of the base class
The derived class may have additional members of its own

You can have a hierarchy of derivations, i.e. child of a child

A good way to recognize that inheritance is a suitable model is
when the relationship is "is a", e.g. A Student is a Person

Inheritance is a fundamental concept in OOP
*/

#include <iostream>
#include <string>

using namespace std;

class Person // Base class
{
    string name;
    string address;
public:
    string getName() const
    {
        return name;
    }
    void setName(string name_)
    {
        name = name_;
    }
};

class Student : public Person // Derived class
{
    double GPA;
    string major;
public:
    double getGPA() const
    {
        return GPA;
    }
    void setGPA(double GPA_)
    {
        GPA = GPA_;
    }
};

int main()
{
    Student s; // create object of derived class
    s.setName("C-3PO"); // setName and getName are members of the derived object
    cout << "Name is " << s.getName();

    s.setGPA(3.2);
    cout << "\nGPA is " << s.getGPA();

    return 0;
}
