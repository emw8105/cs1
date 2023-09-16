#ifndef REGULARACCOUNT_H_INCLUDED
#define REGULARACCOUNT_H_INCLUDED

class RegularAccount : public Account
{
public:
    RegularAccount(string ownerName_, double balance_, Date date_);
    void print() const override;

};

#endif // REGULARACCOUNT_H_INCLUDED
