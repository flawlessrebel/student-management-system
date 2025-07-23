#include <iostream> // for input/output operations
#include "../include/student.h" // for Student class
#include "../include/utils.h" // for utility functions
#include <fstream> // for file operations
#include <sstream> // for stringstream
#include <string> // for string operations
#include <cstdio> // for remove and rename functions
#include <vector> // for using vectors

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

// function to delete student by ID
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

// Function to edit a student's details
void editStudent() {
    string targetID;
    cout << "\n--- Edit Student ---\n";
    cout << "Enter Student ID to edit: ";
    cin >> targetID;
    cin.ignore();

    ifstream infile("students.txt");
    ofstream tempFile("temp.txt");

    if (!infile || !tempFile) {
        cerr << "Error opening files!\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(infile, line)) {
        stringstream ss(line);
        string id, name, gender, email, dob, phoneNumber, ageStr, grade;
        int age;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, gender, ',');
        getline(ss, email, ',');
        getline(ss, dob, ',');
        getline(ss, phoneNumber, ',');
        getline(ss, ageStr, ',');
        getline(ss, grade, ',');

        age = stoi(ageStr);

        if (id == targetID) {
            found = true;
            cout << "\nEditing student: " << name << endl;

            string input;

            cout << "Enter new Name (or press Enter to keep current): ";
            getline(cin, input);
            if (!input.empty()) name = input;

            cout << "Enter new Gender (or press Enter to keep current): ";
            getline(cin, input);
            if (!input.empty()) gender = input;

            cout << "Enter new Email (or press Enter to keep current): ";
            getline(cin, input);
            if (!input.empty()) email = input;

            cout << "Enter new DOB (or press Enter to keep current): ";
            getline(cin, input);
            if (!input.empty()) dob = input;

            cout << "Enter new Phone Number (or press Enter to keep current): ";
            getline(cin, input);
            if (!input.empty()) phoneNumber = input;

            cout << "Enter new Age (or press Enter to keep current): ";
            getline(cin, input);
            if (!input.empty()) age = stoi(input);

            cout << "Enter new Grade (or press Enter to keep current): ";
            getline(cin, input);
            if (!input.empty()) grade = input;

            // Write updated student info
            tempFile << id << "," << name << "," << gender << ","
                    << email << "," << dob << "," << phoneNumber << ","
                    << age << "," << grade << "\n";
        } else {
            // Copy unchanged student line
            tempFile << line << "\n";
        }
    }

    infile.close();
    tempFile.close();

    if (found) {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        cout << "Student with ID " << targetID << " edited successfully.\n";
    } else {
        remove("temp.txt");
        cout << "Student with ID " << targetID << " not found.\n";
    }
}

// Function to search for a student by ID
void searchStudent() {
    ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "Unable to open student records." << endl;
        return;
    }

    cout << "Search by:\n1. Student ID\n2. Student Name\nEnter your choice: ";
    int choice;
    cin >> choice;
    cin.ignore();

    string query;
    cout << "Enter search value: ";
    getline(cin, query);

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, gender, email, dob, phoneNumber, age, grade;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, gender, ',');
        getline(ss, email, ',');
        getline(ss, dob, ',');
        getline(ss, phoneNumber, ',');
        getline(ss, age, ',');
        getline(ss, grade, ',');

        if ((choice == 1 && id == query) || 
            (choice == 2 && name == query)) {
            cout << "\n--- Student Found ---" << endl;
            cout << "ID: " << id 
                << "\nName: " << name 
                << "\nGender: " << gender
                << "\nEmail: " << email
                << "\nDOB: " << dob
                << "\nPhone Number: " << phoneNumber
                << "\nAge: " << age
                << "\nGrade: " << grade << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No matching student found." << endl;
    }

    file.close();
}

// Function to view all students
void viewStudent(const std::vector<Student>& student) {
    if (student.empty()) {
        std::cout << "\nNo students available in the system.\n";
        return;
    }

    std::cout << "\n--- List of All Students ---\n";
    for (const auto& student : student) {
        student.displayStudent();
        std::cout << "----------------------------\n";
}
}
