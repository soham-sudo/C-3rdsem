//002210501077 
//soham majumdar
// Define a structure student with roll and score as attributes and with two member
// functions to take input and to show the data. Use the member functions to take
// data for a structure variable and to show. Write global function i) to modify score
// and ii) to show the data again.

#include<iostream>
using namespace std;

struct student{
    int roll;
    float score;

    void getData(){
        int s;float r;
        cout<<"Input :(roll score)";
        cin>>r>>s;
        score = s;
        roll = r;
    }
    void showData(){
        cout<<"roll: "<<roll<<" score: "<<score<<endl;
    }
};

void showData(student s){
    cout<<"roll: "<<s.roll<<" score: "<<s.score<<endl;
}

void modifyScore(student &s){
    s.score+=5;
}

int main(){
    student s;
    s.getData();
    s.showData();
    modifyScore(s);
    showData(s);
}