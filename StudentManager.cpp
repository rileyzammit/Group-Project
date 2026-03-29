#include "StudentManager.h"

#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

StudentManager::StudentManager() : studentCount(0) {}

int StudentManager::promptInt(const string& prompt) {
    int value;

    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Please enter a valid number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

Date StudentManager::promptDate() {
    Date deadline{};
    deadline.day = promptInt("Enter deadline day: ");
    deadline.month = promptInt("Enter deadline month: ");
    deadline.year = promptInt("Enter deadline year: ");
    return deadline;
}

int StudentManager::promptStudentIndex() const {
    if (studentCount == 0) {
        cout << "No students available.\n";
        return -1;
    }

    cout << "\nSelect a student:\n";
    for (int i = 0; i < studentCount; ++i) {
        cout << i + 1 << ". " << students[i].getStudentName()
             << " (ID: " << students[i].getStudentID() << ")\n";
    }

    const int choice = promptInt("Enter your choice: ");
    if (choice < 1 || choice > studentCount) {
        cout << "Invalid student selection.\n";
        return -1;
    }

    return choice - 1;
}

void StudentManager::addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student limit reached.\n";
        return;
    }

    string name;
    cout << "Enter student name: ";
    getline(cin, name);

    const int id = promptInt("Enter student ID: ");
    students[studentCount++] = Student(name, id);
    cout << "Student added successfully.\n";
}

void StudentManager::addCourseToStudent() {
    const int studentIndex = promptStudentIndex();
    if (studentIndex == -1) {
        return;
    }

    string courseName;
    string courseCode;

    cout << "Enter course name: ";
    getline(cin, courseName);
    cout << "Enter course code: ";
    getline(cin, courseCode);

    if (students[studentIndex].addCourse(Course(courseName, courseCode))) {
        cout << "Course added successfully.\n";
    } else {
        cout << "This student already has the maximum of "
             << Student::MAX_COURSES << " courses.\n";
    }
}

void StudentManager::addTaskToCourse() {
    const int studentIndex = promptStudentIndex();
    if (studentIndex == -1) {
        return;
    }

    Student& student = students[studentIndex];
    if (student.getCourseCount() == 0) {
        cout << "Please add a course first.\n";
        return;
    }

    Course* courses = student.getCourses();
    cout << "\nSelect a course:\n";
    for (int i = 0; i < student.getCourseCount(); ++i) {
        cout << i + 1 << ". " << courses[i].getCourseName()
             << " (" << courses[i].getCourseCode() << ")\n";
    }

    const int courseChoice = promptInt("Enter your choice: ");
    if (courseChoice < 1 || courseChoice > student.getCourseCount()) {
        cout << "Invalid course selection.\n";
        return;
    }

    string title;
    cout << "Enter task title: ";
    getline(cin, title);
    const Date deadline = promptDate();

    cout << "\nChoose the type of task you want to add:\n";
    cout << "1. Assignment\n";
    cout << "2. Exam\n";
    const int typeChoice = promptInt("Enter 1 for Assignment or 2 for Exam: ");

    bool added = false;
    if (typeChoice == 1) {
        string submissionType;
        cout << "Enter submission type (example: Online, In person, Paper): ";
        getline(cin, submissionType);
        AssignmentTask task(title, deadline, submissionType);
        added = courses[courseChoice - 1].addTask(task);
    } else if (typeChoice == 2) {
        const int studyHours = promptInt("Enter estimated study hours required: ");
        ExamTask task(title, deadline, studyHours);
        added = courses[courseChoice - 1].addTask(task);
    } else {
        cout << "Invalid task type. Please enter 1 for Assignment or 2 for Exam.\n";
        return;
    }

    if (added) {
        cout << "Task added successfully.\n";
    } else {
        cout << "This course already has the maximum of "
             << Course::MAX_TASKS << " tasks.\n";
    }
}

void StudentManager::displayAllStudents() const {
    if (studentCount == 0) {
        cout << "No students available.\n";
        return;
    }

    for (int i = 0; i < studentCount; ++i) {
        cout << "\nStudent: " << students[i].getStudentName()
             << " (ID: " << students[i].getStudentID() << ")\n";

        const Course* courses = students[i].getCourses();
        if (students[i].getCourseCount() == 0) {
            cout << "  No courses added.\n";
            continue;
        }

        for (int j = 0; j < students[i].getCourseCount(); ++j) {
            courses[j].displayTasks();
        }
    }
}

