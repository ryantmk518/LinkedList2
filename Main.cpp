#include <iostream>
#include <cstring>
#include "node.h"
#include "Student.h"

using namespace std;

//Ryan Thammakhoune. Linked List2. Allows user to enter student info and prints it. Can also average the ids and delete student info.

void add(Node* head, char* fname, char* lname, int id, float GPA);
void print(Node* next); //Initialize functions
void delete_(int id, Node* head);
void average(Node* head, float ave, float num);
Node* first = NULL;

int main() {
  bool start = true;
  while (start == true) { //Loop
    char* fname=new char[99]; //Initialize variables
    char* lname=new char[99];
    float gpa;
    int ID;
    char q[3];
    char input[10];
    int del;
    cout << "Enter command (ADD, PRINT, DELETE, QUIT, AVERAGE)" << endl;
    cin.get(input, 10);
    cin.clear();
    cin.ignore();
    if (strcmp(input, "ADD")==0) {
      cout << "Enter first name" << endl; //Get info
      cin >> fname;
      cin.get();
      cin.clear();
      cout << "Enter last name" << endl;
      cin >> lname;
      cin.get();
      cin.clear();
      cout << "Enter GPA" << endl;
      cin >> gpa;
      cin.get();
      cin.clear();
      cout << "Enter ID" << endl;
      cin >> ID;
      cin.get();
      cin.clear();
      add(first, fname, lname, ID, gpa); //Add function
    }
    if (strcmp(input, "PRINT")==0) {
      print(first);
    }
    if (strcmp(input, "DELETE")==0) {
      cout << "Enter ID of student you would like to delete." << endl;
      cin >> del;
      cin.ignore();
      delete_(del,first);
    }
    if (strcmp(input, "QUIT")==0) {
      start = false;
    }
    if (strcmp(input, "AVERAGE")==0) {
      average(first, 0, 0);
    }
  }
}

void  average(Node* head, float ave, float num) { //Average function
  if (head->getNext()==NULL){ //If this is the last node
    ave=ave+head->getStudent()->getID(); //Add to the sum
    num++;
    cout << ave/num << endl; //Print
  }
  else {
    ave = ave+head->getStudent()->getID(); //Add to the sum
    num++;
    average(head->getNext(), ave, num); //Do the same for the next node
  }
}

void delete_(int id, Node* head) {
  if (head->getStudent()->getID() == id) { //If the id matches
    if (head->getNext() == NULL) {//If the node is the first
      first = NULL; //First is null now
      head ->~Node(); //Delete the node
    }
    else { //If it's not the next node
      first = head -> getNext();
      head-> ~Node();
    }
  
  }
  else { //Else, search the next node
    delete_(id, head->getNext());
  }
}

void add(Node* head, char* fname, char* lname, int id, float gpa) { //Adds student
  Student* null = NULL;
  Student* student = new Student(fname, lname, id, gpa); //Initialize variables and constants
  if (first == NULL) { //If the current node is the first
    first  = new Node(null);
    first  -> setStudent(student);
  }
  else {
    if (student->getID() < first->getStudent()->getID()) { //If the student id is less than the one of the node
      Node* newNode = new Node(null);
      newNode -> setStudent(first ->getStudent());
      newNode -> setNext(first->getNext());
      first -> setStudent(student);
      first -> setNext(newNode);
    }
    if (head -> getNext() == NULL) { //If the node is the last
      Node* newNode2 = new Node(null);
      newNode2->setStudent(student);
      head->setNext(newNode2);
    }
    if(student->getID()<head->getNext()->getStudent()->getID()){ //If the id is less than the one before
      Node* newNode3 =new Node(null);
      newNode3->setStudent(student);
      newNode3->setNext(head->getNext());
      head->setNext(newNode3);
    }
    else {
      add(head->getNext(), fname, lname, id, gpa); //Else keep searching
    }
  }
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

