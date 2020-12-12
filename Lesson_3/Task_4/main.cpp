#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    int strLenght = s.length();
    char charArray[strLenght];
    strcpy(charArray, s.c_str());

    char asciiArray[256];
    for (int i = 0; i < 256; i++)
        asciiArray[i] = 0;

    for (int i = 0; i < strLenght; i++)
        asciiArray[charArray[i]]++;

    int arrayToSort[256][2];
    for (int i = 0; i < 256; i++)
        for (int j = 0; j < 2; j++)
            arrayToSort[i][j] = 0;

    int counter = 0;
    for (int i = 0; i < 256; i++)
        if ((int) asciiArray[i] != 0)
        {
            arrayToSort[counter][0] = (int) asciiArray[i];
            arrayToSort[counter][1] = i;
            counter++;
        }

    for (int i = 0; i < counter - 1; i++)
        for (int j = 0; j < counter - i - 1; j++)
            if (arrayToSort[j + 1][0] > arrayToSort[j][0])
            {
                int tmp0 = arrayToSort[j][0];
                int tmp1 = arrayToSort[j][1];

                arrayToSort[j][0] = arrayToSort[j + 1][0];
                arrayToSort[j][1] = arrayToSort[j + 1][1];

                arrayToSort[j + 1][0] = tmp0;
                arrayToSort[j + 1][1] = tmp1;
            }

    for (int i = 0; i < counter; i++)
          cout << (char) arrayToSort[i][1] << " - " << arrayToSort[i][0] << endl;
}
