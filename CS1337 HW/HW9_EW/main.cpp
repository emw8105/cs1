/*Author: Evan Wright
Compiler: GNU GCC
Date: 4/13/2022
Purpose of program:
The program functions as a bank account that receives file input specified
by the user, and sorts the given information into various fields all headed
under different accounts, such as the number of owners and their various
personal information, the number of transactions, and the details of each
transaction such as the date. The program then displays all of the information
in a formatted style for the user
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "Date.h"
#include "Account.h"

int getMonthFromString(string d); // substrings the month out of a date formatted as mm/dd/yyyy/hh
int getDayFromString(string d); // substrings the day out of a date formatted as mm/dd/yyyy/hh
int getYearFromString(string d); // substrings the year out of a date formatted as mm/dd/yyyy/hh
int getHourFromString(string d); // substrings the hour out of a date formatted as mm/dd/yyyy/hh
bool readAccounts(string fname, Account  accntPtr [], int numAccnts);

int main()
{
    string fileName;
    cout << "Enter the account file name: ";
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
        string temp;
        int numAccs = 0;
        while (inFile >> temp) // count number of elements in the file
        {
            if (temp == "#") // # is used as a delimiter, every # effectively represents an account
            {
                numAccs++;
            }
        }
        Account * accArr = new Account[numAccs]; // dynamic memory allocation for account array
        inFile.close();
        readAccounts(fileName, accArr, numAccs); // populate all account information

        // output account information in formatted style
        cout << "There are " << numAccs << " accounts in the file" << endl;
        cout << endl;
        for (int i = 0; i < numAccs; i++) // loop over accounts
        {
            int balance = 0; // reset balance for each account
            cout << endl << "Account Number: " << accArr[i].getAccountNumber();
            cout << endl << "===============" << endl;
            for (int j = 0; j < accArr[i].getNumOwners(); j++) // loop over owners for the given account
            {
                Person temp = accArr[i].getOwner(j); // set a temporary person object to array element to access variables
                cout << "Name: " << temp.name << ", DOB: ";
                temp.DOB.print(); // print function outputs the date in specific format
                cout << ", Address: " << temp.address << endl << endl;
            } // loop over owners
            cout << "Transaction history:" << endl << "--------------------";
            for (int g = 0; g < accArr[i].getNumTransactions(); g++) // loop over transactions for the given account
            {
                Transaction temp = accArr[i].getTransaction(g);  // set a temporary person object to array element to access variables
                cout << endl << "Transaction #" << g+1 << endl;
                cout << "Date: ";
                temp.transactionDate.print(); // print function outputs the date in specific format
                cout << ", type: ";
                if (temp.type == 1) // account creation, adds balance
                {
                    cout << "account creation, ";
                    cout << "amount: " << temp.amount << ", new balance: ";
                    balance += temp.amount; // add the amount to the balance
                    cout << balance << endl;
                }
                else if (temp.type == 2) // deposit, adds balance
                {
                    cout << "deposit, ";
                    cout << "amount: " << temp.amount << ", new balance: ";
                    balance += temp.amount; // add the amount to the balance
                    cout << balance << endl;
                }
                else if (temp.type == 3) // withdrawal, subtracts balance
                {
                    cout << "withdrawal, ";
                    cout << "amount: " << temp.amount << ", new balance: ";
                    balance -= temp.amount; // subtract the amount from the balance
                    cout << balance << endl;
                }
            } // loop over transactions

        } // loop over accounts
    }
    return 0;
}

/* This function takes as argument a string representing a date
in the mm/dd/yyyy/hh format and returns the month as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getMonthFromString(string d)
{
    return stoi(d.substr(0,2));
}

/* This function takes as argument a string representing a date
in the mm/dd/yyyy/hh format and returns the day as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getDayFromString(string d)
{
    return stoi(d.substr(3,5));
}

/* This function takes as argument a string representing a date
in the mm/dd/yyyy/hh format and returns the year as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getYearFromString(string d)
{
    return stoi(d.substr(6,10));
}

/* This function takes as argument a string representing a date
in the mm/dd/yyyy/hh format and returns the hour as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getHourFromString(string d)
{
    return stoi(d.substr(11));
}

/* This function reads from an account file and populates an array of Account
objects (not an array of pointers to Account) with all the owners and transactions
data read from the file. The owner data is the owner's name, DOB and address.
The transaction data is the transaction date, transaction type
(account creation, deposit, withdrawal), and transaction amount. For each account,
the function should dynamically allocate an array of Transaction of size
equal to the number of transactions, assign the array's address to transacPtr,
and populate the array with the transaction data. In the extra credit version,
after the array has been populated, this function should sort the transactions
array by date (oldest first).
It takes as arguments the file name, the array and the size of the array.
It returns true if file open is successful, false otherwise. It should close
the file when done
*/
bool readAccounts(string fname, Account  accntPtr [], int numAccnts)
{
    ifstream inFile;
    inFile.open(fname);

    if (inFile.fail()) // test for file open failure or empty file
    {
        cout << "Could not open file" << endl;
        cout << "Exiting" << endl;
        inFile.close();
        return false;
    }

    for (int accntIndex = 0; accntIndex < numAccnts; accntIndex++)  // Loop over the accounts
    {
        string temp; // holds #
        inFile >> temp;
        // read from the file the various data items related to the account, up to numOwners
        int accNumber;
        inFile >> accNumber;
        int numOwners;
        inFile >> numOwners;
        // Call the setAccount() member function to set the relevant member variables of the account
        accntPtr[accntIndex].setAccount(accNumber, numOwners);

        for (int ownerIndex = 0; ownerIndex < numOwners; ownerIndex++) // Loop over the owners for Account at accntIndex
        {
            // read the owner's name, DOB and address, perform the necessary conversions
            // read in owner info by line, loop over numOwners to get all info
            Person p;
            string DOB; // must substring to get individual values of time

            inFile >> p.name;

            inFile >> DOB;
            // split the date string up into individual values of time
            int month = getMonthFromString(DOB);
            int day = getDayFromString(DOB);
            int year = getYearFromString(DOB);
            int hour = getHourFromString(DOB);
            p.DOB.set(month, day, year, hour);

            inFile >> p.address;
            accntPtr[accntIndex].setOwner(ownerIndex, p);
            // Use the appropriate setter to set the owner at ownerIndex
        }
        // read numTransactions
        int numTransactions;
        inFile >> numTransactions;
        accntPtr[accntIndex].setNumTransactions(numTransactions);
        // dynamically allocate an array of Transactions of the right size, and assign address to transactionPtr
        Transaction * transactionPtr = new Transaction [numTransactions];
        for (int transac = 0; transac < numTransactions; transac++) // loop over the transactions for Account at accntIndex
        {
            // Read date from file, perform the appropriate conversions and set the transaction date
            string transacDate;
            inFile >> transacDate;
            // split the date string up into individual values of time
            int month = getMonthFromString(transacDate);
            int day = getDayFromString(transacDate);
            int year = getYearFromString(transacDate);
            int hour = getHourFromString(transacDate);
            transactionPtr[transac].transactionDate.set(month, day, year, hour);

            // Read type, amount and set the transaction type and amount
            int transacType;
            double transacAmount;
            inFile >> transacType;
            inFile >> transacAmount;
            transactionPtr[transac].type = transacType;
            transactionPtr[transac].amount = transacAmount;
        }
        // use bubble sort to organize transactions chronologically by earliest first
        for(int i = 0; i< numTransactions; i++)
            {
            for(int j = 0; j< numTransactions-1; j++)
            {
                if(transactionPtr[j+1].transactionDate < transactionPtr[j].transactionDate)
                {
                    Transaction temp = transactionPtr[j];
                    transactionPtr[j] = transactionPtr[j+1];
                    transactionPtr[j+1] = temp;
                }
            }
        }
        // Use the appropriate setter to set transacPtr with transactionPtr
        accntPtr[accntIndex].setTransacPtr(transactionPtr);
        // Call the function to sort the transaction array by date, oldest date first (extra credit version only)
    } // end of loop over accounts

    inFile.close();

    return true;
}
