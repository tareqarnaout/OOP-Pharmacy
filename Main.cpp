#include <iostream>
#include "Customer.h"
#include "Date.h"
#include "Medication.h"
#include "OffTheShelf.h"
#include "pharmacy.h"
#include "prescription.h"


using namespace std;
int Medication::medIdCounter = 0;
int Customer::customercounter = 0;
int Pharmacy::PhIdCounter = 0;
//int pCounter = 0;
Pharmacy* pharmacies;
int pnumber = 0;
int validatepharm() // checks if the pharmacy given from user if exists or not
{
    if (pnumber == 0) {
        cout << "There is no pharmacy created to access\n";
        return 0;
    }
    else {
        string name;
        cout << "Enter the name of the pharmacy you would like to access" << endl;
        cin >> name;
        for (int i = 0; i < pnumber; i++) {
            if (pharmacies[i].getName() == name)
                return i + 1;
        }
        cout << "Pharmacy not found" << endl;
        return 0;
    }
}
void checkname(string n, int i, Pharmacy p[]) // ensuring no pharmacy naming duplicts, array
// paramter to use it for during resizing as well
{
    for (int i = 0; i < pnumber; i++) {
        while ((n) == pharmacies[i].getName()) {
            cout << "Name taken, please rename ";
            cin >> n;
        }
    }
    p[i].setName(n);
}

