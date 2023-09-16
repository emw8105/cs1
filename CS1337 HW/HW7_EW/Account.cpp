#include <iostream>

using namespace std;

#include "Account.h"

int Account::accountCounter = 1000;

Account::Account(int numberOwners, double amount)
{
    accountNumber = accountCounter;
    numOwners = numberOwners;
    ownerPtr = new Person[numOwners];
    balance = amount;
    accountCounter++;
}
Account::~Account()
{
    delete [] ownerPtr;
}
int Account::withdraw(double amount)
{
    if (amount > 0)
    {
        if (amount <= balance) // if there is enough in balance to withdrawal
        {
            balance -= amount;
            return 0;
        }
        else // if not enough balance
        {
            return 1;
        }
    }
    else // if amount is negative
    {
        return 2;
    }
}
int Account::deposit(double amount)
{
    if (amount > 0) // if amount is positive
    {
        balance += amount;
        return 0;
    }
    else // if amount if negative
    {
        return 1;
    }
}
void Account::setOwner(int ind, Person p)
{
    ownerPtr[ind] = p;
}
Person Account::getOwner(int ind) const
{
    return ownerPtr[ind];
}
int Account::getAccountNumber() const
{
    return accountNumber;
}
double Account::getBalance() const
{
    return balance;
}
int Account::getNumOwners() const
{
    return numOwners;
}
