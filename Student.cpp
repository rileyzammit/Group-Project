#include "Student.h"

using namespace std;

// Default constructor creates default name and student id, no courses
Student::Student() {
    studentName = "Unknown";
    studentID = 0;
    courseCount = 0;
}

// Overloaded constructor creates student based on arguments, no courses
Student::Student(const string& nameArg, int idArg) {
    studentName = nameArg;
    studentID = idArg;
    courseCount = 0;
}

// Setters for name and ID
void Student::setStudentName(const string& nameArg) {
    studentName = nameArg;
}

void Student::setStudentID(int idArg) {
    studentID = idArg;
}

// Getters for name and ID
const string& Student::getStudentName() const {
    return studentName;
}

int Student::getStudentID() const {
    return studentID;
}

//Checks if able to add course, if so adds course from argument
bool Student::addCourse(const Course& courseArg) {
    // Stop adding if the fixed-size course list is already full.
    if (courseCount >= MAX_COURSES) {
        return false;
    }

    // Store the course in the next open slot.
    courses[courseCount++] = courseArg;
    return true;
}

int Student::getCourseCount() const {
    return courseCount;
}

Course* Student::getCourses() {
    return courses;
}

const Course* Student::getCourses() const {
    return courses;
}
