class Patient
{
  public:
    Patient( const string &in_first_name,
        const string &in_last_name,
        const string &in_age,
        const string &in_ailment );
    
    friend std::ostream& operator<<( std::ostream &os, Patient &in_patient );
    
    void print ( std::ostream &os ); 

  private:
    string  first_name;
    string  last_name;
    string  age;
    string  ailment;
}
