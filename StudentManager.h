#pragma once
#ifndef STUDYMANAGER_H
#define STUDYMANAGER_H

#include "Student.h"
#include "Course.h"
#include "Task.h"
#include "AssignmentTask.h"
#include "ExamTask.h"
#include "ProgressTracker.h"

class StudyManager {
private:
    Student student;

public:
    StudyManager();

    void setupStudent();
    void addCourse();
    void addTask();
    void displayAllCoursesAndTasks() const;
    void markTaskComplete();
    void saveToFile() const;
    void loadFromFile();
    void showProgress();
    void menu();
};

#endif
