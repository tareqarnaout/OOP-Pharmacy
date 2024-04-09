#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
  int day;
  int month;
  int year;
public:
  // defaulted constructor
  Date(int day_ = 1, int month_ = 1,int year = 2023);
  // setter 
  void setDay(int day_);
  void setMonth(int month_);
  void setYear(int year_);
  // getters
  int getDay();
  int getMonth();
  int getYear();
  void print() const;
};