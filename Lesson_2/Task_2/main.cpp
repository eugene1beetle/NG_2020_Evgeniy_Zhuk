#include <iostream>

using namespace std;

int main()
{
    int cards[10];

    for (int i = 0; i < 10; i++)
        cards[i] = 0;

    while (true)
    {
        int numberOfCard = 5, moneyToAdd = 0, sumOnCards = 0;
        do
        {
            cout << "Enter the number of a card (0-9): ";
            cin >> numberOfCard;
        } while (!(numberOfCard >= 0 && numberOfCard <= 9));
        cout << "How much money you want to add: ";
        cin >> moneyToAdd;
        cards[numberOfCard] += moneyToAdd;

        for (int i = 0; i < 10; i++)
        {
            cout << cards[i] << " ";
            sumOnCards += cards[i];
        }

        cout << endl << "Money on all cards is " << sumOnCards << endl;
    }
}
