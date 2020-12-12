#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string str;
    cin >> str;

    char charArray[str.length() + 1];
    strcpy(charArray, str.c_str());

    int charCounter = 0;
    int wordCounter = 0;

    for (int i = 0; i < str.length() + 1; i++)
    {
        if ((charArray[i] >= 'A' && charArray[i] <= 'Z') || (charArray[i] >= 'a' && charArray[i] <= 'z'))
        {
            charCounter++;
            continue;
        }
        else if (charCounter > 0)
        {
            charCounter = 0;
            wordCounter++;
        }
    }
    cout << wordCounter << endl;
}
