#include <iostream>
#include <cstring>
#include <String.h>
#include "Node.h"
#include "Student.h"

using namespace std;

//Ryan Thammakhoune. Linked List. Allows user to enter student info and prints it.

void add(char* fname, char* lname, int id, float GPA);
void print(Node* next); //Initialize functions

int main() {
  bool start = true;
  while (start == true) { //Loop
    char fname[99]; //Initialize variables
    char lname[99];
    float gpa;
    int ID;
    char q[3];
    cout << "Enter first name" << endl; //Get info
    cin.get(fname, 99);
    cin.get();
    cout << "Enter last name" << endl;
    cin.get(lname, 99);
    cin.get();
    cout << "Enter GPA" << endl;
    cin >> gpa;
    cin.get();
    cout << "Enter ID" << endl;
    cin >> ID;
    cin.get();
    add(fname, lname, ID, gpa); //Add function
  }
}

void add(char* fname, char* lname, int id, float gpa) { //Adds student
  Student* null = NULL;
  Student* student = new Student(fname, lname, id, gpa);
  bool run = true;
  Node* head = NULL;
  Node* current = head; //Initialize variables and constants
  if (current == NULL) { //If the current node is the first
    head = new Node(null);
    head -> setStudent(student);
  }
  else {
    if (current -> getNext() != NULL) { //If the current node is not the last
      run = false;
    }
    while (run == true) {
      current = current -> getNext();
    }
    current -> setNext(new Node(null));
    current -> getNext() -> setStudent(student);
  }
  print(head); //Print the node
}

void print (Node* next) { //Prints the node
  if (next != NULL){ //Prints info
    cout << "Name: " << next -> getStudent() -> getfname() << " " << next->getStudent()->getlname()<<endl;
    cout << "GPA: " << next ->getStudent()->getGPA() << endl;
    cout << "ID: " << next->getStudent()->getID() << endl;
    print(next->getNext());
    cout << "\n" << endl;
  }
}
