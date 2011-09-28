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
    
  ifstream fin(argv[1]);
		
  Hospital *hospital = new Hospital("KU Hospital");
  Command command;

  while (fin >> cmdStr) {
    command = identifyNextCommand(cmdStr); 
        
    switch (command) {
    case HIRE_DOCTOR:
       hospital.hire_doctor( doctorFirstname, doctorLastname, patientFirstname, patientLastname );
      break;
    case FIRE_DOCTOR:
       hospital.fire_doctor( doctorFirstname, doctorLastnam );
       break;
    case PRINT_DOCTOR:
           
       break;
    case ADD_PATIENT:
      /* IMPLEMENT ME */
      break;
    case REMOVE_PATIENT:
      /* IMPLEMENT ME */
      break;
    case PRINT_PATIENT:
      /* IMPLEMENT ME */
      break;
    case PRINT_HOSPITAL:
      /* IMPLEMENT ME */
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
