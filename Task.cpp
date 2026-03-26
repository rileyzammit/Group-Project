#include "Task.h"

#include <iostream>

using namespace std;

Task::Task() : title("Untitled Task"), deadline{0, 0, 0}, completed(false) {}

Task::Task(const string& taskTitle, const Date& dueDate, bool isCompleted)
    : title(taskTitle), deadline(dueDate), completed(isCompleted) {}

void Task::setTitle(const string& taskTitle) {
    title = taskTitle;
}

void Task::setDeadline(const Date& dueDate) {
    deadline = dueDate;
}

void Task::markComplete() {
    completed = true;
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

string Task::getType() const {
    return "Task";
}

Task* Task::clone() const {
    return new Task(*this);
}

void Task::display() const {
    cout << getType() << ": " << title
         << " | Due: " << deadline.day << "/" << deadline.month << "/" << deadline.year
         << " | Status: " << (completed ? "Completed" : "Pending");
}

void Task::save(ofstream& outFile) const {
    outFile << getType() << '\n';
    outFile << title << '\n';
    outFile << deadline.day << ' ' << deadline.month << ' ' << deadline.year << '\n';
    outFile << completed << '\n';
}
