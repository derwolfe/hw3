class Hospital
{
  public:
    Hospital ( const &in_name );

    void add_patient(string doctor_firstname, 
        string doctor_lastname, 
        Patient *patient);
    
    void delete_patient(string doctor_firstname, 
        string doctor_lastname, 
        string firstname, 
        string lastname);
    
    Patient* search_patient(string doctor_firstname, 
        string doctor_lastname, 
        string firstname, 
        string lastname);
    
    void hire_doctor(string doctor_firstname, string doctor_lastname);
    
    void fire_doctor(string doctor_firstname, string doctor_lastname);
    
    void search_doctor(string doctor_firstname, string doctor_lastname);

    friend ostream& operator<<( ostream &os, Hospital &hospital);

  private:
    string  name;
    Patient *patients;
    Doctor  *doctors;
}

