#include "Course.h"
#include <string>

Course::Course(){
    courseName="Unknown Course";
}
Course::Course(string nameArg){
    courseName=nameArg;
}
const string Course::getCourseName(){
    return courseName;
}
void Course::setCourseName(string nameArg){
    courseName=nameArg;
}