#include <iostream>

using namespace std;

int main()
{
    int a = 0, b = 0, action = 0, result = 0;

    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    cout << "1 - adding" << endl;
    cout << "2 - subtraction" << endl;
    cout << "3 - multiplication" << endl;
    cout << "4 - division" << endl;
    cout << "Choose an action: ";
    cin >> action;

    if (action == 1) result = a + b;
    if (action == 2) result = a - b;
    if (action == 3) result = a * b;
    if (action == 4) result = a / b;

    cout << "Result = " << result;
}
