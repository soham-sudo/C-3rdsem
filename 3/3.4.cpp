// Write a function void f(int) that prints “inside f(int)”. Call the function with
// actual argument of type: i) int, ii) char, iii) float and iv) double. Add one more
// function f(float) that prints “inside f(float)”. Repeat the calls again and observe
// the outcomes.
#include<iostream>
using namespace std;
void f(int i){
    cout<<"inside f(int) "<<i;
}
// void f(float i){
//     cout<<"inside f(float) "<<i;
// }
int main()
{
    int i=0;
    f(1);
    cout<<++i<<endl;
    f('a');
    cout<<++i<<endl;
    f(1.01);
    cout<<++i<<endl;
    double j = 1.22222222222221;
    f(j);
    cout<<++i<<endl;
    i=0;
    f(1);
    cout<<++i<<endl;
    f('a');
    cout<<++i<<endl;
    f(1.01);
    cout<<++i<<endl;
    f(j);
    cout<<++i<<endl;
}
