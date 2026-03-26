#pragma once

#include "Task.h"

#include <string>

using namespace std;

class Course {
public:
    static const int MAX_TASKS = 10;

private:
    string courseName;
    string courseCode;
    Task* tasks[MAX_TASKS];
    int taskCount;

    void clearTasks();
    void copyFrom(const Course& other);

public:
    Course();
    Course(const string& nameArg, const string& codeArg);
    Course(const Course& other);
    Course& operator=(const Course& other);
    ~Course();

    const string& getCourseName() const;
    const string& getCourseCode() const;
    void setCourseName(const string& nameArg);
    void setCourseCode(const string& codeArg);

    bool addTask(const Task& taskArg);
    int getTaskCount() const;
    Task** getTasks();
    Task* const* getTasks() const;
    void displayTasks() const;
};
