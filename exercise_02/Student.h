#ifndef _SIMPLE_STUDENT_H
#define _SIMPLE_STUDENT_H

#include <vector>
#include <string>

using namespace std;

// The struct definition for Student
struct Student {
    // Note to self: Below this are constructors
    // Default constructor - Initialize members to default values
    Student(){
        hw_grades = nullptr;
        number_of_homeworks = 0;
     }

    // Parameterized constructor - Initialize members with given values
    Student(string _name, int _final, int _number_of_homeworks){
        name = _name;
        final = _final;
        number_of_homeworks = _number_of_homeworks;
        // Allocate memory for homework grades
        hw_grades = new int[number_of_homeworks];
    }

    // Copy constructor - Deep copy (needed for push_back in vector) 
    Student(const Student& other) {
        name = other.name;
        final = other.final;
        number_of_homeworks = other.number_of_homeworks;
        
        // Deep copy the array
        hw_grades = new int[number_of_homeworks];
        for (int i = 0; i < number_of_homeworks; i++) {
            hw_grades[i] = other.hw_grades[i];
        }
    }
    
    // Copy assignment operator
    // replacing existing object with a copy of another object
    Student& operator=(const Student& other) {
        if (this != &other) {  // Check for self-assignment
            // Clean up old memory
            delete[] hw_grades;
            
            // Copy data
            name = other.name;
            final = other.final;
            number_of_homeworks = other.number_of_homeworks;
            
            // Deep copy the array
            hw_grades = new int[number_of_homeworks];
            for (int i = 0; i < number_of_homeworks; i++) {
                hw_grades[i] = other.hw_grades[i];
            }
        }
        return *this;
    }
    
    // Note to self: Below this are destructors - cleanup code/free memory
    // This just helps with memory leaks
    // Note to self: the symbol "~" means destructor
    ~Student(){
        if (nullptr != hw_grades){
            delete [] hw_grades;
        }
    }

    // by default these are public
    string name;
    int final;
    int number_of_homeworks;
    int * hw_grades; // this is our scores
};

// our declaration
Student get_student_struct_data();

ostream & operator<<(ostream & os, const Student & student);

#endif