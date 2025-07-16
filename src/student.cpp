#include <iostream> // for input/output operations
#include "student.h" // for Student class
#include <fstream> // for file operations
#include <sstream> // for stringstream
#include <string> // for string operations
#include <cstdio> // for remove and rename functions

using namespace std;

// Implementation of the displayStudent method
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

// Function to add a new student
void addStudent() {
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

//Delete a student by ID
void deleteStudent() {
    string targetID;
    cout << "\n--- Delete Student ---\n";
    cout << "Enter Student ID to delete: ";
    cin >> targetID;

    ifstream inFile("students.txt");
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile) {
        cerr << "Error opening files!\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string id;
        getline(ss, id, ',');

        if (id != targetID) {
            tempFile << line << "\n";
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    // Replace original file if student was found
    if (found) {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        cout << "Student with ID " << targetID << " deleted successfully.\n";
    } else {
        remove("temp.txt"); // clean up
        cout << "Student with ID " << targetID << " not found.\n";
    }
}
