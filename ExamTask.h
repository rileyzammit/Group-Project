#pragma once

#include "Task.h"

using namespace std;

class ExamTask : public Task {
private:
    int studyHours;

public:
    ExamTask();
    ExamTask(const string& taskTitle, const Date& dueDate, int hours,
             bool isCompleted = false);

    void setStudyHours(int hours);
    int getStudyHours() const;

    string getType() const override;
    Task* clone() const override;
    void display() const override;
    void save(ofstream& outFile) const override;
};
