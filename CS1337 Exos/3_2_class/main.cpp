// 3_2_class


#include <iostream>

using namespace std;

struct StudentStruct
{
    string name;
    int netID;
};


void setNetID(StudentStruct * const stuPtr, int Id);
void printNetID(const StudentStruct * const stuPtr);
void printStud(const Student * const stuPtr);

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

    cout << "Enter student's netID: ";
    cin >> ID;
    Student stu3;

    // Pointer to object
    Student * stuPtr = &stu3;
    stuPtr->setNetID(ID);
    stuPtr->printNetID();
    printStud(&stu3);

    // Dynamic allocation
    stuPtr = new Student;
    stuPtr->setNetID(789);
    stuPtr->setName("Uhura");
    printStud(stuPtr);



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
