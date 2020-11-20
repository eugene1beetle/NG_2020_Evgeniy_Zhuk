#include <iostream>

using namespace std;

int main()
{
    int schools[10];
    int yourSchool = 0;

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter some numbers of schools: ";
        cin >> schools[i];
    }

    cout << "Enter the number of your school: ";
    cin >> yourSchool;

    for (int i = 0; i < 10; i++)
    {
        if (schools[i] == yourSchool)
        {
            cout << "I know that school!" << endl;
            return 0;
        }
    }

    cout << "I don't know that school" << endl;
}
