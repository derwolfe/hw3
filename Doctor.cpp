#include <stdlib.h>
#include <stdio.h>
#include <ostream>
#include <string>

using namespace std;

#include "linkedlist_template.h"
#include "Patient.h"
#include "Doctor.h"

/* 
 * construct a class of doctor, that has a list of patients
 */

Doctor::Doctor ( const string &doctor_first_name,
    const string &doctor_lastname )
{
  first_name  = doctor_first_name;
  last_name   = doctor_lastname;
  patients    = Double_list<Patient> ();
}

void Doctor::add_patient ( const Patient &in_patient )
{/* problematic: the double list template should take the patient
  * object and just shove it inside of a new double_node structure
  * for whatever reason patients.item_add is calling a Patient::
  * Patient constructor
  */
  // copy patient, add
  Patient *pat = new Patient ( in_patient ); 
  cout << *pat << endl;
}
/* find the patient node, delete it. You will need to use string 
 * functions to compare the data. You basically need to compare
 * every patient to the data fed in.
 */
//void Doctor::delete_patient ( string first_name, string last_name )
//{
//  Double_node <Patient>* patient = patients.retrieve ( first_name, last_name ); 
//  patients.remove ( patient );
//  delete patient;
//  patient = NULL;
//}
//
///* traverse the patient nodes and check to see if
// * the content is equal. This shoud basically be a MATCH function,
// * matching the input to the data_item.
// */
//Double_node<Patient>* Doctor::search_patient ( string first_name, string last_name ) 
//{
//  return ( patients.retrieve ( first_name, last_name ));
//}

std::ostream& operator<<( std::ostream &os, Doctor &in_doctor )
{
  /* this isn't working because of the in_doctor.patients line
   * the goal is to take doctor, and use its overloaded patient
   * operator to print out the each patient. I would think calling
   * patient would call its operator. But there must need to be some
   * loop to cycle through each patient?
   */
  os << " Doctor: " << in_doctor.first_name 
    << " " << in_doctor.last_name << endl;
  os << "   List of patients:" << endl;
    in_doctor.patients.print_items( os );
  os << endl;
  return os; 
}

void Doctor::print ( std::ostream &os )
{
  os << this << endl;
} 
