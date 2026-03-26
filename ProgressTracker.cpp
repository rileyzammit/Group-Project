#include "ProgressTracker.h"
#include "Task.h"
#include "Course.h"
#include "Student.h"
#include <iostream>
using namespace std;

void ProgressTracker::show(Student& s) {
    int total = 0;
    int completed = 0;

    for (int i = 0; i < s.getCourseCount(); i++) {
        Course* courses = s.getCourses();
        Task** tasks = courses[i].getTasks();

        for (int j = 0; j < courses[i].getTaskCount(); j++) {
            total++;
            if (tasks[j]->isCompleted()) {
                completed++;
            }
        }
    }

    cout << "\nStudent: " << s.getStudentName() << endl;
    cout << "Student ID: " << s.getStudentID() << endl;
    cout << "Courses Selected: " << s.getCourseCount() << endl;
    cout << "Tasks Completed: " << completed << "/" << total << endl;

    if (total > 0) {
        double percentage = (double)completed / total * 100;
        cout << "Progress: " << percentage << "%" << endl;
    } else {
        cout << "Progress: 0%" << endl;
    }
}