#include <string>

// Student Class
class Student{
private: 
string studentName;
static int studentCount;
int studentID;

protected:

public:
    Student(){ }
    Student(string nameArg, int IDArg){
        studentName=nameArg;
        studentID=IDArg;
    }
    void setName(string nameArg){
        studentName=nameArg;
    }
    void setStudentID(int IDArg){
        studentID=IDArg;
    }
    string getName(){
        return studentName;
    }
    int getStudentID(){
        return studentID;
    }
    ~Student(){}
};
int Student::studentCount=0;