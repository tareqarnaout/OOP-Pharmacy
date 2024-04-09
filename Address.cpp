#include "Address.h"
#include <iostream>
#include <string>
using namespace std;

Address::Address()
{
    email = "noemailset@gmail.com";
    city = "No City Set";
    street = "No Street Set";
    pnumber = "000000000";
}
Address::Address(string e, string c, string p, string s)
{
    setEmail(e);
    setCity(c);
    setPnumber(p);
    setStreet(s);

}
void Address::setEmail(string e)
{
    int i = 0;
    while (i != e.length())
    {
        if (e[i == '@'])
        {
            for (int j = i; j < e.length(); j++)
                if (j + 3 < e.length() && e[j] == '.' && e[j + 1] == 'c' && e[j + 2] == 'o' && e[j + 3] == 'm') //if an email doesn't contain both @ and .com it is invalid
                {
                    email = e;
                    return;
                }
            i++;
        } //if we reached the end of the string and we didn't find both the @ symbol and .com we output an error message and ask them to renter, then repeat process
        if (i == e.length())
        {
            cout << "Invalid email address, please enter another one" << endl;
            cin >> e;
            i = 0;
        }
    }
}
void Address::setCity(string c)
{
    int i = 0;
    while (i != c.length())
    {
        if (c == "")
        {
            cout << "Please enter non-empty City Name";
            cin >> c;
            i = 0;
        }

        if (!((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z')) || (c[i] == ' ')) //if it contains any non-alphabetical characters or a space anywhre other then in the first letter, it is invalid
        {
            cout << "\nInvalid character. Please Re-enter City" << endl;
            cin >> c;
            i = 0;
        }
        else
        {
            i++;
        }
    }
    city = c;
}
void Address::setPnumber(string pn)
{
    {
        int i = 0;
        while (i != pn.length())
        {
            if (!(pn[i] >= '0' && pn[i] <= '9'))
            {
                cout << "\nInvalid character. Please Re-enter phone number" << endl; //if it contains any non-numeric characters it is invalid
                cin >> pn;
                i = 0;
            }
            else
            {
                i++;
            }
        }
        pnumber = pn;
    }
}
void Address::setStreet(string s)
{
    int i = 0;
    while (i != s.length())
    {
        if (s == "")
        {
            cout << "Please enter non-empty Street Name";
            cin >> s;
            i = 0;
        }

        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) || (s[i] == ' ')) //if it contains any non-alphabetical characters or a space anywhre other then in the first letter, it is invalid
        {
            cout << "\nInvalid character. Please Re-enter Street name" << endl;
            cin >> s;
            i = 0;
        }
        else
        {
            i++;
        }
    }
    street = s;
}
string Address::getEmail()const
{
    return email;
}
string Address::getCity()const
{
    return city;
}
string Address::getPnumber()const
{
    return pnumber;
}
string Address::getStreet()const
{
    return street;
}
void Address::print() const //prints details
{
    cout << "Address details:\nEmail: " << email << " \nPhone number: " << pnumber << "\nCity: " << city << " Street: " << street << endl;
}


