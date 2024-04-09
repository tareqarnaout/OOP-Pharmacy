#include"Date.h"
#include"Medication.h"
#include"prescription.h"
using namespace std;

Prescription::Prescription(Date ExpiryDate, string MedicationName, string Description,
    float Price, int QuantityInStock, string Barcode, int FDAn, const Date& AD): Medication(ExpiryDate, MedicationName, Description, Price, QuantityInStock, Barcode),ApprovalDate(AD)
{
    FDANumber = new int;
    setFDANumber(FDAn);
}
Prescription::Prescription()
{
    FDANumber = nullptr;
}
Prescription::Prescription(const Prescription& p) :FDANumber(p.FDANumber), ApprovalDate(p.ApprovalDate) {}
void Prescription::setFDANumber(int newFDANumber) {
    if (newFDANumber >= 0) {
        FDANumber = new int;
        (*FDANumber) = newFDANumber;
    }
    else
        cout << "invalid number";
}
void Prescription::setApprovalDate(const Date& newApprovalDate) {
    ApprovalDate = newApprovalDate;
}
int Prescription::getFDANumber() const {
    return (*FDANumber);
}

Date Prescription::getApprovalDate() const {
    return ApprovalDate;
}//overiding Medication's display
void Prescription::Display()const {
    //printing medication
    Medication::Display(); 
    //printing prescription
    cout << "\nFDANumber: " << FDANumber << endl;
    cout << "\nApprovalDate: ";
    ApprovalDate.print();
}

Prescription::~Prescription()
{
    if (FDANumber != nullptr) {
        delete FDANumber;
        FDANumber = nullptr;  
    }
}




