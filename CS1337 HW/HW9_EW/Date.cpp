#include <iostream>

using namespace std;

#include "Date.h"

string Date::monthName[] = {"January", "February", "March",
"April", "May", "June", "July", "August", "September", "October", "November", "December"};

void Date::set(int month_, int day_, int year_, int hour_)
{
    month = month_;
    day = day_;
    year = year_;
    hour = hour_;
} // constructor sets given data into member variables

bool Date::operator<(const Date &date2) // check if date d1 < d2 is true if d2 comes after d1 (d2 is bigger)
{
    if (year < date2.year) // check largest values first, hours dont matter if year is bigger
    {
        return true;
    }
    else if (year == date2.year) // when the given value is equal, move to the next largest value
    {
        if (month < date2.month)
        {
            return true;
        }
        else if (month == date2.month)
        {
            if (day < date2.day)
            {
                return true;
            }
            else if (day == date2.day)
            {
                if (hour < date2.hour)
                {
                    return true;
                }
            }
        }
    } // if any relational steps are false, then return false
    return false;
}
void Date::print() const
{
    // given a numerical month input, convert to the name of the month
    cout << monthName[month-1] << " ";
    // print remaining values in format
    cout << day << ", " << year << ", " << hour << ":00"; // output in structured format
}
int Date::getMonthFromDate() const
{
    return month;
}
int Date::getDayFromDate() const
{
    return day;
}
int Date::getYearFromDate() const
{
    return year;
}
int Date::getHourFromDate() const
{
    return hour;
}
