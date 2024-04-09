| | |
|-|-|
|Member Functions| |
|Pharmacy class| |
|Methods|Functionality|
|  Pharmacy(string n = "N/A");   Pharmacy(const Pharmacy& p2);   ~Pharmacy();|Default -parameterized constructorand copy constructor assign values to objects to avoid garbage values and a destructor.|
|Setters:  void setid(int i);   void setName(string name);   void setNumCustomer(int NumCustomer);   void setNumMed(int NumMed);   void decrementMed(string);   void setMedication(int i, Medication& m);   void setCustomer(int i,Customer &c);   void setPrescArray(Prescription* temp);   void setOffTheArray(OffTheShelf* temp);|Setter functions that enable us to modify private member values.|
|Getters:   int getid() const;   string getName()const;   int getNumCustomer()const;   int getNumMed()const;   Medication *getMedication() ;   Customer *getCustomer(); Prescription* getPrescription(); OffTheShelf* getOffTheShelf();|Getter functions that enable us to get and use private member values.|
|  void AddOffShelfMedication(OffTheShelf& medication);   void AddPrescMedication(Prescription& medication); void AddCustomer(const Customer& c);|Adds a new medication or a customer to the pharmacy's inventory.|
|  void RemoveprescMedications(string medication); -voidRemoveoffthshelfMedications(string medication);|Removes the selected medication from the pharmacy's inventory.|
| void DisplayCustomers()const;   void DisplayMedication() const; |Prints all information about medications and customers.|
| void NumberofMedication(Pharmacy& p);   void NumberOfCustomers(Pharmacy& p)const; |Compares the number of medications and customers between two pharmacies.|
|  void CompareMedicationPrice(string medicationName, Pharmacy& pharmacy2); |Compares the price of a specific medication in the current pharmacy with another pharmacy .|
|float CalculateAVGtPrice();|Calculates the average price of all available medications in the pharmacy.|
|  void NullArrays();|This function decrements quantity of a med when when purchasing|
|Address Class| |
|Methods|Functionality|
|Address(); Address(string e, string c, string p, string s);|Paramterized and defualt constructers to intialize values of data members|
|Setters: - void setEmail(string e); - void setCity(string c); - void setPnumber(string pn); - void setStreet(string s);|Setters to modify private data members from the main|
|Getters:  string getEmail() const; string getCity()const; string getPnumber()const; string getStreet()const;|Getters to return private values to the main|
|void print() const;|Print function to display details appropriately|
|Customer Class| |
|Methods|Functionality|
|  Customer();   Customer(string cn, Address a);   Customer(const Customer& c2);|Default and parameterized constructor assign values to objects to avoid garbage values|
|Setters: - void setcname(string cn); -void setId(int id); -void setcaddress(const Address& a);|Setter functions that enable us to modify private member values|
|Getters: - int getcid() const; - string getcname() const; -Address getcaddress()const; -static int getcustomercounter();|Getter functions that enable us to get and use private member values|
|void print() const|Prints object’s information|
|Date Class| |
|Methods|Functionality|
|Date(int day_ = 1, int month_ = 1, int year = 2023);|Default-parameterized constructor assigns values to objects to avoid garbage values|
|Setter: void setDay(int day_); void setMonth(int month_); void setYear(int year_);|Setter functions that enable us to modify private member values Year setter ensures that the expiry date is in the future, not the present |
|Getters: int getDay(); int getMonth(); int getYear();|Getter functions that enable us to get and use private member values|
|  void print() const;| |
|Medication Class| |
|Methods|Functionality|
|  Medication(Date ExpiryDate = Date(), string MedicationName = "NoName", string Description = "NoDescription", float Price = 0.0, int QuantityInStock = 0, string Barcode = "000000");   Medication(const Medication& m2);|Default-parameterized constructor assigns values to objects to avoid garbage values|
|-void setId(int id); - void setMedicationName(string); -void setDescription(string); -void setPrice(float); -void setQuantityInStock(int); -void setBarcode(string); -void setExpire(Date);|Setter functions that enable us to modify private member values|
|-int getMedId() const; -string getMedicationName() const; -string getDescription() const; -Date getExpire() const; -int getQuantityInStock() const; -float getPrice() const; -string getBarcode() const; -static int getmedcounter(); |Getter functions that enable us to get and use private member values|
|Void Display() const|Prints object’s information|
|Main| |
|Methods|Functionality|
|int validatepharm() |Validates that the input pharmacy exists and is valid|
|OffTheShelf class| |
|     public Medication | |
|Methods|Functionality|
| OffTheShelf(Date ExpiryDate, string MedicationName, string Description,      float Price, int QuantityInStock, string Barcode,      bool BOGOF, const Date& OfferEnds);|constructor assigns values to objects to avoid garbage values|
|  void setBOGOF(bool bogof);  void setOfferEnds(const Date& date);|Setter functions that enable us to modify private member values|
| bool getBOGOF() const;  Date getOfferEnds() const;|Getter functions that enable us to get and use private member values|
| void Display() const;|Prints object’s information (override)|
| | |
|Prescription class| |
|     public Medication | |
|Methods|Functionality|
|     Prescription(Date ExpiryDate = Date(), string MedicationName = "NoName",         string Description = "NoDescription", float Price = 0.0,         int QuantityInStock = 0, string Barcode = "000000", int FDAn = 0,         const Date& AD = Date(1, 1, 2026));    Prescription(const Prescription& p);|Default-parameterized constructor  and copy constructor assigns values to objects to avoid garbage values|
|  void setFDANumber(int newFDANumber); void setApprovalDate(const Date& newApprovalDate);  |Setter functions that enable us to modify private member values|
|Date getApprovalDate() const; void Display() const; |Getter functions that enable us to get and use private member values|
| void Display() const;|Prints object’s information (override)|
|~Prescription();|destructor|
