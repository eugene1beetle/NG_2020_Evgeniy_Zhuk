#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string s;
    cout << "Enter string: "; // asdw4qwerty4zxc
    cin >> s;

    char charArray[s.length() + 1];
    strcpy(charArray, s.c_str());

    int charCounter = 0;
    int maxCharLenght = 0;
    int wordStart = 0;
    int longestWordStart = 0;

    for (int i = 0; i < s.length() + 1; i++)
    {
        if ((charArray[i] >= 'A' && charArray[i] <= 'Z') || (charArray[i] >= 'a' && charArray[i] <= 'z'))
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
        cout << charArray[i];
    }
    cout << endl;
}
