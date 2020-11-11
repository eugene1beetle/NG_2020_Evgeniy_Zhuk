#include <iostream>

using namespace std;

int main()
{
    int threeSize = 0, counter = 1;
    cout << "Enter christmas three size: ";
    cin >> threeSize;
    cout << endl;
    for (int i = threeSize; i > 0; i--)
    {
        for (int j = i - 1; j > 0; j--)
        {
            cout << " ";
        }
        for (int j = counter; j > 0; j--)
        {
            cout << "*";
        }
        counter += 2;
        cout << endl;
    }

    for (int i = 0; i < threeSize - 1; i++)
    {
        cout << " ";
    }
    cout << "*" << endl;
}
