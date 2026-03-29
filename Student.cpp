#include "Student.h"

using namespace std;

// Default student used when an empty object is created first.
Student::Student() : studentName("Unknown"), studentID(0), courseCount(0) {}

// Builds a student with a real name and ID.
Student::Student(const string& nameArg, int idArg)
    : studentName(nameArg), studentID(idArg), courseCount(0) {}

void Student::setStudentName(const string& nameArg) {
    studentName = nameArg;
}

void Student::setStudentID(int idArg) {
    studentID = idArg;
}

const string& Student::getStudentName() const {
    return studentName;
}

int Student::getStudentID() const {
    return studentID;
}

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
