#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
public:
    int id;
    std::string name;
    std::string gender;
    std::string email;
    std::string dob;
    std::string phoneNumber;
    int age;
    std::string grade;

    void displayStudent() const;
};

void addStudent();

void deleteStudent();

void editStudent();

void searchStudent();

void deleteStudent(const std::vector<Student>& students);

#endif
