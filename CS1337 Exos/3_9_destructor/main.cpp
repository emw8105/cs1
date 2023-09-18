// 3_9_destructor

/*
A destructor is a special member function that is automatically
called when an object is destroyed (this applies to statically
and dynamically created objects)

Destructor's name is ~className. It takes no argument, and returns
nothing (not even void)
Destructor cannot be overloaded -> There is only one destructor
for a class

Example of use: release memory that was dynamically allocated
in the constructor

A private member function can be called only by another member
function of the same class
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

    // Dynamic creation
    Student * stuPtr = new Student("R2D2", 2);
    delete stuPtr;
    cout << endl << "Exiting program" << endl;

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
