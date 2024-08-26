#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x, n = 0;
    long long sum = 0;
    while (cin >> x)
    {
        sum += x;
        n++;
    }
    sum *= pow(2, n - 1);
    cout << sum;
    return 0;
}