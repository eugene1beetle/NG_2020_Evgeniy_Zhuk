#include <iostream>

using namespace std;

int main()
{
    int salary = 0;

    cout << "Enter your salary: ";
    cin >> salary;

    if (salary < 1000)
    {
        cout << "You need to work more!";
    }

    if (salary > 999)
    {
        if (salary < 1000000)
        {
            cout << "You have a nice salary!";
        }

        if (salary > 999999)
        {
            cout << "You're millioner!";
        }
    }

    cout << "... Good job!";
}
