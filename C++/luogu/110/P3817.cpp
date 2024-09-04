#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;
int n, x;
ll num = 0;
vector<ll> V;

int main()
{
    cin >> n >> x;
    V.resize(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    if (V[0] > x)
    {
        num += V[0] - x;
        V[0] = x;
    }
    for (int i = 1; i < n; i++)
    {
        if (V[i] + V[i - 1] > x)
        {
            num += V[i] + V[i - 1] - x;
            V[i] = x - V[i - 1];
        }
    }
    cout << num;
    return 0;
}