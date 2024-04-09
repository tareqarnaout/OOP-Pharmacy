#pragma once
#include <string>
#include "Date.h"
using namespace std;

class Medication {
private:
  int medId;
  string MedicationName_;
  string Description_;
  float Price_;
  int QuantityInStock_;
  Date ExpiryDate_;
  string Barcode_;
  static int medIdCounter;

public:

  Medication(Date ExpiryDate = Date(), string MedicationName = "NoName", string Description = "NoDescription", float Price = 0.0, int QuantityInStock = 0, string Barcode = "000000");
  Medication(const Medication& m2);
  // setters
  void setId(int id);
  void setMedicationName(string);

  void setDescription(string);

  void setPrice(float);

  void setQuantityInStock(int);

  void setBarcode(string);
  void setExpire(Date);// change
  // getters 
  int getMedId() const;
  string getMedicationName() const;

  string getDescription() const;

  Date getExpire() const;// change

  int getQuantityInStock() const;

  float getPrice() const;

  string getBarcode() const;

  static int getmedcounter();

  void Display() const;



};





