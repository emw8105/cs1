// 4_11_virtual_base_class_pointer

/*
Binding is the process which maps a function call to the
actual function to be executed
In static binding (or early binding), the binding is done
at compile time. Static binding can result in problems
if the function is redefined, e.g. printObject with calcGPA
To address the problem, we need dynamic binding (or late binding)
With dynamic binding, the mapping is done at run time when the
object type (base or derived) is known

To enable dynamic binding:
1) declare the function "virtual"
2) pass the object by reference or pass a pointer to an object

Another key concept in OOP: Polymorphism. ("multiple shapes"
in Greek): A function can take multiple shapes depending on the
type of the object that calls the function

Once a function is declared virtual, all the corresponding
functions in the derived classes (child, grandchild, etc.)
are automatically virtual, but we should still
put "virtual" for good practice

A virtual function is overridden, a non-virtual function
is redefined

Base class pointer: A pointer to a base object can hold the
address of a derived object
Through a base class pointer, you can only access the members
of the base class, even if it is pointing to a derived object
e.g. sPtr->calcGPA will access the calcGPA of the base class, unless
calcGPA is declared virtual
When called from a base class pointer, the correct function version
will be called if the function is virtual
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
    virtual double calcGPA() const
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
    string getName() const
    {
        return name;
    }
    double getAvgScore() const
    {
        return avgScore;
    }
};

class UGStudent : public Student
{
public:
    UGStudent(string name_, double avgScore_) :
        Student(name_, avgScore_)
    {

    }
    virtual double calcGPA() const // "virtual" can be omitted but put in for good practice
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

void printObject(const Student & s);

int main()
{
    UGStudent ugs("Obi-Wan", 99);
    Student s("Jabba", 99);

    cout << "GPA of undergrad student is " << ugs.calcGPA() << endl;
    cout << "GPA of student is " << s.calcGPA() << endl;

    printObject(ugs);
    printObject(s);

    // Base class pointer
    Student * sPtr = &ugs;
    cout << "GPA of ugs is " << sPtr->calcGPA() << endl;

    return 0;
}

// must be reference variable, basically derived class flag info for computer is lost when copied
void printObject(const Student & s) // pass by reference to enable the correct binding
{
    cout << "Name: " << s.getName() << ", average score = "
    << s.getAvgScore() << ", GPA = " << s.calcGPA() << endl;
}
