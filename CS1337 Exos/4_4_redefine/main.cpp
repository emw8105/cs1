// 4_4_redefine

/*
A derived class can redefine a function of the base class
Redefinition is different from overloading because the redefined
function has the same name and parameter list as the original
function

Objects of the base class use the base version, and objects of
the derived class use the derived version.
*/

#include <iostream>

using namespace std;

class Student
{
private:
    string name;
protected:
    double avgScore;
public:
    Student(string name_, double avgScore_)
    {
        name = name_;
        avgScore = avgScore_;
    }
    double calcGPA() const
    {
        double GPA;
        if (avgScore > 95)
            GPA = 4.0;
        else if (avgScore > 90)
            GPA = 3.5;
        else if (avgScore > 85)
            GPA = 3.0;
        else
            GPA = 2.5;
        return GPA;
    }
};

class UGStudent : public Student
{
public:
    UGStudent(string name_, double avgScore_) :
        Student(name_, avgScore_)
    {

    }
    double calcGPA() const // redefine
    {
        double GPA;
        if (avgScore > 98)
            GPA = 4.4;
        else if (avgScore > 95)
            GPA = 4.0;
        else if (avgScore > 90)
            GPA = 3.5;
        else
            GPA = 3.0;
        return GPA;
    }
};

int main()
{
    UGStudent ugs("Obi-Wan", 99);
    Student s("Jabba", 99);

    cout << "GPA of undergrad student is " << ugs.calcGPA() << endl;
    cout << "GPA of student is " << s.calcGPA() << endl;
    return 0;
}
