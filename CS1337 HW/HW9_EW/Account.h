#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include "Date.h"

struct Transaction
{
   Date transactionDate;
   int type;
   double amount;
};

struct Person
{
   string name;
   Date DOB;
   string address;

};

class Account
{

private:
    int accountNumber;
    int numOwners;
    Person* ownerPtr;
    double balance;
    int numTransactions;
    Transaction* transacPtr;
public:

    Account();
    void setAccount(int accountNumber_, int numOwners_);
    void setOwner(int ind, Person p);
    Person getOwner(int ind) const;
    int getAccountNumber() const;
    int getNumOwners() const;
    void setTransacPtr(Transaction * transacPtr_);
    int getNumTransactions () const;
    void setNumTransactions (int numTransactions_);
    Transaction getTransaction(int ind) const;
};

#endif // ACCOUNT_H_INCLUDED
