#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int strLen = 256;
    char str[strLen];

    for (int i = 0; i < strLen; i++) str[i] = 0;

    cin.getline(str, strLen);

    int charCounter = 0;
    int wordCounter = 0;

    for (int i = 0; i < strLen; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
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
