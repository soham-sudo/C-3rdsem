// 002210501077
//  1. Write a function swap (a, b) to interchange the values of two variables. Do not
//  use pointers.
#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 5, b = 7;
    swap(a, b);
    cout << a << " " << b << endl;
}
