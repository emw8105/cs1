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
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

struct Person
{
    string name;
    string address;
};
struct Account
{
    int accountNumber;
    Person ownerInfo;
    double balance;
};

void populateAccount(Account accArr[], int& numPopAcc, int numAccounts);
void printAccount(const Account& inputAcc);

int main()
{
    string tempNumAccounts;
    int numAttempts = 0;
    cout << "Enter max number of accounts: ";
    getline(cin, tempNumAccounts); // prompt user and receive input

    bool hasValidNum = true;
    do // input validation by looping through input and checking all characters
    {
        hasValidNum = true;
        for (unsigned int i = 0; i < tempNumAccounts.length(); i++) // loop through the given string
        {
            char charAtIndex = tempNumAccounts[i];
            if (!(isdigit(charAtIndex))) // check if the character isn't a digit
            {
                hasValidNum = false;
                cout << "Invalid value, please reenter: "; // if the character isnt a digit, receive new input
                getline(cin, tempNumAccounts);
                numAttempts++; // record the number of attempts
                break;
            }
        }
    }
    while (hasValidNum == false && numAttempts < 4); // keep looping until the input is valid or until attempts run out
    if (numAttempts  == 4)
    {
        cout << "Too many unsuccessful attempts, exiting";
        exit(EXIT_FAILURE); // exit if attempts expire
    }

    int numAccounts = stoi(tempNumAccounts); // convert input to integer to use for array size

    Account* accArr = new Account[numAccounts]; // declare dynamically created array of accounts with the number of accounts as size
    int numPopAcc = 0; // current number of accounts in the array
    string menuChoice = "0";

    while (menuChoice != "4") // loop until the user enters 4 to exit the program
    {

        cout << endl << "Menu:" << endl;
        cout << "1->Enter data for specific account, 2->Display data for specific account" << endl;
        cout << "3->Display data for all accounts  , 4->Quit:" << endl;
        getline(cin, menuChoice); // prompt user and receive input

        numAttempts = 0; // validate data, can only be among available menu options (1, 2, 3, 4)
        do
        {
            hasValidNum = true;
            if (!(menuChoice == "1" || menuChoice == "2" || menuChoice == "3" || menuChoice == "4")) // check for viable inputs
            {
                cout << "Invalid choice, please reenter: ";
                getline(cin, menuChoice); // if input is not valid, receive new input
                numAttempts++; // record number of attempts
                hasValidNum = false;
            }
        }
        while (hasValidNum == false && numAttempts < 4); // loop until input is valid or the number of attempts exceeds the limit
        if (numAttempts == 4)
        {
            cout << "Too many unsuccessful attempts, exiting";
            exit(EXIT_FAILURE); // exit if too many attempts used
        }

        if (menuChoice == "1") // if the user wants to add an account
        {
            populateAccount(accArr, numPopAcc, numAccounts); // call the populate array function
        }
        if (menuChoice == "2") // if the user wants to search for an account
        {
            string inputAccNum;
            cout << "Enter account number: ";
            getline(cin, inputAccNum); // prompt user and receive input


            numAttempts = 0;
            do // validate input, account number must be an integer
            {
                hasValidNum = true;
                for (unsigned int i = 0; i < inputAccNum.length(); i++) // loop through the given string
                {
                    char charAtIndex = inputAccNum[i];
                    if (!(isdigit(charAtIndex))) // check if the character isn't a digit
                    {
                        hasValidNum = false;
                        cout << "Invalid value, please reenter: ";
                        getline(cin, inputAccNum); // if input if invalid, receive new input
                        numAttempts++; // track number of attempts
                        break;
                    }
                }
            }
            while (hasValidNum == false && numAttempts < 4); // loop until input is valid or the number of attempts exceeds the limit
            if (numAttempts  == 4)
            {
                cout << "Too many unsuccessful attempts, exiting";
                exit(EXIT_FAILURE); // exit if too many attempts
            }
            else // if the inputted value passed validation within the allotted number of attempts
            {
                int accNum = stoi(inputAccNum); // if the input is valid convert to an integer to match the structure variable accountNumber
                int accNumIndex = -1;
                for (int i = 0; i < numPopAcc+1; i++) // loop through the number of accounts currently in the array
                {
                    if (accNum == accArr[i].accountNumber) // check each index for a match
                    {
                        accNumIndex = i; // if a match is found, then record the index and replace the placeholder -1
                    }
                }
                if (accNumIndex == -1) // if index is still -1 at the end, then no matching account was found
                {
                    cout << "Account not found" << endl;
                }
                else
                {
                    printAccount(accArr[accNumIndex]); // if an index was found, then print the account at that index
                }
            }
        }
        if (menuChoice == "3") // if the user wants to print all accounts currently in the area
        {
            for (int i = 0; i < numPopAcc+1; i++) // loop through the number of accounts currently in the array
            {
                printAccount(accArr[i]); // print every account
            }
        }
    }
    if (menuChoice == "4") // if the user wants to exit the program
    {
        exit(EXIT_SUCCESS); // exit
    }

    return 0;
}

