// 3_23_static

/*
A static variable is associated with a class, and not with a
specific object
It is shared among all objects. There is only one copy

Remember to have a declaration inside the class declaration
(template), and a definition (memory is allocated) outside
of the class declaration

If you have a separate className.cpp, a simple rule is to
put the definition in the cpp

The purpose of a static member function is to allow access
to a static member variable, independently of objects
e.g. Tree::getTreeCountStatic()
You can also call a static member function from an object, e.g.
t1.getTreeCountStatic

A static member function is not allowed to access an instance
member variable

A non-static member function can access a static member variable
*/

#include <iostream>

using namespace std;

class Tree
{
private:
    static int treeCount; // Static member declaration
    static string descr[3]; //Static array declaration
    int type;
public:
    Tree(int type_)
    {
        type = type_;
        treeCount++;
    }
    static int getTreeCountStatic() // Static member function
    {
        return treeCount;
    }
    int getTreeCount() const
    {
        return treeCount;
    }
    string getDescr() const
    {
        return descr[type];
    }
    static void printDescr()
    {
        for (int i = 0; i < 3; i++)
            cout << i << ": " << descr[i] << endl;
    }
};

int Tree::treeCount = 0; // Member definition
string Tree::descr[] = {"Firs", "Pine", "Oak"};

int main()
{
    cout << "Get treeCount, using static member function from a class:"
        << Tree::getTreeCountStatic();

    Tree t1(0), t2(1);
    cout << endl << "Get treeCount, using a regular member function:"
        << t1.getTreeCount();

    cout << endl << "Get treeCount, using static member function from an object:"
        << t1.getTreeCountStatic();

    // Another use of static
    cout << endl << "Description of types of trees" << endl;
    Tree::printDescr();

    //Access static member through regular member function
    cout << endl << t1.getDescr();


    return 0;
}
