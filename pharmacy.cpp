#include "pharmacy.h"
#include "Customer.h"
#include "Medication.h"
#include "OffTheShelf.h"
#include "prescription.h"
#include <iostream>


using namespace std;
// defaulted constructor
Pharmacy::Pharmacy(string n)
: PharmacyID_(++PhIdCounter), name_(n), NumCustomer_(0), NumMedication_(0), NumMedicationPresc(0), NumMedicationOffTheShelf(0), prescriptionArray(NULL), OffTheShelfArray(NULL), customers(NULL) {

}

// destructor decrements number of customers and number of medications
Pharmacy::~Pharmacy() {
    if(customers != NULL)
    {
      NumCustomer_--;
      delete[] customers;
      customers = nullptr;
    }
    if (prescriptionArray != NULL)
    {
      delete[] prescriptionArray;
      prescriptionArray = NULL;
    }
    if (OffTheShelfArray != NULL)
    {
      delete[] OffTheShelfArray;
      OffTheShelfArray = NULL;
    }
    NumMedication_--;
    //delete[] meds;

    //meds = nullptr;
}

//deep copy constructer 
Pharmacy::Pharmacy(const Pharmacy& p2) :PharmacyID_(p2.PharmacyID_), name_(p2.name_), NumCustomer_(p2.NumCustomer_), NumMedication_(p2.NumMedication_),NumMedicationPresc(p2.NumMedicationPresc),NumMedicationOffTheShelf(p2.NumMedicationOffTheShelf)
{    prescriptionArray = new Prescription[p2.NumMedicationPresc];
    for (int i = 0; i < NumMedicationPresc; ++i) {
          prescriptionArray[i] = p2.prescriptionArray[i];
      
        OffTheShelfArray = new OffTheShelf[p2.NumMedicationOffTheShelf];
      for (int i = 0; i < NumMedicationOffTheShelf; ++i) {
              OffTheShelfArray[i] = p2.OffTheShelfArray[i];
    }


    customers = new Customer[NumCustomer_];
    for (int i = 0; i < NumCustomer_; ++i) {
        customers[i] = p2.customers[i];
    }

}
}
void Pharmacy::AddOffShelfMedication(OffTheShelf& medication) {
    // make sure Medication doesnt already exsist in list
    bool flag = false;
    if (OffTheShelfArray != NULL)
    {
        for (int i = 0; i < NumMedicationOffTheShelf; i++)
        {
            if (OffTheShelfArray[i].getMedicationName() == medication.getMedicationName())
            {
                cout << "Medication aready exists in list" << endl;
                flag = true;
                break;
            }
        }

        if (flag == false)
        {
            OffTheShelf* temp = new OffTheShelf[NumMedicationOffTheShelf];
            //Medication* temp = new Medication[NumMedication_ + 1];
            for (int i = 0; i < NumMedicationOffTheShelf; i++)
            {
                temp[i].setBarcode(OffTheShelfArray[i].getBarcode());
                temp[i].setDescription(OffTheShelfArray[i].getDescription());
                temp[i].setExpire(OffTheShelfArray[i].getExpire());
                temp[i].setMedicationName(OffTheShelfArray[i].getMedicationName());
                temp[i].setPrice(OffTheShelfArray[i].getPrice());
                temp[i].setQuantityInStock(OffTheShelfArray[i].getQuantityInStock());
                temp[i].setId(OffTheShelfArray[i].getMedId());
                temp[i].setBOGOF(OffTheShelfArray[i].getBOGOF());
                temp[i].setOfferEnds(OffTheShelfArray[i].getOfferEnds());

            }
            delete[]OffTheShelfArray;
            OffTheShelfArray = temp;
            temp = NULL;
            OffTheShelfArray[NumMedicationOffTheShelf] = OffTheShelf(medication);
            NumMedicationOffTheShelf++;
            NumMedication_++;
            cout << "shelf Medication Added Successfully";
        }

    }
    else if (OffTheShelfArray == NULL)
    {
        OffTheShelfArray = new OffTheShelf[1];
        OffTheShelfArray[0] = OffTheShelf(medication);
       
        NumMedicationOffTheShelf++;
        NumMedication_++;
        cout << " shelf Medication added successfully" << endl;
    }
}


