/*Author: Evan Wright
Compiler: GNU GCC
Date: 3/7/2022
Purpose of program:

*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

struct Student
{
    int netID;
    string major;
    double GPA;
};

void modifiedSortGPA(Student array1[], int siz);
void modifiedSortID(Student array2[], int siz);
int linearSearchID(Student arr[], int numElems, int value, int &nIter);
int binarySearchID(Student arr[], int numElems, int value, int &nIter);

int main()
{
    const int NUM_ELMTS = 18;

    // Original array of Student structures
    Student studArray[NUM_ELMTS];

    // Array sorted by GPA
    Student studArraysortedbyGPA[NUM_ELMTS];

    // Array sorted by netID
    Student studArraysortedbyID[NUM_ELMTS];


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
        int i;
        for (i = 0; i < NUM_ELMTS; i++)
        {
            if (inFile >> studArray[i].netID >> studArray[i].major >> studArray[i].GPA) // copy file contents to array
            {
                studArraysortedbyGPA[i].netID = studArray[i].netID;
                studArraysortedbyGPA[i].major = studArray[i].major;
                studArraysortedbyGPA[i].GPA = studArray[i].GPA;

                studArraysortedbyID[i].netID = studArray[i].netID;
                studArraysortedbyID[i].major = studArray[i].major;
                studArraysortedbyID[i].GPA = studArray[i].GPA;
            }
            else
            {
                break; // if there isn't any more data in the file, stop the loop
            }
        }
        inFile.close(); // close the file after use

        modifiedSortID(studArraysortedbyID, i);
        modifiedSortGPA(studArraysortedbyGPA, i);

        cout << fixed;
        cout << "Original array:" << endl << "---------------" << endl;
        cout << setw(7) << "index" << setw(7) << "netID" << setw(7) << "major" << setw(6) << "GPA" << setw(7) << "index" << setw(7)
             << "netID" << setw(7) << "major" << setw(6) << "GPA";
        for (int counter = 0; counter < i; counter++) // loop thru the array and output all the elements of the array in the table
        {
            if (counter % 2 == 0)
            {
                cout << endl;
            }
            cout << setw(7) << counter << setw(7) << studArray[counter].netID << setw(7) << studArray[counter].major
                 << setw(6) << setprecision(2) <<  studArray[counter].GPA;
        }
        // output all of the information for arrays sorted by GPA
        cout << endl << "Array sorted by GPA:" << endl << "--------------------" << endl;
        cout << setw(7) << "index" << setw(7) << "netID" << setw(7) << "major" << setw(6) << "GPA" << setw(7) << "index" << setw(7)
             << "netID" << setw(7) << "major" << setw(6) << "GPA";
        for (int counter = 0; counter < i; counter++) // loop thru the GPA sorted array and output all the elements of the array in the table
        {
            if (counter % 2 == 0)
            {
                cout << endl;
            }
            cout << setw(7) << counter << setw(7) << studArraysortedbyGPA[counter].netID << setw(7)
            << studArraysortedbyGPA[counter].major << setw(6) << setprecision(2) <<  studArraysortedbyGPA[counter].GPA;
        }

        // output all of the information for arrays sorted by netID
        cout << endl << "Array sorted by netID:" << endl << "----------------------" << endl;
        cout << setw(7) << "index" << setw(7) << "netID" << setw(7) << "major" << setw(6) << "GPA" << setw(7) << "index" << setw(7)
             << "netID" << setw(7) << "major" << setw(6) << "GPA";
        for (int counter = 0; counter < i; counter++) // loop thru the netID sorted array and output all the elements of the array in the table
        {
            if (counter % 2 == 0)
            {
                cout << endl;
            }
            cout << setw(7) << counter << setw(7) << studArraysortedbyID[counter].netID << setw(7)
            << studArraysortedbyID[counter].major << setw(6) << setprecision(2) <<  studArraysortedbyID[counter].GPA;
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
                int sortIndex = i - 1;
                cout << "Enter n: "; // prompt user for number of student cutoff point
                cin >> numTopStudents;
                if (numTopStudents > i) // prevents array overflow error by outputting as many elements as possible
                {
                    numTopStudents = i;
                }
                cout << "Top " << numTopStudents << " students are:" << endl << endl;
                for (int j = 0; j < numTopStudents; j++) // output respective students with corresponding major and GPA
                {
                    cout << "netID: " << studArraysortedbyGPA[sortIndex].netID << ", major: " << studArraysortedbyGPA[sortIndex].major
                    << ", GPA: " << studArraysortedbyGPA[sortIndex].GPA << endl;
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
                int linSearchPos = linearSearchID(studArray, i, netIDSearch, numIter);
                if (linSearchPos == -1) // if the function returns -1, then there was no netID that matched the user's given one
                {
                    cout << "Student not found" << endl;
                }
                else // if the function returns anything else, it would correspond to the index of the respective netID
                {
                    cout << "Student found at index " << linSearchPos << ", major is " << studArray[linSearchPos].major << ", GPA is " << studArray[linSearchPos].GPA;
                }
                cout << endl << "It took " << numIter << " iterations" << endl;

                cout << endl << "Result of binary search:" << endl << "------------------------" << endl;
                int binSearchPos = binarySearchID(studArraysortedbyID, i, netIDSearch, numIter);
                if (binSearchPos == -1) // if the function returns -1, then there was no netID that matched the user's given one
                {
                    cout << "Student not found" << endl;
                }
                else // if the function returns anything else, it would correspond to the index of the respective netID
                {
                    cout << "Student found at index " << binSearchPos << ", major is " << studArraysortedbyID[binSearchPos].major << ", GPA is " << studArraysortedbyID[binSearchPos].GPA;
                }
                cout << endl << "It took " << numIter << " iterations" << endl;
            }
            else if (menuChoice == 3) // menu choice for quitting the program, exits the loop finishes the program
            {
                cout << "Exiting";
            }
        }
    }
}

/* This function sorts the array of Student structures according to GPA
*/
void modifiedSortGPA(Student array1[], int siz)
{

    int maxElement;
    int index;

    for (maxElement = siz - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (array1[index].GPA > array1[index + 1].GPA)
            {
                Student temp = array1[index];
                array1[index] = array1[index + 1];
                array1[index + 1] = temp;
            }
        }
    }
}

