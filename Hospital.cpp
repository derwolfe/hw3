#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

#include "Hospital.h"
#include "Doctor.h"

Hospital::Hospital ( const &in_name )
{
  name = in_name;
  doctors = new Double_list ();
}

void Hospital::add_patient (string doctor_firstname, 
        string doctor_lastname, 
        Patient *patient );

/* find the doctor, add the patient to the doctor
 */
{
  Doctor *doctor = doctors.retrieve ( doctor_firstname, doctor_lastname );
  doctor.add_patient ( patient );
  doctor = NULL;
}

    /* search for the Doctor then the patient, using the method defined
     * by your linkedlist template
     */    
void Hospital::delete_patient ( string doctor_firstname, 
        string doctor_lastname, 
        string firstname, 
        string lastname )
{
  Doctor *doctor = doctors.retrieve  ( doctor_firstname, doctor_lastname );
  doctor.delete_patient ( firstname, lastname );
}

Patient* Hospital::search_patient ( string doctor_firstname, 
        string doctor_lastname, 
        string firstname, 
        string lastname )
{
  Doctor *doctor = doctors.retrieve  ( doctor_firstname, doctor_lastname );
  Patient *patient = doctor.search_patient<Patient> ( firstname, lastname );
  return patient;
}
/* uses the native item add method to double_list
 */    
void Hospital::hire_doctor (string doctor_firstname, string doctor_lastname)
{
  doctors.item_add ( doctor_firstname, doctor_lastname );
}
/* uses the remove item method native to double list
 */    
void Hospital::fire_doctor (string doctor_firstname, string doctor_lastname)
{
  Doctor *target = doctors.search_doctor (doctor_firstname, doctor_lastname );
  doctors.remove ( target );
  target = NULL;
}
    
Doctor*  search_doctor(string doctor_firstname, string doctor_lastname)
{
  return ( doctors.search_doctor ( doctor_firstname, doctor_lastname ));
}

friend ostream& operator<<( ostream &os, Hospital &hospital)
{
  os << "----------------------"          << endl;
  os << " Hospital: "   << hospital.name  << endl;
  os << "----------------------"          << endl;
  os << " List of doctors:"               << endl;
  os << hospital.doctors                  << endl; 
  os << endl;
  return os; 
