#include "ExamTask.h"

#include <iostream>

using namespace std;

ExamTask::ExamTask() : Task(), studyHours(0) {}

ExamTask::ExamTask(const string& taskTitle, const Date& dueDate, int hours,
                   bool isCompleted)
    : Task(taskTitle, dueDate, isCompleted), studyHours(hours) {}

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
    return new ExamTask(*this);
}

void ExamTask::display() const {
    Task::display();
    cout << " | Study Hours: " << studyHours;
}

void ExamTask::save(ofstream& outFile) const {
    Task::save(outFile);
    outFile << studyHours << '\n';
}
