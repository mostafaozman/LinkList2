//
//  main.cpp
//  LL-F
//
//  Created by Mostafa Osman on 1/18/20.
//  Copyright © 2020 Mostafa Osman. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include "Student.h"
#include "node.h"
#define FIXED_FLOAT(x) std::fixed<<std::setprecision(2)<<x

using namespace std;

//Head of linked list
Node* head = NULL;

int add(Student* student, Node* MyPosition);
int del(int, Node* MyPosition);
int print(Node* ptr);
float average(Node* ptr);

int main(int argc, const char * argv[]) {

    // Main loops, asks for inputs and saves to student
    while (true)
    {
        char input[10];
        //char firstName[20];
        //char lastName[20];
        int id;
        float gpa;
        cout << "What would you like to do? (Add, Print, Delete, Average, or Quit)" << endl;
        cin.get(input, 10);
        cin.clear();
        cin.ignore(100000, '\n');
        //cin.ignore(numeric_limits<streamsize>::max(),'\n');
        
        //Add student
        if(strcmp(input, "Add") == 0)
        {
            Student* newStudent = new Student;
            cout << "What is the students first name?" << endl;
            cin.get(newStudent->getFirstName(), 20);
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "What is the students last name?" << endl;
            cin.get(newStudent->getLastName(), 20);
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "What is the students ID?" << endl;
            cin >> id;
            newStudent -> setID(id);
            cout << "What is the students GPA?" << endl;
            cin >> gpa;
            newStudent -> setGPA(gpa);
          // cin.ignore(numeric_limits<streamsize>::max(),'\n');
            //Call the add function
            add(newStudent, head);
            cout << "\nStudent added!" << endl;
        }
        // Print list
        else if (strcmp(input, "Print") == 0)
        {
            print(head);
        }
        //Delete a student using ID
        else if (strcmp(input, "Delete") == 0)
        {
            cout << "What is the ID of the student you would like to delete?" << endl;
            int id;
            cin >> id;
            del(id, head);
        }
        //Print Average GPA
        else if (strcmp(input, "Average") == 0)
        {
           float average_gpa = average(head);
           cout<<"\nAverage GPA ="<<FIXED_FLOAT(average_gpa)<<"\n";
        }
        //Quit
        else if (strcmp(input, "Quit") == 0)
        {
            break;
        }
        else{
            
            cout << "Invalid input. Check spelling/capitalization" << endl;
        }
    }
    
    //Clean up the memory
    Node *ptr= head;
    while (head != NULL) {
        delete head->getStudent();
        ptr = ptr->getNext();
        head = ptr;
        delete ptr;
    }
    return 0;
}

// add function
int add(Student* student, Node* MyPosition)
{
    Node *prev;
    
    // If the list is empty
    if(head == NULL)
     {
         head = new Node(student);
         return 0;
     }
    //or the new value is greater than the head value
    else if(head -> getStudent()->getID() >= student -> getID())
    {
        Node* temp = NULL;
        temp = new Node(student);
        temp->setNext(head);
        head = temp;
        return 0;
    }
    
    else
    {
        prev = MyPosition;
        Node * Position = MyPosition-> getNext();
        
       // Adding to end of the list
        if (Position == NULL)
        {
            MyPosition -> setNext(new Node(student));
            return 0;

        }
        // Into the middle
        if (Position->getStudent()->getID() >= student->getID())
        {
            Node* temp = NULL;
            temp = new Node(student);
            temp->setNext(Position);
            prev->setNext(temp);
            return 0;
        }
        
        // Advancing to the next position
        if(Position != NULL && Position->getStudent()->getID() <= student->getID())
        {
            //prev = MyPosition;
            //Position = MyPosition -> getNext();
            add(student, Position);
            return 0;
        }
    
        // if we get to the end or the loop terminates
       // prev -> getNext()->setNext(new Node(student));
       // return 0;
    }
    return 1;
}

// delete function
int del(int id, Node* MyPosition)
{
    Student* student;
    Node* prev;
    
    // If the list is empty
    if(head == NULL)
    {
        return 0;
    }
    // If you want to delete the first value
    if(head->getStudent()->getID() == id)
    {
        Node* temp = nullptr;
        temp = head;
        head = head->getNext();
        delete temp->getStudent();
        delete temp;
        return 0;
        /* temp = head->getNext();
        delete head;
        head = temp; */
    }
    else
    {
        prev = MyPosition;
        Node * Position = MyPosition-> getNext();
        
        
       /* if (Position != NULL && Position -> getStudent() -> getID() != id)
        {
            return del(id, MyPosition);
        }
        */
       /* if (Position != NULL)
        {
            Node* temp = nullptr;
            temp = Position;
            Position = Position->getNext();
            head -> getNext()->setNext(Position -> getNext());
            delete temp->getStudent();
            delete temp;
        }*/
        // Delete from middle
       
       /*if((Position->getStudent()->getID() == id) && Position->getNext() == NULL)
       {
           Node* temp = nullptr;
           temp = Position;
           prev->setNext(NULL);
           delete temp->getStudent();
           delete temp;
           return 0;
       }*/
        
        if (Position != NULL &&Position->getStudent()->getID() == id)
            {
                Node* temp = nullptr;
                temp = Position;
                prev->setNext(Position->getNext());
                delete temp->getStudent();
                delete temp;
                return 0;
            }
        
        if(Position != NULL && Position->getStudent()->getID() != id)
        {
            //prev = MyPosition;
            //Position = MyPosition -> getNext();
            del(id, Position);
            return 0;
    
        }
        else
        {
            return 1; 
        }
    }
    return 1;
}

// print function
int print(Node* ptr)
{
    
    if (ptr == NULL)
    {
        return 0;
    }
    // If the list is empty
    if (ptr->getNext() == NULL)
    {
    //print this node and return 0;
        cout << ptr -> getStudent() -> getLastName() << ", ";
        cout << ptr -> getStudent() -> getFirstName() << endl;
        cout << ptr -> getStudent() -> getID() << endl;
        cout << ptr -> getStudent() -> getGPA() << endl << endl;
        return 0;
    
    }
    // Print and iterate
    if (ptr->getNext() != NULL)
    {
        cout << ptr -> getStudent() -> getLastName() << ", ";
        cout << ptr -> getStudent() -> getFirstName() << endl;
        cout << ptr -> getStudent() -> getID() << endl;
        cout << ptr -> getStudent() -> getGPA() << endl << endl;
        
        print(ptr->getNext());
        return 0;
    }
    return 1;
}

// average
float average(Node* ptr)
{
    ptr = head;
    float GpaSum = 0;
    int numStudents = 0;
    
    while (ptr->getNext() != NULL)
    {
        GpaSum += ptr->getNext()->getStudent()->getGPA();
        ptr = ptr->getNext();
        numStudents++;
    }
    return(GpaSum/numStudents);
}

