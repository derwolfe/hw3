class Hospital
{
  public:
    Hospital ( const String &in_name );

    void add_patient(string doctor_firstname, 
        string doctor_lastname, 
        Patient *patient);
    /* search for the Doctor then the patient
     * once you find the patient, then drop it
     */    
    void delete_patient(string doctor_firstname, 
        string doctor_lastname, 
        string firstname, 
        string lastname);
    /* search for doctor then patient
     */ 
    Patient* search_patient(string doctor_firstname, 
        string doctor_lastname, 
        string firstname, 
        string lastname);
    
    void hire_doctor(string doctor_firstname, string doctor_lastname);
    
    void fire_doctor(string doctor_firstname, string doctor_lastname);
    
    Doctor*  search_doctor(string doctor_firstname, string doctor_lastname);

    friend ostream& operator<<( ostream &os, Hospital &hospital);

  private:
    string          name;
    Double_list     *doctors;
};

