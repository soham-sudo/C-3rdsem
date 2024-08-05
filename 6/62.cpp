#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    int roll;
    string name;
    double score;

    void input() {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Score: ";
        cin >> score;
    }

    void display() {
        cout << "Roll Number: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Score: " << score << endl;
    }
};

class StudentArray {
private:
    int maxSize;
    Student *students;

public:
    StudentArray(int size) {
        maxSize = size;
        students = new Student[maxSize];
    }

    ~StudentArray() {
        delete[] students;
    }

    void collectData() {
        for (int i = 0; i < maxSize; i++) {
            cout << "Enter data for Student " << i + 1 << ":" << endl;
            students[i].input();
        }
    }
    Student& operator[](int i)
    {
        if(i<0 || i > maxSize)
        {
            throw i;
        }
        else
        {
            return students[i];
        }
    }


    void displayData() {
        for (int i = 0; i < maxSize; i++) {
            cout << "Data for Student " << i + 1 << ":" << endl;
            students[i].display();
            cout << endl;
        }
    }
};

int main() {
    int maxArraySize;
    
    cout << "Enter the maximum number of students: ";
    cin >> maxArraySize;

    StudentArray studentArray(maxArraySize);

    studentArray.collectData();
    cout << "Data for all students:" << endl;
    studentArray.displayData();

    return 0;
}
