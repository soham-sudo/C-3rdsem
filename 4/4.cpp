#include<iostream>
#include<string.h>
using namespace std;
class STRING{
    int size;
    char* str;
    public:
    //constructor 
    STRING(char*p=NULL){
        if(p!=NULL){
            size = strlen(p);
            str = new char[size+1];
            strcpy(str,p);
        }
    }
    //copy constructor
    STRING(const STRING &);

    //checks if same string or not
    bool operator!=(const STRING &s);

    //adds two string, takes total size of left invoking object and right operand and copies both in new string
    STRING operator+(const STRING &s)const;

    // > operator overloading returns 1 if true 0 if false compares lexographically
    int operator>(const STRING &)const;
    // < operator overloading returns 1 if true 0 if false compares lexographically
    int operator<(const STRING &)const;

    //overloading for cout operator
    ostream& operator<< (ostream& ,STRING s);
};