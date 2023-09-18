// 3_2_separate

#include <iostream>

using namespace std;
#include "Student.h"

void printStud(const Student * const stuPtr);

int main()
{
    int ID;

    cout << "Enter student's netID: ";
    cin >> ID;

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

void printStud(const Student * const stuPtr)
{
    cout << endl << "Print with printStud" << endl;
    cout << stuPtr->getName() << " has netID "
    << stuPtr->getNetID() << endl;
}
