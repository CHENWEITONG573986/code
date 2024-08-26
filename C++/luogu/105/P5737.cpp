#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isLeapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    else
        return false;
}

int main()
{
    int x, y;
    cin >> x >> y;
    vector<int> V;
    for (int i = x; i <= y; i++)
        if (isLeapYear(i))
            V.push_back(i);
    cout << V.size() << endl;
    for (auto c : V)
        cout << c << " ";
    return 0;
}