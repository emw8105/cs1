// 1_26_ptrs_arrays

#include <iostream>

using namespace std;

int main()
{
    cout << "Array name is starting address of array" << endl;

    const int SIZ = 4;
    int arr[SIZ] = {10, 20, 30, 40};

    cout << "Value of arr[0] is " << arr[0] << endl;
    cout << "Address of arr is " << arr << endl;
    cout << "Address of arr[0] is " << &arr[0] << endl;

    // Pointers can be used like an array name
    int* intPtr = arr;
    cout << endl << "Pointers can be used like an array name" << endl;
    cout << "Display array content using intPtr[i] notation" << endl;
    for (int i = 0; i < SIZ; i++)
        cout << intPtr[i] << endl;

    // Array name can be used like a constant ptr
    cout << endl << "Array name can be used like a constant pointer" << endl;
    cout << "Display array content using *arr notation" << endl;
    cout << "*arr is " << *arr << endl;

    // Pointer arithmetic
    cout << "Value of intPtr is " << intPtr << endl;
    cout << "Value of (intPtr+1) is " << (intPtr+1) << endl;
    cout << "Value of (intPtr+2) is " << (intPtr+2) << endl;
    cout << "Value of (intPtr-1) is " << (intPtr-1) << endl;
    cout << "One int takes " << sizeof(int) << " bytes"<< endl;


    return 0;
}