void Pharmacy::AddPrescMedication(Prescription& medication) {
    // make sure Medication doesnt already exsist in list
    bool flag = false;
    if (prescriptionArray != NULL)
    {
        for (int i = 0; i < NumMedicationPresc; i++)
        {
            if (prescriptionArray[i].getMedicationName() == medication.getMedicationName())
            {
                cout << "Medication aready exists in list" << endl;
                flag = true;
                break;
            }
        }

        if (flag == false)
        {
            Prescription* temp = new Prescription[NumMedicationOffTheShelf];
            //Medication* temp = new Medication[NumMedication_ + 1];
            for (int i = 0; i < NumMedicationPresc; i++)
            {
                temp[i].setBarcode(prescriptionArray[i].getBarcode());
                temp[i].setDescription(prescriptionArray[i].getDescription());
                temp[i].setExpire(prescriptionArray[i].getExpire());
                temp[i].setMedicationName(prescriptionArray[i].getMedicationName());
                temp[i].setPrice(prescriptionArray[i].getPrice());
                temp[i].setQuantityInStock(prescriptionArray[i].getQuantityInStock());
                temp[i].setId(prescriptionArray[i].getMedId());
                temp[i].setFDANumber(prescriptionArray[i].getFDANumber());
                temp[i].setApprovalDate(prescriptionArray[i].getApprovalDate());

            }
            delete[]prescriptionArray;
            prescriptionArray = temp;
            temp = NULL;
            NumMedicationPresc++;
            NumMedication_++;
            prescriptionArray[NumMedicationPresc].setExpire(medication.getExpire());
            prescriptionArray[NumMedicationPresc].setMedicationName(medication.getMedicationName());
            prescriptionArray[NumMedicationPresc].setDescription(medication.getDescription());
            prescriptionArray[NumMedicationPresc].setPrice(medication.getPrice());
            prescriptionArray[NumMedicationPresc].setQuantityInStock(medication.getQuantityInStock());
            prescriptionArray[NumMedicationPresc].setBarcode(medication.getBarcode());
            prescriptionArray[NumMedicationPresc].setFDANumber(medication.getFDANumber());
            prescriptionArray[NumMedicationPresc].setApprovalDate(medication.getApprovalDate());
          
            cout << " presc Medication Added Successfully";
        }

    }
    else if (OffTheShelfArray == NULL)
    {
        prescriptionArray = new Prescription[1];
        prescriptionArray[NumMedicationPresc].setExpire(medication.getExpire());
        prescriptionArray[NumMedicationPresc].setMedicationName(medication.getMedicationName());
        prescriptionArray[NumMedicationPresc].setDescription(medication.getDescription());
        prescriptionArray[NumMedicationPresc].setPrice(medication.getPrice());
        prescriptionArray[NumMedicationPresc].setQuantityInStock(medication.getQuantityInStock());
        prescriptionArray[NumMedicationPresc].setBarcode(medication.getBarcode());
        prescriptionArray[NumMedicationPresc].setFDANumber(medication.getFDANumber());
        prescriptionArray[NumMedicationPresc].setApprovalDate(medication.getApprovalDate());
        
        NumMedicationPresc++;
        NumMedication_++;
        cout << "presc Medication added successfully" << endl;
    }
}