void populateAccount(Account accArr[], int& numPopAcc, int numAccounts)
{
    bool hasIndex = false;
    for (int i = 0; i < numAccounts; i++) // loop through the max amount of accounts
    {
        string arrAtIndex = accArr[i].ownerInfo.name;
        if (arrAtIndex == "") // use the name to see if the structure in the area is empty to check how many elements there are
        {
            hasIndex = true;
            numPopAcc = i;
            break; // exit loop once index is found if at all
        }
    }
    if (hasIndex == false) // if there is no available index in the array
    {
        cout << "Cannot execute, array is full" << endl;
    }
    else
    {
        //ACCOUNT NUMBER
        string input;
        cout << "Enter account number: ";
        getline(cin, input); // prompt user and receive input

        bool hasValidNum;
        int numAttempts = 0;
        do
        {
            // validate input, must be a number
            hasValidNum = true;
            for (unsigned int i = 0; i < input.length(); i++) // loop through the given string
            {
                char charAtIndex = input[i];
                if (!(isdigit(charAtIndex))) // check if the character isn't a digit
                {
                    hasValidNum = false;
                    cout << "Invalid value, please reenter: ";
                    getline(cin, input); // if the input is invalid, receive new input
                    numAttempts++; // record number of attempts
                    break;
                }
            }
            if (hasValidNum == true) // check for duplicate account numbers by searching the current list of account numbers
            {
                int accNum = stoi(input); // if the input is valid convert to an integer to match the structure variable accountNumber
                int accNumIndex = -1;
                for (int i = 0; i < numPopAcc+1; i++) // loop through the number of accounts currently in the array
                {
                    if (accNum == accArr[i].accountNumber) // check each index for a match
                    {
                        accNumIndex = i; // if a match is found, then record the index and replace the placeholder -1
                    }
                }
                if (accNumIndex != -1) // if index isn't -1, then an account with this account number already exists
                {
                    cout << "Duplicate account number";
                    exit(EXIT_FAILURE);
                }
            }
        }
        while (hasValidNum == false && numAttempts < 4); // loop until input is valid or attempts exceed limit
        if (numAttempts  == 4)
        {
            cout << "Too many unsuccessful attempts, exiting";
            exit(EXIT_FAILURE);
        }
        else // if the inputted value passed validation within the allotted number of attempts
        {
            // check if the account number is already in use for extra credit
            // record the data post-validation at that index using the structures
            int accountNum = stoi(input);
            accArr[numPopAcc].accountNumber = accountNum;
        }

        // BALANCE
        cout << "Enter balance: ";
        getline(cin, input);

        numAttempts = 0;
        do
        {
            hasValidNum = true;
            bool hasDot = false;
            int dotIndex = -1;

            for (unsigned int i = 0; i < input.length(); i++) // loop through the given string
            {
                char charAtIndex = input[i];
                if (!(isdigit(charAtIndex))) // check if the character isn't a digit
                {
                    if (charAtIndex == '.' && hasDot == false) // check if the character at the index is a dot
                    {
                        hasDot = true; // there can only be one dot, so prevent this check in future loop iterations
                        dotIndex = i;
                    }
                    else // if a second dot is found, return false
                    {
                        hasValidNum = false;
                        break;
                    }
                }
            }
            if (hasDot) // if the number has a decimal, make sure there are no more than 2 indexes after the decimal
            {
                if (!(input.length()-dotIndex-1 <= 2))
                {
                    hasValidNum = false;
                }
            }
            if (hasValidNum == false)
            {
                cout << "Invalid value, please reenter: ";
                getline(cin, input); // if input is invalid receive new input
                numAttempts++; // record number of attempts
            }
        }
        while (hasValidNum == false && numAttempts < 4); // loop until input is valid or attempts exceed limit
        if (numAttempts  == 4)
        {
            cout << "Too many unsuccessful attempts, exiting";
            exit(EXIT_FAILURE);
        }
        else
        {
            double balance = stof(input);
            accArr[numPopAcc].balance = balance;
        }

        //NAME
        cout << "Enter owner's name: ";
        getline(cin, input); // prompt user and receive input, record in structure
        accArr[numPopAcc].ownerInfo.name = input;

        //ADDRESS
        cout << "Enter owner's address: ";
        getline(cin, input); // prompt user and receive input, record in structure
        accArr[numPopAcc].ownerInfo.address = input;
    }
}// function prompts the user for and receives all account information and performs input validation when necessary
void printAccount(const Account& inputAcc)
{
    cout << "Account #: " << inputAcc.accountNumber << endl;
    cout << "Owner's name: " << inputAcc.ownerInfo.name << endl;
    cout << "Owner's address: " << inputAcc.ownerInfo.address << endl;
    cout << "Balance: " << inputAcc.balance << endl;
} // function outputs the all the stored data for the provided structure from the array
