#include <iostream>

using namespace std;

void getUserImput(char str[], int strLen)
{
    cout << "Enter string: ";
    for (int i = 0; i < strLen; i++)
        str[i] = 0;
    cin.getline(str, strLen);
}

int countWord(char str[], int strLen, int pos, int charCounter, int wordCounter)
{
    if (pos < strLen)
    {
        if ((str[pos] >= 'A' && str[pos] <= 'Z') || (str[pos] >= 'a' && str[pos] <= 'z'))
        {
            charCounter++;
            return 0 + countWord(str, strLen, pos + 1, charCounter, wordCounter);
        }
        else if (charCounter > 0)
        {
            wordCounter++;
            charCounter = 0;
            return 1 + countWord(str, strLen, pos + 1, charCounter, wordCounter);
        }
        if (!((str[pos] >= 'A' && str[pos] <= 'Z') || (str[pos] >= 'a' && str[pos] <= 'z')))
            return 0 + countWord(str, strLen, pos + 1, charCounter, wordCounter);
    }
}

int main()
{
    int len = 256;
    char str[len];
    getUserImput(str, len);
    cout << countWord(str, len, 0, 0, 0) - len << endl;
}