void Pharmacy::RemoveoffthshelfMedications(string medication) {
    // validation to make sure that the number of medication are not over the
    // array size
    if (OffTheShelfArray != NULL) {
        // find index with the name of medication that will be deleted
        int index = -1;
        for (int i = 0; i < NumMedicationOffTheShelf; i++) {
            if (OffTheShelfArray[i].getMedicationName() == medication) {
                index = i;
                break; // once found break
            }
        }

        if (index != -1)
        {
            OffTheShelf* temp = new OffTheShelf[NumMedicationOffTheShelf - 1];
            for (int i = 0, j = 0; i < NumMedicationOffTheShelf; i++)
            {
                if (i != index)
                {
                    temp[j++].setBarcode(OffTheShelfArray[i].getBarcode());
                    temp[j++].setDescription(OffTheShelfArray[i].getDescription());
                    temp[j++].setExpire(OffTheShelfArray[i].getExpire());
                    temp[j++].setMedicationName(OffTheShelfArray[i].getMedicationName());
                    temp[j++].setPrice(OffTheShelfArray[i].getPrice());
                    temp[j++].setQuantityInStock(OffTheShelfArray[i].getQuantityInStock());
                    temp[j++].setId(OffTheShelfArray[i].getMedId());
                    temp[j++].setBOGOF(OffTheShelfArray[i].getBOGOF());
                    temp[j++].setOfferEnds(OffTheShelfArray[i].getOfferEnds());
                }
            }
            delete[]OffTheShelfArray; // delete  old meds 
            OffTheShelfArray = temp; // meds now points to temp array in heap 
            temp = NULL; // temp points to nothing
            NumMedicationOffTheShelf--;
        }
        cout << "Medication removed successfully." << endl;
    }
    else
    {
        // if medication does not exist
        cout << "Medication not found" << endl;
    }
}
void Pharmacy::RemoveprescMedications(string medication) {
    // validation to make sure that the number of medication are not over the
    // array size
    if (prescriptionArray != NULL) {
        // find index with the name of medication that will be deleted
        int index = -1;
        for (int i = 0; i < NumMedicationPresc; i++) {
            if (prescriptionArray[i].getMedicationName() == medication) {
                index = i;
                break; // once found break
            }
        }

        if (index != -1)
        {
            Prescription* temp = new Prescription[NumMedicationPresc - 1];
            for (int i = 0, j = 0; i < NumMedicationPresc; i++)
            {
                if (i != index)
                {
                    temp[j++].setBarcode(prescriptionArray[i].getBarcode());
                    temp[j++].setDescription(prescriptionArray[i].getDescription());
                    temp[j++].setExpire(prescriptionArray[i].getExpire());
                    temp[j++].setMedicationName(prescriptionArray[i].getMedicationName());
                    temp[j++].setPrice(prescriptionArray[i].getPrice());
                    temp[j++].setQuantityInStock(prescriptionArray[i].getQuantityInStock());
                    temp[j++].setId(prescriptionArray[i].getMedId());
                    temp[j++].setFDANumber(prescriptionArray[i].getFDANumber());
                    temp[j++].setApprovalDate(prescriptionArray[i].getApprovalDate());
                }
            }
            delete[]prescriptionArray; // delete  old meds 
            prescriptionArray = temp; // meds now points to temp array in heap 
            temp = NULL; // temp points to nothing
            NumMedicationPresc--;
        }
        cout << "Medication removed successfully." << endl;
    }
    else
    {
        // if medication does not exist
        cout << "Medication not found" << endl;
    }
}

