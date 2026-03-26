#pragma once

#include "Course.h"

#include <string>

using namespace std;

class Student {
public:
    static const int MAX_COURSES = 6;

private:
    string studentName;
    int studentID;
    Course courses[MAX_COURSES];
    int courseCount;

public:
    Student();
    Student(const string& nameArg, int idArg);

    void setStudentName(const string& nameArg);
    void setStudentID(int idArg);
    const string& getStudentName() const;
    int getStudentID() const;

    bool addCourse(const Course& courseArg);
    int getCourseCount() const;
    Course* getCourses();
    const Course* getCourses() const;
};
