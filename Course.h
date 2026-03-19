#pragma once
#ifndef COURSE_H
#define COURSE_H
#include <string>
class Course{
private: 
string courseName;
string courseCode;
public:
Course();
Course(string nameArg, string codeArg);
const string getCourseName() ;
const string getCourseCode() ;
void setCourseName(string nameArg);
void setCourseCode(string codeArg);
};
#endif