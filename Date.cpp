#include <iostream>
#include "Date.h"
using namespace std;

// defaulted constructor
Date::Date(int day_, int month_, int year_)
{
  setDay(day_);
  setMonth(month_);
  setYear(year_);
}
// setter 
void Date::setDay(int day_)
{
  while(day_ < 1 || day_ > 31) // checks id day is valid
  {
    cout << "Enter valid day: " << endl;
    cin >> day_;
  }
  day = day_;
}
void Date::setMonth(int month_)
{
  while(month_ < 1 || month_ > 12) // checks if month is valid
    {
      cout << "Enter valid month: " << endl;
      cin >> month_;
    }
    month = month_;
}
void Date::setYear(int year_)
{
  while (year_ < 2023 || year_ > 2030) // check if year is valid
    {
      cout << "Enter valid year: " << endl;
      cin >> year_;
    }
  year = year_;
}
// getters
int Date::getDay()
{
  return day;
}
int Date::getMonth()
{
  return month;
}
int Date::getYear()
{
  return year;
}
void Date::print() const
{
  cout << day << "/" << month << "/" << year << endl;  
} 