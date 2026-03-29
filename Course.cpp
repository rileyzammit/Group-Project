#include "Course.h"

#include <iostream>

using namespace std;

// Start with a default course and an empty task list.
Course::Course() : courseName("Unknown Course"), courseCode("UNKN"), taskCount(0) {
    for (int i = 0; i < MAX_TASKS; ++i) {
        tasks[i] = nullptr;
    }
}

// Start with a named course and an empty task list.
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
    // Make a deep copy so each course owns its own task objects.
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
    // Free any tasks that were created on the heap.
    clearTasks();
}

void Course::clearTasks() {
    // Delete only the tasks that are actually being used.
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

    // Clone each task so copies do not share the same pointers.
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
    // Stop adding if the fixed-size task list is already full.
    if (taskCount >= MAX_TASKS) {
        return false;
    }

    // Store a cloned copy so the course owns its own task object.
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

    // Show each task in the course using the task's own display function.
    for (int i = 0; i < taskCount; ++i) {
        cout << "  " << i + 1 << ". ";
        tasks[i]->display();
        cout << '\n';
    }
}
