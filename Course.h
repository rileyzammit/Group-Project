#ifndef COURSE_H
#define COURSE_H
#include <string>
class Course{
private: 
string courseName;
public:
Course();
Course(string nameArg);
const string getCourseName() ;
void setCourseName(string nameArg);
};
#endif