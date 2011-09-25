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

