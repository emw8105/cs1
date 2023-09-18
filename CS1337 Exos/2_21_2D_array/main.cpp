// 2_21_2D_array

/*
To initialize a 2D array with a list, provide 1D lists, one for each row.
Initialization will be done row by row

When a 2D array is passed to a function, the array name (address of the array)
is passed to the function.
The number of columns (2nd dimension) must always be provided in the
function prototype and function header
If the function needs to know the number of rows, it must be provided as an
additional argument
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_STUDENTS = 4;
const int NUM_TESTS = 3;

void print2DArray(double a[][NUM_TESTS], int numRows);

int main()
{
    double score[NUM_STUDENTS][NUM_TESTS] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}, {100, 110, 120}};
    // Initialization is done row by row with 1D initialization lists

    // Print array
    cout << "Content of score array" << endl;
    print2DArray(score, NUM_STUDENTS);

    return 0;
}

void print2DArray(double a[][NUM_TESTS], int numRows)
{
    for (int student = 0; student < numRows; student++)
    {
        for (int test = 0; test < NUM_TESTS; test++)
        {
            cout << setw(7) << a[student][test];
        }
        cout << endl;
    }
}
