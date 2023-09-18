// 2_10_C-string

/*
C++ has a library of functions for C-strings. An argument can be:
- Name of array holding the C-string
- pointer to the array
- string literal
Some examples below

A C-string is stored in memory as an array of charts with a null terminator at the end
It's valid to define an array of chars without a null terminator, but it's not a valid C-string
Arrays of chars are an exception: When you cout the name of an array holding a C-string,
it prints the C-string instead of the address of the array -
*/

#include <iostream>
#include <cstring>
#include <cstdlib> // For the numeric conversion

using namespace std;

int main()
{
    // strlen
    cout << strlen("Hello") << endl; // string literal as argument
    char myArr[40] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cout << strlen(myArr) << endl; // array as argument
    char * charPtr = myArr;
    cout << strlen(charPtr) << endl; // Pointer as argument

    // strcat
    cout << endl << "strcat" << endl;
    strcat(myArr, " there!");
    cout << myArr << endl; // cout the array name, it prints the C-string

    // strcmp
    cout << endl << "strcmp" << endl;
    cout << strcmp("Hello", "Hellp") << endl;
    cout << strcmp("Hellp", "Hello") << endl;
    cout << strcmp("Hello", myArr) << endl;
    cout << strcmp("Hello there!", myArr) << endl;

    // atoi
    cout << endl << "atoi" << endl;
    cout << atoi("123") - 120 << endl;
    cout << atof("123.45") + 1000 << endl;
    cout << atoi("123$") << endl;


    return 0;
}
