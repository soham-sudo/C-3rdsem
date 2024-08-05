// 002210501077
//  3. Write a function that will have income and tax rate as arguments and will return
//  tax amount. In case tax rate is not provided it will be automatically taken as 10%.
//  Call it with and without tax rate.
#include <iostream>
using namespace std;
float tax_amt(float income, float tax = 10.0)
{
    float amt = income * tax * 0.01;
    return amt;
}

int main()
{
    float income1 = 10000, r1, r2;
    r1 = tax_amt(income1, 12.6);
    r2 = tax_amt(income1);
    cout << r1 << " " << r2 << " " << endl;
}