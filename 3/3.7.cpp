// Design a class TIME which stores hour, minute and second. The class should have
// the methods to support the following:
// • User may give the time value in 24-hour format.
// • User may give the time value in AM/PM format
// • Display the time in 24-hour format.
// • Display the time in AM/PM format.
// • User may like to add minute with a time value.

#include <iostream>
using namespace std;

class TIME
{
    int second;
    int minute;
    int hour;
    int f = 2;

public:
    void getData_24hr()
    {
        cout << "Input(24hr)(hour minute second): ";
        cin >> hour >> minute >> second;
        minute += second / 60;
        hour += minute / 60;
        hour %= 24;
        minute %= 60;
        second %= 60;
    }
    void getData_AM_PM()
    {
        cout << "Input(AM_PM)(hour minute second format(am(0),pm(1))): ";
        cin >> hour >> minute >> second >> f;
        minute += second / 60;
        hour += minute / 60;
        hour %= 12;
        minute %= 60;
        second %= 60;
    }
    void showData_24hr()
    {
        if (f == 2)
            cout << hour << ":" << minute << ":" << second << endl;
        else if (f == 0)
        {
            cout << hour << ":" << minute << ":" << second << endl;
        }
        else
        {
            cout << (hour + 12) % 24 << ":" << minute << ":" << second << endl;
        }
    }
    void showData_AM_PM()
    {
        if (f == 0)
        {
            cout << hour << ":" << minute << ":" << second << " AM" << endl;
        }
        else if (f == 1)
        {
            cout << hour << ":" << minute << ":" << second << " PM" << endl;
        }
        else
        {
            if (hour >= 12)
            {
                cout << hour - 12 << ":" << minute << ":" << second << " PM" << endl;
            }
            else
            {
                cout << hour << ":" << minute << ":" << second << " AM" << endl;
            }
        }
    }
    void AddMinute(int m)
    {
        minute += m;
        hour += minute / 60;
        minute = minute % 60;
        if (f == 0)
        {
            if (hour % 24 >= 12)
            {
                f = 1;
                hour = hour % 24 - 12;
            }
            else hour%=24;
        }
        else if (f == 1)
        {
            if ((hour) % 24 >= 12)
            {
                f = 0;
                hour = hour % 24 - 12;
            }
            else hour%=24;
        }
        else hour%=24;
    }
};

void getDATA(TIME t[], int n);
void showDATA(TIME t[], int n);
void addMinute(TIME t[], int n);
int main()
{
    int n;
    cout << "Input n: ";
    cin >> n;
    TIME t[n];
    getDATA(t, n);
    showDATA(t, n);
    addMinute(t, n);
    showDATA(t, n);
}

void getDATA(TIME t[], int n)
{
    cout << "GET DATA\n";
    int k;
    for (int i = 0; i < n; i++)
    {
        cout << "1. 24hr_format\n2. AM/PM_format\n";
        cin >> k;
        while (k < 1 || k > 2)
        {
            perror("invalid input,Try again");
            cout << "1. 24hr_format\n2. AM/PM_format\n";
            cin >> k;
        }
        switch (k)
        {
        case 1:
            cout << i + 1 << ". ";
            t[i].getData_24hr();
            break;
        case 2:
            cout << i + 1 << ". ";
            t[i].getData_AM_PM();
            break;
        }
    }
}
void showDATA(TIME t[], int n)
{
    int k;
    cout << "SHOW DATA\n";
    while (1)
    {
        cout << "1. 24hr_format\n2. AM/PM_format\n3. break\n";
        cin >> k;
        while (k < 1 || k > 3)
        {
            perror("invalid input,Try again");
            cout << "1. 24hr_format\n2. AM/PM_format\n3. break\n";
            cin >> k;
        }
        if (k == 3)
            break;
        switch (k)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                cout << i << ". ";
                t[i].showData_24hr();
            }
        case 2:
            for (int i = 0; i < n; i++)
            {
                cout << i << ". ";
                t[i].showData_AM_PM();
            }
        }
    }
}
void addMinute(TIME t[], int n)
{
    int i = 0, m = 0;
    cout << "Input index,minutes(0-" << n - 1 << " m): ";
    cin >> i >> m;
    t[i].AddMinute(m);
}
