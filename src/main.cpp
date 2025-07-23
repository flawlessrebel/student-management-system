#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../include/student.h"
#include "../include/utils.h"

using namespace std;

int main() {
    vector<Student> studentList;

    // Load existing students from file
    ifstream file("students.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string idStr, ageStr;
            Student s;

            getline(ss, idStr, ',');
            getline(ss, s.name, ',');
            getline(ss, s.gender, ',');
            getline(ss, s.email, ',');
            getline(ss, s.dob, ',');
            getline(ss, s.phoneNumber, ',');
            getline(ss, ageStr, ',');
            getline(ss, s.grade, ',');

            s.id = stoi(idStr);
            s.age = stoi(ageStr);

            studentList.push_back(s);
        }
        file.close();
    }


    int choice;

    do {
        cout << "\n--- Student Management System ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Edit Student" << endl;
        cout << "4. Search Student" << endl;
        cout << "5. View Students" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 5.";
            continue;
        }

        cin.ignore();

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                editStudent();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                viewStudent(studentList);
                break;
            case 6:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
