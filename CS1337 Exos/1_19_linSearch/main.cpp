// 1_19_linSearch

#include <iostream>
#include <iomanip>

using namespace std;

const int ARR_SIZE = 10;

int linSearch(int arr[], int siz, int searchValue);

int main()
{
    int Arr[ARR_SIZE] = {1, 5, 8, 2, 6, 7, 9, 45, 22, 12};
    int val;

    cout << "Array: " << endl;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << setw(6) << Arr[i];
        if ((i + 1) % 5 == 0)
            cout << endl;
    }

    cout << "Enter search value: ";
    cin >> val;
    cout << "Position in array is " << linSearch(Arr, ARR_SIZE, val) << endl;

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
