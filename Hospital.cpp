

Hospital::Hospital ( const &in_name )
{
  name = in_name;
  doctors = Double_list ( );
  patients = Double_list ( );
}

void Hospital::add_patient(string doctor_firstname, 
        string doctor_lastname, 
        Patient *patient);
/* find the doctor, add the patient to the doctor
 */
{
  Doctor *target = doctors.retrieve ( doctor_firstname, doctor_lastname );

}

    /* search for the Doctor then the patient
     */    
void Hospital::delete_patient(string doctor_firstname, 
        string doctor_lastname, 
        string firstname, 
        string lastname);
{
  
    
    Patient* search_patient(string doctor_firstname, 
        string doctor_lastname, 
        string firstname, 
        string lastname);
    
    void hire_doctor(string doctor_firstname, string doctor_lastname);
    
    void fire_doctor(string doctor_firstname, string doctor_lastname);
    
    Doctor*  search_doctor(string doctor_firstname, string doctor_lastname);

    friend ostream& operator<<( ostream &os, Hospital &hospital);
