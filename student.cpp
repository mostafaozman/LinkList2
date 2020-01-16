//
//  student.cpp
//  LL_1
//
//  Created by Mostafa Osman (Sunset HS) on 1/14/20.
//
# include <string>
#include "student.h"
student::student(std::string fname, std::string lname, int s_id, float s_gpa)
{
    first_name = fname;
    last_name = lname;
    id = s_id;
    gpa = s_gpa;
}

student::~student()
{
    
}
