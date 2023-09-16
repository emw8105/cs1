#include <iostream>

using namespace std;

#include "Date.h"
#include "Account.h"
#include "PremiumAccount.h"

double const PremiumAccount::MIN_BALANCE = 1000;

PremiumAccount::PremiumAccount(string name, double amount, Date date):Account(name, amount, date)
{

}
void PremiumAccount::print() const
{
    cout << "Premium account, #: ";
    this->Account::print();
}
bool PremiumAccount::withdraw(double amount, Date date)
{
    if ((balance - amount) > 1000)
    {
        balance -= amount;
        return true;
    }
    else
        return false;
    Date tempDate = date; // set parameter date to dummy date to prevent "unused parameter" warning
    int wowza = tempDate.getMonth(); // do garbage with dummy date to prevent "set but not used" warning
    wowza -= 1;
}