void StudentManager::markTaskComplete() {
    const int studentIndex = promptStudentIndex();
    if (studentIndex == -1) {
        return;
    }

    Student& student = students[studentIndex];
    if (student.getCourseCount() == 0) {
        cout << "No courses available.\n";
        return;
    }

    Course* courses = student.getCourses();
    cout << "\nSelect a course:\n";
    for (int i = 0; i < student.getCourseCount(); ++i) {
        cout << i + 1 << ". " << courses[i].getCourseName() << '\n';
    }

    const int courseChoice = promptInt("Enter your choice: ");
    if (courseChoice < 1 || courseChoice > student.getCourseCount()) {
        cout << "Invalid course selection.\n";
        return;
    }

    Task** tasks = courses[courseChoice - 1].getTasks();
    const int taskCount = courses[courseChoice - 1].getTaskCount();
    if (taskCount == 0) {
        cout << "No tasks in this course.\n";
        return;
    }

    cout << "\nSelect a task to mark complete:\n";
    for (int i = 0; i < taskCount; ++i) {
        cout << i + 1 << ". ";
        tasks[i]->display();
        cout << '\n';
    }

    const int taskChoice = promptInt("Enter your choice: ");
    if (taskChoice < 1 || taskChoice > taskCount) {
        cout << "Invalid task selection.\n";
        return;
    }

    tasks[taskChoice - 1]->markComplete();
    cout << "Task marked as complete.\n";
}

void StudentManager::showProgressForStudent() const {
    const int studentIndex = promptStudentIndex();
    if (studentIndex == -1) {
        return;
    }

    ProgressTracker::show(students[studentIndex]);
}

void StudentManager::saveToFile() const {
    ofstream outFile("study_data.txt");
    if (!outFile) {
        cout << "Error opening file for saving.\n";
        return;
    }

    outFile << studentCount << '\n';
    for (int i = 0; i < studentCount; ++i) {
        outFile << students[i].getStudentName() << '\n';
        outFile << students[i].getStudentID() << '\n';
        outFile << students[i].getCourseCount() << '\n';

        const Course* courses = students[i].getCourses();
        for (int j = 0; j < students[i].getCourseCount(); ++j) {
            outFile << courses[j].getCourseName() << '\n';
            outFile << courses[j].getCourseCode() << '\n';
            outFile << courses[j].getTaskCount() << '\n';

            Task* const* tasks = courses[j].getTasks();
            for (int k = 0; k < courses[j].getTaskCount(); ++k) {
                tasks[k]->save(outFile);
            }
        }
    }

    cout << "Data saved successfully.\n";
}

void StudentManager::loadFromFile() {
    ifstream inFile("study_data.txt");
    if (!inFile) {
        cout << "No saved file found.\n";
        return;
    }

    int loadedStudentCount = 0;
    inFile >> loadedStudentCount;
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');

    studentCount = 0;
    for (int i = 0; i < loadedStudentCount && i < MAX_STUDENTS; ++i) {
        string studentName;
        int studentID;
        int courseCount;

        getline(inFile, studentName);
        inFile >> studentID;
        inFile >> courseCount;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');

        Student loadedStudent(studentName, studentID);

        for (int j = 0; j < courseCount && j < Student::MAX_COURSES; ++j) {
            string courseName;
            string courseCode;
            int taskCount;

            getline(inFile, courseName);
            getline(inFile, courseCode);
            inFile >> taskCount;
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');

            Course loadedCourse(courseName, courseCode);

            for (int k = 0; k < taskCount && k < Course::MAX_TASKS; ++k) {
                string type;
                string title;
                Date deadline{};
                bool completed;

                getline(inFile, type);
                getline(inFile, title);
                inFile >> deadline.day >> deadline.month >> deadline.year;
                inFile >> completed;
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');

                if (type == "Assignment") {
                    string submissionType;
                    getline(inFile, submissionType);
                    AssignmentTask task(title, deadline, submissionType, completed);
                    loadedCourse.addTask(task);
                } else if (type == "Exam") {
                    int studyHours;
                    inFile >> studyHours;
                    inFile.ignore(numeric_limits<streamsize>::max(), '\n');
                    ExamTask task(title, deadline, studyHours, completed);
                    loadedCourse.addTask(task);
                } else {
                    Task task(title, deadline, completed);
                    loadedCourse.addTask(task);
                }
            }

            loadedStudent.addCourse(loadedCourse);
        }

        students[studentCount++] = loadedStudent;
    }

    cout << "Data loaded successfully.\n";
}

void StudentManager::menu() {
    int choice;

    do {
        cout << "\n========== Student Management Menu ==========\n";
        cout << "1. Add student\n";
        cout << "2. Add course to student\n";
        cout << "3. Add task to course\n";
        cout << "4. Display all students, courses, and tasks\n";
        cout << "5. Mark task as complete\n";
        cout << "6. Show student progress\n";
        cout << "7. Save to file\n";
        cout << "8. Load from file\n";
        cout << "9. Exit\n";

        choice = promptInt("Enter your choice: ");
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                addCourseToStudent();
                break;
            case 3:
                addTaskToCourse();
                break;
            case 4:
                displayAllStudents();
                break;
            case 5:
                markTaskComplete();
                break;
            case 6:
                showProgressForStudent();
                break;
            case 7:
                saveToFile();
                break;
            case 8:
                loadFromFile();
                break;
            case 9:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 9);
}
