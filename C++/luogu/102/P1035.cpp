#include <iostream>
using namespace std;
int main()
{
    int k;
    cin >> k;
    double Sn = 1;
    int n = 1;
    while (Sn <= k)
    {
        n++;
        Sn += 1 / double(n);
    }
    cout << n;
}