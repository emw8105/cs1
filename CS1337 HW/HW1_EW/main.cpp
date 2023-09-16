/*Author: Evan Wright
Compiler: GNU GCC
Date: 2/7/2022
Purpose of program:
The program is provided a file with a list of students and their respective netID's,
majors, and GPA's. The program extracts the data into arrays and sorts them as
necessary using the bubble sort method. It prompts the user, and upon receiving input,
can list the top n students by GPA or search for a specific student using both linear
and binary search. The program tracks the number of iterations for both searches and
outputs it along with the index of the netID being searched and the corresponding GPA
of that student
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

int linearSearchID(int arr[], int numElems, int value, int &nIter);
int binarySearchID(int arr[], int numElems, int value, int &nIter);
void modifiedSortGPA(double array1[], int array2[], string array3[], int size);
void modifiedSortID(int array2[], double array1[], string array3[], int size);


int main()
{
    const int NUM_ELMTS = 18;

    // netID, major and GPA are parallel arrays
    int netID[NUM_ELMTS]; // Original netID array
    string major[NUM_ELMTS]; // Original major array
    double GPA[NUM_ELMTS]; // Original GPA array

    // sortedGPAbyGPA is sorted by GPA, and sortedNetIDbyGPA and sortedMajorbyGPA are parallel arrays
    double sortedGPAbyGPA[NUM_ELMTS]; // GPA array, sorted by GPA
    int sortedNetIDbyGPA[NUM_ELMTS];
    string sortedMajorbyGPA[NUM_ELMTS];

    // sortedNetIDbyID is sorted by netID, and sortedMajorbyID and sortedGPAbyID are parallel arrays
    int sortedNetIDbyID[NUM_ELMTS]; // netID array,sorted by netID
    string sortedMajorbyID[NUM_ELMTS];
    double sortedGPAbyID[NUM_ELMTS];


    string fileName; // prompt user and receive inputted file name
    cout << "Enter file name: ";
    cin >> fileName;
    ifstream inFile;

    inFile.open(fileName); // open the file specified by the user
    if (inFile.fail()) // test for file open failure or empty file
    {
        cout << "Could not open file" << endl;
        cout << "Exiting" << endl;
        inFile.close();
        exit(EXIT_FAILURE);
    }
    else
    {
        int counter; // tracks the number of elements in the file
        for (counter = 0; counter < NUM_ELMTS; counter++)
        {
            if (inFile >> netID[counter] >> major[counter] >> GPA[counter]) // copy file contents to array
            {
                sortedNetIDbyGPA[counter] = netID[counter]; // make parallel arrays for corresponding data
                sortedGPAbyGPA[counter] = GPA[counter];
                sortedMajorbyGPA[counter] = major[counter];

                sortedNetIDbyID[counter] = netID[counter]; // make parallel arrays for corresponding data
                sortedGPAbyID[counter] = GPA[counter];
                sortedMajorbyID[counter] = major[counter];
            }
            else
            {
                break; // if there isn't any more data in the file, stop the loop
            }
        }
        inFile.close(); // close the file after use


        modifiedSortID(sortedNetIDbyID, sortedGPAbyID, sortedMajorbyID, counter); // sort respective arrays by netID
        modifiedSortGPA(sortedGPAbyGPA, sortedNetIDbyGPA, sortedMajorbyGPA, counter); // sort respective arrays by GPA

        // begin outputting all of the array information into a table
        cout << fixed;
        cout << "Original arrays:" << endl << "----------------" << endl;
        cout << setw(7) << "index" << setw(7) << "netID" << setw(7) << "major" << setw(6) << "GPA" << setw(7) << "index" << setw(7)
             << "netID" << setw(7) << "major" << setw(6) << "GPA";
        for (int i = 0; i < counter; i++) // loop thru the array and output all the elements of the array in the table
        {
            if (i % 2 == 0)
            {
                cout << endl;
            }
            cout << setw(7) << i << setw(7) << netID[i] << setw(7) << major[i] << setw(6) << setprecision(2) <<  GPA[i];
        }

        // output all of the information for arrays sorted by GPA
        cout << endl << endl << "Arrays sorted by GPA:" << endl << "---------------------" << endl;
        cout << setw(7) << "index" << setw(7) << "netID" << setw(7) << "major" << setw(6) << "GPA" << setw(7) << "index" << setw(7)
             << "netID" << setw(7) << "major" << setw(6) << "GPA";
        for (int i = 0; i < counter; i++) // loop thru the GPA sorted array and output all the elements of the array in the table
        {
            if (i % 2 == 0)
            {
                cout << endl;
            }
            cout << setw(7) << i << setw(7) << sortedNetIDbyGPA[i] << setw(7) << sortedMajorbyGPA[i] << setw(6) << setprecision(2) <<  sortedGPAbyGPA[i];
        }

        // output all of the information for arrays sorted by netID
        cout << endl << endl << "Arrays sorted by netID:" << endl << "-----------------------" << endl;
        cout << setw(7) << "index" << setw(7) << "netID" << setw(7) << "major" << setw(6) << "GPA" << setw(7) << "index" << setw(7)
             << "netID" << setw(7) << "major" << setw(6) << "GPA";
        for (int i = 0; i < counter; i++) // loop thru the netID sorted array and output all the elements of the array in the table
        {
            if (i % 2 == 0)
            {
                cout << endl;
            }
            cout << setw(7) << i << setw(7) << sortedNetIDbyID[i] << setw(7) << sortedMajorbyID[i] << setw(6) << setprecision(2) <<  sortedGPAbyID[i];
        }

        int menuChoice; // repeat until the menu choice corresponds with user indication to quit
        while (menuChoice != 3)
        {
            cout << endl << endl << "***************" << endl << "Menu of choices" << endl << "***************" << endl;
            cout << "1 - List top n students" << endl << "2 - Search on a netID" << endl << "3- Quit" << endl;
            cin >> menuChoice; // prompt user and receive input

            if (menuChoice == 1) // list the top n amount of students by GPA
            {
                int numTopStudents;
                int sortIndex = counter - 1;
                cout << "Enter n: "; // prompt user for number of student cutoff point
                cin >> numTopStudents;
                if (numTopStudents > counter) // prevents array overflow error by outputting as many elements as possible
                {
                    numTopStudents = counter;
                }
                cout << "Top 10 students are:" << endl << endl;
                for (int i = 0; i < numTopStudents; i++) // output respective students with corresponding major and GPA
                {
                    cout << "netID: " << sortedNetIDbyGPA[sortIndex] << ", major: " << sortedMajorbyGPA[sortIndex]
                    << ", GPA: " << sortedGPAbyGPA[sortIndex] << endl;
                    sortIndex--;
                }
            }
            else if (menuChoice == 2) // search by netID
            {
                int numIter = 0;
                int netIDSearch;
                cout << "Enter netID: "; // prompt user for netID to search and receive input
                cin >> netIDSearch;

                cout << "Result of linear search:" << endl << "------------------------" << endl;
                int linSearchPos = linearSearchID(netID, counter, netIDSearch, numIter);
                if (linSearchPos == -1) // if the function returns -1, then there was no netID that matched the user's given one
                {
                    cout << "Student not found" << endl;
                }
                else // if the function returns anything else, it would correspond to the index of the respective netID
                {
                    cout << "Student found at index " << linSearchPos << ", GPA is " << GPA[linSearchPos];
                }
                cout << endl << "It took " << numIter << " iterations" << endl;

                cout << endl << "Result of binary search:" << endl << "------------------------" << endl;
                int binSearchPos = binarySearchID(sortedNetIDbyID, counter, netIDSearch, numIter);
                if (binSearchPos == -1) // if the function returns -1, then there was no netID that matched the user's given one
                {
                    cout << "Student not found" << endl;
                }
                else // if the function returns anything else, it would correspond to the index of the respective netID
                {
                    cout << "Student found at index " << binSearchPos << ", GPA is " << sortedGPAbyID[binSearchPos];
                }
                cout << endl << "It took " << numIter << " iterations" << endl;
            }
            else if (menuChoice == 3) // menu choice for quitting the program, exits the loop finishes the program
            {
                cout << "Exiting";
            }
        }

    }
    return 0;
}

/* This function implements linear search on an array. It takes the following arguments:
arr: the array, numElems: number of elements of array,
value: search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index where the match is found, -1 if no
match is found
*/


