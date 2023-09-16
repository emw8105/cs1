/*Author: Evan Wright
Compiler: GNU GCC
Date: 2/15/2022
Purpose of program:
The program reads through a file specified by the user to obtain
information about grocery products and stores that information in
parallel arrays. It then performs various tasks for the user such
as allowing them to checkout different products of varying quantities
and calculating the total cost while removing as much product as
necessary from the inventory and providing an updated list of items
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

bool readInventory(string fileName, const int SIZE, string*, double*, string*, int*, int*);
double checkout(const int SIZE, string*, double*, int*);

int main()
{
    string fileName; // prompt user and receive inputted file name
    cout << "Enter the file name: ";
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

    string temp; // used to read through array to determine number of elements
    int numRecords = 0;

    while (inFile >> temp >> temp >> temp >> temp >> temp)
    {
        numRecords++;
    }
    cout << "There are " << numRecords << " records in the file" << endl;
    const int SIZE = numRecords;

    string* PLUArray = new string[SIZE]; // declares dynamically allocated arrays to hold file information
    string* productArray = new string[SIZE];
    int* salesType = new int[SIZE];
    double* poundPrice = new double[SIZE];
    int* inventory = new int[SIZE];

    inFile.close();

    if (readInventory(fileName, SIZE, PLUArray, poundPrice, productArray, salesType, inventory)) // populate arrays
    {
        cout << endl << "Inventory read from file" << endl << "------------------------" << endl;

        for (int i = 0; i < SIZE; i++) // outputs file information in formatted table for user
        {
            cout << "PLU: " << PLUArray[i] << ", " << left << setw(17) << productArray[i] << ", type: " << salesType[i]
                 << ", unit price: "<< setw(5) << right << poundPrice[i] << ", inventory: " << inventory[i] << endl;
        }

        // print list of options and receive user input
        int menuChoice;
        cout << "1 - Checkout" << endl << "2 - Print current inventory" << endl << "3 - Quit";
        cin >> menuChoice;

        while (true) // loop the menu choice until the user wants to exit the program
        {
            while (menuChoice < 1 || menuChoice > 3) // input validation for menu choice
            {
                cout << "Invalid choice, reenter: ";
                cin >> menuChoice;
            }
            if (menuChoice == 1) // user chose checkout, calls checkout function and prints total cost
            {

                double totalCost = checkout(SIZE, PLUArray, poundPrice, inventory);
                cout << "Total is: $" << totalCost << endl;

            }
            else if (menuChoice == 2) // user chose print inventory, loops through arrays with updated info
            {
                cout << "Current inventory" << endl << "-----------------" << endl;

                for (int i = 0; i < SIZE; i++)
                {
                    cout << "PLU: " << PLUArray[i] << ", " << left << setw(17) << productArray[i] << ", type: " << salesType[i]
                         << ", unit price: "<< setw(5) << right << poundPrice[i] << ", inventory: " << inventory[i] << endl;
                }
            }
            else if (menuChoice == 3) // user chose quit, exits program
            {
                cout << "Updated inventory" << endl << "-----------------" << endl;
                for (int i = 0; i < SIZE; i++) // prints the updated inventory and exits
                {
                    cout << "PLU: " << PLUArray[i] << ", " << left << setw(17) << productArray[i] << ", type: " << salesType[i]
                         << ", unit price: "<< setw(5) << right << poundPrice[i] << ", inventory: " << inventory[i] << endl;
                }
                cout << "Exiting" << endl;
                exit(EXIT_SUCCESS);
            }

            //reprint menu and get new input if program was not exited
            cout << endl << "1 - Checkout" << endl << "2 - Print current inventory" << endl << "3 - Quit" << endl;
            cin >> menuChoice;
        }
    }

    // release dynamic memory
    delete [] PLUArray;
    delete [] productArray;
    delete [] salesType;
    delete [] poundPrice;
    delete [] inventory;

    return 0;
}

bool readInventory(string fileName, const int SIZE, string* PLUArray, double* poundPrice, string* productArray, int* salesType, int* inventory)
{
    ifstream inFile;

    inFile.open(fileName); // open the file specified by the user
    if (inFile.fail()) // test for file open failure or empty file
    {
        cout << "Could not open file" << endl;
        cout << "Exiting" << endl;
        inFile.close();
        return false; // program ends
    }
    for (int i = 0; i < SIZE; i++) // if file did open, loop through all elements and store info
    {
        inFile >> PLUArray[i] >> productArray[i] >> salesType[i] >> poundPrice[i] >> inventory[i];
    }
    inFile.close();
    return true; // satisfies if statement
} // function loops through the user specified file after checking if it opens, and stores all information in given parallel arrays

double checkout(const int SIZE, string* PLUArray, double* poundPrice, int* inventory)
{
    double totalCost;
    string inputPLU;
    int numItems;
    cout << "Enter PLU, 0 if done: "; // prompt user and receive input
    cin >> inputPLU;

    while (inputPLU != "0") // check if input isn't 0
    {

        int itemIndex = -1; // set index to -1, if still -1 after looping then given PLU has no index / doesn't exist
        cout << "Enter quantity: "; // prompt user and receive input
        cin >> numItems;

        for (int i = 0; i < SIZE; i++) // loop through PLU array and compare with user input to find a match
        {
            if (inputPLU == PLUArray[i])
                itemIndex = i; // if a match is found, record the index at which the PLU exists
        }
        if (itemIndex == -1) // if the input remained unchanged from -1 then none was found
        {
            cout << "PLU not found" << endl << endl;
        }
        else // if the PLU was found, remove the quantity specified by the user from the inventory if available
        {
            if (inventory[itemIndex] < numItems) // if user orders more than available
            {
                totalCost += poundPrice[itemIndex] * inventory[itemIndex];
                inventory[itemIndex] = 0;
            }
            else // if there is enough inventory for user's order
            {
                totalCost+= poundPrice[itemIndex] * numItems;
                inventory[itemIndex] = inventory[itemIndex] - numItems;
            }
        }

        while (numItems < 0) // input validation to make sure quantity of elements is positive
        {
            cout << "Quantity must be positive, reenter: ";
            cin >> numItems;
        }
        cout << "Enter PLU, 0 if done: ";
        cin >> inputPLU;
    }
    return totalCost; // return the total cost
}
