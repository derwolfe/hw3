#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

#include "linkedlist.h"
#include "Doctor.h"

/* 
 * construct a class of doctor, that has a list of patients
 */

Doctor::Doctor ( const string &doctor_first_name,
    const string &doctor_lastname )
{
  first_name  = doctor_first_name;
  last_name   = doctor_lastname;
  patients    = d_list ();
}

void Doctor::add_patient ( Patient &in_patient )
{
  patients.item_add ( Patient &in_patient )
}
/* find the patient node, delete it. You will need to use string 
 * functions to compare the data. You basically need to compare
 * every patient to the data fed in.
 */
void Doctor::delete_patient ( string first_name, string lastname )
{
  Patient *target = search_patient ( first_name, lastname ); 
  patients.remove ( target );
  target = NULL;
}

/* you must traverse the patient nodes and check to see if
 * the content is equal. This shoud basically be a MATCH function,
 * matching the input to the data_item.
 */
//Patient* search_patient ( string first_name, string lastname )
//{
//}

friend ostream& operator<<( ostream &os, Doctor &doctor )
{
  os << "   First Name: "   << doctor.first_name      << endl;
  os << "   Last Name:  "   << doctor.last_name       << endl;
  os << " ** Patients ** "                            << endl;
  os << doctor.patients  << endl;
  os << endl;
  return os; 
}
  
