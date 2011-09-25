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
    string  name;
    string  age;
    string  ailment;
}
