// 2_11_Cpp_string_class

/*
C++ has a library of functions for C++ string class. Examples:
getline(cin, myString) reads the whole line and puts into myString
Relational operators: e.g. str1 < str2
Can initialize a string with a literal, another string, or a char array (C-string)
+ means concatenation
[] references a character in the string
.length member function returns the number of characters
Many other functions
*/

#include <iostream>

using namespace std;

int main()
{
    // getline
    string name;
    cout << "Input your name: ";
    getline(cin, name);
    cout << "Name is " << name << endl;

    // Initialize strings
    string myOtherString("Chris"); // Initialize with string literal
    string myStr(myOtherString); // Initialize with existing C++ string class
    cout << "myStr is " << myStr << ", myOtherString is " << myOtherString << endl;
    char myArr[40] = {'J', 'o', 'e', '\0'}; // = "Joe"; the compiler automatically adds a null terminator

    string mySecondStr(myArr); // Initialize with char array (C-string)
    cout << "myArr is " << myArr << ", mySecondStr " << mySecondStr << endl;

    // Reference a char in a C++ string class
    cout << endl << "2nd character of myStr is " << myStr[1] << endl;

    // length member function
    cout << "Length of myStr is " << myStr.length();


    return 0;
}
