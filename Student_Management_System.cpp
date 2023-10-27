#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    int studentID;
    std::string name;
    int age;
    double grade;

    Student(int studentID, std::string name, int age, double grade) {
        this->studentID = studentID;
        this->name = name;
        this->age = age;
        this->grade = grade;
    }
};

class StudentManagementSystem {
// private:
//     std::vector<Student> students;

public:
std::vector<Student> students;
    void addStudent(Student student) {
        if (student.age <= 0) {
            std::cout << "Error: Age should be a positive integer." << std::endl;
            return;
        }
        if (student.grade < 0.0 || student.grade > 4.0) {
            std::cout << "Error: Grade should be between 0.0 and 4.0." << std::endl;
            return;
        }

        for (const auto& s : students) {
            if (s.studentID == student.studentID) {
                std::cout << "Error: Student ID already exists. Please use a different ID." << std::endl;
                return;
            }
        }
        students.push_back(student);
    }

    void getStudent(int studentID) {
        for (const auto& student : students) {
            if (student.studentID == studentID) {
                std::cout << "Student ID: " << student.studentID << ", Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade << std::endl;
                return;
            }
        }
        std::cout << "Student not found." << std::endl;
    }

    void listAllStudents() {
        for (const auto& student : students) {
            std::cout << "Student ID: " << student.studentID << ", Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade << std::endl;
        }
    }
};

int main() {
    StudentManagementSystem sms;

    while (true) {
        std::cout << "\n1. Add a new student" << std::endl;
        std::cout << "2. View a student's information" << std::endl;
        std::cout << "3. List all students" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int studentID;
            std::string name;
            int age;
            double grade;

            std::cout << "Enter student ID: ";
            std::cin >> studentID;

            // Check for unique student ID
            bool isUnique = true;
            for (const auto& student : sms.students) {
                if (student.studentID == studentID) {
                    isUnique = false;
                    break;
                }
            }

            if (!isUnique) {
                std::cout << "Error: Student ID already exists. Please use a different ID." << std::endl;
                continue;
            }

            std::cout << "Enter student name: ";
            std::cin >> name;
            std::cout << "Enter student age: ";
            std::cin >> age;
            std::cout << "Enter student grade: ";
            std::cin >> grade;

            Student student(studentID, name, age, grade);
            sms.addStudent(student);
        } else if (choice == 2) {
            int studentID;
            std::cout << "Enter student ID: ";
            std::cin >> studentID;
            sms.getStudent(studentID);
        } else if (choice == 3) {
            sms.listAllStudents();
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
