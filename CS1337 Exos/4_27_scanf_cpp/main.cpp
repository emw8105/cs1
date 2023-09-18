// 4_25_scanf

/*
scanf format is scanf(format-control-string, one or more arguments)
Arguments are referred to by their addresses (use & operator)
Many conversion specifiers are common with printf
With %i, the user can enter a value in decimal, octal, or hexadecimal
%f, %e, %g are interchangeable for floating points
To read a string, the argument is the array name (no need for &)
The field width can be used to limit the number of chars read
%n will return the number of characters typed so far in the current scanf
The same left over character issue as in C++ exists: need to flush
the buffer before a scanf("%c", ...)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num;
    unsigned num2, num3; // %o and %x must be positive
    float flt1, flt2, flt3, flt;
    double doub;

    // Read in decimal, hex and octal
    printf("Enter 3 numbers in decimal, hexadecimal and octal: ");
    scanf("%d%x%o", &num1, &num2, &num3);
    printf("Numbers in decimal are %d, %d, %d\n", num1, num2, num3);

    // %i specifier
    printf("Enter a decimal, octal (prepend 0), or a hex number (prepend 0x): ");
    scanf("%i", &num);
    printf("Value entered is %d\n", num);

    // Floating point: %e, %f, and %g are interchangeable
    printf("Enter 3 floating point numbers: ");
    scanf("%e%f%g", &flt1, &flt2, &flt3);
    printf("flt1 = %f, flt2 = %f, flt3 = %f\n", flt1, flt2, flt3);

    // Mix various types
    printf("Enter an int, a float and a double: ");
    scanf("%d%f%lf", &num, &flt, &doub); // Use %f for float, %if for double
    printf("num = %d, flt = %f, doub = %lf\n", num, flt, doub);

    // Character and string
    char c;
    printf("Enter a character: ");
    scanf("%c", &c); // Flush the buffer of the leftover new line
    scanf("%c", &c);
    printf("Char entered is %c\n");
    char myStr[10];
    printf("Enter a string: ");
    scanf("%s", myStr); // myStr is the address of the array, no need for &
    printf("String entered is %s\n", myStr);

    // Use fieldwidth to limit the number of characters written into the array
    // to avoid overflowing the array
    // Use %n specifier to know how many characters have been inputted so far
    // in the current scanf
    int count1, count2;
    printf("Enter a string, max 9 characters and an int: ");
    scanf("%9s%n%d%n", myStr, &count1, &num, &count2);
    printf("String entered is %s, int entered is %d\n", myStr, num);
    printf("%d chars have been entered after the string, and %d chars entered after the int\n",
           count1, count2);

    // Scanset
    char str[10];
    printf("Scanset is [aeiou], enter string: ");
    scanf("%c", &c); // Flush the buffer
    scanf("%[aeiou]", str);
    printf("The input was \"%s\"", str);

    // Suppression character
    int m, d, y;
    printf("Enter a date in the form mm-dd-yyyy: ");
    while((getchar()) != '\n'); // Flush the buffer
    scanf("%c", &c); // Flush the buffer
    scanf("%d%*c%d%*c%d", &m, &d, &y);
    printf("d = %d, m = %d, y = %d\n", m, d, y);

    return 0;
}
