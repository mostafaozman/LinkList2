//
//  node.cpp
//  LL_1
//
//  Created by Mostafa Osman (Sunset HS) on 1/14/20.
//

#include "node.h"
#include <iostream>

node::node(student *newstudent, node * n_node) {
   //my_student = new student(newstudent->get_first_name(), newstudent->get_last_name(), newstudent->get_id(), newstudent->get_gpa());
   // next_node = n_node;
}
node::~node() {
    delete my_student;
}

void node::set_student(student *newstudent) {
    my_student = new student(newstudent->get_first_name(), newstudent->get_last_name(), newstudent->get_id(), newstudent->get_gpa());
}
student * node::get_student(void){
    //std::cout<<"\nstudentaddress = "<<my_student<<"\n";
    return my_student;
    
}
void node::set_next(node *the_node){
    next_node = the_node;
    
}
node * node::get_next(void) {
    return next_node;
    
}

int node::print_node() {
    std::cout<<"\n********************************************";
    std::cout<<"\nFirst Name: "<<my_student->get_first_name();
    std::cout<<"\nLast Name: "<<my_student->get_last_name();
    std::cout<<"\nID: "<<my_student->get_id();
    std::cout<<"\nGPA: "<<my_student->get_gpa();
    std::cout<<"\n********************************************";
    return 0;
}
