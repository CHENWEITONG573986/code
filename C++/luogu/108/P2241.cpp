#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    long long square = 0;
    long long rectangle = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            square += min(i, j);
            sum += i * j;
        }
    rectangle = sum - square;
    cout << square << " " << rectangle;
    return 0;
}