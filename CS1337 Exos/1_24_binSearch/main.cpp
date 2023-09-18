// 1_24_binSearch

#include <iostream>
#include <iomanip>

using namespace std;

const int ARR_SIZE = 10;

int linSearch(int arr[], int siz, int searchValue);
int binSearch(int arr[], int siz, int searchValue);

int main()
{
    int Arr[ARR_SIZE] = {1, 5, 8, 2, 6, 7, 9, 45, 22, 12};
    int sortedArr[ARR_SIZE] = {1, 2, 5, 6, 7, 8, 9, 12, 22, 45};

    int val;

    cout << "Array: " << endl;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << setw(6) << Arr[i];
        if ((i + 1) % 5 == 0)
            cout << endl;
    }

    cout << "Sorted array: " << endl;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << setw(6) << sortedArr[i];
        if ((i + 1) % 5 == 0)
            cout << endl;
    }

    cout << "Enter search value: ";
    cin >> val;
    cout << "Position in array is " << linSearch(Arr, ARR_SIZE, val) << endl;
    cout << "Position in sorted array is " << binSearch(sortedArr, ARR_SIZE, val) << endl;

    return 0;
}

int linSearch(int arr[], int siz, int searchValue)
{
    int ind = 0, position = -1;
    bool notFound = true;

    while (ind < siz && notFound)
    {
        if (arr[ind] == searchValue)
        {
            notFound = false;
            position = ind;
        }
        ind++;
    }
    return position;
}

int binSearch(int arr[], int siz, int searchValue)
{
    int first = 0, last = siz - 1;
    bool notFound = true;
    int position = -1;
    int middle;

    while(notFound && first <= last)
    {
        middle = (first + last)/2;
        if (arr[middle] < searchValue)
        {
            first = middle + 1;
        }
        else if (arr[middle] > searchValue)
        {
            last = middle - 1;
        }
        else
        {
            notFound = false;
            position = middle;
        }
    }
    return position;
}
