#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <string>
using namespace std;

class Date
{
private:
    int month; // dates represented as mm/dd/yyyy/hh
    int day;
    int year;
    int hour;
public:
    void set(int month_, int day_, int year_, int hour_);
    bool operator==(const Date &date2);
    bool operator<(const Date &date2);
    bool operator<=(const Date &date2);
    int operator-(const Date &date2);
    void print();

};

#endif // DATE_H_INCLUDED
