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
    static string monthName[13];
public:
    void set(int month_, int day_, int year_, int hour_);
    bool operator<(const Date &date2);
    void print() const;
    int getMonthFromDate() const;
    int getDayFromDate() const;
    int getYearFromDate() const;
    int getHourFromDate() const;
};

#endif // DATE_H_INCLUDED
