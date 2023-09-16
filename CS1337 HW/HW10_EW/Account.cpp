#include <iostream>
#include <iomanip>

using namespace std;

#include "Date.h"
#include "Account.h"

int Account::numberAccounts = 0;

Account::Account(string ownerName_, double balance_, Date date_)
{
    ownerName = ownerName_;
    balance = balance_;
    transactionHistory = nullptr;
    numberTransactions = 0;
    accountNumber = numberAccounts + 1000;
    numberAccounts++;
    Date tempDate = date_; // set date parameter to dummy date to prevent "unused parameter" warning
    int wowza = tempDate.getMonth(); // do garbage with dummy date to prevent "set but not used" warning
    wowza -= 1;
}
bool Account::withdraw(double amount, Date date_)
{
    Date tempDate = date_; // set date parameter to dummy date to prevent "unused parameter" warning
    int wowza = tempDate.getMonth(); // do garbage with dummy date to prevent "set but not used" warning
    wowza -= 1;
    if (amount > 0)
    {
        if (amount <= balance) // if there is enough in balance to withdrawal
        {
            balance -= amount;
            return true;
        }
    }
    // else if amount is negative or not enough balance
    return false;
}
bool Account::deposit(double amount, Date date_)
{
    Date tempDate = date_; // set date parameter to dummy date to prevent "unused parameter" warning
    int wowza = tempDate.getMonth(); // do garbage with dummy date to prevent "set but not used" warning
    wowza -= 1;
    if (amount > 0) // if amount is positive
    {
        balance += amount;
        return true;
    }
    // else if amount if negative
    return false;
}
int Account::getAccountNumber() const
{
    return accountNumber;
}
double Account::getBalance() const
{
    return balance;
}
int Account::getNumberAccounts()
{
    return numberAccounts;
}
void Account::print() const
{
    cout << fixed; // turn on decimal
    cout << accountNumber << ", Name: " << ownerName << ", Balance: " <<  setprecision(2) << balance << " Galactic units" << endl;
}
