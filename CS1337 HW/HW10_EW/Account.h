#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

struct Transaction
{
    Date date;
    int transactionType; // 0, 1, 2 for account creation, deposit and withdrawal respectively
    double amount;
};

class Account
{

private:
    int accountNumber;
    string ownerName;
protected:
    double balance;
    static int numberAccounts;
    Transaction * transactionHistory;
    int numberTransactions;
public:
    Account(string ownerName_, double balance_, Date date_);
    virtual bool withdraw(double amount, Date date_);
    bool deposit(double amount, Date date_);
    int getAccountNumber() const;
    double getBalance() const;
    static int getNumberAccounts();
    virtual void print() const;
};

#endif // ACCOUNT_H_INCLUDED
