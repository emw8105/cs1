// 3_7_constructor

/*
A constructor is a special member function that is automatically
called (no explicit call by programmer) when an object is created
statically or dynamically

Constructor must have the same name as the class. It has no
return type (not even void)

A constructor can take zero or more arguments

A default constructor is the constructor that is automatically
called when an object is created without arguments

A class can have multiple constructors, through overloading,
but it can have only one default constructor
Refer to the diagram on slide 54 for a summary
*/

#include <iostream>

using namespace std;

class Student
{
private:
    string name;
    int netID;
public:
    Student(); // Default constructor
    Student(string, int); // Overloaded constructor
    Student(string); // Overloaded constructor
    void setNetID(int); // Example of setter or mutator
    void printNetID() const;
    void setName(string);
    int getNetID() const; // Example of getter or accessor
    string getName() const;
};


void printStud(const Student * const stuPtr);

int main()
{
    // Static object creation
    cout << "Create object stu1" << endl;
    Student stu1;
    printStud(&stu1);

    cout << "Create object stu2" << endl;
    Student stu2("Han Solo",  101);
    printStud(&stu2);

    cout << "Create object stu3" << endl;
    Student stu3("Scotty");
    printStud(&stu3);

    // Dynamic object creation
    cout << endl << "Dynamically create object" << endl;
    Student * stuPtr = new Student("Scotty");
    printStud(stuPtr);

    cout << endl << "Dynamically create object" << endl;
    stuPtr = new Student;
    printStud(stuPtr);

    return 0;
}

void printStud(const Student * const stuPtr)
{
    cout << endl << "Print with printStud" << endl;
    cout << stuPtr->getName() << " has netID "
    << stuPtr->getNetID() << endl;
}

void Student::setNetID(int Id)
{
    if (Id > 0)
        netID = Id;
    else
    {
        cout << "Error, Id must be positive" << endl;
        exit(EXIT_FAILURE);
    }
}

void Student::printNetID() const
{
    cout << "Student ID is " << netID << endl;
}

void Student::setName(string name_)
{
    name = name_;
}
int Student::getNetID() const
{
    return netID;
}
string Student::getName() const
{
    return name;
}

Student::Student() // Default constructor
{
    cout << "Inside default constructor of Student" << endl;
    name = "";
    netID = 0;
}
Student::Student(string name_, int netID_) // Overloaded constructor
{
    cout << "Inside constructor with 2 arguments of Student" << endl;
    name = name_;
    netID = netID_;
}
Student::Student(string name_) // Overloaded constructor
{
    cout << "Inside constructor with 1 argument of Student" << endl;
    name = name_;
    netID = 0;
}
