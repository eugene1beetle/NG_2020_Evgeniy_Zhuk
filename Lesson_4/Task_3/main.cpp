#include <iostream>

using namespace std;

void getUserImput(char str[], int strLen)
{
    cout << "Enter string: ";
    for (int i = 0; i < strLen; i++)
        str[i] = 0;
    cin.getline(str, strLen);
}

int charCounter = 0;
int wordCounter = 0;

void countWord(char str[], int strLen, int pos)
{
    if (pos < strLen)
    {
        if ((str[pos] >= 'A' && str[pos] <= 'Z') || (str[pos] >= 'a' && str[pos] <= 'z'))
        {
            charCounter++;
            countWord(str, strLen, pos + 1);
            return;
        }
        else if (charCounter > 0)
        {
            wordCounter++;
            charCounter = 0;
            countWord(str, strLen, pos + 1);
            return;
        }
        if (!((str[pos] >= 'A' && str[pos] <= 'Z') || (str[pos] >= 'a' && str[pos] <= 'z')))
            countWord(str, strLen, pos + 1);
    }
}

int main()
{
    int len = 256;
    char str[len];
    getUserImput(str, len);
    countWord(str, len, 0);
    cout << wordCounter << endl;
}
