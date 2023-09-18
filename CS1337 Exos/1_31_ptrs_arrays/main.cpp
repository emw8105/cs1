// 1_31_ptrs_arrays

/*
Array name is starting address of array
Array name can be used like a constant pointer (you are not allowed to change its value)
Everything about pointers applies to array names, except that you cannot modify them
You can use an array name like a pointer, e.g. *arr
You can use a pointer like an array name, e.g. intPtr[1]
Ptr arithmetic: Value of (intPtr + 1) = intPtr + 1 * (size of the data type)
(intPtr + i) will point to the location i ints down from intPtr
*(intPtr+i), *(arr+1), arr[i], intPtr[i] are all equivalent, assuming intPtr holds arr

*/

/*
#include <iostream>

using namespace std;

int main()
{
    cout << "Array name is starting address of array" << endl;

    const int SIZ = 4;
    int arr[SIZ] = {10, 20, 30, 40};

    cout << "Value of arr[0] is " << arr[0] << endl;
    cout << "Address of arr is " << arr << endl;
    cout << "Address of arr[0] is " << &arr[0] << endl; // use the address operator on that particular element

    // Pointers can be used like an array name
    int  * intPtr = arr;
    cout << endl << "Pointers can be used like an array name" << endl;
    cout << "Display array content using intPtr[i] notation" << endl;
    for (int i = 0; i < SIZ; i++)
        cout << intPtr[i] << endl;

    // Array name can be used like a constant pointer
    cout << endl << "Array name can be used like a constant pointer" << endl;
    cout << "Display array content using *arr notation" << endl;
    cout << "*arr is " << *arr << endl;

    // Pointer arithmetic
    cout << "Value of intPtr is " << intPtr << endl;
    cout << "Value of (intPtr+1) is " << (intPtr+1) << endl;
    cout << "Value of (intPtr+2) is " << (intPtr+2) << endl;
    cout << "Value of (intPtr-1) is " << (intPtr-1) << endl;
    cout << "One int takes " << sizeof(int) << " bytes" << endl;

    // Use ptr arithmetic to access the elements of an array
    cout << endl << "Use *(intPtr+i) notation to access array elements" << endl;
    intPtr = arr;
    for (int i = 0; i < SIZ; i++)
        cout << *(intPtr+i) << endl; // Same as intPtr[i]

    // Use ptr arithmetic on the array name to access array elements
    cout << endl << "Use *(arr+i) notation to access array elements" << endl;
    for (int i = 0; i < SIZ; i++)
        cout << *(arr+i) << endl;

    return 0;
}

*/
#include <iostream>

using namespace std;

/*
- Array name is starting address of array
- Array name can be used like a constant pointer (you are not allowed to change its value)
- Everything about pointers applies to array names, except that you cannot modify them
- You can use an array name like a pointer, e.g. *arr
- You can use a pointer like an array name, e.g. dPtr[0]
- Pointer arithmetic: Value of (intPtr+i) = intPtr + i * (size of an int)
- (intPtr+i) will point to the location i ints down from intPtr
- *(intPtr+i), *(arr+i), arr[i], intPtr[i] are equivalent, assuming intPtr holds arr
*/
int main()
{
    cout << "Array name is starting address of array" << endl;

    const int SIZ = 4;
    int arr[SIZ] = {10, 20, 30, 40};

    cout << "Value of arr[0] is " << arr[0] << endl;
    cout << "Address of arr is " << arr << endl; // Array name is the starting address of the array
    cout << "Address of arr[0] is " << &arr[0] << endl;

    // Pointers can be used like an array name
    int * intPtr = arr;
    cout << endl << "Pointers can be used like an array name" << endl;
    cout << "Display array content using intPtr[i] notation" << endl;
    for (int i = 0; i < SIZ; i++)
        cout << intPtr[i] << endl;

    // Array name can be used like a constant pointer
    cout << endl << "Array name can be used like a constant pointer" << endl;
    cout << "Display array content using *arr notation" << endl;
    cout << "*arr is " << *arr << endl; // Dereference the array name, as with a pointer

    // Pointer arithmetic
    cout << "Value of intPtr is " << intPtr << endl;
    cout << "Value of (intPtr+1) is " << (intPtr+1) << endl;
    cout << "Value of (intPtr+2) is " << (intPtr+2) << endl;
    cout << "Value of (intPtr-1) is " << (intPtr-1) << endl;
    cout << "One int takes " << sizeof(int) << " bytes" << endl;

    // Use pointer arithmetic on a pointer to access the elements of an array
    cout << "\nUse *(intPtr+i) notation to access array elements" << endl;
    intPtr = arr;
    for (int i = 0; i < SIZ; i++)
        cout << *(intPtr+i) << endl; // *(intPtr+i) is the same as intPtr[i]

    // Use pointer arithmetic on the array name to access the elements of an array
    cout << "\nUse *(arr+i) notation to access array elements" << endl;
    for (int i = 0; i < SIZ; i++)
        cout << *(arr+i) << endl; // *(intPtr+i) is the same as arr[i]

    return 0;
}
