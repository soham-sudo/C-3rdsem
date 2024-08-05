// Roll- 002210501077
/*
8. Create a STACK class with operation for initialization, push and pop. Support for
checking underflow and overflow condition are also to be provided.
*/

#include <iostream>
#include<stdlib.h>
using namespace std;

class stack{
    //private data members
    int *arr;
    int size;
    int top;
public:
    //default constructor with size as parameter
    stack(int a=0){
        size=a;
        if(size<0){
            cout<<"Error size cannot be less than 0\n";
            exit(0);
        }
        arr=new int[size];
        top=-1;
    }
    //member function to check overflow
    bool overflow(){
        if(top>size-1)return true;
        else return false;
    }
    //member function to check underflow
    bool underflow(){
        if(top<0)return true;
        else return false;
    }
    //add intger in stack
    void push(int a){
        top++;
        if(!overflow()){
            arr[top]=a;
        }
        else{
            cout<<"overflow\n";
            top--;
        }
    }
    //remove last added element from stack
    int pop(){
        if(!underflow()){
            int retr= arr[top];
            top--;
            return retr;
        }
        else{
            cout<<"underflow\n";
            return 0;
        }
    }
    //destructor to delete dynamically allocated space for stack
    ~stack(){
        delete[] arr;
    }
};

int main(){
    int n;
    cout<<"input for s1: ";
    cin>>n;
    stack s1(n);
    for(int i=0;i<n;i++){
        s1.push(i+1);
    }
    for(;!s1.underflow();){
        cout<<"pop: "<<s1.pop()<<endl;
    }
    //stack s3;
    ///will get created with default value

    //stack s3();
    // s3.push(1);
    // //shows error: request for member 'push' in 's3', which is of non-class type 'stack()' 
    // s3.pop(); //same

    //will show error for -ve initialisation
    //stack s2(-3);


    //overflow
    for(int i=0;i<n+2;i++){
        s1.push(i+1);
    }
    //it only stored numberrs before overflow
    for(;!s1.underflow();){
        cout<<"pop: "<<s1.pop()<<endl;
    }

    //underflow
    s1.pop();
    s1.pop();
    for(int i=0;i<n;i++){
        s1.push(i+1);
    }
    for(;!s1.underflow();){
        cout<<"pop: "<<s1.pop()<<endl;
    }
}