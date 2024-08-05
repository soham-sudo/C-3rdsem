#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
    int roll;
    string name;
    double score;

    // Constructor
    Student(int r, const std::string &n, double s) : roll(r), name(n), score(s) {}

    // Overloading << operator for easy printing
    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "Roll: " << student.roll << ", Name: " << student.name << ", Score: " << student.score;
        return os;
    }

    bool check_sub(string sub) {
        bool isFound = name.find(sub) != string::npos;

        // verifying the result
        if (isFound) {
            // printing success message if found
            cout << "Substring Found in name of roll" << roll << endl;
        } else {
            // else printing the error message
            cout << "Substring not Found in roll " << roll << endl;
        }
        return isFound;
    }

    double get_score() const {
        return score;
    }
};

class StudentArray {
private:
    vector<Student> students;

public:
    // Function to add a student to the array
    void addStudent(const Student &student) {
        students.push_back(student);
    }

    // Overloading [] operator for random access
    Student &operator[](int index) {
        return students[index];
    }

    // Function to get the size of the array
    int size() const {
        return students.size();
    }

   static bool compare(const Student &s1, const Student &s2) {
        return s1.get_score() < s2.get_score();
    }

    // Function to find the student with the highest score
    Student getHighestScoreStudent() {
        return *max_element(students.begin(), students.end(), compare);
    }

    // Function to find students with a substring in their name
    void getStudentsWithNameSubstring(const string &substring) {
        for ( auto student : students) {
            student.check_sub(substring);
        }
    }

    // Function to find a student by roll number
    Student getStudentByRoll(int roll) const {
        auto it = std::find_if(students.begin(), students.end(),
                               [roll](const Student &student) {
                                   return student.roll == roll;
                               });

        if (it != students.end()) {
            return *it;
        } else {
            // Return a default-constructed Student if not found
            return Student(-1, "Not Found", 0.0);
        }
    }
};

int main() {
    // Create an instance of StudentArray
    StudentArray studentArray;

    // Add some students
    studentArray.addStudent(Student(1, "John Doe", 85.5));
    studentArray.addStudent(Student(2, "Jane Smith", 92.0));
    studentArray.addStudent(Student(3, "Bob Johnson", 78.5));

    // Access students randomly
    cout << "Random access: " << studentArray[1] << std::endl;

    // Get the number of students
    cout << "Number of students: " << studentArray.size() << std::endl;

    // Find the student with the highest score in descending order
    cout << "Student with highest score (descending): " << studentArray.getHighestScoreStudent() << std::endl;

    // Find students with a substring in their name
    cout << "Students with 'Doe' in their name:" << std::endl;
    studentArray.getStudentsWithNameSubstring("Doe");

    // Find students without a substring in their name
    cout << "Students without 'Smith' in their name:" << std::endl;
    studentArray.getStudentsWithNameSubstring("Smith");

    // Find a student by roll number
    cout << "Student with roll number 2: " << studentArray.getStudentByRoll(2) << std::endl;
    cout << "Student with roll number 4: " << studentArray.getStudentByRoll(4) << std::endl;

    return 0;
}
