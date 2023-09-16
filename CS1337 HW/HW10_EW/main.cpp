/*Author: Evan Wright
Compiler: GNU GCC
Date: 4/20/2022
Purpose of program:
This program functions as a banking system that utilizes
inheritance to allow users to make either a regular account
or a premium account. The premium account requires users
to hold more than 1000 dollars in their account, while
regular accounts have no monetary restrictions. The user can
also make deposits and withdrawals from an account based on
the account number if it exists, as long as their inputs
are valid (no negative deposits), and as long as they don't
withdrawal an amount that would put a premium account's
balance under 1000. The user can also print all of the
current accounts in the system
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"
#include "Account.h"
#include "RegularAccount.h"
#include "PremiumAccount.h"

string tokenize(string& inputString); // function is used to separate values of time from provided date as a string

using namespace std;

int main()
{
    const int MAX_NUM_ACCOUNTS = 5;
    Account * accountArray[MAX_NUM_ACCOUNTS];
    int currentNumAcc = 0;
    // tracks the amount of elements filled in the array to prevent out-of-bounds
    cout << fixed;

    int menuChoice = 0;
    while (menuChoice != 6) // loop until user chooses to quit
    {
        cout << endl;
        // prompt user and receive input
        cout << "1->Create regular accnt, 2->Create premium accnt, 3->Deposit to accnt" << endl;
        cout << "4->Withdraw from accnt, 5->Print info accnts, 6->Quit" << endl;
        cin >> menuChoice;

        if (menuChoice == 1) // create a regular account
        {
            if (currentNumAcc < MAX_NUM_ACCOUNTS) // don't make a new account if max amount is reached
            {
                string ownerName, date;
                double amount;
                cout << "Enter owner's name: ";
                cin >> ownerName; // prompt user and receive input
                cout << "Enter date, in the mm/dd/yyyy/hh format: ";
                cin >> date; // prompt user and receive input
                int month = stoi(tokenize(date)); // split input into different values through substring functions
                int day = stoi(tokenize(date));
                int year = stoi(tokenize(date));
                int hour = stoi(tokenize(date));
                Date tempDate;
                tempDate.set(month, day, year, hour); // set respective time values into the class
                cout << "Enter amount: ";
                cin >> amount; // prompt user and receive input
                if (amount < 0)
                {
                    cout << "Amount cannot be negative, account creation not executed" << endl;
                }
                else
                {
                    cout << "Account created: " << endl;
                    // create account with provided inputs
                    accountArray[currentNumAcc] = new RegularAccount(ownerName, amount, tempDate);
                    accountArray[currentNumAcc]->print(); // print account for user
                    currentNumAcc++; // increase the current account number counter to reflect the new account
                }
            }
            else
            {
                cout << "Max number of accounts reached, cannot add a new account" << endl;
            }
        }
        else if (menuChoice == 2) // create a premium account
        {
            if (currentNumAcc < MAX_NUM_ACCOUNTS) // don't make a new account if max amount is reached
            {
                string ownerName, date;
                double amount;
                cout << "Enter owner's name: ";
                cin >> ownerName; // prompt user and receive input
                cout << "Enter date, in the mm/dd/yyyy/hh format: ";
                cin >> date; // prompt user and receive input
                int month = stoi(tokenize(date)); // split input into different values through substring functions
                int day = stoi(tokenize(date));
                int year = stoi(tokenize(date));
                int hour = stoi(tokenize(date));
                Date tempDate;
                tempDate.set(month, day, year, hour); // set respective time values into the class
                cout << "Enter amount: ";
                cin >> amount; // prompt user and receive input
                if (amount < 0)
                {
                    cout << "Amount cannot be negative, account creation not executed" << endl;
                }
                else if (amount < 1000)
                {
                    cout << "Insufficient amount, you need at least 1000.00 Galactic units to open a premium account" << endl;
                }
                else
                {
                    cout << "Account created: " << endl;
                    // create account with provided inputs
                    accountArray[currentNumAcc] = new PremiumAccount(ownerName, amount, tempDate);
                    accountArray[currentNumAcc]->print(); // print account for user
                    currentNumAcc++; // increase the current account number counter to reflect the new account
                }
            }
            else
            {
                cout << "Max number of accounts reached, cannot add a new account" << endl;
            }
        }
        // either unused parameter for date or set but not used, also static issue
        else if (menuChoice == 3) // Deposit to account
        {
            int accNum;
            string date;
            double amount;
            cout << "Enter account number: ";
            cin >> accNum; // prompt user and receive input
            int accIndex = -1;
            for (int i = 0; i < currentNumAcc; i++) // loop through current accounts
            {
                if ((accountArray[i]->getAccountNumber())== accNum) // check for matching account number
                {
                    accIndex = i; // record a match if found
                }
            }
            if (accIndex == -1) // if no matching account numbers were found
            {
                cout << "No such account" << endl;
            }
            else // if a match was found
            {
                cout << "Enter date, in the mm/dd/yyyy/hh format: ";
                cin >> date; // prompt user and receive input
                int month = stoi(tokenize(date)); // split given input into respective values of time
                int day = stoi(tokenize(date));
                int year = stoi(tokenize(date));
                int hour = stoi(tokenize(date));
                Date tempDate;
                tempDate.set(month, day, year, hour); // set placeholder date with values of time
                cout << "Enter amount: ";
                cin >> amount; // prompt user and receive input
                if (accountArray[accIndex]->deposit(amount, tempDate)) // add amount to balance
                {
                    cout << "Deposit executed: " << endl;
                    accountArray[accIndex]->print(); // print account to show change in balance
                }
                else // if deposit was invalid
                {
                    cout << "Amount cannot be negative, deposit not executed" << endl;
                }
            }
        }
        else if (menuChoice == 4) // withdrawal from account
        {
            int accNum;
            string date;
            double amount;
            cout << "Enter account number: ";
            cin >> accNum; // prompt user and receive input
            int accIndex = -1;
            for (int i = 0; i < currentNumAcc; i++) // loop through current accounts
            {
                if ((accountArray[i]->getAccountNumber())== accNum) // check for matching account number
                {
                    accIndex = i; // record a match if found
                }
            }
            if (accIndex == -1) // if no matching account numbers were found
            {
                cout << "No such account" << endl;
            }
            else
            {
                cout << "Enter date, in the mm/dd/yyyy/hh format: ";
                cin >> date; // prompt user and receive input
                int month = stoi(tokenize(date)); // split given input into respective values of time
                int day = stoi(tokenize(date));
                int year = stoi(tokenize(date));
                int hour = stoi(tokenize(date));
                Date tempDate;
                tempDate.set(month, day, year, hour); // set placeholder date with values of time
                cout << "Enter amount: ";
                cin >> amount; // prompt user and receive input
                if (amount < 0)
                {
                    cout << "Amount cannot be negative, withdraw not executed" << endl;
                }
                else if (accountArray[accIndex]->withdraw(amount, tempDate)) // attempt to withdraw
                {
                    cout << "Withdraw executed: " << endl;
                    accountArray[accIndex]->print(); // print account to show change in balance
                }
                else
                {
                    cout << "Insufficient balance, withdrawal not executed" << endl;
                }
            }
        }
        else if (menuChoice == 5) // print info for all accounts
        {
            cout << "Accounts" << endl << "========" << endl;
            // loop through current accounts and print them all
            for (int i = 0; i < currentNumAcc; i++)
            {
                cout << endl;
                accountArray[i]->print();
            }
        }
    }
    if (menuChoice == 6)
    {
        exit(EXIT_SUCCESS);
    }

    return 0;
}
string tokenize(string& inputString)
{
    char charAtIndex = inputString[0];
    string tempToken;
    unsigned int i = 0;

    while (!(isdigit(charAtIndex) && i < inputString.length())) // removes leading delimiters by looping until it encounters a non-space char
    {
        i++;
        charAtIndex = inputString[i];
    }
    inputString = inputString.substr(i, inputString.length()); // remove all specified delimiters from the string

    //reloop and grab the first token, end once delimiters begin again
    i = 0;
    while ((isdigit(charAtIndex)) && i < inputString.length())
    {
        tempToken+= inputString[i]; // store the token in tempToken and return it after the loop ends
        i++;
        charAtIndex = inputString[i];
    }
    inputString = inputString.substr(i, inputString.length()); // remove the token from the string

    return tempToken;
} // function takes an inputted string and removes delimiters and white space, returns the first token found and passes the remainder string back by reference
