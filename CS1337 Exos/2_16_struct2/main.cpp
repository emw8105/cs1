// 2_16_struct2

/*
Nested structure: A structure can have as member another structure
You can pass a structure member or a whole structure variable to a
function

A structure variable is passed by value by default
(pass by reference using & is an option)

Pass by reference gives faster execution and more efficient memory
usage, but the function can modify the original structure variable
If you pass by reference, use const to prevent the function from
modifying the array

A function can return a structure

A structure variable has an address. To hold the address, use
a pointer to a structure
Everything we learned about pointers is applicable
- Can assign nullptr or an actual structure address
- Can dereference using the indirection operator to access
the structure variable

You can pass a structure pointer to a function:
1. Use * in parameter list of prototype and header
2. Dereference the ptr to access the structure variable
(you can also use the -> notation)
3. Pass the address of the structure when calling the function

To access a structure member from a pointer, there are 2 options:
1. Dereference the pointer, then use the dot notation, e.g.
(*studPtr).GPA. Make sure the parenthesis are in the right place
2. Use the arrow notation, e.g. studPtr->GPA

Can dynamically allocate a structure (or array of structure)
with the "new" operator, need a ptr to store the address that
is returned

Should return the chunk of memory when done, using delete

Same concepts and syntax as in chapter 9
*/

#include <iostream>

using namespace std;

struct Person
{
    string name;
    int bMonth;
    int bDay;
    int bYear;
};

struct Student
{
  Person studPerson; // Nested structure
  double GPA;

};

Student getStudentInfo();
void printStud(Student s);
void printStud2(const Student & s);
void printStud3(Student * sPtr);


int main()
{
    int numStudents;

    cout << "A structure can be nested within another structure" << endl;
    Student stu1;
    // Function returns a structure
    stu1 = getStudentInfo();

    // Pass structure by value
    cout << endl;
    printStud(stu1);

    // Pass structure by reference
    cout << endl;
    printStud2(stu1);

    // Pass structure by value
    cout << endl;
    //printStud3(stu1);

    // Address of a structure variable
    cout << endl << "Address of stu1 is " << &stu1;

    // Pointer to a structure
    Student * studPtr = &stu1;

    // Pass structure ptr to function
    cout << endl << "Print stu1 using pointer" << endl;
    printStud3(studPtr);

    // Dynamic allocation of an array of Students
    cout << endl << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore();
    studPtr = new Student[numStudents];
    for (int i = 0; i < numStudents; i++)
    {
        *(studPtr + i) = getStudentInfo(); // Equivalent: studPtr[i]
    }

    cout << endl << "Student array" << endl;
    for (int i = 0; i < numStudents; i++)
    {
        printStud(studPtr[i]);
        cout << endl;
    }

    // Release memory
    delete [] studPtr;

    return 0;
}

Student getStudentInfo()
{
    Student stud;
    cout << "Enter student's name: ";
    getline(cin, stud.studPerson.name);
    cout << "Enter month, day, year of birth: ";
    cin >> stud.studPerson.bMonth >> stud.studPerson.bDay >> stud.studPerson.bYear;
    cout << "Enter GPA: ";
    cin >> stud.GPA;
    cin.ignore();
    return stud;
}

void printStud(Student s) // Pass by reference
{
    cout << "Name: " << s.studPerson.name << ", DOB " << s.studPerson.bMonth
    << "/" << s.studPerson.bDay << "/" << s.studPerson.bYear << ", GPA: " << s.GPA;

}

void printStud2(const Student & s) // Pass a pointer to structure
{
    cout << "Name: " << s.studPerson.name << ", DOB " << s.studPerson.bMonth
    << "/" << s.studPerson.bDay << "/" << s.studPerson.bYear << ", GPA: " << s.GPA;

}

void printStud3(Student * sPtr) // Pass a pointer to structure
{
    cout << "Name: " << sPtr->studPerson.name << ", DOB " << sPtr->studPerson.bMonth
    << "/" << sPtr->studPerson.bDay << "/" << (*sPtr).studPerson.bYear << ", GPA: " << (*sPtr).GPA;

}
