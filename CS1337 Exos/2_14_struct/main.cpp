// 2_14_struct

/*
The data types we already know are primitive (built-in) data types
meaning they come with the language, e.g. int, double
Attributes of a data type are the values it can take and the operations
that can be performed
For example, int values are numbers without the fractional part
ranging from INT_MIN to INT_MAX,
Operations: +, -, *, etc.

An abstract data type is a data type where the implementation
is hidden, an example is C++ string class

A structure is a grouping of multiple variables not necessarily
of the same type (unlike arrays)

A structure definition is a template, no memory is allocated
(name of the template is the structure tag)

Once a structure has been defined, you can declare variables
of that structure type. The variable is called a structure
variable. Memory is allocated

Use the dot operator to access a member of a structure
Can use initialization list to initialize a structure variable when
it is defined

Partial initialization list is possible

Arrays of structures can be used instead of parallel arrays
*/

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
    cout << "stu2: Student's netID and GPA are ";
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

    // Arrays of Structures
    const int NUM_ELMTS = 3;
    Student stuArr[NUM_ELMTS]; // stuArr is an array of structures
    cout << endl << "Array of structures" << endl;
    for (int i = 0; i < NUM_ELMTS; i++)
    {
        cout << endl << "Enter the netID and GPA of student "
        << (i + 1) << ": ";
        cin >> stuArr[i].netID >> stuArr[i].GPA;
        cout << "Student's netID and GPA are ";
        cout << stuArr[i].netID << ", " << stuArr[i].GPA << endl;
    }

    return 0;
}
