#include "Course.h"
#include <string>

using namespace std;

Course::Course(){
    courseName="Unknown Course";
    courseCode="1AB0";
}
Course::Course(string nameArg, string codeArg){
    courseName=nameArg;
    courseCode=codeArg;
}
const string Course::getCourseName(){
    return courseName;
}
const string Course::getCourseCode(){
    return courseCode;
}
void Course::setCourseName(string nameArg){
    courseName=nameArg;
}
void Course::setCourseCode(string codeArg){
    courseName=codeArg;
}