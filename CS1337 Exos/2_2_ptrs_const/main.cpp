// 2_2_ptrs_const

/*
1) Ptr to constant
The compiler won't allow the function to modify the "pointed at" data, but the pointer value (address)
can be modified
If the original data was declared constant (rate array in this Exo), must have constant data in the parameter
list of the function

If the original data was not declared constant (rate2 array in this Exo), it's good practice to declare the data
constant if the function is not supposed to modify the data

2) Constant ptr
The address cannot be changed, but the data can be changed
MUST initialize the pointer at definition time

3) Constant ptr to constant
Both the data and the address cannot be changed
MUST initialize the pointer at definition

Principle of least privilege: Give a function the minimum rights to do its job, but no more
*/

#include <iostream>

using namespace std;

void printArray(const double * dbPtr, int siz);
void printArray2(const double * const dbPtr, int siz);
void setToPI(double * const dbPtr, int siz);

int main()
{
    const int ARR_SIZ = 4;
    const double rate [ARR_SIZ] = {20, 25, 30, 35};
    double rate2[ARR_SIZ] = {100, 200, 300, 400};

    printArray(rate, ARR_SIZ);
    cout << endl;
    printArray(rate2, ARR_SIZ);

    double val = 100;
    double * dbPtr = &val;
    setToPI(dbPtr, 1);
    cout << endl << "val = " << val << endl;

    setToPI(rate2, ARR_SIZ);
    printArray(rate2, ARR_SIZ);

    return 0;
}

// we don't modify the data so the array elements are const, but the ptr is not const
void printArray(const double * dbPtr, int siz) // Ptr to constant
{
    for (int i = 0; i < siz ; i++)
    {
        cout  << *dbPtr << endl;
        dbPtr++; // pointer now points to next array element
    }
}

void printArray2(const double * const dbPtr, int siz) // Constant ptr to constant
{
    for (int i = 0; i < siz; i++)
    {
        cout << *(dbPtr + i) << endl; // equivalent to dbPtr[i]
    }
}

void setToPI(double * const dbPtr, int siz) // Constant ptr
{
    for (int i = 0; i < siz; i++)
    {
        *(dbPtr + i) = 3.1416;

    }
}
