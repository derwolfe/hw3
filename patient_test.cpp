#include <stdio.h>
#include <iostream>

using namespace std;

#include "linkedlist_template.h"
#include "Patient.h"
#include "Doctor.h"

int main ( )
{
  Patient *billy = new Patient ( "billy", "Johnson", "23", "flu" );
  Patient *donny = new Patient ( "Donald", "Dirkman", "900", "syphillus" );
  Doctor *don  = new Doctor ( "John", "Gustofson" );
  don->add_patient ( *billy );
  cout << *billy << endl;
  cout << *donny << endl;
  cout << *don << endl;
  return (0);
}
