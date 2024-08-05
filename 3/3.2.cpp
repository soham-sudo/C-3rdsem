// 002210501077
//  2. Write a function max (a, b) that will return the reference of larger value. Store the
//  returned information to x where x is a i) variable of type a or b, ii) variable
//  referring to type of a or b. In both the cases modify x. Check also the values of a
//  and b.
#include <iostream>
using namespace std;

int &max(int &a, int &b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int a = 5, b = 6;
    cout << a << " " << b << endl;
    int x1 = max(a, b);
    x1++;
    int &x2 = max(a, b);
    x2++;
    cout << x1 << " " << x2 << " " << endl;
    cout << a << " " << b << endl;
}