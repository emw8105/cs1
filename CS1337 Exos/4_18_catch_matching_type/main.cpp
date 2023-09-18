// 4_18_catch_matching_type

/*
Exceptions can be used to handle abnormal conditions in a
controlled and flexible manner

An exception can be an object or a variable. It's used like
a signal

The code that detects the abnormal condition throws the exception
It's executed when a try block is executed

Another part of the code catches the exception and handles it
(exception handler). It's inside a catch block

If the types of the exception and what the catch is trying
to catch have to match, the catch block will not catch it

If you throw an exception outside of a try block, it will not
be caught

If an exception is not caught, the program will terminate
*/

#include <iostream>

using namespace std;

double divide(double num, double denom);

int main()
{
    double x, y, res;
    cout << "Enter x then y:";
    cin >> x >> y;

    try
    {
        res = divide(x,y);
        cout << "Result of division is " << res << endl;
    }
    catch(string str)
    {
        cout << "ERROR: " << str << endl;
    }

    /*catch(string) // both catch statements work
    {
        cout << "ERROR: " << endl;
    }*/

    cout << "Done\n";
    return 0;
}

double divide(double num, double denom)
{
    if (denom == 0)
    {
        string exceptionMsg = "Divide by zero";
        throw exceptionMsg;
    }
    else
        return num/denom;
}
