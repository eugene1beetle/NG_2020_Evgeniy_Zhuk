#include <iostream>

using namespace std;

void fillArrWith0(char arr[], int len)
{
    for (int i = 0; i < len; i++)
        arr[i] = 0;
}

void fillArrWith0(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        arr[i] = 0;
}

int main()
{
    int strLen = 256;
    char str[strLen];
    cout << "Enter string: ";
    fillArrWith0(str, strLen);
    cin.getline(str, strLen);

    char asciiArray[strLen];
    fillArrWith0(asciiArray, strLen);

    for (int i = 0; i < strLen; i++)
        if (str[i] != 0) asciiArray[str[i]]++;

    int vals[strLen];
    int freq[strLen];
    fillArrWith0(vals, strLen);
    fillArrWith0(freq, strLen);

    int counter = 0;
    for (int i = 0; i < strLen; i++)
        if ((int) asciiArray[i] != 0)
        {
            freq[counter] = (int) asciiArray[i];
            vals[counter] = i;
            counter++;
        }

    for (int i = 0; i < counter - 1; i++)
        for (int j = 0; j < counter - i - 1; j++)
            if (freq[j + 1] > freq[j])
            {
                int tmp0 = freq[j];
                int tmp1 = vals[j];

                freq[j] = freq[j + 1];
                vals[j] = vals[j + 1];

                freq[j + 1] = tmp0;
                vals[j + 1] = tmp1;
            }

    for (int i = 0; i < counter; i++)
          cout << (char) vals[i] << " - " << freq[i] << endl;
}
