#pragma once
#include "Customer.h" 
#include"Medication.h"
#include"prescription.h"
#include "OffTheShelf.h"


class Pharmacy {
private:
  int PharmacyID_; //removed the const because when attempting to resize the area in the main, the id of the pharmacy would be change
  static int PhIdCounter;
  string name_;
  int NumCustomer_;
  int NumMedication_;
  int NumMedicationPresc;
  int NumMedicationOffTheShelf;
  //Medication* meds;
  Prescription* prescriptionArray;
  OffTheShelf* OffTheShelfArray;
  Customer* customers;
  
 


public:
  Pharmacy(string n = "N/A");
  Pharmacy(const Pharmacy& p2);
  ~Pharmacy();
  void AddOffShelfMedication(OffTheShelf& medication);
  void AddPrescMedication(Prescription& medication);
  void RemoveMedications(string medication);
 void RemoveprescMedications(string medication);
void RemoveoffthshelfMedications(string medication);
  void AddCustomer(const Customer& c);
  void DisplayCustomers()const;
  void DisplayMedication() const;
  float CalculateAVGtPrice();
  void CompareMedicationPrice(string medicationName, Pharmacy& pharmacy2);
  void NumberofMedication(Pharmacy& p);
  void NumberOfCustomers(Pharmacy& p)const;

  // setters
  void setid(int i);
  void setName(string name);
  void setNumCustomer(int NumCustomer);
  void setNumMed(int NumMed);
  void decrementMed(string);
  void setMedication(int i, Medication& m);
  void setCustomer(int i,Customer &c);
  void setPrescArray(Prescription* temp);
  void setOffTheArray(OffTheShelf* temp);
  //void setMedArr(Medication *m);
  //void setCusArr(Customer *c);
  //getter
  int getid() const;
  string getName()const;
  int getNumCustomer()const;
  int getNumMed()const;
  Medication *getMedication() ;
  Customer *getCustomer();
Prescription* getPrescription();
OffTheShelf* getOffTheShelf();
  //void getMedArr(Medication *m);
  //void getCusArr(Customer *c);  
  void NullArrays();
};