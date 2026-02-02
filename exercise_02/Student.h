#ifndef _SIMPLE_STUDENT_H
#define _SIMPLE_STUDENT_H

#include <vector>
#include <string>

using namespace std;

struct Student {

    Student(){ }
    Student(string _name, int _final, int _number_of_homeworks){
        name = _name;
        final = _final;
        number_of_homeworks = _number_of_homeworks;
        hw_grades = new int[number_of_homeworks];
    }
    ~Student(){
        if (nullptr != hw_grades){
            delete [] hw_grades;
        }
        
    }

    // by default these are public
    string name;
    int final;
    int number_of_homeworks;
    int * hw_grades; // this is our so called scores
};

// our declaration
Student get_student_struct_data();

ostream & operator<<(ostream & os, const Student & student);

#endif