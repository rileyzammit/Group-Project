#include "Course.h"

#include <iostream>

using namespace std;

Course::Course() : courseName("Unknown Course"), courseCode("UNKN"), taskCount(0) {
    for (int i = 0; i < MAX_TASKS; ++i) {
        tasks[i] = nullptr;
    }
}

Course::Course(const string& nameArg, const string& codeArg)
    : courseName(nameArg), courseCode(codeArg), taskCount(0) {
    for (int i = 0; i < MAX_TASKS; ++i) {
        tasks[i] = nullptr;
    }
}

Course::Course(const Course& other) : courseName("Unknown Course"), courseCode("UNKN"), taskCount(0) {
    for (int i = 0; i < MAX_TASKS; ++i) {
        tasks[i] = nullptr;
    }
    copyFrom(other);
}

Course& Course::operator=(const Course& other) {
    if (this != &other) {
        clearTasks();
        courseName = "Unknown Course";
        courseCode = "UNKN";
        taskCount = 0;
        copyFrom(other);
    }
    return *this;
}

Course::~Course() {
    clearTasks();
}

void Course::clearTasks() {
    for (int i = 0; i < taskCount; ++i) {
        delete tasks[i];
        tasks[i] = nullptr;
    }

    for (int i = taskCount; i < MAX_TASKS; ++i) {
        tasks[i] = nullptr;
    }

    taskCount = 0;
}

void Course::copyFrom(const Course& other) {
    courseName = other.courseName;
    courseCode = other.courseCode;

    for (int i = 0; i < other.taskCount; ++i) {
        tasks[i] = other.tasks[i]->clone();
    }

    for (int i = other.taskCount; i < MAX_TASKS; ++i) {
        tasks[i] = nullptr;
    }

    taskCount = other.taskCount;
}

const string& Course::getCourseName() const {
    return courseName;
}

const string& Course::getCourseCode() const {
    return courseCode;
}

void Course::setCourseName(const string& nameArg) {
    courseName = nameArg;
}

void Course::setCourseCode(const string& codeArg) {
    courseCode = codeArg;
}

bool Course::addTask(const Task& taskArg) {
    if (taskCount >= MAX_TASKS) {
        return false;
    }

    tasks[taskCount++] = taskArg.clone();
    return true;
}

int Course::getTaskCount() const {
    return taskCount;
}

Task** Course::getTasks() {
    return tasks;
}

Task* const* Course::getTasks() const {
    return tasks;
}

void Course::displayTasks() const {
    cout << "Course: " << courseName << " (" << courseCode << ")\n";

    if (taskCount == 0) {
        cout << "  No tasks added.\n";
        return;
    }

    for (int i = 0; i < taskCount; ++i) {
        cout << "  " << i + 1 << ". ";
        tasks[i]->display();
        cout << '\n';
    }
}
