#include <iostream>
#include <cstring>
#include "student.h"

using namespace std; 

Student::Student()
{

}

Student::~Student()
{
  delete &firstName;
  delete &lastName;
  delete &ID;
  delete &GPA; 
}

char* Student::getFirstName()
{
  return firstName; 
}

char* Student::getLastName()
{
  return lastName; 
}

int* Student::getID()
{
  return ID; 
}

void Student::setID(int inID)
{
  ID = inID; 
}

float* Student::getGPA()
{
  return GPA; 
}
void Student::setGPA(float inGPA)
{
  GPA = inGPA; 
}
