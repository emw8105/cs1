// 4_4_access

/*
Access to a member of a derived class depends on the class access
specifier and the member access specifier in the base class

Class access specifiers and member access specifiers can be public
private or protected

When an object of the derived class is created, the constructor
of the base class is called, then the constructor of the derived

When an object of the derived class is destroyed, the destructor
of the derived class is called, then the constructor of the base
*/

#include <iostream>
#include <string>

using namespace std;

class Person // Base class
{
    string name; // private by default
    string address;
protected:
    int birthMonth;
public:
    Person(string name_, string address_)
    {
        name = name_;
        address = address_;
        cout << "Inside constructor of base\n";
    }

    ~Person()
    {
        cout << "Inside destructor of base\n";
    }

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
    Student(double GPA_, string major_, string name_, string address_):
        Person(name_, address_)
    {
        GPA = GPA_;
        major = major_;
        cout << "Inside constructor of derived\n";
    }

    ~Student()
    {
        cout << "Inside destructor of derived\n";
    }

    double getGPA() const
    {
        return GPA;
    }
    void setGPA(double GPA_)
    {
        GPA = GPA_;
    }
    int getBirthMonth() const // changing birthMonth to protected allows it to be used in inherited classes
    {
        return birthMonth;
    }
    void setBirthMonth(int birthMonth_)
    {
        birthMonth = birthMonth_;
    }
};

int main()
{
    { // artificial block of code, legal but changes under the hood compilation
        Student s(3.5, "CS", "Solo", "Galaxy");
        s.setName("R2-D2");
        cout << "Name is " << s.getName();

        s.setGPA(3.2);
        cout << "\nGPA is " << s.getGPA();

        s.setBirthMonth(5);
        cout << "\nBirth month is " << s.getBirthMonth();

        cout << endl;
    }

    // cout << endl << "Exiting";

    return 0;
}
