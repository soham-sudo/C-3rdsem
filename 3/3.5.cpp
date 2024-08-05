// Define functions f(int, int) and f (char, int). Call the functions with arguments of
// type (int, char), (char,char) and (float, float).

#include<iostream>
using namespace std;

int f(int i,int j){
    return 1;
}

int f(char a,int i){
    return 2;
}
int main(){
    int i=0;
    //1(int,char),2(char,char),3(float,float)
    do{
        cin>>i;
        switch(i){
            case 1: cout<<f(1,'a')<<endl;break;
            case 2: cout<<f('b','a')<<endl;break;
            case 3: cout<<f(1.01,1.002)<<endl;break;
        }
    }while(i>=1 && i<=3);
}