#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

//Student header

using namespace std;

class Student{
public:
  Student(const char*, const char*, int, float); //Initialize functions and variables
  ~Student();
  char* getfname();
  char* getlname();
  int getID();
  float getGPA();
private:
  int ID;
  float gpa;
  char* fname = new char[99];
  char* lname = new char[99];
};
#endif
