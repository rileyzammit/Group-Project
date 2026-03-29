#include "AssignmentTask.h"

#include <iostream>

using namespace std;

// Default assignment task.
AssignmentTask::AssignmentTask() : Task(), submissionType("Online") {}

// Assignment task with a title, deadline, and submission method.
AssignmentTask::AssignmentTask(const string& taskTitle, const Date& dueDate,
                               const string& submission, bool isCompleted,
                               double taskWeight, double taskGrade,
                               bool gradeRecorded)
    : Task(taskTitle, dueDate, isCompleted, taskWeight, taskGrade, gradeRecorded),
      submissionType(submission) {}

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
    // Preserve the real derived type when a course stores a copy.
    return new AssignmentTask(*this);
}

void AssignmentTask::display() const {
    // Show the common task info first, then the assignment-specific detail.
    Task::display();
    cout << " | Submission: " << submissionType;
}

void AssignmentTask::save(ofstream& outFile) const {
    // Save the shared fields, then the extra assignment field.
    Task::save(outFile);
    outFile << submissionType << '\n';
}