int linearSearchID(int arr[], int numElems, int value, int &nIter)
{
    nIter = 0;
    bool found = false;
    int index = 0;
    int position = -1;
    while (index < numElems && found == false)
    {
        nIter++;

        if (arr[index] == value)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}

/* This function implements binary search on an array. It takes the following arguments:
arr: the array, numElems: number of elements of array,
value: search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index where the match is found, -1 if no
match is found
*/
int binarySearchID(int arr[], int numElems, int value, int &nIter)
{
    nIter = 0;
    int first = 0, last = numElems -1, middle, position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (last + first) / 2;
        if (arr[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (arr[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;

        nIter++;
    }
    return position;

}

/* This function sorts array1 and maintains the parallelism
of array2, and array3
Whenever elements of array1 are swapped, the elements of array 2
and array3 at the same indices are also swapped
*/
void modifiedSortGPA(double array1[], int array2[], string array3[], int size)
{
    int lastElement;
    int index;

    for (lastElement = size - 1; lastElement > 0; lastElement--)
    {
        for (index = 0; index < lastElement; index++)
        {
            if (array1[index] > array1[index + 1])
            {
                swap(array2[index], array2[index + 1]);
                swap(array1[index], array1[index + 1]);
                swap(array3[index], array3[index + 1]);
            }
        }
    }
}

/* This function sorts array2 and maintains the parallelism
of array1 and array3
Whenever elements of array2 are swapped, the elements of array 1
and array3 at the same indices are also swapped
*/
void modifiedSortID(int array2[], double array1[], string array3[], int size)
{
    int maxElement;
    int index;

    for (maxElement = size - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (array2[index] > array2[index + 1])
            {
                swap(array2[index], array2[index + 1]);
                swap(array1[index], array1[index + 1]);
                swap(array3[index], array3[index + 1]);
            }
        }
    }
}
