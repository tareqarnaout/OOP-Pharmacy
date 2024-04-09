
#include "Date.h"
#include "Medication.h"
#include "OffTheShelf.h" 


OffTheShelf::OffTheShelf()
{
    BOGOF_ = false;
}
OffTheShelf::OffTheShelf(Date ExpiryDate, string MedicationName, string Description,
    float Price, int QuantityInStock, string Barcode,
    bool BOGOF, const Date& OfferEnds)
    : Medication(ExpiryDate, MedicationName, Description, Price, QuantityInStock, Barcode),
    BOGOF_(new bool(BOGOF)), OfferEnds_(OfferEnds) {}

//setters
void OffTheShelf::setBOGOF(bool bogof) {
    BOGOF_ = bogof;
    if (!BOGOF_) {
        OfferEnds_.setYear(OfferEnds_.getYear() + 2);
    }
    else {
        OfferEnds_.setMonth(OfferEnds_.getMonth() + 3);
    }
}

void  OffTheShelf::setOfferEnds(const Date& date) {
    OfferEnds_ = date;
}

// Getters
bool OffTheShelf::getBOGOF() const {
    return BOGOF_;
}


Date OffTheShelf::getOfferEnds() const {
    return OfferEnds_;
}


// Print information about the medication (override )
void OffTheShelf::Display() const {
    Medication::Display();
    // Print object's attributes
    cout << "BOGOF: " << (BOGOF_ ? "Yes" : "No") << "\nOffer Ends: ";
    OfferEnds_.print();
}
/*OffTheShelf::~OffTheShelf()
{
    if (BOGOF_ != nullptr) {
        delete BOGOF_;
        BOGOF_ = nullptr; 
    }

}*/
