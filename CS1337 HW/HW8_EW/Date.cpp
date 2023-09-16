#include <iostream>

using namespace std;

#include "Date.h"

void Date::set(int month_, int day_, int year_, int hour_)
{
    month = month_;
    day = day_;
    year = year_;
    hour = hour_;
} // constructor sets given data into member variables
bool Date::operator==(const Date &date2)
{
    return ((month == date2.month) && (day == date2.day) && (year == date2.year) && (hour == date2.hour));
} // check to make sure each date value is equivalent
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
bool Date::operator<=(const Date &date2) // check if date d1 <= d2 is true if d2 comes after d1 (d2 is bigger) or if d2 is equal to d1
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
                else if (hour == date2.hour)
                {
                    return true;
                }
            }
        }
    } // if any relational steps are false, then return false
    return false;
}
int Date::operator-(const Date &date2) // convert all values to hours and substract
{
    int monthToDay[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}; // array of num days from Jan 1 to 1st of each month
    int d1Hours = (365*(year-1) + monthToDay[month-1] + day)*24 + hour; // calculate the number of hours in the first date
    int d2Hours = (365*(date2.year-1) + monthToDay[date2.month-1] + date2.day)*24 + date2.hour; // calculate the number of hours in the second date
    return d1Hours - d2Hours; // subtract the values from each other
}
void Date::print()
{
    // given a numerical month input, convert to the name of the month
    if (month == 1)
    {
        cout << "January ";
    }
    else if (month == 2)
    {
        cout << "February ";
    }
    else if (month == 3)
    {
        cout << "March ";
    }
    else if (month == 4)
    {
        cout << "April ";
    }
    else if (month == 5)
    {
        cout << "May ";
    }
    else if (month == 6)
    {
        cout << "June ";
    }
    else if (month == 7)
    {
        cout << "July ";
    }
    else if (month == 8)
    {
        cout << "August ";
    }
    else if (month == 9)
    {
        cout << "September ";
    }
    else if (month == 10)
    {
        cout << "October ";
    }
    else if (month == 11)
    {
        cout << "November ";
    }
    else if (month == 12)
    {
        cout << "December ";
    }
    cout << day << ", " << year << ", " << hour << ":00"; // output in structured format
}
