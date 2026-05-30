#include <bits/stdc++.h>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string branch;
    float cgpa;
};

// File name
const string FILE_NAME = "students.txt";

// Save all students to file
void saveToFile(vector<Student>& students) {
    ofstream file(FILE_NAME);
    for (auto& s : students) {
        file << s.id << "\n" << s.name << "\n" << s.age << "\n" << s.branch << "\n" << s.cgpa << "\n";
    }
    file.close();
}

// Load students from file
vector<Student> loadFromFile() {
    vector<Student> students;
    ifstream file(FILE_NAME);
    if (!file) return students;

    Student s;
    while (file >> s.id) {
        file.ignore();
        getline(file, s.name);
        file >> s.age;
        file.ignore();
        getline(file, s.branch);
        file >> s.cgpa;
        file.ignore();
        students.push_back(s);
    }
    file.close();
    return students;
}

// Add student
void addStudent(vector<Student>& students) {
    Student s;
    cout << "\n--- Add Student ---\n";
    cout << "Enter ID: "; cin >> s.id;
    cin.ignore();

    // Check duplicate ID
    for (auto& st : students) {
        if (st.id == s.id) {
            cout << "ID already exists!\n";
            return;
        }
    }

    cout << "Enter Name: "; getline(cin, s.name);
    cout << "Enter Age: "; cin >> s.age;
    cin.ignore();
    cout << "Enter Branch: "; getline(cin, s.branch);
    cout << "Enter CGPA: "; cin >> s.cgpa;

    students.push_back(s);
    saveToFile(students);
    cout << "Student added successfully!\n";
}

// Display all students
void displayAll(vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo students found!\n";
        return;
    }
    cout << "\n--- All Students ---\n";
    cout << left << setw(6) << "ID" << setw(20) << "Name" << setw(6) << "Age" << setw(15) << "Branch" << "CGPA\n";
    cout << string(55, '-') << "\n";
    for (auto& s : students) {
        cout << left << setw(6) << s.id << setw(20) << s.name << setw(6) << s.age << setw(15) << s.branch << s.cgpa << "\n";
    }
}

// Search student by ID
void searchStudent(vector<Student>& students) {
    int id;
    cout << "\nEnter Student ID to search: "; cin >> id;
    for (auto& s : students) {
        if (s.id == id) {
            cout << "\n--- Student Found ---\n";
            cout << "ID     : " << s.id << "\n";
            cout << "Name   : " << s.name << "\n";
            cout << "Age    : " << s.age << "\n";
            cout << "Branch : " << s.branch << "\n";
            cout << "CGPA   : " << s.cgpa << "\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

// Update student
void updateStudent(vector<Student>& students) {
    int id;
    cout << "\nEnter Student ID to update: "; cin >> id;
    for (auto& s : students) {
        if (s.id == id) {
            cin.ignore();
            cout << "Enter New Name: "; getline(cin, s.name);
            cout << "Enter New Age: "; cin >> s.age;
            cin.ignore();
            cout << "Enter New Branch: "; getline(cin, s.branch);
            cout << "Enter New CGPA: "; cin >> s.cgpa;
            saveToFile(students);
            cout << "Student updated successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

// Delete student
void deleteStudent(vector<Student>& students) {
    int id;
    cout << "\nEnter Student ID to delete: "; cin >> id;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            saveToFile(students);
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

int main() {
    vector<Student> students = loadFromFile();
    int choice;

    cout << "========================================\n";
    cout << "     STUDENT MANAGEMENT SYSTEM\n";
    cout << "========================================\n";

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: "; cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: displayAll(students); break;
            case 3: searchStudent(students); break;
            case 4: updateStudent(students); break;
            case 5: deleteStudent(students); break;
            case 6:
                cout << "Exiting... Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
