#include <iostream>

using namespace std;

int main()
{
    int numbers[5];
    int maxNumber = 0;
    for (int i = 0; i < 5; i++)
    {
        cout << "Stars in " << i + 1 << " column: ";
        cin >> numbers[i];
        if (numbers[i] > maxNumber) maxNumber = numbers[i];
    }

    for (int i = 0; i < maxNumber; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int num = numbers[i];
            if (num > 0)
            {
                cout << "*";
                num--;
            }
            else cout << " ";
        }
        cout << endl;
    }
}
