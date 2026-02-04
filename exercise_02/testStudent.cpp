#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "./include/doctest.h" 
#include "Student.h"

TEST_CASE("Testing initialization of Student struct") {
    Student s;
    CHECK(s.number_of_homeworks == 0);
    CHECK(s.hw_grades == nullptr);
}

TEST_CASE("Testing parameterized constructor of Student struct") {
    Student s("John", 90, 3);
    CHECK(s.name == "John");
    CHECK(s.final == 90);
    CHECK(s.number_of_homeworks == 3);
    for (int i = 0; i < s.number_of_homeworks; i++) {
        s.hw_grades[i] = i * 10; // Assigning some values
    }
    CHECK(s.hw_grades[0] == 0);
    CHECK(s.hw_grades[1] == 10);
    CHECK(s.hw_grades[2] == 20);
}

TEST_CASE("Zero homeworks doesn't crash") {
    Student s("Dave", 88, 0);
    CHECK(s.number_of_homeworks == 0);
    CHECK(s.hw_grades == nullptr);  // Array allocated but size 0
    // Destructor should handle this safely
}