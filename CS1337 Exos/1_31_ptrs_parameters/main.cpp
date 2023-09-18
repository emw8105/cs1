// 1_31_ptrs_parameters

/*
A pointer can be an argument to a function
With ptrs, the function can modify the original data
Works like a reference variable
Difference is that with ref variables, you cannot assign an address
or do pointer arithmetic

1) Use * in parameter list in function prototype and function header
2) Use * inside the function to access the data
3) When you call the function, pass an address as argument
*/

#include <iostream>

using namespace std;

void swapByPtr(double * dbPtr1, double * dbPtr2);
void swapByRef(double & db1, double & db2);


int main()
{
    double d1 = 10.5, d2 = 5.6;
    cout << "d1 = " << d1 << ", d2 = " << d2 << endl;
    swapByRef(d1, d2);
    cout << "d1 = " << d1 << ", d2 = " << d2 << endl;
    swapByPtr(&d1, &d2);
    cout << "d1 = " << d1 << ", d2 = " << d2 << endl;

}

void swapByPtr(double * dbPtr1, double * dbPtr2)
{
    double temp = *dbPtr1;
    *dbPtr1 = *dbPtr2;
    *dbPtr2 = temp;
    dbPtr2 = dbPtr2 + 1; // not possible with reference variable
}

void swapByRef(double & db1, double & db2)
{
    double temp = db1;
    db1 = db2;
    db2 = temp;
}
