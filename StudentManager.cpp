#include "StudyManager.h"
#include <iostream>
#include <fstream>

using namespace std; 
class StudyManager {
private:
    Student student;

public:
    StudyManager() {}

    void setupStudent() {
        string name, id;
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter student ID: ";
        getline(cin, id);

        student = Student(name, id);
    }

    void addCourse() {
        string courseName;
        cout << "Enter course name: ";
        getline(cin, courseName);

        Course course(courseName);
        student.addCourse(course);

        cout << "Course added successfully.\n";
    }

    void addTask() {
        vector<Course>& courses = student.getCourses();

        if (courses.empty()) {
            cout << "Please add a course first.\n";
            return;
        }

        cout << "\nSelect a course:\n";
        for (size_t i = 0; i < courses.size(); i++) {
            cout << i + 1 << ". " << courses[i].getCourseName() << endl;
        }

        int courseChoice;
        cin >> courseChoice;
        cin.ignore();

        if (courseChoice < 1 || courseChoice > (int)courses.size()) {
            cout << "Invalid course selection.\n";
            return;
        }

        string title;
        Date deadline;
        int typeChoice;

        cout << "Enter task title: ";
        getline(cin, title);

        cout << "Enter deadline day: ";
        cin >> deadline.day;
        cout << "Enter deadline month: ";
        cin >> deadline.month;
        cout << "Enter deadline year: ";
        cin >> deadline.year;

        cout << "Task type:\n";
        cout << "1. Assignment\n";
        cout << "2. Exam\n";
        cout << "Choose: ";
        cin >> typeChoice;
        cin.ignore();

        if (typeChoice == 1) {
            string submissionType;
            cout << "Enter submission type (Online/In Person): ";
            getline(cin, submissionType);

            Task* task = new AssignmentTask(title, deadline, submissionType);
            courses[courseChoice - 1].addTask(task);
            cout << "Assignment added successfully.\n";
        }
        else if (typeChoice == 2) {
            int studyHours;
            cout << "Enter study hours required: ";
            cin >> studyHours;
            cin.ignore();

            Task* task = new ExamTask(title, deadline, studyHours);
            courses[courseChoice - 1].addTask(task);
            cout << "Exam added successfully.\n";
        }
        else {
            cout << "Invalid task type.\n";
        }
    }

    void displayAllCoursesAndTasks() const {
        const vector<Course>& courses = student.getCourses();

        if (courses.empty()) {
            cout << "No courses available.\n";
            return;
        }

        for (size_t i = 0; i < courses.size(); i++) {
            courses[i].displayTasks();
        }
    }

    void markTaskComplete() {
        vector<Course>& courses = student.getCourses();

        if (courses.empty()) {
            cout << "No courses available.\n";
            return;
        }

        cout << "\nSelect a course:\n";
        for (size_t i = 0; i < courses.size(); i++) {
            cout << i + 1 << ". " << courses[i].getCourseName() << endl;
        }

        int courseChoice;
        cin >> courseChoice;
        cin.ignore();

        if (courseChoice < 1 || courseChoice > (int)courses.size()) {
            cout << "Invalid course selection.\n";
            return;
        }

        vector<Task*>& tasks = courses[courseChoice - 1].getTasks();

        if (tasks.empty()) {
            cout << "No tasks in this course.\n";
            return;
        }

        cout << "\nSelect a task to mark complete:\n";
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". ";
            tasks[i]->display();
            cout << endl;
        }

        int taskChoice;
        cin >> taskChoice;
        cin.ignore();

        if (taskChoice < 1 || taskChoice > (int)tasks.size()) {
            cout << "Invalid task selection.\n";
            return;
        }

        tasks[taskChoice - 1]->markComplete();
        cout << "Task marked as complete.\n";
    }

    void saveToFile() const {
        ofstream outFile("study_data.txt");

        if (!outFile) {
            cout << "Error opening file for saving.\n";
            return;
        }

        outFile << student.getName() << endl;
        outFile << student.getStudentID() << endl;

        const vector<Course>& courses = student.getCourses();
        outFile << courses.size() << endl;

        for (size_t i = 0; i < courses.size(); i++) {
            outFile << courses[i].getCourseName() << endl;

            const vector<Task*>& tasks = courses[i].getTasks();
            outFile << tasks.size() << endl;

            for (size_t j = 0; j < tasks.size(); j++) {
                tasks[j]->save(outFile);
            }
        }

        outFile.close();
        cout << "Data saved successfully.\n";
    }

    void loadFromFile() {
        ifstream inFile("study_data.txt");

        if (!inFile) {
            cout << "No saved file found.\n";
            return;
        }

        string name, id;
        getline(inFile, name);
        getline(inFile, id);

        student = Student(name, id);

        int courseCount;
        inFile >> courseCount;
        inFile.ignore();

        for (int i = 0; i < courseCount; i++) {
            string courseName;
            getline(inFile, courseName);

            Course course(courseName);

            int taskCount;
            inFile >> taskCount;
            inFile.ignore();

            for (int j = 0; j < taskCount; j++) {
                string type, title;
                Date deadline;
                bool completed;

                getline(inFile, type);
                getline(inFile, title);
                inFile >> deadline.day >> deadline.month >> deadline.year;
                inFile >> completed;
                inFile.ignore();

                if (type == "Assignment") {
                    string submissionType;
                    getline(inFile, submissionType);
                    Task* task = new AssignmentTask(title, deadline, submissionType, completed);
                    course.addTask(task);
                }
                else if (type == "Exam") {
                    int studyHours;
                    inFile >> studyHours;
                    inFile.ignore();
                    Task* task = new ExamTask(title, deadline, studyHours, completed);
                    course.addTask(task);
                }
                else {
                    Task* task = new Task(title, deadline, completed);
                    course.addTask(task);
                }
            }

            student.addCourse(course);
        }

        inFile.close();
        cout << "Data loaded successfully.\n";
    }

    void showProgress() const {
        ProgressTracker::calculateProgress(student);
    }

    void menu() {
        int choice;

        do {
            cout << "\n========== StudyAssist Menu ==========\n";
            cout << "1. Set up student\n";
            cout << "2. Add course\n";
            cout << "3. Add task\n";
            cout << "4. Display courses and tasks\n";
            cout << "5. Mark task as complete\n";
            cout << "6. Show progress\n";
            cout << "7. Save to file\n";
            cout << "8. Load from file\n";
            cout << "9. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    setupStudent();
                    break;
                case 2:
                    addCourse();
                    break;
                case 3:
                    addTask();
                    break;
                case 4:
                    displayAllCoursesAndTasks();
                    break;
                case 5:
                    markTaskComplete();
                    break;
                case 6:
                    showProgress();
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
            }

        } while (choice != 9);
    }
};