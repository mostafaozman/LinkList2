//
//  student.h
//  LL_1
//
//  Created by Mostafa Osman (Sunset HS) on 1/14/20.
//

#ifndef student_h
#define student_h

#include <stdio.h>
#include <string>

class student {
    std::string first_name;
    std::string last_name;
    int id;
    float gpa;
public:
    student(std::string fname = "john", std::string lname = "doe", int s_id=0, float s_gpa=0);
    ~student();
    int get_id(void) {return id;};
    float get_gpa(void) {return gpa;};
    std::string get_first_name(void) {return first_name;};
    std::string get_last_name(void) {return last_name;};
};
#endif /* student_h */
