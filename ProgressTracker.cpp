#include "ProgressTracker.h"

#include <iostream>

using namespace std;

// Add up weights for tasks being counted toward grade
double ProgressTracker::calculateRecordedWeight(const Course& course) {
    double totalWeight = 0.0;
    Task* const* tasks = course.getTasks();

    for (int i = 0; i < course.getTaskCount(); ++i) {
        if (tasks[i]->hasGrade() && tasks[i]->getWeight() > 0.0) {
            totalWeight += tasks[i]->getWeight();
        }
    }

    return totalWeight;
}

// Check if course has enough data to calculate avg (more than 1 graded task w weight >0)
bool ProgressTracker::courseHasGradeData(const Course& course) {
    return calculateRecordedWeight(course) > 0.0;
}

// Calculate the current weighted grade for course in arg
double ProgressTracker::calculateCourseAverage(const Course& course) {
    double weightedTotal = 0.0;
    double totalWeight = 0.0;
    Task* const* tasks = course.getTasks();

    for (int i = 0; i < course.getTaskCount(); ++i) {
        if (tasks[i]->hasGrade() && tasks[i]->getWeight() > 0.0) {
            weightedTotal += tasks[i]->getGrade() * tasks[i]->getWeight();
            totalWeight += tasks[i]->getWeight();
        }
    }

    if (totalWeight == 0.0) {
        return 0.0;
    }

    return weightedTotal / totalWeight;
}

// Checks if student has at least one course with grade data
bool ProgressTracker::studentHasGradeData(const Student& student) {
    const Course* courses = student.getCourses();

    for (int i = 0; i < student.getCourseCount(); ++i) {
        if (courseHasGradeData(courses[i])) {
            return true;
        }
    }

    return false;
}

// Average together one student's course averages
double ProgressTracker::calculateStudentAverage(const Student& student) {
    const Course* courses = student.getCourses();
    double totalAverage = 0.0;
    int gradedCourses = 0;

    for (int i = 0; i < student.getCourseCount(); ++i) {
        if (courseHasGradeData(courses[i])) {
            totalAverage += calculateCourseAverage(courses[i]);
            gradedCourses++;
        }
    }

    if (gradedCourses == 0) {
        return 0.0;
    }

    return totalAverage / gradedCourses;
}

// Average together each student's overall average
double ProgressTracker::calculateAllStudentsAverage(const Student students[], int studentCount) {
    double totalAverage = 0.0;
    int gradedStudents = 0;

    for (int i = 0; i < studentCount; ++i) {
        if (studentHasGradeData(students[i])) {
            totalAverage += calculateStudentAverage(students[i]);
            gradedStudents++;
        }
    }

    if (gradedStudents == 0) {
        return 0.0;
    }

    return totalAverage / gradedStudents;
}

// Show completion stats, course grades, the student's overall average,
// and the average across all students that currently have grade data
void ProgressTracker::show(const Student& student, const Student students[], int studentCount) {
    int totalTasks = 0;
    int completedTasks = 0;
    const Course* courses = student.getCourses();

    for (int i = 0; i < student.getCourseCount(); ++i) {
        Task* const* tasks = courses[i].getTasks();

        for (int j = 0; j < courses[i].getTaskCount(); ++j) {
            totalTasks++;
            if (tasks[j]->isCompleted()) {
                completedTasks++;
            }
        }
    }

    cout << "\nStudent: " << student.getStudentName() << endl;
    cout << "Student ID: " << student.getStudentID() << endl;
    cout << "Courses Selected: " << student.getCourseCount() << endl;
    cout << "Tasks Completed: " << completedTasks << "/" << totalTasks << endl;

    if (totalTasks > 0) {
        double completionPercentage = (double)completedTasks / totalTasks * 100.0;
        cout << "Progress: " << completionPercentage << "%" << endl;
    } else {
        cout << "Progress: 0%" << endl;
    }

    cout << "\nCourse Grades:\n";
    if (student.getCourseCount() == 0) {
        cout << "No courses added yet.\n";
    } else {
        for (int i = 0; i < student.getCourseCount(); ++i) {
            cout << i + 1 << ". " << courses[i].getCourseName()
                 << " (" << courses[i].getCourseCode() << ")";

            if (courseHasGradeData(courses[i])) {
                cout << " | Current weighted grade: "
                     << calculateCourseAverage(courses[i]) << "%"
                     << " | Recorded weight: "
                     << calculateRecordedWeight(courses[i]) << "%";
            } else {
                cout << " | No graded tasks recorded yet";
            }

            cout << endl;
        }
    }

    if (studentHasGradeData(student)) {
        cout << "\nStudent overall average: "
             << calculateStudentAverage(student) << "%" << endl;
    } else {
        cout << "\nStudent overall average: No graded courses yet" << endl;
    }

    if (studentCount > 0) {
        bool anyGradedStudents = false;
        for (int i = 0; i < studentCount; ++i) {
            if (studentHasGradeData(students[i])) {
                anyGradedStudents = true;
                break;
            }
        }

        if (anyGradedStudents) {
            double allStudentsAverage = calculateAllStudentsAverage(students, studentCount);
            cout << "Average across all students: "
                 << allStudentsAverage << "%" << endl;
        } else {
            cout << "Average across all students: No graded students yet" << endl;
        }
    }
}
