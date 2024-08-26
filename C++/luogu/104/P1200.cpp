#include <iostream>
#include <string>
using namespace std;
int main()
{
    string Star, Team;
    cin >> Star >> Team;
    int numStar = 1, numTeam = 1;
    for (auto c : Star)
        numStar *= (c - 'A' + 1);
    for (auto c : Team)
        numTeam *= (c - 'A' + 1);
    if (numStar % 47 == numTeam % 47)
        cout << "GO";
    else
        cout << "STAY";
    return 0;
}