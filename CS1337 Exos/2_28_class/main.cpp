// 2_28_class

#include <iostream>

using namespace std;

struct StudentStruct
{
    string name;
    int netID;
};

class Student
{
private:
    string name;
    int netID;
public:
    void setNetID(int);
    void printNetID() const;
};

void setNetID(StudentStruct * const stuPtr, int Id);
void printNetID(const StudentStruct * const stuPtr);

int main()
{
    int ID;

    cout << "Enter student's netID: ";
    cin >> ID;

    // Procedural programming
    StudentStruct stu1; // Define a structure variable
    cout << endl << "Procedural programming" << endl;
    setNetID(&stu1, ID);
    printNetID(&stu1);

    // OOP
    Student stu2; // Define an object
    cout << endl << "OOP" << endl;
    stu2.setNetID(ID);
    stu2.printNetID();



    return 0;
}

void setNetID(StudentStruct * const stuPtr, int Id)
{
    stuPtr->netID = Id;
}

void printNetID(const StudentStruct * const stuPtr)
{
    cout << "Student ID is " << stuPtr->netID << endl;
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
