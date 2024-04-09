#include "Customer.h"
#include "Address.h"
#include <iostream>
using namespace std;

Customer::Customer()
    : cid(1), cname("noname"),
      caddress(Address("noemailset@gmail.com", "NoCitySet", "0000000",
                       "NoStreetSet")) {}
Customer::Customer(string cn, Address a) : cid(++customercounter) {
  setcname(cn);
  setcaddress(a);
}
// copy constructor
Customer::Customer(const Customer &c2)
    : cid(++customercounter), cname(c2.cname), caddress(c2.caddress) {}

// setters
void Customer::setcname(string cn) // checks a name is all letters
{
  int i = 0;
  while (i != cn.length()) {
    if (!((cn[i] >= 'A' && cn[i] <= 'Z') || (cn[i] >= 'a' && cn[i] <= 'z'))) {
      cout << "\nInvalid character. Please Re-enter Name for id: " << cid
           << endl;
      cin >> cn;
      i = 0;
    } else {
      i++;
    }
  }
  cname = cn;
}

void Customer::setId(int id)
{
    cid = id;
}

int Customer::getcid() const { return cid; }
string Customer::getcname() const { return cname; }

// prints customer attributes
void Customer::print() const {
  cout << "customer name: " << cname << endl;
  caddress.print();
}

int Customer::getcustomercounter() { return customercounter; }
// destructor
//Customer::~Customer() { --customercounter; }
// getters
Address Customer::getcaddress() const { return caddress; }
void Customer::setcaddress(const Address &a) {
  caddress.setEmail(a.getEmail());
  caddress.setCity(a.getCity());
  caddress.setStreet(a.getStreet());
  caddress.setPnumber(a.getPnumber());
}
