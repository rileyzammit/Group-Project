#include "Student.h"
using namespace std;

Student::Student(){
studentName="Unknown";
        studentCount++;
        studentID=000000000+studentCount;
}
Student::Student(string nameArg, int IDArg){
    studentName=nameArg;
    studentID=IDArg;
}
