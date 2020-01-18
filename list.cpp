//
//  list.cpp
//  LL_1
//
//  Created by Mostafa Osman (Sunset HS) on 1/14/20.
//

#include "list.h"
#include <iostream>



list::list()
{
   
}

list::~list() {
    //Clean up all the dunamic allocation
    position = head; 
    if(head != NULL) {
        while(position !=NULL) {
            node *temp = position;
            position = position->get_next();
            delete temp;
        }
    }
    
}


int list::add(student *newstudent)
{
    //if this is the first node, add and return
     if (head == NULL) {
            head = new node();
            head->set_student(newstudent);
            head->set_next(NULL);
            addit = head;
            //previous = head;
         return 0;
     }
     
     //sorted add
    //if we reached the end of the list, insert at the end and return
    if (addit == NULL) {
        addit = new node();
        addit->set_student(newstudent);
        addit->set_next(NULL);
        previous->set_next(addit);
        return 0;
    }
     //Determine if should insert at current node position
    if (newstudent->get_id() <= addit->get_student()->get_id()) {
        //is it going to bne the first node in the list?
        if (addit == head){
            head = new node();
            head->set_student(newstudent);
            head->set_next(addit);
            return 0;
        }
        //insert at a middle node
        else {
            node * temp = addit;
            addit = new node();
            addit->set_student(newstudent);
            addit->set_next(temp);
            previous->set_next(addit);
            return 0;
        }
    } else {
        //advance the linked list pointer
        previous = addit;
        addit = addit->get_next();
        //recursive call to add
        add(newstudent);
        //reset the pointers upon return
        addit = head;
        previous = NULL;
        return 0;
    }
     
     return 1;
     
}

int list::print(void) {
    position = head;
    print(position);
    return 0;
}

int list::print(node *myposition) {
    if(myposition == NULL)
        return 0;
    else {
        position->print_node();
        position = position->get_next();
        print(position);
        return 0;
    }
    return 1;
}

float list::average(void) {
    position = head;
    float sum_gpa = 0;
    int nstudents = 0;
    while(position != NULL)
    {
        sum_gpa += position->get_student()->get_gpa();
        position=position->get_next();
        nstudents++;
    }
    //  std::cout<<"\nSum GPA = "<<sum_gpa;
    //  std::cout<<"\nNumber of Students = "<<nstudents;
    return (sum_gpa/nstudents);
}

int list::deletenode(int s_id){
    position = head;
    found = false;
    if (head == NULL)
        return 1;
    else
        //ID found and deleted
        return deletenode(s_id, position);
        //ID not found;
}

int list::deletenode (int s_id, node *myposition){
    //if only one node
    if (head->get_next() == NULL){
        if(myposition->get_student()->get_id() == s_id)
        {
            delete head;
            head = NULL;
            return 0;
            }
        else
            return 1;
    }
    
    //if first node
    if (myposition == head && myposition->get_student()->get_id() == s_id)
        {
            node *temp = head;
            head = head->get_next();
            delete temp;
            return 0;
        }
    
    // last 2 nodes or only 2 nodes;
    if(myposition->get_next()->get_next() == NULL){
        if (myposition->get_next()->get_student()->get_id() == s_id) {
        node * temp = myposition->get_next();
        myposition->set_next(myposition->get_next()->get_next());
        delete temp;
        return 0;
        }
        else
            return 1;
    }
    
    //all in the middle
    if (myposition->get_next()->get_student()->get_id() == s_id) {
        node * temp = myposition->get_next();
        myposition->set_next(myposition->get_next()->get_next());
        delete temp;
        return 0;
    }
    else {
        myposition = myposition->get_next();
        if (position != NULL)
            return deletenode(s_id, myposition);
        else
            return 1;
    }
    
   //why am I here, return 1
    return 1;
    }
