#include <iostream>

using namespace std;

void showMoney(int cards[])
{
    for (int i = 0; i < 10; i++)
        cout << cards[i] << " ";
}

void showAllBalance(int cards[])
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += cards[i];
    cout << endl << "Money on all cards is " << sum << endl;
}

void showMoneyAndSum(int cards[])
{
    showMoney(cards);

    showAllBalance(cards);
}

int getNumber(string s)
{
    int result = 0;
    cout << s;
    cin >> result;
    return result;
}

int getValidNum()
{
    int numberOfCard = 5;
    do numberOfCard = getNumber("Enter the number of a card (0-9): ");
    while (!(numberOfCard >= 0 && numberOfCard <= 9));
    return numberOfCard;
}

void addMoney(int cards[])
{
    cards[getValidNum()] += getNumber("How much money you want to add: ");
}

void startCycle(int cards[])
{
    while (true)
    {
        addMoney(cards);
        showMoneyAndSum(cards);
    }
}

void fillWith0(int array[], int size)
{
    for (int i = 0; i < 10; i++)
        array[i] = 0;
}

int main()
{
    int cards[10];
    fillWith0(cards, 10);
    startCycle(cards);
}

