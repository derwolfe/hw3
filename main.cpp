#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "Hospital.h"

using namespace std;

enum Command {
  HIRE_DOCTOR,
  FIRE_DOCTOR,
  PRINT_DOCTOR,
  ADD_PATIENT,
  REMOVE_PATIENT,
  PRINT_PATIENT,
  PRINT_HOSPITAL,
  INVALID
};

Command identifyNextCommand(const string& cmdStr)
{
  Command command;

  if (cmdStr.compare("hire") == 0) {
    command = HIRE_DOCTOR;
  } else if (cmdStr.compare("fire") == 0) {
    command = FIRE_DOCTOR;
  } else if (cmdStr.compare("print-doctor") == 0) {
    command = PRINT_DOCTOR;
  } else if (cmdStr.compare("add-patient") == 0) {
    command = ADD_PATIENT;
  } else if (cmdStr.compare("remove-patient") == 0) {
    command = REMOVE_PATIENT;
  } else if (cmdStr.compare("print-patient") == 0) {
    command = PRINT_PATIENT;
  } else if (cmdStr.compare("print-hospital") == 0) {
    command = PRINT_HOSPITAL;
  } else {
    command = INVALID;
  }

  return command;
}

int main(int argc, char* argv[])
{
  if (argc < 2) {
      cerr << "Usage error: ./main input.txt" << endl;
      exit(1);
  }

  string cmdStr;
  string doctorFirstname, doctorLastname;
  string patientFirstname, patientLastname, age, ailment;
  Patient *patient;
  Doctor  *doctor;

  ifstream fin(argv[1]);
		
  Hospital *hospital = new Hospital("KU Hospital");
  Command command;

  while (fin >> cmdStr) {
    command = identifyNextCommand(cmdStr); 
    /* overloaded the >> operator to fill in each of the variables
     * listed. It should fill in the needed information.
     *
     */
    switch (command) {
    case HIRE_DOCTOR:
      cmdStr >> doctorFirstname >> doctorLastname; 
      hospital.hire_doctor ( doctorFirstname, doctorLastname );
      break;
    case FIRE_DOCTOR:
      cmdStr >> doctorFirstname >> doctorLastname;
      hospital.fire_doctor ( doctorFirstname, doctorLastname );
      break;
    case PRINT_DOCTOR:
      /* find the doctor and print it */
      cmdStr >> doctorFirstname >> doctorLastname;
      doctor = hospital.search_doctor ( doctorFirstname, doctorLastname );
      cout << *doctor << endl; 
      break;
    case ADD_PATIENT:
      cmdStr >> doctorFirstname >> doctorLastname 
        >> patientFirstname >> patientLastname; 
      hospital.add_patient ( doctorFirstname, doctorLastname, 
          patientFirstname, patientLastname );
      break;
    case REMOVE_PATIENT:
      cmdStr >> doctorFirstname >> doctorLastname 
        >> patientFirstname >> patientLastname; 
      hospital.delete_patient ( doctorFirstname, doctorLastname, 
          patientFirstname, patientLastname );   
      break;
    case PRINT_PATIENT:
      cmdStr >> patientFirstname >> patientLastname;
      patient = hospital.search_patient (patientFirstname, patientLastname );
      cout << *patient << endl;
      break;
    case PRINT_HOSPITAL:
      cout << *hospital << endl;
      break;
    case INVALID:
      cout << "Error: invalid command" << endl;
      break;
    }
  }

  delete hospital;
  fin.close();

  exit(0);
}

