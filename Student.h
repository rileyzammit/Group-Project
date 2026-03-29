#pragma once

#include "Course.h"

#include <string>

using namespace std;

// This class represents one student in the program.
// It stores the student's name, ID, and the courses that belong to them.
class Student {
public:
    // Each student can store up to 6 courses.
    static const int MAX_COURSES = 6;

private:
    // Basic student info.
    string studentName;
    int studentID;

    // Fixed-size array of courses for this student.
    Course courses[MAX_COURSES];

    // Keeps track of how many course slots are actually being used.
    int courseCount;

public:
    // Default constructor.
    Student();

    // Constructor that creates a student with a name and ID.
    Student(const string& nameArg, int idArg);

    // Setters for changing student info.
    void setStudentName(const string& nameArg);
    void setStudentID(int idArg);

    // Getters for reading student info.
    const string& getStudentName() const;
    int getStudentID() const;

    // Adds a course to the student's course list.
    // Returns false if the student already has the maximum number of courses.
    bool addCourse(const Course& courseArg);

    // Returns how many courses this student currently has.
    int getCourseCount() const;

    // Gives access to the course array so other parts of the program can use it.
    Course* getCourses();
    const Course* getCourses() const;
};
