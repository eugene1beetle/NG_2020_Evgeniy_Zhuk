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

    for (int i = 0; i < s.length() + 1; i++)
    {
        if (charArray[i] >= 'a' && charArray[i] <= 'z')
        {
            charArray[i] -= 32;
        }
    }

    cout << "Result: ";
    for (int i = 0; i < s.length() + 1; i++)
    {
        cout << charArray[i];
    }

    cout << endl;
}
