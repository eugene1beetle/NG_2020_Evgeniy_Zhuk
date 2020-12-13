#include <iostream>

using namespace std;

int main()
{
    int strLen = 256;
    char str[strLen];

    for (int i = 0; i < strLen; i++) str[i] = 0;

    cin.getline(str, strLen);

    int charCounter = 0;
    int maxCharLenght = 0;
    int wordStart = 0;
    int longestWordStart = 0;

    for (int i = 0; i < strLen; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            charCounter++;
            if (charCounter == 1)
            {
                wordStart = i;
            }
        }
        else if (charCounter > 0)
        {
            if (maxCharLenght < i - wordStart)
            {
                maxCharLenght = i - wordStart;
                longestWordStart = wordStart;
            }
            charCounter = 0;
        }
    }

    cout << "Longest word: ";
    for (int i = longestWordStart; i < maxCharLenght + longestWordStart; i++)
    {
        cout << str[i];
    }
    cout << endl;
}
