#include <iostream>
#include "student.h"
#include <fstream>

using namespace std;

void Student::displayStudent() const {
    cout << "Student ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "Email: " << email << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Age: " << age << endl;
    cout << "Grade: " << grade << endl;
}

void addStudent(vector<Student>& students) {
    Student newStudent;

    cout << "\n--- Add New Student ---" << endl;

    cout << "Enter Student ID: ";
    cin >> newStudent.id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, newStudent.name);

    cout << "Enter Gender: ";
    getline(cin, newStudent.gender);

    cout << "Enter Email: ";
    getline(cin, newStudent.email);

    cout << "Enter Date of Birth (YYYY-MM-DD): ";
    getline(cin, newStudent.dob);

    cout << "Enter Phone Number: ";
    getline(cin, newStudent.phoneNumber);

    cout << "Enter Age: ";
    cin >> newStudent.age;
    cin.ignore();

    cout << "Enter Grade: ";
    getline(cin, newStudent.grade);

    students.push_back(newStudent);

    ofstream outFile("students.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening students.txt for writing!" << endl;
        return;
    }

    outFile << newStudent.id << ","
            << newStudent.name << ","
            << newStudent.gender << ","
            << newStudent.email << ","
            << newStudent.dob << ","
            << newStudent.phoneNumber << ","
            << newStudent.age << ","
            << newStudent.grade << "\n";

    outFile.close();

    cout << "\nStudent added successfully!\n" << endl;
}
