#include <iostream>

using namespace std;

#include "Date.h"

void Date::set(int month_, int day_, int year_, int hour_)
{
    month = month_;
    day = day_;
    year = year_;
    hour = hour_;
}
void Date::print() const
{
    string monthName[] = {"January", "February", "March",
    "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    // given a numerical month input, convert to the name of the month
    cout << monthName[month-1] << " ";
    // print remaining values in format
    cout << day << ", " << year << ", " << hour << ":00"; // output in structured format
}
int Date::getMonth() const
{
    return month;
}
int Date::getDay() const
{
    return day;
}
int Date::getYear() const
{
    return year;
}
int Date::getHour() const
{
    return hour;
}