void Pharmacy::AddCustomer(const Customer& obj) {
    // make sure Medication doesnt already exsist in list
    bool flag = false;
    if (customers != NULL)
    {
        for (int i = 0; i < NumCustomer_; i++)
        {
            if (customers[i].getcname() == obj.getcname() &&
                customers[i].getcaddress().getPnumber() ==
                obj.getcaddress().getPnumber() &&
                customers[i].getcaddress().getEmail() ==
                obj.getcaddress().getEmail()) {
                cout << "Customer aready exists in list" << endl;
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            Customer* temp = new Customer[NumCustomer_ + 1];
            for (int i = 0; i < NumCustomer_; i++)
            {
                temp[i].setcaddress(customers[i].getcaddress());
                temp[i].setcname(customers[i].getcname());
                temp[i].setId(customers[i].getcid());

            }
            delete[]customers;
            customers = temp;
            temp = NULL;
            // use copy constructor to add new customer to array this will help give the customer correct id 
            customers[NumCustomer_] = Customer(obj);
            NumCustomer_++;
            cout << "Customer added successfully " << endl;
        }
    }
    else if (customers == NULL)
    {
        customers = new Customer[1];
        customers[0] = Customer(obj);
        NumCustomer_++;
    }
}

void Pharmacy::DisplayMedication() const {
  // make sure that the list is not empty
  if (NumMedicationOffTheShelf == 0 && NumMedicationPresc==0) { 
      cout << "No availabe medication" << endl;
  }
  else {
      // print by getting the display member function from class medication
      cout << "List of medication off the shelf for " << name_ << " Pharmacy" << endl;
      for (int i = 0; i < NumMedicationOffTheShelf; i++) {
       
          OffTheShelfArray[i].Display();

          cout << endl;
      }  
cout << "List of medication prescription for " << name_ << " Pharmacy" << endl;
    for (int i = 0; i < NumMedicationPresc; i++) {
      
          prescriptionArray[i].Display();

        cout << endl;
    }  
} 
}

void Pharmacy::DisplayCustomers() const {
    // make sure that the list is not empty
    if (NumCustomer_ == 0) {
        cout << "No availabe customers" << endl;
    }
    else {
        // print by getting the print member function from class customer
        cout << "List of customers for " << name_ << " Pharmacy" << endl;
        for (int i = 0; i < NumCustomer_; i++) {
            customers[i].print();
            cout << endl;
        }
    }
}

void Pharmacy::setName(string name) { name_ = name; }
void Pharmacy::setNumCustomer(int NumCustomer) { NumCustomer_ = NumCustomer; }
void Pharmacy::setNumMed(int NumMed) { NumMedication_ = NumMed; }
string Pharmacy::getName() const { return name_; }
int Pharmacy::getNumCustomer() const { return NumCustomer_; }
int Pharmacy::getNumMed() const { return NumMedication_; }

void Pharmacy::NumberofMedication(Pharmacy& p)  {
    // checks if the number of medication of the current object is more than the
    // number of medication in the passed object
 NumMedication_= NumMedicationOffTheShelf+ NumMedicationPresc;
    if (NumMedication_ > p.NumMedication_) {
        cout << "**************************************" << endl;
        cout << name_ << "has more medications than " << p.name_ << endl;
        cout << "**************************************" << endl;
    }
    else if (NumMedication_ < p.NumMedication_) {
        cout << p.name_ << "has more medications than " << name_ << endl;
        cout << "**************************************" << endl;
    }
    else {
        cout << "**************************************" << endl;
        cout << "Both have the same number of medications " << endl;
        cout << "**************************************" << endl;
    }
}
void Pharmacy::NumberOfCustomers(Pharmacy& p) const {
    // checks if the number of customer of the current object is more than the
    // number of medication in the passed object
    if (NumCustomer_ > p.NumCustomer_) {
        cout << "**************************************" << endl;
        cout << name_ << "has more customers than " << p.name_ << endl;
        cout << "**************************************" << endl;
    }
    else if (NumCustomer_ < p.NumCustomer_) {
        cout << p.name_ << "has more customers than " << name_ << endl;
        cout << "**************************************" << endl;
    }
    else {
        cout << "**************************************" << endl;
        cout << "Both have the same number of customers " << endl;
        cout << "**************************************" << endl;
    }
}

float Pharmacy::CalculateAVGtPrice() {
    // calculates the average available medication prices (can comapre in the
    // main)
  NumMedication_= NumMedicationOffTheShelf+ NumMedicationPresc;
    float total = 0;
    for (int i = 0; i < NumMedicationOffTheShelf; i++) {
        total += OffTheShelfArray[i].getPrice();
    }
  for (int i = 0; i < NumMedicationPresc; i++) {
    total += prescriptionArray[i].getPrice();

    return total / NumMedication_;
}
  return 0;
}

void Pharmacy::CompareMedicationPrice(string medicationName, Pharmacy& p) {
    // value to indicate medication not found
    float P1price = -1;
    float P2price = -1;
    
    // find the price of the medication in the current object
    for (int i = 0; i < NumMedicationPresc; i++) {
        if (prescriptionArray[i].getMedicationName() == medicationName) {
            P1price = prescriptionArray[i].getPrice();
            //found = true;
            break;
        }
          for (int i = 0; i < NumMedicationOffTheShelf; i++) {
          if (OffTheShelfArray[i].getMedicationName() == medicationName) {
            P1price = OffTheShelfArray[i].getPrice();

            break;
          }
        }
    }

    // find the price of the medication in the passed pharmacy
  
      for (int i = 0; i < NumMedicationPresc; i++) {
          if (p.prescriptionArray[i].getMedicationName() == medicationName) {
                  P2price = p.prescriptionArray[i].getPrice();

                  break;
              }
      }
                for (int i = 0; i < NumMedicationOffTheShelf; i++) {
                if (p.OffTheShelfArray[i].getMedicationName() == medicationName) {
                  P2price = p.OffTheShelfArray[i].getPrice();
     
                  break;
                }
              }    

    // Compare prices
    if (P1price != -1.0 && P2price != -1.0) {
        if (P1price < P2price) {
            cout << name_ << " has a lower price for " << medicationName << endl;
        }
        else if (P1price > P2price) {
            cout << p.getName() << " has a lower price for " << medicationName
                << endl;
        }
        else {
            cout << "Both pharmacies have the same price for " << medicationName
                << endl;
        }
    }
    else {
        cout << "Medication " << medicationName
            << "not found in one or both pharmacies" << endl;
    }
};

void Pharmacy::decrementMed(string medicationName) // this function decrements quantity of
// a med when when purchasing
{
    bool found = false;
  for (int i = 0; i < NumMedicationPresc; i++) {
      if (prescriptionArray[i].getMedicationName() == medicationName) {
        if (prescriptionArray[i].getQuantityInStock() > 0)
        {
              prescriptionArray[i].setQuantityInStock(prescriptionArray[i].getQuantityInStock() - 1); // decrements the current quantity by one
            cout << "Purchase success " << endl;

        }
        {
            found = true;
            cout << "There is no more " << prescriptionArray[i].getMedicationName() << " in stock";
        }
      }
  }
        for (int i = 0; i < NumMedicationOffTheShelf; i++) {
        if (OffTheShelfArray[i].getMedicationName() == medicationName)  {
            if (prescriptionArray[i].getQuantityInStock() > 0)
             {
          prescriptionArray[i].setQuantityInStock(prescriptionArray[i].getQuantityInStock() - 1); // decrements the current quantity by one
        cout << "Purchase success " << endl;

              }
          else
          {
              found = true;
              cout << "There is no more " << prescriptionArray[i].getMedicationName() << " in stock";
          }
  }
}
    
    if (!found) {
        cout << "Purchase failed, medicine not found" << endl;
    }
}




void Pharmacy:: setid(int i)
{
    PharmacyID_ = i;
}

int Pharmacy::getid() const
{
    return PharmacyID_;
}

void Pharmacy::setCustomer(int i, Customer &c) {
    customers[i] = c;

}

Customer *Pharmacy::getCustomer(){
    return customers;
}

Prescription *Pharmacy::getPrescription()
{
    return prescriptionArray;
}
OffTheShelf* Pharmacy::getOffTheShelf()
{
    return OffTheShelfArray;
}

void Pharmacy::setPrescArray(Prescription* temp)
{
    prescriptionArray = temp;
}
void Pharmacy::setOffTheArray(OffTheShelf* temp)
{
    OffTheShelfArray = temp;
}


void Pharmacy::NullArrays()
{
  OffTheShelfArray = NULL;
  prescriptionArray = NULL;
}