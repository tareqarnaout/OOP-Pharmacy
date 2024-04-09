#pragma once
#include <iostream>
using namespace std;
#include "Date.h"
#include "Medication.h"
class Prescription : public Medication {
private:
  int *FDANumber; // dynamic member
  Date ApprovalDate;

public:
  Prescription(Date ExpiryDate, string MedicationName, string Description,
               float Price, int QuantityInStock, string Barcode, int FDAn,
               const Date &AD);
  Prescription();
  Prescription(const Prescription &p);

  void setFDANumber(int newFDANumber);
  void setApprovalDate(const Date &newApprovalDate);
  int getFDANumber() const;
  Date getApprovalDate() const;
  void Display() const;
  ~Prescription();
};
