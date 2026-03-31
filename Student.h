#pragma once

#include "Course.h"

#include <string>


// The class is for each student, which includes their name, ID, and their courses
class Student {
public:
    // Each student can store up to 6 courses
    static const int MAX_COURSES = 6;

private:
    // Basic student info
    string studentName;
    int studentID;

    // Fixed-size array of courses for this student.
    Course courses[MAX_COURSES];

    // Keeps track of how many course slots are actually being used.
    int courseCount;

public:
    // Default constructor
    Student();

    // Overloaded constructor that creates a student with a name and ID
    Student(const string& nameArg, int idArg);

    // Setters for changing student info
    void setStudentName(const string& nameArg);
    void setStudentID(int idArg);

    // Getters for reading student info
    const string& getStudentName() const;
    int getStudentID() const;

    // Adds a course to the student's course list, returns false if already at max courses
    bool addCourse(const Course& courseArg);

    // Returns how many courses this student has
    int getCourseCount() const;

    // Returns course array so other functions can use it/read info
    Course* getCourses();
    const Course* getCourses() const;
};
