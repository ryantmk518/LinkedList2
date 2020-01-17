#ifndef NODE_H
#define NODE_H 

#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

class Node {
 public:
  Node(Student*);
  ~Node();
  Student* getStudent();
  void setStudent(Student*);
  Node* getNext();
  void setNext(Node*);
 private:
  Student* student;
  Node* next;
};

#endif
