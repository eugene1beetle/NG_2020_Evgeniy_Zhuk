#include <iostream>

using namespace std;

int main()
{
    int numbers[20];
    int maxNumber = 0;

    for (int i = 0; i < 20; i++)
    {
        cout << "Enter number: ";
        cin >> numbers[i];
        if (numbers[i] > maxNumber) maxNumber = numbers[i];
        if (numbers[i] == 0) break;
    }

    for (int i = 0; i < 20 && numbers[i] != 0; i++)
    {
        for (int j = 0; j < (maxNumber / 2 + 1) - (numbers[i] / 2 + 1); j++)
            cout << " ";

        for (int j = 0; j < numbers[i]; j++)
            cout << "*";

        cout << endl;
    }

}
