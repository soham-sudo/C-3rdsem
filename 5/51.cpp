#include <bits/stdc++.h>

#include <iostream>
#include <string>

using namespace std; 

class student
{
private:
    int roll;
    string name;

public:
    student()
    {
        roll = 0;
        name = "";
    }

    student(int rollNumber, const string &studentName)
    {
        roll = rollNumber;
        name = studentName;
    }
    student (student& st)
    {
        roll = st.roll;
        name = st.name;
    }
    void input()
    {
        cin >> roll;
        cin >> name;
    }

    int getRoll() const
    {
        return roll;
    }

    string getName() const
    {
        return name;
    }
};
class studentlist
{
private:
    student list[100];
    int index;
    //int maxsize;

public:
    studentlist()
    {
        //list = nullptr;
        index = 0;
        //maxsize = 0;
    }
    
    int sizeoflist()
    {
        return index;
    }
    bool searchstudent(int r)
    {
        for (int i = 0; i < index; i++)
        {
            if (list[i].getRoll() == r)
            {
                return true;
            }
        }
        return false;
    }
    bool addstudent(student& st)
    {
        st.input();
        if (searchstudent(st.getRoll()) == false)
        {
            list[index] = st;
            index++;
            cout <<"index added successfully\n";
            return true;
        }
        return false;
    }
    student& ret(int i)
    {
        return list[i];
    }
    //~studentlist() {
    //delete[] list;
//}

};

class subject
{
private:
    int subjectCode;
    string name;

public:
    subject()
    {
        subjectCode = 0;
        name = "";
    }
    subject(subject& other)
    {
        subjectCode = other.subjectCode;
        name = other.name;
    }

    subject(int code, const string &subjectName)
    {
        subjectCode = code;
        name = subjectName;
    }
    void input()
    {
        cin >> subjectCode;
        cin >> name;
    }

    int getSubjectCode() const
    {
        return subjectCode;
    }

    string getName() const
    {
        return name;
    }
    void display()
    {
        cout << name << "  " << subjectCode;
    }
};
class subjectlist
{
private:
    subject list[100];
    //int maxsize;
    int index;

public:
    subjectlist()
    {
        //list = nullptr;
        //maxsize = 0;
        index = 0;
    }


    // Constructor with a specified maximum size
    

    // Destructor to free memory
    

    // Function to add a subject only if its code is unique
    bool addSubject(subject& newSubject)
    {
        newSubject.input();
        for (int i = 0; i < index; ++i)
        {
            if (list[i].getSubjectCode() == newSubject.getSubjectCode())
            {
                cout << "Subject with code " << newSubject.getSubjectCode() << " already exists. Cannot add duplicate subject." << endl;
                return false;
            }
        }

        if (index < 100)
        {
            list[index++] = newSubject;
            cout << "Subject added successfully." << endl;
            return true;
        }
        else
        {
            cout << "Subject list is full. Cannot add more subjects." << endl;
            return false;
        }
    }

    // Function to search for a subject by its code
    bool searchSubject(int code)
    {
        for (int i = 0; i < index; ++i)
        {
            if (list[i].getSubjectCode() == code)
            {
                
                cout << "Subject Code: " << list[i].getSubjectCode() << ", Name: " << list[i].getName() << "\n";
                return true;

            }
        }
        cout << "Subject with code " << code << " not found." << endl;
        return false;
    }
    //~subjectlist() {
    //    cout << " ends\n";
    //delete[] list;
//}

};
class selection
{
private:
    student s;
    
    //subject obj;
    subject pool[5];
    int index;

public:
    selection()
    {
        //s = new student[1];
        s = student();
        //ns = 0;
        index = 0;
        //pool = nullptr;
        //obj = subject();
    }
    selection(student& st, int n)
    {
        s = st;
        //obj = subject();
        //ns = n;
        index = 0;
        //pool = new subject[ns];
    }

    int get_roll()
    {
        return s.getRoll();
    }
    void input(subjectlist &ob , student& st)
    {
        s = st;
        //s.roll = st.roll;
        //s.name = st.name;
        //cout << "enter number of subjects you want to choose\n";
        //cin >> ns;
        
        cout << "enter code and name of subjects  \n";
        cout << "enter number of subjects to be selected\n";
        int ns ; cin >> ns ;
        int code;
        string name;
        for (int i = 0; i < ns; i++)
        {
            
            cin >> code;
            cin >> name;
            subject obj(code, name);
            //
            

            if (ob.searchSubject(code) == true)
            {
                pool[index] = obj;
                index++;
                cout << "\nsubject selected\n";
            }
        }
    }
    bool searchsubject(int code)
    {
        for (int i = 0; i < index; i++)
        {
            if (pool[i].getSubjectCode() == code)
            {
                return true;
            }
        }
        return false;
    }

    void display()
    {
        for (int i = 0; i < index; i++)
        {
            pool[i].display();
        }
    }
};
class selectionlist
{
private:
    selection list[100];
    //int maxsize;
    int index;

public:
    selectionlist()
    {
        //list = nullptr;
        //maxsize = 0;
        index = 0;
    }
    
    void input(studentlist& ob, subjectlist& obj)
    {
        for (int i = 0; i < ob.sizeoflist(); i++)
        {
            list[index].input(obj,ob.ret(i));
            index++;
        }
    }
    void output(int roll)
    {
        for (int i = 0; i < index; i++)
        {
            if (list[i].get_roll() == roll)
            {
                list[i].display();
                break;
            }
        }
    }
    void display(int code)
    {
        int count = 0;
        for (int i = 0; i < index; i++)
        {
            if (list[i].searchsubject(code))
            {
                count++;
            }
        }
        cout << "number of students with subject " << code << " = " << count;
    }
};

int main()
{
    //int m1, m2;
        //cout << "enter total number of students and subjects \n";

        //cin >> m1 >> m2;
        subject obj;
        student st;
        
        subjectlist ob2;
        
        cout << "add the subjects \n";
        for (int i = 0; i < 3; i++)
        {
            ob2.addSubject(obj);
        }
        cout << "add the students \n";
        studentlist ob1;

        for (int i = 0; i < 3; i++)
        {
            ob1.addstudent(st);
        }
        selectionlist ob3;
        cout << "enter subjects selected by each student in the same order \n";
        ob3.input(ob1, ob2);
        cout << "enter roll of student whose selection list you want to view \n";
        int r;
        cin >> r;
        ob3.output(r);
        cout << "enter subject code to find how many students have taken it\n";
        int c;
        cin >> c;
        ob3.display(c);
        cout << "END\n";
        return 0;
    }

