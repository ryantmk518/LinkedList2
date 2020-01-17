#include <iostream>
#include <cstring>
#include "Student.h"

//Student class

using namespace std;

Student::Student(const char* sfname, const char* slname, int sID, float sGPA) { //Puts in student info
  strcpy(fname, sfname);
  strcpy(lname, slname);
  ID = sID;
  gpa = sGPA;
}

Student::~Student() { //Delete the student
  delete &lname;
  delete &fname;
}
char* Student::getfname() { //Get first name
  return fname;
}

char* Student::getlname() { //Get last name
  return lname;
}

int Student::getID() { // Get ID
  return ID;
}

float Student::getGPA() { //Get GPA
  return gpa;
}



