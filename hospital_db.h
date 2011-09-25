class Patient
{
  public:
    Patient( const string &in_name,
        const string &in_age,
        const string &in_ailment );
    
    bool matches ( string &patient_name );

    friend std::ostream& operator<<( std::ostream &os, Patient &in_patient );
    
    void print ( std::ostream & os ); 

  private:
    string name;
    string age;
    string ailment;
}
class Doctor
{
  public:
    Doctor (const string &doctor_firstname,
        const string &doctor_lastname );

    void add_patient ( Patient &in_patient );

    void delete_patient ( string firstname, string lastname );

    Patient* search_patient ( string firstname, string lastname );
    
    friend ostream& operator<<( ostream &os, Doctor &doctor);

  private:
    string    first_name;
    string    last_name;
    Patient*  patients;
}
class Hospital
{
  public:
    Hospital ( const &in_name );

    void add_patient(string doctor_firstname, string doctor_lastname, Patient *patient);
    
    void delete_patient(string doctor_firstname, string doctor_lastname, string firstname, string lastname);
    
    Patient* search_patient(string doctor_firstname, string doctor_lastname, string firstname, string lastname);
    
    void hire_doctor(string doctor_firstname, string doctor_lastname);
    
    void fire_doctor(string doctor_firstname, string doctor_lastname);
    
    void search_doctor(string doctor_firstname, string doctor_lastname);

    friend ostream& operator<<(ostream &os, Hospital &hospital);

  private:
    string  name;
    Patient *patients;
    Doctor  *doctors;
}

