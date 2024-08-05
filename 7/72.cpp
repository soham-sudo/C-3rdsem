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
    Student(int r, const string &n, double s) : roll(r), name(n), score(s) {}

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
    friend bool operator==(Student& s1 , int r);
};
bool operator==(Student& s1 , int r)
{
    return s1.roll == r;

}
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
    void rem(int r)
    {
        remove(students.begin(),students.end(),r);
    }
    static bool com(Student& s1,Student& s2)
    {
        return(s1.get_score()>s2.get_score());
    }
    void sort_des()
    {
        sort(students.begin(),students.end(),com);
    }
    void combine(StudentArray& obj)
    {
        students.insert(students.end(),obj.students.begin(),obj.students.end());
    }
};

int main() {
    // Create an instance of StudentArray
    StudentArray studentArray1;

    // Add some students to the first array
    studentArray1.addStudent(Student(1, "John Doe", 85.5));
    studentArray1.addStudent(Student(2, "Jane Smith", 92.0));
    studentArray1.addStudent(Student(3, "Bob Johnson", 78.5));

    // Access students randomly
    cout << "Random access: " << studentArray1[1] << std::endl;

    // Get the number of students
    cout << "Number of students in the first array: " << studentArray1.size() << std::endl;

    // Find the student with the highest score in descending order
    cout << "Student with the highest score in the first array (descending): " << studentArray1.getHighestScoreStudent() << std::endl;

    // Find students with a substring in their name
    cout << "Students with 'Doe' in their name:" << std::endl;
    studentArray1.getStudentsWithNameSubstring("Doe");

    // Find students without a substring in their name
    cout << "Students without 'Smith' in their name:" << std::endl;
    studentArray1.getStudentsWithNameSubstring("Smith");

    // Find a student by roll number
    cout << "Student with roll number 2 in the first array: " << studentArray1.getStudentByRoll(2) << std::endl;

    // Create a second instance of StudentArray
    StudentArray studentArray2;

    // Add some students to the second array
    studentArray2.addStudent(Student(4, "Alice Johnson", 88.5));
    studentArray2.addStudent(Student(5, "Charlie Brown", 95.0));

    // Combine the two arrays
    studentArray1.combine(studentArray2);

    // Display the combined array
    cout << "Combined Array: ";
    for (int i = 0; i < studentArray1.size(); ++i) {
        cout << studentArray1[i] << " ";
    }
    cout << std::endl;

    // Remove a student with roll number 3
    studentArray1.rem(3);

    // Display the array after removal
    cout << "Array after removing student with roll number 3: ";
    for (int i = 0; i < studentArray1.size(); ++i) {
        cout << studentArray1[i] << " ";
    }
    cout << std::endl;

    // Sort the array in descending order
    studentArray1.sort_des();

    // Display the array after sorting in descending order
    cout << "Array after sorting in descending order: ";
    for (int i = 0; i < studentArray1.size(); ++i) {
        cout << studentArray1[i] << " ";
    }
    cout << std::endl;

    return 0;
}
