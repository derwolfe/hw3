#include <iostream>
#include <ostream>
#include <string>

using namespace std;

#include "Patient.h"

Patient::Patient ( const string &in_first_name,
    const string &in_last_name,
    const string &in_age,
    const string &in_ailment )
{
  first_name  = in_first_name;
  last_name   = in_last_name;
  age         = in_age;
  ailment     = in_ailment;
}

/* overloaded << to print out all patient information
 */
std::ostream& operator<<( std::ostream &os, Patient &in_patient )
{
  os << "" << in_patient.first_name
    << " "        << in_patient.last_name 
    << ", "       << in_patient.age 
    << " -- "     << in_patient.ailment
    << endl;
  os << endl;
  return os;
}
