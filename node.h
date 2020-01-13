#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

class Node {
 public:
  Node(Student*);  //constructor
  ~Node();
  //setters
  void setStudent(Student* newstudent);
  void setNext(Node* newnext);
  //getters
  Student* getStudent();
  Node* getNext();
 private:
  //variables
  Student* student;
  Node* next;
};
#endif        
