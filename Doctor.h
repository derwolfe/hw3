class Doctor
{
  public:
    Doctor ( const string &doctor_first_name,
        const string &doctor_lastname );

    void add_patient ( const Patient &in_patient );

    void delete_patient ( string first_name, string lastname );

    Double_node<Patient>* search_patient ( string first_name, string lastname );

    friend std::ostream& operator<<( std::ostream &os, Doctor &in_doctor);
    
    void print ( std::ostream &os );

  private:
    string                  first_name;
    string                  last_name;
    Double_list<Patient>    patients;
};