/* This function sorts the array of Student structures according to netID
*/
void modifiedSortID(Student array2[], int siz)
{
    int maxElement;
    int index;

    for (maxElement = siz - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (array2[index].netID > array2[index + 1].netID)
            {

                //swap(array2[index], array2[index + 1]);

                Student temp = array2[index];
                array2[index] = array2[index + 1];
                array2[index + 1] = temp;
            }

        }
    }
}

/* This function implements linear search. It takes the following arguments:
arr: the array of Student structures, numElems: number of elements of array,
value: netID search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index of the structure where the match is found, -1 if no
match is found
*/
int linearSearchID(Student arr[], int numElems, int value, int &nIter)
{
    nIter = 0;
    bool found = false;
    int index = 0;
    int position = -1;
    while (index < numElems && found == false)
    {
        nIter++;

        if (arr[index].netID == value)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}

/* This function implements binary search. It takes the following arguments:
arr: the array of Student structures, numElems: number of elements of array,
value: netID search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index of the structure where the match is found, -1 if no
match is found
*/
int binarySearchID(Student arr[], int numElems, int value, int &nIter)
{
    nIter = 0;
    int first = 0, last = numElems -1, middle, position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (last + first) / 2;
        if (arr[middle].netID == value)
        {
            found = true;
            position = middle;
        }
        else if (arr[middle].netID > value)
            last = middle - 1;
        else
            first = middle + 1;

        nIter++;
    }
    return position;
}
