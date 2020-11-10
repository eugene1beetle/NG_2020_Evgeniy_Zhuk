#include <iostream>

using namespace std;

int main()
{
    int salary = 0;

    cout << "Enter your salary: ";
    cin >> salary;
    if (salary < 1000) cout << "You need to work more!";
    else if (salary < 1000000) cout << "You have nice salary!";
    else cout << "You're millioner!";
}
