#include <iostream>

using namespace std;

int main()
{
    int nutsNeed = 0, coneCollect = 0, nutsInCone = 0;

    cout << "Squirrel needs some nuts to survive a winter." << endl;
    cout << "How many nuts do she need?: ";
    cin >> nutsNeed;
    cout << "How many nuts in one cone?: ";
    cin >> nutsInCone;
    cout << "How many cone do squirrel collect?: ";
    cin >> coneCollect;

    if (nutsNeed < coneCollect * nutsInCone) cout << "YES, She'll survive";
    else cout << "NO, She needs more nuts to survive";
}
