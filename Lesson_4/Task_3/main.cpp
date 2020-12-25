#include <iostream>

using namespace std;

void getUserImput(char str[], int strLen)
{
    cout << "Enter string: ";
    for (int i = 0; i < strLen; i++)
        str[i] = 0;
    cin.getline(str, strLen);
}

void countWord(char str[], int strLen, int pos, int data[])
{
    if (pos < strLen)
    {
        if ((str[pos] >= 'A' && str[pos] <= 'Z') || (str[pos] >= 'a' && str[pos] <= 'z'))
        {
            data[0]++;
            countWord(str, strLen, pos + 1, data);
            return;
        }
        else if (data[0] > 0)
        {
            data[1]++;
            data[0] = 0;
            countWord(str, strLen, pos + 1, data);
            return;
        }
        if (!((str[pos] >= 'A' && str[pos] <= 'Z') || (str[pos] >= 'a' && str[pos] <= 'z')))
            countWord(str, strLen, pos + 1, data);
    }
}

int main()
{
    int strLen = 256;
    char str[strLen];
    getUserImput(str, strLen);

    int data[] = {0, 0}; // data0 - char counter, data1 - word counter

    countWord(str, strLen, 0, data);
    cout << data[1] << endl;
}
