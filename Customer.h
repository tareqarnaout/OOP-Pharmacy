#pragma once
#include <iostream>
#include <string>
#include "Address.h"
using namespace std;
class Customer {
  int cid;
  string cname;
  // customer id variable
  Address caddress;
  static int customercounter;

public:
  Customer();
  Customer(string cn, Address a);
  Customer(const Customer& c2);
  void setcname(string cn);
  void setId(int id);
  int getcid() const;
  string getcname() const;
  void setcaddress(const Address& a);
  Address getcaddress()const;
  void print() const;
  static int getcustomercounter();
  //~Customer();
};