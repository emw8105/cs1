// 2_2_malloc

/*
With dynamic memory allocation, a program, during execution, asks for a chunk of memory large
enough to hold a variable (or an array) of a specific type
The computer returns the address of the chunk that is allocated
Program needs a ptr to store the address
Dynamic allocation is useful when you don't know how much storage you need when you write
the program
When the chunk is no longer needed, you should return it using delete
*/

#include <iostream>

using namespace std;

int main()
{
    int numTests;

    cout << "Enter the number of tests: " << endl;
    cin >> numTests;

    // Dynamically allocate an array of the right size
    double * testPtr = new double[numTests]; // Use [] for array

    // Use the array
    for(int i = 0; i < numTests; i++)
    {
        cout << "Enter the score: ";
        cin >> testPtr[i];
    }

    cout << "Test scores are: " << endl;
    for (int i = 0; i < numTests; i++)
        cout << testPtr[i] << endl;

    // Can also allocate for a single variable
    int * intPtr = new int;

    // Release memory when no longer needed
    delete [] testPtr;
    delete intPtr;
    testPtr = nullptr;
    intPtr = nullptr;

    return 0;
}
