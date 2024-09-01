#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
vector<int> V;

void CCC(int x)
{
    for (int i = 14; i >= 0; i--)
    {
        if (pow(2, i) <= x)
        {
            if (i == 1)
                cout << "2";
            else if (i == 0)
                cout << "2(0)";
            else
            {
                cout << "2(";
                CCC(i);
                cout << ")";
            }
            x -= pow(2, i);
            if (x)
                cout << "+";
        }
    }
}

int main()
{
    cin >> n;
    CCC(n);
    return 0;
}