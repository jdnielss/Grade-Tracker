#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

struct Student {
    std::string nim;   // NIM (Student Identification Number)
    std::string name;
    double grade;
};

class GradeTracker {
private:
    std::vector<Student> students;

public:
    void addStudent() {
        std::string nim, name;
        double grade;

        // Input NIM with validation
        while (true) {
            std::cout << "Enter student's NIM (max 12 digits): ";
            std::cin >> nim;
            if (nim.length() <= 12 && std::all_of(nim.begin(), nim.end(), ::isdigit)) {
                break;
            }
            std::cout << "Invalid NIM. Ensure it contains only digits and is at most 12 characters long.\n";
        }

        // Input Name
        std::cout << "Enter student's name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
        std::getline(std::cin, name);

        // Input Grade with validation
        std::cout << "Enter student's grade (0-100): ";
        while (!(std::cin >> grade) || grade < 0 || grade > 100) {
            std::cout << "Invalid grade. Please enter a value between 0 and 100: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        students.push_back({nim, name, grade});
        std::cout << "Student added successfully!\n\n";
    }

    void displayStudents() const {
        if (students.empty()) {
            std::cout << "No students in the list.\n";
            return;
        }

        // Display table header
        std::cout << std::left
                  << std::setw(5) << "No."
                  << std::setw(15) << "NIM"
                  << std::setw(25) << "Name"
                  << std::setw(10) << "Grade"
                  << "\n";
        std::cout << std::string(55, '-') << "\n";

        // Display each student's details
        int index = 1;
        for (const auto& student : students) {
            std::cout << std::left
                      << std::setw(5) << index++
                      << std::setw(15) << student.nim
                      << std::setw(25) << student.name
                      << std::setw(10) << student.grade
                      << "\n";
        }

        std::cout << "\n";
    }

    void calculateStatistics() const {
        if (students.empty()) {
            std::cout << "No students to calculate statistics.\n";
            return;
        }

        double total = 0, highest = students[0].grade, lowest = students[0].grade;
        std::string highestName = students[0].name;
        std::string lowestName = students[0].name;

        for (const auto& student : students) {
            total += student.grade;
            if (student.grade > highest) {
                highest = student.grade;
                highestName = student.name;
            }
            if (student.grade < lowest) {
                lowest = student.grade;
                lowestName = student.name;
            }
        }

        double average = total / students.size();

        // Display statistics in a table
        std::cout << std::left
                  << std::setw(25) << "Statistic"
                  << std::setw(10) << "Value"
                  << "\n";
        std::cout << std::string(35, '-') << "\n";

        std::cout << std::left
                  << std::setw(25) << "Average Grade"
                  << std::setw(10) << average
                  << "\n";
        std::cout << std::left
                  << std::setw(25) << "Highest Grade (Name)"
                  << std::setw(10) << highest << " (" << highestName << ")"
                  << "\n";
        std::cout << std::left
                  << std::setw(25) << "Lowest Grade (Name)"
                  << std::setw(10) << lowest << " (" << lowestName << ")"
                  << "\n\n";
    }

    void searchStudent() const {
        if (students.empty()) {
            std::cout << "No students in the list to search.\n";
            return;
        }

        std::cout << "Search by:\n1. NIM\n2. Name\nEnter choice: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string nim;
            std::cout << "Enter NIM: ";
            std::cin >> nim;

            auto it = std::find_if(students.begin(), students.end(),
                                   [&nim](const Student& student) { return student.nim == nim; });

            if (it != students.end()) {
                std::cout << "Student Found:\n";
                std::cout << "NIM: " << it->nim << "\nName: " << it->name << "\nGrade: " << it->grade << "\n";
            } else {
                std::cout << "No student found with NIM: " << nim << "\n";
            }
        } else if (choice == 2) {
            std::string name;
            std::cout << "Enter Name: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            std::getline(std::cin, name);

            auto it = std::find_if(students.begin(), students.end(),
                                   [&name](const Student& student) { return student.name == name; });

            if (it != students.end()) {
                std::cout << "Student Found:\n";
                std::cout << "NIM: " << it->nim << "\nName: " << it->name << "\nGrade: " << it->grade << "\n";
            } else {
                std::cout << "No student found with Name: " << name << "\n";
            }
        } else {
            std::cout << "Invalid choice. Returning to menu.\n";
        }
    }
};

void displayMenu() {
    std::cout << "=== Student Grade Tracker ===\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Display Students\n";
    std::cout << "3. Calculate Statistics\n";
    std::cout << "4. Search Student\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    GradeTracker tracker;
    int choice;

    do {
        displayMenu();
        while (!(std::cin >> choice) || choice < 1 || choice > 5) {
            std::cout << "Invalid choice. Please select a valid option: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                tracker.addStudent();
                break;
            case 2:
                tracker.displayStudents();
                break;
            case 3:
                tracker.calculateStatistics();
                break;
            case 4:
                tracker.searchStudent();
                break;
            case 5:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
