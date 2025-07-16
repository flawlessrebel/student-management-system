#include <iostream>
#include "../include/student.h"
#include "../include/utils.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "\n--- Student Management System ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Edit Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
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
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
