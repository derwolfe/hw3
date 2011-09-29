#include <stdlib.h>
#include <stdio.h>
#include <ostream>
#include <string>

using namespace std;

#include "linkedlist_template.h"
#include "Doctor.h"
#include "Patient.h"

/* 
 * construct a class of doctor, that has a list of patients
 */

Doctor::Doctor ( const string &doctor_first_name,
    const string &doctor_lastname )
{
  first_name  = doctor_first_name;
  last_name   = doctor_lastname;
  patients    = Double_list <Patient> () ;
}

void Doctor::add_patient <Patient>  ( Patient &in_patient )
{
  patients.item_add ( in_patient )
}
/* find the patient node, delete it. You will need to use string 
 * functions to compare the data. You basically need to compare
 * every patient to the data fed in.
 */
void Doctor::delete_patient <Patient> ( string first_name, string last_name )
{
  Patient *target = search_patient ( first_name, last_name ); 
  patients.remove ( target );
  delete target;
  target = NULL;
}

/* you must traverse the patient nodes and check to see if
 * the content is equal. This shoud basically be a MATCH function,
 * matching the input to the data_item.
 */
Patient* Doctor::search_patient <Patient> ( string first_name, string last_name ) 
{
  return ( patients.search ( first_name, last_name ));
}

friend ostream& operator<<( ostream &os, Doctor &doctor )
{
  os << " Doctor: " << doctor.first_name << "" << doctor.last_name  << endl;
  os << "   List of patients:"                                      << endl;
  os << " --  " << doctor.patients                                  << endl;
  os << endl;
  return os; 
}

void Doctor::print ( ostream &os )
{
  os << this << endl;
}
  
