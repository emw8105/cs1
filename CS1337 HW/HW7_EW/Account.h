#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

struct Date
{
    int month;
    int day;
    int year;
};

struct Person // stores account owner’s info
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
    static int accountCounter;
public:

    Account(int numberOwners, double amount);
    ~Account(); // maybe dynamic array as parameter
    int withdraw(double amount);
    int deposit(double amount);
    void setOwner(int ind, Person p);
    Person getOwner(int ind) const;
    int getAccountNumber() const;
    double getBalance() const;
    int getNumOwners() const;
};

#endif // ACCOUNT_H_INCLUDED
