#ifndef PREMIUMACCOUNT_H_INCLUDED
#define PREMIUMACCOUNT_H_INCLUDED



class PremiumAccount : public Account
{
private:
    static const double MIN_BALANCE;

public:
    PremiumAccount(string name, double amount, Date date);
    bool withdraw(double amount, Date date) override;
    static double getMinBalance();
    void print() const override;
};


#endif // PREMIUMACCOUNT_H_INCLUDED
