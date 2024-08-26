#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long Sn = 0;
    for (int i = 1; i <= n; i++)
    {
        Sn += i;
    }
    cout << Sn;
}