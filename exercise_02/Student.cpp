#include <iostream>
#include "Student.h"

// The helper function to get student data from user input
Student get_student_struct_data() {
    // creates an empty Student struct
    Student student;

    string name;
    int final;
    int total_homeworks;

    // if (!cin) return student; were added to each input to handle ctrl+D 
    cout << "Enter student name (Ctrl+D to end): " << endl;
    cin >> student.name;
    if (!cin) return student;

    cout << "Enter student final: " << endl;
    cin >> student.final;
    if (!cin) return student;

    cout << "How many homeworks does the student have? " << endl;
    cin >> total_homeworks;
    if (!cin) return student;

    // negative, zero assignments or too assignments, return empty student
    if (total_homeworks <= 0 || total_homeworks >= 35){
        cout << "Either less than 1 assignments or too many assignments" << endl;
        return student; 
    } 
    student.number_of_homeworks = total_homeworks;
    student.hw_grades = new int[total_homeworks];       // Allocate memory for homework grades

    cout << "Enter a score:  " << endl;
    int score;
    for (int i = 0; i < student.number_of_homeworks; i++) {
        cin >> score;
        if (!cin) {
            return student;
        }
        student.hw_grades[i] = score;
        // This block just makes the prompt cleaner (nothing too complex)
        if (i < student.number_of_homeworks - 1){
            cout << "Enter another score: " << endl;
        }
        
    }

    return student;
}

// what is this (will ask later)
ostream & operator<<(ostream & os, const Student & student) {
    os << student.name
        << " Final: "
        << student.final
        << " Homework scores: ";
        for (int i = 0; i < student.number_of_homeworks; i++){
            os << student.hw_grades[i]
                << " ";
        }
    return os;
}