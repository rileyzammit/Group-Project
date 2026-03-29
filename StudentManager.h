#pragma once

#include "AssignmentTask.h"
#include "Course.h"
#include "ExamTask.h"
#include "ProgressTracker.h"
#include "Student.h"

using namespace std;

// Handles the menu, user input, and the top-level list of students.
class StudentManager {
private:
    static const int MAX_STUDENTS = 10;

    Student students[MAX_STUDENTS];
    int studentCount;

    // Shared input helpers so the menu code stays cleaner.
    int promptStudentIndex() const;
    static int promptInt(const string& prompt);
    static double promptDouble(const string& prompt);
    static Date promptDate();

public:
    StudentManager();

    void addStudent();
    void addCourseToStudent();
    void addTaskToCourse();
    void displayAllStudents() const;
    void markTaskComplete();
    void showProgressForStudent() const;
    void saveToFile() const;
    void loadFromFile();
    void menu();
};
