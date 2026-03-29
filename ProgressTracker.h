#pragma once

#include "Student.h"

// Utility class that summarizes how much work a student has completed.
class ProgressTracker {
public:
    static double calculateCourseAverage(const Course& course);
    static double calculateRecordedWeight(const Course& course);
    static bool courseHasGradeData(const Course& course);
    static double calculateStudentAverage(const Student& student);
    static bool studentHasGradeData(const Student& student);
    static double calculateAllStudentsAverage(const Student students[], int studentCount);
    static void show(const Student& student, const Student students[], int studentCount);
};
