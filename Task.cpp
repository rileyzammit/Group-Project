#include "Task.h"

#include <iostream>

using namespace std;

// Default task used when an empty task object is created.
Task::Task()
    : title("Untitled Task"), deadline{0, 0, 0}, completed(false),
      weight(0.0), grade(0.0), hasGradeValue(false) {}

// Main task constructor used by the rest of the program.
Task::Task(const string& taskTitle, const Date& dueDate, bool isCompleted,
           double taskWeight, double taskGrade, bool gradeRecorded)
    : title(taskTitle), deadline(dueDate), completed(isCompleted),
      weight(taskWeight), grade(taskGrade), hasGradeValue(gradeRecorded) {}

void Task::setTitle(const string& taskTitle) {
    title = taskTitle;
}

void Task::setDeadline(const Date& dueDate) {
    deadline = dueDate;
}

void Task::markComplete() {
    // Flip the task from pending to completed.
    completed = true;
}

void Task::setWeight(double taskWeight) {
    weight = taskWeight;
}

void Task::setGrade(double taskGrade) {
    grade = taskGrade;
    hasGradeValue = true;
}

const string& Task::getTitle() const {
    return title;
}

Date Task::getDeadline() const {
    return deadline;
}

bool Task::isCompleted() const {
    return completed;
}

double Task::getWeight() const {
    return weight;
}

double Task::getGrade() const {
    return grade;
}

bool Task::hasGrade() const {
    return hasGradeValue;
}

string Task::getType() const {
    // Base task label used unless a derived class overrides it.
    return "Task";
}

Task* Task::clone() const {
    // Return a heap copy so courses can store independent task objects.
    return new Task(*this);
}

void Task::display() const {
    // Print the common task details shared by all task types.
    cout << getType() << ": " << title
         << " | Due: " << deadline.day << "/" << deadline.month << "/" << deadline.year
         << " | Status: " << (completed ? "Completed" : "Pending")
         << " | Weight: " << weight << "%";

    if (hasGradeValue) {
        cout << " | Grade: " << grade << "%";
    } else {
        cout << " | Grade: Not entered";
    }
}

void Task::save(ofstream& outFile) const {
    // Save the shared task fields in a fixed order for loading later.
    outFile << getType() << '\n';
    outFile << title << '\n';
    outFile << deadline.day << ' ' << deadline.month << ' ' << deadline.year << '\n';
    outFile << completed << '\n';
    outFile << weight << '\n';
    outFile << hasGradeValue << '\n';
    outFile << grade << '\n';
}
