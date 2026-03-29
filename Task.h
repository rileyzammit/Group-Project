#pragma once

#include <fstream>
#include <string>

using namespace std;

// Simple date container used by all tasks.
struct Date {
    int day;
    int month;
    int year;
};

// Base task type shared by assignments and exams.
class Task {
protected:
    string title;
    Date deadline;
    bool completed;
    double weight;
    double grade;
    bool hasGradeValue;

public:
    Task();
    Task(const string& taskTitle, const Date& dueDate, bool isCompleted = false,
         double taskWeight = 0.0, double taskGrade = 0.0, bool gradeRecorded = false);
    virtual ~Task() = default;

    void setTitle(const string& taskTitle);
    void setDeadline(const Date& dueDate);
    void markComplete();
    void setWeight(double taskWeight);
    void setGrade(double taskGrade);

    const string& getTitle() const;
    Date getDeadline() const;
    bool isCompleted() const;
    double getWeight() const;
    double getGrade() const;
    bool hasGrade() const;

    // Virtual functions let derived task types customize how they behave.
    virtual string getType() const;
    virtual Task* clone() const;
    virtual void display() const;
    virtual void save(ofstream& outFile) const;
};
