#include "ExamTask.h"

#include <iostream>

using namespace std;

// Default exam task.
ExamTask::ExamTask() : Task(), studyHours(0) {}

// Exam task with a title, deadline, and study-hour estimate.
ExamTask::ExamTask(const string& taskTitle, const Date& dueDate, int hours,
                   bool isCompleted, double taskWeight, double taskGrade,
                   bool gradeRecorded)
    : Task(taskTitle, dueDate, isCompleted, taskWeight, taskGrade, gradeRecorded),
      studyHours(hours) {}

void ExamTask::setStudyHours(int hours) {
    studyHours = hours;
}

int ExamTask::getStudyHours() const {
    return studyHours;
}

string ExamTask::getType() const {
    return "Exam";
}

Task* ExamTask::clone() const {
    // Preserve the real derived type when a course stores a copy.
    return new ExamTask(*this);
}

void ExamTask::display() const {
    // Show the common task info first, then the exam-specific detail.
    Task::display();
    cout << " | Study Hours: " << studyHours;
}

void ExamTask::save(ofstream& outFile) const {
    // Save the shared fields, then the extra exam field.
    Task::save(outFile);
    outFile << studyHours << '\n';
}
