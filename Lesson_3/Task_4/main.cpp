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

    char asciiArray[strLen];
    for (int i = 0; i < strLen; i++)
        asciiArray[i] = 0;

    for (int i = 0; i < strLen; i++)
        if (str[i] != 0) asciiArray[str[i]]++;

    int arrayToSort[strLen][2];
    for (int i = 0; i < strLen; i++)
        for (int j = 0; j < 2; j++)
            arrayToSort[i][j] = 0;

    int counter = 0;
    for (int i = 0; i < strLen; i++)
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
