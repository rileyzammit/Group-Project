#include "AssignmentTask.h"

#include <iostream>

using namespace std;

AssignmentTask::AssignmentTask() : Task(), submissionType("Online") {}

AssignmentTask::AssignmentTask(const string& taskTitle, const Date& dueDate,
                               const string& submission, bool isCompleted)
    : Task(taskTitle, dueDate, isCompleted), submissionType(submission) {}

void AssignmentTask::setSubmissionType(const string& submission) {
    submissionType = submission;
}

const string& AssignmentTask::getSubmissionType() const {
    return submissionType;
}

string AssignmentTask::getType() const {
    return "Assignment";
}

Task* AssignmentTask::clone() const {
    return new AssignmentTask(*this);
}

void AssignmentTask::display() const {
    Task::display();
    cout << " | Submission: " << submissionType;
}

void AssignmentTask::save(ofstream& outFile) const {
    Task::save(outFile);
    outFile << submissionType << '\n';
}
