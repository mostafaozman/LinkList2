//
//  node.h
//  LL_1
//
//  Created by Mostafa Osman (Sunset HS) on 1/14/20.
//

#ifndef node_h
#define node_h

#include <stdio.h>
#include "student.h"

class node {
    student *my_student;
    node *next_node;
public:
    node(student *newstudent = NULL, node * n_node = NULL);
    ~node();
    void set_student(student *the_student);
    student * get_student(void);
    void set_next(node *the_node);
    node * get_next(void);
    int print_node();
    
};

#endif /* node_h */
