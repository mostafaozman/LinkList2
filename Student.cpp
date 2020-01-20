//
//  Student.cpp
//  LL-F
//
//  Created by Mostafa Osman on 1/18/20.
//  Copyright © 2020 Mostafa Osman. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;


Student::Student()
{
    
}


Student::~Student()
{

}

char* Student::getFirstName()
{
    return FirstName;
}

char* Student::getLastName()
{
    return LastName;
}

void Student::setID(int inputID)
{
    ID = inputID;
}

int Student::getID()
{
    return ID;
}

void Student::setGPA(float inputGPA)
{
    GPA = inputGPA;
}

float Student::getGPA()
{
    return GPA;
}
