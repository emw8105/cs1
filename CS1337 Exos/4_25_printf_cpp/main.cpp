// copied from 4_20_printf to pass zylabs cpp file
/*
printf has this format: printf(format-control-string, zero or more arguments)
format-control-string is always in double quotes
format-control-string has zero or more conversion specifications and zero
or more character literals
%e and %E will print floating point in scientific notation
%f will print floating point data with a decimal point, with 6 digits
after the point by default
%g and %G will print floating point data in scientific notation if the
value is very large or very small, fixed point otherwise
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n"); // format control string has zero
    // conversion specification and 13 character literals

    // Print integers
    int num1 = 10;

    // %d prints in decimal
    printf("num1 with the d specifier (decimal) is %d, 5 in decimal is %d\n",
           num1, 5);

    // %i also prints in decimal
    printf("num1 with the i specifier is %i, 5 in decimal is %d\n",
           num1, 5);

    // %u prints in unsigned
    printf("num1 with the u specifier is %u, 5 in decimal is %d\n",
           num1, 5);

    // %o prints in base 8 (octal)

    printf("num1 with the o specifier is %o, 5 in decimal is %d\n",
           num1, 5);

    // %x prints in base 16 (hexadecimal)
    printf("num1 with the x specifier is %x, 5 in decimal is %d\n",
           num1, 5);

    // %X prints in base 16 (hexadecimal)
    printf("num1 with the X specifier is %X, 5 in decimal is %d\n",
           num1, 5);

    // Floating point
    printf("\nFloating point\n");
    printf("1234567.89 with the %%e specifier is %e\n", 1234567.89);
    printf("1234567.89 with the %%f specifier is %f\n", 1234567.89);
    printf("1234567.89 with the %%g specifier is %g\n", 1234567.89);

    printf("0.000000123456789 with the %%e specifier is %e\n", 0.000000123456789);
    printf("0.000000123456789 with the %%f specifier is %f\n", 0.000000123456789);
    printf("0.000000123456789 with the %%g specifier is %g\n", 0.000000123456789);

    printf("123.456 with the with the %%e specifier is %e\n", 123.456);
    printf("123.456 with the with the %%f specifier is %f\n", 123.456);
    printf("123.456 with the with the %%g specifier is %g\n", 123.456);

    //Precision
    printf("\nPrecision\n");
    printf("0.000000123456789 with the %%15.13f specifier is %15.13f", 0.000000123456789);
    printf("0.000000123456789 with the %%15.6g specifier is %15.6g", 0.000000123456789);

    // Chars and strings
    printf("\nChars and strings\n");
    printf("My char is %c\n", 'd');
    char c = 'a';
    printf("My char is %c\n", c);
    char myString[] = "Hi there";
    printf("%s\n", myString);

    // Pointer
    int num = 5;
    printf("\nPointers\n");
    printf("Address of num is %p\n", (void *) &num); // Type cast to void*

    return 0;
}
