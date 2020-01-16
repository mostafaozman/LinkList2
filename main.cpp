//
//  main.hpp
//  LL_1
//
//  Created by Mostafa Osman (Sunset HS) on 1/14/20.
//


#include <iostream>
#include <iomanip>
#include "student.h"
#include "node.h"
#include "list.h"
#define FIXED_FLOAT(x) std::fixed<<std::setprecision(2)<<x

using namespace std;

int main(int argc, const char * argv[]) {
    
    //variables
    list* my_list;
    student *newstudent;
    
    //Initialize
    my_list = new list;
     
    //input loop
    /*
     while (true)
     {
     char input[10];
     char firstName[20];
     char lastName[20];
     int id;
     float gpa;
     cout << "What would you like to do? (Add, Print, Delete, Average, or Quit)" << endl;
     cin.get(input, 10);
     cin.clear();
     cin.ignore(100000, '\n');
     
         //Add student
     if(strcmp(input, "Add") == 0)
     {
         cout << "What is the students first name?" << endl;
         cin.get(firstName, 20);
         cin.clear();
         cin.ignore(100000, '\n');
         cout << "What is the students last name?" << endl;
         cin.get(lastName, 20);
         cin.clear();
         cin.ignore(100000, '\n');
         cout << "What is the students ID?" << endl;
         cin >> id;
         cout << "What is the students GPA?" << endl;
         cin >> gpa;
    
         newstudent = new student(firstName, lastName, id, gpa);
         my_list->add(newstudent);
         cout << "\nStudent added!" << endl;
     }
    // Print list
     else if (strcmp(input, "Print") == 0)
     {
         my_list->print();
     }
    //Delete a student using ID
     else if (strcmp(input, "Delete") == 0)
     {
         cout << "What is the ID of the student you would like to delete?" << endl;
         int id;
         cin >> id;
         my_list -> deletenode(id);
     }
    //Print Average GPA
     else if (strcmp(input, "Average") == 0)
     {
         float average_gpa = my_list->average();
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
    */
//Test code - use for debug
    //Define and add students
    student *student1, *student2, *student3, *student4, *student5, *student6;
    student1 = new student("Samuel", "Jackson", 3, 4.0);
    student2 = new student("Barak", "Obama", 53, 3.8);
    student3 = new student("Thomas", "Jefferson",67, 3.5);
    student4 = new student("Bill", "Clinton", 2, 3.0);
    student5 = new student("John", "Adams", 6, 2.7);
    student6 = new student("Donald", "Trump", 776543, 3.0);
    
    //Print List
    my_list->print();
    //Add student
    my_list->add(student1);
    my_list->print();
    
    my_list->add(student2);
    my_list->print();
    
    my_list->add(student3);
    my_list->print();
    
    my_list->add(student4);
    my_list->print();
    
    my_list->add(student5);
    my_list->print();
    
    my_list->add(student6);
    my_list->print();
    
    //Average GPA
    float average_gpa = my_list->average();
    cout<<"\nAverage GPA ="<<FIXED_FLOAT(average_gpa)<<"\n";
    
    //Delete student
    if(my_list->deletenode(2))
        std::cout<<"\nID NOT FOUND";
    else
        std::cout<<"\nStudent deleted";

    my_list->print();
    
    return 0;
}


