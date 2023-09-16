#include <iostream>

using namespace std;

#include "Account.h"

Account::Account()
{
    accountNumber = 0;
    numOwners = 0;
    ownerPtr = nullptr;
    balance = 0;
    transacPtr = nullptr;
}
void Account::setAccount(int accountNumber_, int numOwners_)
{
    accountNumber = accountNumber_;
    numOwners = numOwners_;
    ownerPtr = new Person[numOwners];
    balance = 0;
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
int Account::getNumOwners() const
{
    return numOwners;
}
void Account::setTransacPtr(Transaction * transacPtr_)
{
    transacPtr = transacPtr_;
}
int Account::getNumTransactions () const
{
    return numTransactions;
}
void Account::setNumTransactions (int numTransactions_)
{
    numTransactions = numTransactions_;
}
Transaction Account::getTransaction(int ind) const
{
    return transacPtr[ind];
}
