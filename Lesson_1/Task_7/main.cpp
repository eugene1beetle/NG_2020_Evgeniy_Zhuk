#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    cout << "Enter the number for counting: ";
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        cout << i << ",";
    }
    cout << number << endl;
}
