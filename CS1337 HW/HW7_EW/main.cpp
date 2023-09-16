/*Author: Evan Wright
Compiler: GNU GCC
Date: 3/28/2022
Purpose of program:
Program allows users to create banking accounts to hold specified
amounts of balance as well as add multiple owners to each account.
The accounts retain information about each owner including name,
date of birth, and address, and the account itself holds info
such as the account number, the balance, the number of owners,
and the structure containing the owner information. The program
allows users to make deposits and withdrawals and will perform input
validation on balance inputs. It can also display all of the current
accounts and their respective information
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "Account.h"

string tokenize(string& inputString);

const int MAX_NUM_ACCOUNTS = 4;
Account* accountArray[MAX_NUM_ACCOUNTS];

int main()
{
    for (int i = 0; i < MAX_NUM_ACCOUNTS; i++)
    {
        accountArray[i] = nullptr;
    }

    int menuChoice = 0;
    while (menuChoice != 8)
    {
        cout << fixed;

        cout << "Menu" << endl << "----" << endl;
        cout << "1->Create account" << setw(12) << "2->Deposit " << setw(13)
             << "3->Withdraw" << "     4->Display " << endl;
        cout << "5->Delete owner" << setw(15) << "6->Add owner" << setw(16)
             << "7->Delete accnt" << " 8->Quit    " << endl;
        cin >> menuChoice;

        int accInd = -1;
        if (menuChoice == 1) // Create account
        {
            for (int i = 0; i < MAX_NUM_ACCOUNTS; i++)
            {
                if (accountArray[i] == nullptr)
                {
                    accInd = i; // record available index
                    break; // once index is found, stop looping
                }
            }
            if (accInd == -1) // if no nullptr index was found
            {
                cout << "Max number of accounts reached, cannot add a new account" << endl;
            }
            else
            {
                int numOwners;
                double amount;
                string dobTemp;
                cout << "Enter number of owners: ";
                cin >> numOwners;
                cout << "Enter amount: ";
                cin >> amount;
                cin.ignore();

                accountArray[accInd] = new Account(numOwners, amount);

                for (int i = 0; i < numOwners; i++)
                {
                    // fill up person structure by prompting user and receiving input,
                    Person p;
                    cout << "Enter owner's name: ";
                    getline(cin, p.name);
                    cout << "Enter owner's DOB, month, day then year: ";
                    getline(cin, dobTemp);
                    cout << "Enter owner's address: ";
                    getline(cin, p.address);

                    p.DOB.month = stoi(tokenize(dobTemp)); // call tokenize to separate date values into respective values of time
                    p.DOB.day = stoi(tokenize(dobTemp));
                    p.DOB.year = stoi(tokenize(dobTemp));

                    accountArray[accInd]->setOwner(i, p); // set gathered data into owner structure in account
                }

                cout << "Account #100" << accInd << " created" << endl;
            }
        }
        else if (menuChoice == 2) // Deposit to account
        {
            int accNum;
            double amount;
            cout << "Enter account number: ";
            cin >> accNum;

            int numAccounts = 0;
            for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) // check how many accounts are in the array
            {
                if (accountArray[i] == nullptr)
                {
                    numAccounts = i;
                    break;
                }
            }
            int matchAccInd = -1;
            for (int i = 0; i < numAccounts; i++) // loop thru account array and check for a matching account number
            {
                if (accNum == accountArray[i]->getAccountNumber())
                {
                    matchAccInd = i; // when match is found, record index and stop looping
                    break;
                }
            }
            if (matchAccInd == -1) // if no match was found
            {
                cout << "No such account" << endl;
            }
            else // if the account number exists
            {
                cout << "Enter amount: ";
                cin >> amount;

                int result = accountArray[matchAccInd]->deposit(amount); // attempt to deposit the user specified amount
                if (result == 1) // amount is negative
                {
                    cout << "Amount cannot be negative, deposit not executed" << endl;
                }
                else // amount is valid, print new balance
                {
                    cout << "New balance is $" << setprecision(2) << accountArray[matchAccInd]->getBalance() << endl;
                }
            }
        }
        else if (menuChoice == 3) // Withdrawal from account
        {
            int accNum;
            double amount;
            cout << "Enter account number: ";
            cin >> accNum;

            int numAccounts = 0;
            for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) // check how many accounts are in the array
            {
                if (accountArray[i] == nullptr)
                {
                    numAccounts = i;
                    break;
                }
            }
            int matchAccInd = -1;
            for (int i = 0; i < numAccounts; i++) // loop thru account array and check for a matching account number
            {
                if (accNum == accountArray[i]->getAccountNumber())
                {
                    matchAccInd = i; // when match is found, record index and stop looping
                    break;
                }
            }
            if (matchAccInd == -1) // if no match was found
            {
                cout << "No such account" << endl;
            }
            else // if the account number exists
            {
                cout << "Enter amount: ";
                cin >> amount;

                int result = accountArray[matchAccInd]->withdraw(amount); // attempt to withdrawal user specified amount
                if (result == 0) // if amount is valid
                {
                    cout << "New balance is $" << setprecision(2) << accountArray[matchAccInd]->getBalance() << endl;
                }
                else if (result == 1) // if withdrawal amount exceeds balance
                {
                    cout << "Insufficient balance, withdrawal not executed" << endl;
                }
                else if (result == 2) // if amount is negative
                {
                    cout << "Amount cannot be negative, withdrawal not executed" << endl;
                }
            }
        }
        else if (menuChoice == 4) // Display all account info
        {
            int i = 0;
            while (accountArray[i] != nullptr) // loop through all accounts in the array and print stored info
            {
                cout << "Account Number: " << accountArray[i]->getAccountNumber() << endl << "--------------" << endl;
                int numOwners = accountArray[i]->getNumOwners(); // print all owners of a specific account
                for (int j = 0; j < numOwners; j++)
                {
                    Person output = accountArray[i]->getOwner(j);
                    cout << "*Name: " << output.name << ", DOB: "
                         << output.DOB.month << "/" << output.DOB.day << "/" << output.DOB.year
                         << endl << "Address: " <<  output.address << endl;
                }
                cout << "*Balance: $" << accountArray[i]->getBalance() << " " << endl;
                i++;
            }
        }
        else if (menuChoice == 5) // Delete owner, extra credit
        {

        }
        else if (menuChoice == 6) // Add owner, extra credit
        {

        }
        else if (menuChoice == 7) // Delete account, extra credit
        {

        }
        else if (menuChoice == 8)
        {
            exit(EXIT_SUCCESS);
        }
    }

    delete [] *accountArray; // release stored memory

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
} // function takes an inputted string and removes delimiters and white space, returns the first token found and passes the remainder string back by reference
