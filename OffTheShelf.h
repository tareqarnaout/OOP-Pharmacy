#pragma once
#include "Date.h"
#include "Medication.h"
class OffTheShelf : public Medication {
private:
    bool BOGOF_;  //dynamic member
    Date OfferEnds_;

public:
    // Constructor 
    OffTheShelf(Date ExpiryDate, string MedicationName = "", string Description = "none",
        float Price = 0, int QuantityInStock = 0, string Barcode = "00",
        bool BOGOF = false, const Date& OfferEnds = Date());
    OffTheShelf();
    // Setters
    void setBOGOF(bool bogof);
    void setOfferEnds(const Date& date);

    // Getters
    bool getBOGOF() const;
    Date getOfferEnds() const;
    // Print information about the medication (override)
    void Display() const;
    //~OffTheShelf();
};


