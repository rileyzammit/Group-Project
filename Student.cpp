#include <string>
#include "Student.h"

using namespace std;

Student::Student(){
studentName="Unknown";
        studentCount++;
        studentID=000000000+studentCount;
        courseCount=0;
}
Student::Student(string nameArg, int IDArg){
    studentName=nameArg;
    studentID=IDArg;

}
void Student::setStudentName(string nameArg){
     studentName=nameArg;
}
void Student::setStudentID(int IDArg){
     studentID=IDArg;
}

string Student::getStudentName(){
    return studentName;
}
int Student::getStudentID(){
    return studentID;
}
void Student::addCourse(Course c){
    if (courseCount<5){
        courses[courseCount++]=c;
    }
}
int Student::studentCount=0;
