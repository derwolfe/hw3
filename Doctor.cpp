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

Doctor::Doctor ( const string &doctor_firstname,
    const string &doctor_lastname )
{
  first_name  = doctor_firstname;
  last_name   = doctor_lastname;
  patients    = d_list ();
}

void Doctor::add_patient ( Patient &in_patient )
{
  patients.item_add( Patient &in_patient )
}


