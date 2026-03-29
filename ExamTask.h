#pragma once

#include "Task.h"

using namespace std;

// A task that represents an exam to prepare for.
class ExamTask : public Task {
private:
    int studyHours;

public:
    ExamTask();
    ExamTask(const string& taskTitle, const Date& dueDate, int hours,
             bool isCompleted = false, double taskWeight = 0.0,
             double taskGrade = 0.0, bool gradeRecorded = false);

    void setStudyHours(int hours);
    int getStudyHours() const;

    string getType() const override;
    Task* clone() const override;
    void display() const override;
    void save(ofstream& outFile) const override;
};
