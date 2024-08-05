#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
    int roll;
    string name;
    double score;

    //default Constructor
    Student(int r=0, const string &n=NULL, double s=0);

    // Overloading << operator for  printing
    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "Roll: " << student.roll << ", Name: " << student.name << ", Score: " << student.score;
        return os;
    }

    //will check if substring present in name, returns index, else -1
    int check_substring(string sub) {
        int index = name.find(sub);

        if(index==string::npos)index=-1;

        return index;
        // // verifying the result
        // if (index) {
        //     // printing success message if found
        //     cout << "Substring Found in name of roll" << roll << endl;
        // } else {
        //     // else printing the error message
        //     cout << "Substring not Found in roll " << roll << endl;
        // }
    }

    double get_score() const {
        return score;
    }

    //overloading to remove student with given roll
    bool operator==(Student& s1 , int r)
    {
        return s1.roll == r;
    }
};


class StudentArray {
private:
    vector<Student> list;

public:
    // Function to add a student to the array
    void addStudent(const Student &student) {
        list.push_back(student);
    }

    // Overloading [] operator for random access
    Student &operator[](int index) {
        return list[index];
    }

    // Function to get the size of the array
    int size() const {
        return list.size();
    }

    //to compare using score of 2 elements
    bool compare(const Student &s1, const Student &s2) {
        return s1.get_score() < s2.get_score();
    }

    // Function to find the student with the highest score
    Student getHighestScoreStudent() {
        return *max_element(list.begin(), list.end(), compare);
    }

    // find students in list with a substring in their name
    void check_substring(const string &substring) {
        vector<student>::iterator itr;
        for (itr=list.begin();itr<list.end();itr++) {
            itr.check_substring(substring);
        }
    }

    //overloading == to remove using roll
    bool operator==(int r) const{
        return roll==r;
    }
    void rem(int r)
    {
        remove(list.begin(),list.end(),r);
    }

    //compare function to sort student in descending order
    bool com(Student& s1,Student& s2)
    {
        return(s1.get_score()>s2.get_score());
    }
    void sort_des()
    {
        sort(list.begin(),list.end(),com);
    }

    //to merge to students lists
    void combine(StudentArray& obj)
    {
        list.insert(list.end(),obj.list.begin(),obj.list.end());
    }
};

