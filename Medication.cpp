//Passenger
#include "Medication.h"
#include <iostream>
using namespace std;
// parameterized constructor
Medication::Medication(Date ExpiryDate, string MedicationName, string Description,
    float Price, int QuantityInStock, string Barcode)
    : medId(1), ExpiryDate_(ExpiryDate) {
    setMedicationName(MedicationName);
    setDescription(Description);
    setBarcode(Barcode);
    setPrice(Price);
    setQuantityInStock(QuantityInStock);
}

//copy comnstructer
Medication::Medication(const Medication& m2):medId(++medIdCounter),MedicationName_(m2.MedicationName_), Description_(m2.Description_), Price_(m2.Price_),QuantityInStock_(m2.QuantityInStock_), ExpiryDate_(m2.ExpiryDate_),
Barcode_(m2.Barcode_)
{

}
// setters 


void Medication::setMedicationName(string name)  //makes sure medicine name is all letters

{

    int i = 0;
    while (i != name.length())
    {
        if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z')))
        {
            cout << "\nInvalid character. Please Re-enter name for medication : " << endl;
            cin >> name;
            i = 0;
        }
        else
        {
            i++;
        }
    }
    MedicationName_ = name;
}



void Medication::setDescription(string description_) { //makes sure description is all letters

    int i = 0;
    while (i != description_.length())
    {
        if (!((description_[i] >= 'A' && description_[i] <= 'Z') || (description_[i] >= 'a' && description_[i] <= 'z')))
        {
            cout << "\nInvalid character. Please Re-enter description for medication : " << MedicationName_ << endl;
            cin >> description_;
            i = 0;
        }
        else
        {
            i++;
        }
    }
    Description_ = description_;
}

void Medication::setBarcode(string Barcode) //makes sure the barcode is all numbers
{

    int i = 0;
    while (i != Barcode.length())
    {
        if (!(Barcode[i] >= '0' && Barcode[i] <= '9'))
        {
            cout << "\nInvalid character. Please Re-enter barcode for medication : " << MedicationName_ << endl;
            cin >> Barcode;
            i = 0;
        }
        else
        {
            i++;
        }
    }
    Barcode_ = Barcode;

}

void Medication::setPrice(float price_)
{
    while (price_ < 0)// make sure price isnt negative
    {
        cout << "Error in price, please enter a positive value" << endl;
        cin >> price_;
    }

    Price_ = price_;

}

void Medication::setQuantityInStock(int quantity_)
{
    while (quantity_ < 0) // make sure quantity isnt negative
    {
        cout << "Error in quantity, please enter a positive value" << endl;
        cin >> quantity_;
    }

    QuantityInStock_ = quantity_;
}

void Medication::setExpire(Date expire) // expiry setter
{
    ExpiryDate_.setDay(expire.getDay());
    ExpiryDate_.setMonth(expire.getMonth());
    ExpiryDate_.setYear(expire.getYear());
}

void Medication::setId(int id)
{
    medId = id;
}

// getters
int Medication::getMedId() const
{
    return medId;
}
string Medication::getMedicationName() const
{
    return MedicationName_;
}

string Medication::getDescription() const
{
    return Description_;
}


int Medication::getQuantityInStock() const
{
    return QuantityInStock_;
}

float Medication::getPrice() const
{
    return Price_;
}

string Medication::getBarcode() const
{
    return Barcode_;
}


Date Medication::getExpire() const
{
    return ExpiryDate_;
}
int Medication::getmedcounter()
{
    return medIdCounter;
}
// print info 
void Medication::Display() const
{
   
    cout << "Medication name is: " << MedicationName_ << endl;
    cout << "The price is: " << Price_ << endl;
    cout << "Med Description: " << Description_ << endl;
    cout << "Quantity in stock: " << QuantityInStock_ << endl;
    cout << "Best before: ";
    ExpiryDate_.print();
    cout << "Barcode: " << Barcode_ << endl;
}