#include <iostream>
#include <vector>

#include "Student.h"

using namespace std;

// Where all the action happens (copying data into vector, vector location, displaying data)
int main() {
    // create a vector of Student structs
    vector<Student> students;

    cout << "Entering Students data: " << endl;

    while (cin){
        // this creates a single Student struct variable
        Student student = get_student_struct_data();
        if (cin){
            // if input was succesful, add the copy of student into the vector
            students.push_back(student);
        }
    }

    // note to self, study this
    // display all students
    cout << "List of Students: " << endl;
    for (const Student & student : students){
        cout << student << endl;
    }

    return 0;

    // something about polymorphic call?
    // Student student = get_student_struct_data();
    // cout << endl << student << endl;

}   
// we compiled two source files linking them into one executable code
// g++ Student.cpp StudentMain.cpp
// ./a.out