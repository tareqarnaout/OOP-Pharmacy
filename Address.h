#pragma once
#include <iostream>
#include <string>

using namespace std;

class Address {
  string email, city, pnumber, street;
public:
  Address();
  Address(string e, string c, string p, string s);
  void setEmail(string e);
  void setCity(string c);
  void setPnumber(string pn);
  void setStreet(string s);
  string getEmail() const;
  string getCity()const;
  string getPnumber()const;
  string getStreet()const;
  void print() const;
};

