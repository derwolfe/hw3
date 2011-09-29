class Doctor
{
  public:
    Doctor ( const string &doctor_first_name,
        const string &doctor_lastname );

    void add_patient ( Patient &in_patient );

    void delete_patient ( string first_name, string lastname );

    Patient* search_patient ( string first_name, string lastname );
    
    friend ostream& operator<<( ostream &os, Doctor &doctor);

    void print ( ostream &os );

  private:
    string        first_name;
    string        last_name;
    Double_list   *patients;
}

