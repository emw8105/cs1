#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

using namespace std;

class Date
{
private:
    int month, day, year, hour; // dates represented as mm/dd/yyyy/hh

public:
    void set(int month_, int day_, int year_, int hour_);
    void print() const;
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    int getHour() const;
};


#endif // DATE_H_INCLUDED
