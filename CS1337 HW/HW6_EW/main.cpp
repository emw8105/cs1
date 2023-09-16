/*Author: Evan Wright
Compiler: GNU GCC
Date: 3/21/2022
Purpose of program:
Program stores account information by prompting the user for various inputs
and storing them as structures in an array with a size specified by the user.
The program performs input validation on necessary inputs, and allows the user
to search through all currently entered account information for a specific
account using their account number, or output all of the currently entered
accounts at once.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#include "Product.h"

string tokenize(string& inputString);

int main()
{
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;
    ifstream inFile;

    inFile.open(fileName); // open the file specified by the user
    if (inFile.fail()) // test for file open failure or empty file
    {
        cout << "Could not open file" << endl;
        cout << "Exiting" << endl;
        inFile.close();
        exit(EXIT_FAILURE); // if file open in unsuccessful, terminate program
    }
    else
    {
        string stringRead;
        int numProducts = 0;
        while (getline(inFile, stringRead)) // loop while a new line can be read from the file to determine the number of elements
        {
            numProducts++; // record number of lines in the file to determine number of products
        }

        Product* prodArr = new Product[numProducts]; // dynamically create array with size specified by number of products

        inFile.close();
        inFile.open(fileName); // close and reopen file to reposition read pointer
        string PLU_;
        string name_;
        int type_;
        double price_;
        int inventory_;
        string temp;

        for (int i = 0; i < numProducts; i++) // loop back through the file and assign elements to product array
        {
            getline(inFile, stringRead); // repeatedly call tokenize function to remove whitespaces between file inputs and separate values
            PLU_ = tokenize(stringRead);
            name_ = tokenize(stringRead);
            type_ = stoi(tokenize(stringRead));
            price_ = stof(tokenize(stringRead));
            inventory_ = stoi(tokenize(stringRead));
            prodArr[i].setProductAttributes(PLU_, name_, type_, price_, inventory_); // set all gathered values to the object in the array
        }
        cout << "There are " << numProducts << " records in the file" << endl;
        cout << endl << "Content of object array" << endl << "-----------------------" << endl;
        for (int i = 0; i < numProducts; i++) // loop through the array and output it's contents in a formatted table
        {
            cout << "PLU: " << prodArr[i].getPLU() << ", " << setw(17)  << left << prodArr[i].getName()
                 << ", type: " << prodArr[i].getType() << ", unit price: " << right << setw(5) << prodArr[i].getPrice()
                 << ", inventory: " << prodArr[i].getInventory() << endl;
        }

        int menuChoice = 0;
        while (menuChoice != 4)
        {
            cout << endl << "Menu" << endl << "----" << endl;
            cout << setw(30) << left << "1->Add to inventory" << ", 2->Subtract from inventory" << endl;
            cout << setw(30) << "3->Print info for all products" << ", 4->Exit" << endl;
            cin >> menuChoice; // prompt and receive desired menu option

            if (menuChoice == 1) // add to inventory
            {
                int PLUIndex = -1;
                string PLUAdd;
                cout << "Enter the PLU: ";
                cin >> PLUAdd;
                for (int i = 0; i < numProducts; i++) // loop through array to check for matching PLU
                {
                    if (PLUAdd == prodArr[i].getPLU())
                    {
                        PLUIndex = i;
                    }
                }
                if (PLUIndex == -1) // if no matching PLU was found, value remained unchanged throughout loop
                {
                    cout << "PLU not found" << endl;
                }
                else // if there was an index with a matching element to the user specified PLU
                {
                    int invenAdd;
                    cout << "Enter amount to add: ";
                    cin >> invenAdd; // prompt user and receive input
                    if (invenAdd <= 0)
                    {
                        cout << "Amount must be > 0" << endl;
                    }
                    else
                    {
                        invenAdd += prodArr[PLUIndex].getInventory(); // sum the user added amount to current inventory
                        prodArr[PLUIndex].setInventory(invenAdd); // set inventory of that object to be the sum
                    }
                }
            }
            else if (menuChoice == 2) // subtract inventory
            {
                int PLUIndex = -1;
                string PLUSub;
                cout << "Enter the PLU: ";
                cin >> PLUSub;
                for (int i = 0; i < numProducts; i++) // if no matching PLU was found, value remained unchanged throughout loop
                {
                    if (PLUSub == prodArr[i].getPLU())
                    {
                        PLUIndex = i;
                    }
                }
                if (PLUIndex == -1) // if no matching PLU was found, value remained unchanged throughout loop
                {
                    cout << "PLU not found" << endl;
                }
                else // if there was an index with a matching element to the user specified PLU
                {
                    int invenSub;
                    cout << "Enter amount to subtract: ";
                    cin >> invenSub; // prompt user and receive input
                    if (invenSub <= 0)
                    {
                        cout << "Amount must be > 0" << endl;
                    }
                    else if (invenSub > prodArr[PLUIndex].getInventory()) // if the amount to be subtracted is greater than the current amount
                    {
                        prodArr[PLUIndex].setInventory(0);
                    }
                    else // if the amount to be subtracted is less than the current amount
                    {
                        int temp = prodArr[PLUIndex].getInventory();
                        temp -= invenSub; // subtract the requested amount from the current inventory
                        prodArr[PLUIndex].setInventory(temp); // set inventory of that object to be the result
                    }
                }
            }
            else if (menuChoice == 3) // print info for all products
            {
                cout << "Current inventory" << endl << "-----------------" << endl;
                for (int i = 0; i < numProducts; i++) // loop through array and print objects in formatted table
                {
                    cout << "PLU: " << prodArr[i].getPLU() << ", " << setw(17)  << left << prodArr[i].getName()
                         << ", type: " << prodArr[i].getType() << ", unit price: " << right << setw(5) << prodArr[i].getPrice()
                         << ", inventory: " << prodArr[i].getInventory() << endl;
                }
            }
            else // if menu choice was 4 (or anything else to avoid complication) terminate program
            {
                exit(EXIT_SUCCESS);
            }
        }
    }
    return 0;
}

string tokenize(string& inputString)
{
    char charAtIndex = inputString[0];
    string tempToken;
    unsigned int i = 0;

    while ((isspace(charAtIndex) && i < inputString.length())) // removes leading delimiters by looping until it encounters a non-space char
    {
        i++;
        charAtIndex = inputString[i];
    }
    inputString = inputString.substr(i, inputString.length()); // remove all specified delimiters from the string

    //reloop and grab the first token, end once delimiters begin again
    i = 0;
    while (!(isspace(charAtIndex)) && i < inputString.length())
    {
        tempToken+= inputString[i]; // store the token in tempToken and return it after the loop ends
        i++;
        charAtIndex = inputString[i];
    }
    inputString = inputString.substr(i, inputString.length()); // remove the token from the string

    return tempToken;
} // function deletes excess characters and returns the first block of non whitespace characters, and puts the remainder back into the inputted
    // string to be called again later, when used with the loop to populate the array, it segments all the file inputs into chunked variables
