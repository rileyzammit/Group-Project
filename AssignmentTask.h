#pragma once

#include "Task.h"

using namespace std;

// A task that is meant to be turned in somehow.
class AssignmentTask : public Task {
private:
    string submissionType;

public:
    AssignmentTask();
    AssignmentTask(const string& taskTitle, const Date& dueDate,
                   const string& submission, bool isCompleted = false,
                   double taskWeight = 0.0, double taskGrade = 0.0,
                   bool gradeRecorded = false);

    void setSubmissionType(const string& submission);
    const string& getSubmissionType() const;

    string getType() const override;
    Task* clone() const override;
    void display() const override;
    void save(ofstream& outFile) const override;
};
