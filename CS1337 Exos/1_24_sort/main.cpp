// 1_24_sort

#include <iostream>
#include <iomanip>

using namespace std;

const int ARR_SIZE = 50;

void selectionSort(int arr[], int siz);

int main()
{
    int Arr[ARR_SIZE];

    // Populate the array
    for (int i = 0; i < ARR_SIZE; i++)
    {
        Arr[i] = rand();
    }

    cout << "Array: " << endl;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << setw(12) << Arr[i];
        if ((i + 1) % 4 == 0)
            cout << endl;
    }

    selectionSort(Arr, ARR_SIZE);

    cout << endl << "Sorted array: " << endl;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << setw(12) << Arr[i];
        if ((i + 1) % 4 == 0)
            cout << endl;
    }

    return 0;
}

void selectionSort(int arr[], int siz)
{
    int start, minIndex, minValue;
    for (start = 0; start < (siz - 1); start++)
    {
        minIndex = start;
        minValue = arr[start];
        for (int ind = start + 1; ind < siz; ind++) // Loop over remaining array to find the minimum
        {
            if (arr[ind] < minValue)
            {
                minValue = arr[ind];
                minIndex = ind;
            }
        }

        arr[minIndex] = arr[start]; // Swap min value found with the 1st element of the remaining array
        arr[start] = minValue;
    }
}
