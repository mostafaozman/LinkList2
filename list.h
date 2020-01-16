//
//  list.h
//  LL_1
//
//  Created by Mostafa Osman (Sunset HS) on 1/14/20.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include "node.h"
#include "student.h"

class list {
    node * head = NULL;
    node * position = NULL;
    node * previous = NULL;
    node * addit = NULL;
    bool found = false;
public:
    list();
    ~list();
    int add(student *);
    //for simplicity, use in main
    int deletenode (int);
    //overloaded for recursion is list objects
    int deletenode (int, node *);
    //for simplicity, use in main
    int print(void);
    //overloaded for recursion is list objects
    int print(node *myposition);
    float average(void);
    
};

#endif /* list_h */
