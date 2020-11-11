#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    cout << "Enter some number for painting: ";
    cin >> number;

    for (int i = number; i > 0; i--)
    {
        for (int j = number; j > 0; j--)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < number + 1; i++)
    {
        for (int j = i; j > 0; j--)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < number + 1; i++) // ocey
    {
        for (int j = number - i; j > 0; j--)
        {
            cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = number; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < number + 1; i++)
    {
        for (int j = i; j > 0; j--)
        {
            cout << " ";
        }
        for (int j = number - i; j > 0; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}
