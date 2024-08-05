#include <iostream>
#include<string.h>
using namespace std;

class applicant
{
    //private data members
    static int last_id;
    int id;
    char *name;
    float score;

public:
    // default constructor
    applicant();
    // constructor with name , float as parametes
    applicant(char *, float);
    //to getdata using member function
    void getdata();
    //to showdata using member function
    void showdata();
    //to show number of applicants
    static int total_applicants();
    //destructor to delete dynamically space for name
    ~applicant();
};

int applicant:: last_id=0;
//in definition no need to again write static keyword
int  applicant:: total_applicants(){
    return last_id;
}
applicant::applicant()
{
    id = 0;
    name = NULL;
    score = 0;
}
applicant::applicant(char * s, float n){
    id=last_id+1;
    name= new char[strlen(s)+1];
    strcpy(name,s);
    score=n;
}

applicant:: ~applicant(){
    delete []name;
}

int main(){
    applicant a1;
    a1.getdata();
    cout<< applicant::total_applicants();
}