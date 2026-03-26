#pragma once

#include "Task.h"

using namespace std;

class AssignmentTask : public Task {
private:
    string submissionType;

public:
    AssignmentTask();
    AssignmentTask(const string& taskTitle, const Date& dueDate,
                   const string& submission, bool isCompleted = false);

    void setSubmissionType(const string& submission);
    const string& getSubmissionType() const;

    string getType() const override;
    Task* clone() const override;
    void display() const override;
    void save(ofstream& outFile) const override;
};