int main() {

    /*Creating the required 4 objects:
    Date e1(1, 1, 2025);
    string n1 = "Pandol";
    string d1 = "Painkiller";
    string b1 = "12345678";
    float p1 = 10;
    int q1 = 10;
    Date OfferEnds(2, 2, 2024);
    OffTheShelf obj1(e1, n1, d1, p1, q1, b1, true, OfferEnds); // An object in
    static memory with attributes in static memory (ex:OfferEnds) and dynamic
    memory(BOGOF_) OffTheShelf* ofs = new OffTheShelf(e1, n1, d1, p1, q1, b1,
    true, OfferEnds); // An object in dynamic memory with attributes in static
    memory (ex:OfferEnds) and dynamic memory(BOGOF_)

    Date e2(1, 1, 2025);
    string n2 = "xanax ";
    string d2 = "Anxiety";
    string b2 = "348454958";
    float p2 = 10;
    int q2 = 10;
    int FDA = 456789;
    Date AD (1, 3, 2024);

    Prescription obj2(e2, n2, d2, p2, q2, b2, FDA, AD);  //An object in static
    memory with attributes in static memory(ex:ApprovalDate) and dynamic
    memory(FDANumber); Prescription *pres= new Prescription(e2, n2, d2, p2, q2,
    b2, FDA, AD); //An object in dynamic memory with attributes in static
    memory(ex:ApprovalDate) and dynamic memory(FDANumber);

    cout<< "Medicine Report";
    obj1.display();
    (*ofs).display();
    obj2.display();
    (*pres).display();

    delete ofs;
    delete pres;
    */
    char choice;
    //Date expiryDate;

    do {
        cout << "\n\nChoose what you want:\n"
            << "1- if you want to create a new array of pharmacies enter 'f'\n"
            << "2-if you want to resize the array of pharmacies enter 'g'\n"
            << "3- if you want to add the medication enter 'b'\n"
            << "4-  if you went to add customer  enter 'c'\n"
            << "5- if you want to display customer enter 'd'\n"
            << "6- if you want to display medications enter 'o'\n "
            << "7 - if you want to make a purchase enter 'h'\n"
            << "8- if you want to delete a medication enter 'm'\n"
            << "9- if you want to compare pharmacies enter 'r'\n"
            << "10-  if you want to exit enter 'e'\n\n";
        cin >> choice;
        if (choice == 'f') {
            if (pharmacies != NULL)
            {
                delete[]pharmacies;
            }
            cout << "How many pharmacies do you want in your array? ";
            cin >> pnumber;
            pharmacies = new Pharmacy[pnumber];

            for (int i = 0; i < pnumber; i++) {
                string name;
                cout << "enter Pharmacy " << i + 1 << "'s name " << endl;
                cin >> name;
                checkname(name, i, pharmacies);
            }
        }
        
        else if (choice == 'g') {
            if (pharmacies != NULL) {
                int newnumber;
                cout << "What would you like to resize it to? ";
                cin >> newnumber;
                Pharmacy* temp = new Pharmacy[newnumber];
                if (newnumber > pnumber) {
                    for (int i   = 0; i < pnumber; i++) {
                        temp[i].setid(pharmacies[i].getid());
                        temp[i].setName(pharmacies[i].getName());
                      // get the address of the heap array and give it to the new pharmacy array same for address
                        temp[i].setPrescArray(pharmacies[i].getPrescription());
                        temp[i].setOffTheArray(pharmacies[i].getOffTheShelf());
                        pharmacies[i].NullArrays();

                        
                        
                    }

                    for (int i = pnumber; i < newnumber; i++) {
                        string name;
                        cout << "enter Pharmacy " << i + 1 << "'s name " << endl;
                        cin >> name;
                        checkname(name, i, temp);
                    }
                    
                    delete[] pharmacies;
                    pharmacies = temp;
                    temp = NULL;
                    pnumber = newnumber;
                    // testing
                    for (int i = 0; i < pnumber; i++)
                    {
                        cout << pharmacies[i].getName() << endl;
                    }
                }
                else if (pnumber > newnumber) {
                    //int del = pnumber - newnumber;
                    for (int i = 0; i < newnumber; i++) {
                        temp[i].setid(pharmacies[i].getid());
                        temp[i].setName(pharmacies[i].getName());
                        temp[i].setPrescArray(pharmacies[i].getPrescription());
                        temp[i].setOffTheArray(pharmacies[i].getOffTheShelf());
                        pharmacies[i].NullArrays();
                      
                        
                        temp[i].setNumCustomer(pharmacies[i].getNumCustomer());
                        temp[i].setNumMed(pharmacies[i].getNumMed());
                        
                    }
                    delete[] pharmacies;
                    pharmacies = temp;
                    temp = NULL;
                    pnumber = newnumber;
                    // testing causese
                    for (int i = 0; i < pnumber; i++)
                    {
                        cout << pharmacies[i].getName() << endl;
                    }

                }
                else
                    cout << "This is the current value, please pick a different value";
            }
            else
                cout << "No Pharmacies Array Created to resize";

        }

        else if (choice == 'b') // add med
        {
            int index = validatepharm();
            if (index != 0) {
                cout << " what type of mid for off the shelf enter 1 for prescription enter 2" << endl;
                int choice;
                cin >> choice;
                if (choice == 1)
                {
                    string name, description, barcode;
                    float price;
                    int quantity;
                   


                    cout << "Enter Medication Name: ";
                    cin >> name;
                    cout << "Enter Description: ";
                    cin >> description;
                    cout << "Enter Expiry Date: ";
                    int day, month, year;
                    cin >> day >> month >> year;
                  

                    Date expiryDate(day, month, year); // expiry object for the med

                    cout << "Enter Barcode: ";
                    cin >> barcode;
                    cout << "Enter Price: ";
                    cin >> price;
                    cout << "Enter Quantity in Stock: ";
                    cin >> quantity;
                    cout << "when does the offer end" << endl;
                   
                    int endDay, endMonth, endYear;
                    cin >> endDay >> endMonth >> endYear;
                    Date endOffer(endDay, endMonth, endYear);
                    OffTheShelf offTheShelfMed(expiryDate, name, description, price, quantity, barcode,true, endOffer);
                    pharmacies[index - 1].AddOffShelfMedication(offTheShelfMed); // index -1 to add to array
                }
                else if (choice == 2)
                {
                    string name, description, barcode;
                    float price;
                    int quantity;
                    


                    cout << "Enter Medication Name: ";
                    cin >> name;
                    cout << "Enter Description: ";
                    cin >> description;
                    cout << "Enter Expiry Date: ";
                    int day, month, year;
                    cin >> day >> month >> year;
                  

                    Date expiryDate(day, month, year); // expiry object for the med

                    cout << "Enter Barcode: ";
                    cin >> barcode;
                    cout << "Enter Price: ";
                    cin >> price;
                    cout << "Enter Quantity in Stock: ";
                    cin >> quantity;
                    
                    int fda;
                    cout << "enter fda number " << endl;
                    cin >> fda;
                    cout << "enter approval date" << endl;
                    int approvalDay, approvalMonth, approvalYear;
                    cin >> approvalDay >> approvalMonth >> approvalYear;
                    Date endOffer(approvalDay, approvalMonth, approvalYear);
                    Prescription prescriptionmMed(expiryDate, name, description, price, quantity, barcode, fda, endOffer);
                    pharmacies[index - 1].AddPrescMedication(prescriptionmMed); // index -1 to add to array
                }
                

             
            }
        }
        else if (choice == 'c') { // add customer
            int index = validatepharm();
            if (index != 0) {
                if (pharmacies[index - 1].getNumCustomer() <= 50) {
                    Address address;
                    Customer c;
                    string cname;
                    cout << "\nEnter Customer Name: \n";
                    cin >> cname;
                    c.setcname(cname);
                    cout << "\nEnter Address:";
                    string email, city, pnum, street;
                    cout << "\nEnter Email:";
                    cin >> email;
                    address.setEmail(email);
                    cout << "Enter city: ";
                    cin >> city;
                    address.setCity(city);
                    cout << "Enter phone number: ";
                    cin >> pnum;
                    address.setPnumber(pnum);
                    cout << "Enter Street: ";
                    cin >> street;
                    address.setStreet(street);
                    c.setcaddress(address);
                    pharmacies[index - 1].AddCustomer(c); // index -1 to search array
                }
                else
                    cout << " Sorry, the customer array is full\n";
            }
        }

        else if (choice == 'd') {
            int index = validatepharm();
            if (index != 0)
                pharmacies[index - 1].DisplayCustomers(); // index -1 to search array
        }
        else if (choice == 'o') {
            int index = validatepharm();
            if (index != 0)
                pharmacies[index - 1].DisplayMedication(); // index -1 to search array
        }
        else if (choice == 'h')                      // purchasing medication
        {
            int index = validatepharm();
            if (index != 0) {
                string medName;
                cout << "What's the medication name?" << endl;
                cin >> medName;
                pharmacies[index - 1].decrementMed(medName);
            }
        }

      

        else if (choice == 'r') {
            char choice2;
            do {

                cout << "Choose what you want:\n"
                    << "1- if you want to compare the price for a specfic medication "
                    "enter 'p'\n"
                    << "2- if you want to compare the number of customers enter 'c'\n"
                    << "3-  if you went to compare the number of medications enter "
                    "'m'\n"
                    << "4- if you want to compare the average price of the "
                    "medications enter 'a'\n"
                    << "5- if you want to go back to main menu enter 'e'\n\n";
                cin >> choice2;
                if (pnumber <= 1) // checks there are at least 2 pharmacies to compare
                {
                    cout << "Not enough Pharmacies to compare" << endl;
                    choice2 = 'e';
                }

                else if (choice2 == 'p') { // compares price of medicine
                    cout << "For the first pharmacy: ";
                    int p1 = validatepharm();
                    cout << "For the second pharmacy: ";
                    int p2 = validatepharm();
                    if (p1 != 0 && p2 != 0) {
                        cout << "enter the name of the medicine\n";
                        string mname;
                        cin >> mname;
                        pharmacies[p1 - 1].CompareMedicationPrice(mname,
                            pharmacies[p2 - 1]);
                    }

                }
                else if (choice2 == 'c') { // compares number of customers
                    cout << "For the first pharmacy: ";
                    int p1 = validatepharm();
                    cout << "For the second pharmacy: ";
                    int p2 = validatepharm();
                    if (p1 != 0 && p2 != 0) {
                        pharmacies[p1 - 1].NumberOfCustomers(pharmacies[p2 - 1]);
                    }
                }
                else if (choice2 == 'm') { // compares total number of medication
                    cout << "For the first pharmacy: ";
                    int p1 = validatepharm();
                    cout << "For the second pharmacy: ";
                    int p2 = validatepharm();
                    if (p1 != 0 && p2 != 0) {
                        pharmacies[p1 - 1].NumberofMedication(pharmacies[p2 - 1]);
                    }
                }
                else if (choice2 == 'a') { // compares which pharmacy is more
                    // expensive on average
                    cout << "For the first pharmacy: ";
                    int p1 = validatepharm();
                    cout << "For the second pharmacy: ";
                    int p2 = validatepharm();
                    if (p1 != 0 && p2 != 0) {
                        if (pharmacies[p1 - 1].CalculateAVGtPrice() >
                            pharmacies[p2 - 1].CalculateAVGtPrice()) {
                            cout << "**************************************" << endl;
                            cout << pharmacies[p1 - 1].getName()
                                << " has a higher average price than "
                                << pharmacies[p2 - 1].getName() << endl;
                            cout << "**************************************" << endl;
                        }
                        else if (pharmacies[p1 - 1].CalculateAVGtPrice() <
                            pharmacies[p2 - 1].CalculateAVGtPrice()) {
                            cout << "**************************************" << endl;
                            cout << pharmacies[p2 - 1].getName()
                                << " has a higher average price than "
                                << pharmacies[p1 - 1].getName() << endl;
                            cout << "**************************************" << endl;
                        }
                        else {
                            cout << "**************************************" << endl;
                            cout << "Both have the same average" << endl;
                            cout << "**************************************" << endl;
                        }
                    }
                }
            } while (choice2 != 'e');

        }

        else if (choice == 'e') {
            cout << "Exiting the program." << endl;
        }
        else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
        cout << "\n";

    } while (choice != 'e');
    if (pharmacies != NULL)
    {
        delete[] pharmacies;
        pharmacies = nullptr;
    }
    return 0;
}
