#include <iostream>

#include "Student.h"

Student get_student_struct_data() {

    Student student;

    string name;
    int final;
    int total_homeworks;

    cout << "Enter name: " << endl;
    cin >> student.name;

    cout << "Enter final: " << endl;
    cin >> student.final;

    cout << "How many homeworks: " << endl;
    cin >> total_homeworks;

    Student student(name, final, total_homeworks);

    cout << "Enter a score:  " << endl;
    int score;
    for (int i = 0; i < student.number_of_homeworks; i++) {
        cin >> score;
        student.hw_grades[i].push_back(score);
        cout << "Enter another score: " << endl;
    }

    return student;
}

// what is this (do more research on this)
ostream & operator<<(ostream & os, const Student & student) {
    os << student.name
        << " Final: "
        << student.final
        << " homework scores: ";
        for (int i = 0; i < student.number_of_homeworks; i++){
            os << score
                << " ";
        }
    return os;
}