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
  patient.remove ( target );
  target = NULL;
}

/* you must traverse the patient nodes and check to see if
 * the content is equal
 */
Patient* search_patient ( string first_name, string lastname )
{
  // for patient in patient check each first name against the next
  if ( !patients.is_empty ())
    throw no_patients_exception ("This doctor has no patients");
    if (( patient.first_name.compare ( first_name )) && 
          ( patient.last_name.compare ( last_name )) ) {


