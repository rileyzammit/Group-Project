
#include "Student.h"
#include "Course.h"
#include <iostream>

using namespace std;

int main() {
    StudyManager manager;
    manager.menu();

Student s("Student 1");

    Course math1("Math 1");
    math1.addTask(new AssignmentTask("HW1"));
    math1.addTask(new ExamTask("Midterm"));
    s.addCourse(math1);

    Course math2("Math 2");
    math2.addTask(new AssignmentTask("HW1"));
    math2.addTask(new ExamTask("Midterm"));
    s.addCourse(math2);

    Course cpp("C++ Programming");
    cpp.addTask(new AssignmentTask("HW1"));
    cpp.addTask(new ExamTask("Midterm"));
    s.addCourse(cpp);

    Course oop("Object Oriented Programming");
    oop.addTask(new AssignmentTask("HW1"));
    oop.addTask(new ExamTask("Midterm"));
    s.addCourse(oop);

    Course chemistry("Chemistry");
    chemistry.addTask(new AssignmentTask("HW1"));
    chemistry.addTask(new ExamTask("Midterm"));
    s.addCourse(chemistry);

    Course analyticalChem("Analytical Chemistry");
    analyticalChem.addTask(new AssignmentTask("HW1"));
    analyticalChem.addTask(new ExamTask("Midterm"));
    s.addCourse(analyticalChem);

    Course proComms("Professional Communication");
    proComms.addTask(new AssignmentTask("HW1"));
    proComms.addTask(new ExamTask("Midterm"));
    s.addCourse(proComms);

    Course business("Foundations of Business");
    business.addTask(new AssignmentTask("HW1"));
    business.addTask(new ExamTask("Midterm"));
    s.addCourse(business);

    Course physics("Physics");
    physics.addTask(new AssignmentTask("HW1"));
    physics.addTask(new ExamTask("Midterm"));
    s.addCourse(physics);

    for (int i = 0; i < s.getCourseCount(); i++) {
        s.getCourses()[i].display();
    }

    s.getCourses()[0].getTasks()[0]->markComplete();

    ProgressTracker::show(s);

    return 0;
}