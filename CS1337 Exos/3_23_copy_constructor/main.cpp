// 3_23_copy_constructor

/*
A copy constructor is a special constructor that is automatically
invoked when an object is created and initialized with another
object:
1) Student s1 = s1;
2) Object is passed by value to a function // Function parameter
// is created and initialized with argument
If creation and initialization are not in the same statement,
that will not invoke the copy constructor. Example:
Student s2;
s2 = s1;

If you do not write a copy constructor, the default copy constructor
will be used. It will copy memberwise, which may cause a problem
if a variable is a pointer

Copy constructor must have this parameter list: (const className & obj),
where obj is the object we copy from
const is required because we are not supposed to modify what
we copy from.

Must pass by reference because if we pass by value, the copy
constructor will automatically call the copy constructor,
which calls the copy constructor again, and so on.
*/

#include <iostream>
#include <iomanip>

using namespace std;


class Student
{
private:
    string name;
    int numTests;
    double * scoresPtr;
    void initScores(double); // Private member function
public:
    Student(string, int);
    Student(const Student &); // Copy constructor
    ~Student();
    void printStud() const;
    void setScore(double, int);
};


int main()
{

    int numTests;
    double score;
    cout << "Enter the number of tests: ";
    cin >> numTests;
    Student s("Kylo", numTests);
    for (int i = 0; i < numTests; i++)
    {
        cout << "Enter score for test " << (i + 1)
             << ": ";
        cin >> score;
        s.setScore(score, i);
    }
    s.printStud();
    cout << endl;

    Student s2 = s; // Will invoke the copy constructor
    cout << endl << "s2:" << endl;
    s2.printStud();

    s2.setScore(85, 0);
    cout << endl << "s2:" << endl;
    s2.printStud();

    cout << endl << "s:" << endl;
    s.printStud();
    cout << endl;

    return 0;
}


Student::Student(string name_, int numTests_)
{
    cout << "In Student constructor" << endl;
    name = name_;
    numTests = numTests_;
    scoresPtr = new double[numTests];
    initScores(0);
    //for (int i = 0; i < numTests; i++)
        //scoresPtr[i] = 0;
}
Student::~Student()
{
    cout << "In Student destructor" << endl;
    delete [] scoresPtr;
}
void Student::printStud() const
{
    cout << "Student " << name << " took " << numTests << " tests" << endl;
    for (int i = 0; i < numTests; i++)
    {
        cout << setw(8) << scoresPtr[i];
        if ((i+1) % 5 == 0)
            cout << endl;
    }
}
void Student::setScore(double score, int ind)
{
    scoresPtr[ind] = score;
}
void Student::initScores(double val)
{
    for (int i = 0; i < numTests; i++)
    {
        scoresPtr[i] = val;
    }
}
Student::Student(const Student & s) // copy constructor
{
    name = s.name;
    numTests = s.numTests;
    scoresPtr = new double[numTests];
    for(int i = 0; i < numTests; i++)
        scoresPtr[i] = s.scoresPtr[i];

}
