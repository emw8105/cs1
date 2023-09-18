// 2_7_struct

#include <iostream>

using namespace std;

int main()
{
    // Define a struct called Student
    // No memory is allocated yet
    struct Student // Student is the structure tag
    {
        string netID; // First member
        double GPA; // Second member
    };

    // Define a structure variable
    // Memory is allocated
    Student stu1;

    // Use the dot operator to access the structure members
    cout << endl << "Enter the student's netID, then GPA: ";
    cin >> stu1.netID >> stu1.GPA;

    cout << "stu1: Student's netID and GPA are ";
    cout << stu1.netID << ", " << stu1.GPA << endl;

    // Initialize structure with a list
    Student stu2 = {"def456", 100};
    cout << endl << "Initialize structure with a list" << endl;
    cout << stu2.netID << ", " << stu2.GPA << endl;

    // Initialize member by member
    Student stu3;
    stu3.netID = "ghi789";
    stu3.GPA = 2.0;
    cout << endl << "Initialize member by member" << endl;
    cout << stu3.netID << ", " << stu3.GPA << endl;

    // Partial initialization list
    Student stu4 = {"jkl7890"};
    cout << endl << "Initialize with partial list" << endl;
    cout << "stu4: Student's netID and GPA are ";
    cout << stu4.netID << ", " << stu4.GPA << endl;

    return 0;
}
