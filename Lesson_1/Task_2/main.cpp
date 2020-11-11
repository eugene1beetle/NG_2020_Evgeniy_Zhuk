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

    switch (action)
    {
        case 1:
            result = a + b;
            break;
        case 2:
            result = a - b;
            break;
        case 3:
            result = a * b;
            break;
        case 4:
            result = a / b;
            break;
        default:
            cout << "You peek a wrong operation!" << endl;
    }

    if (action > 0)
    {
        if (action < 5)
        {
            cout << "Result = " << result;
        }
    }

}
