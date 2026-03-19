#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "Course.h"
#include <string>


// Student Class
class Student{
private: 
string studentName;
Course courses[6];
int studentID;
int courseCount;
static int studentCount;

protected:

public:
    Student();
    Student(string nameArg, int IDArg);
    void setStudentName(string nameArg){}
    void setStudentID(int IDArg){}
    string getStudentName(){}
    int getStudentID(){}
    void addCourse(Course courseArg);
     int getCourseCount();
    Course* getCourses();
    ~Student(){}
};

#endif