#include <iostream>
using namespace std;
int main()
{
    int x, y = 0;
    cin >> x;
    if (x % 2 == 0)
        y++;
    if (x > 4 && x <= 12)
        y++;
    if (y == 2)
        cout << "1 ";
    else
        cout << "0 ";
    if (y >= 1)
        cout << "1 ";
    else
        cout << "0 ";
    if (y == 1)
        cout << "1 ";
    else
        cout << "0 ";
    if (y == 0)
        cout << "1";
    else
        cout << "0";
}