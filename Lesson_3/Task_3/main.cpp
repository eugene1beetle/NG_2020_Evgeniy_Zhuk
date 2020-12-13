#include <iostream>

using namespace std;

int main()
{
    int strLen = 256;
    char str[strLen];
    cout << "Enter string: ";
    for (int i = 0; i < strLen; i++)
        str[i] = 0;
    cin.getline(str, strLen);

    for (int i = 0; i < strLen; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;

    cout << "Result: ";
    for (int i = 0; i < strLen; i++)
        cout << str[i];

    cout << endl;
}
