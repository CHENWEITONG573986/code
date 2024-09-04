#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;
int n;
ll sum = 0;
multiset<ll> S;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        S.insert(a);
    }
    while (S.size() > 1)
    {
        ll a = *S.begin();
        S.erase(S.begin());
        ll b = *S.begin();
        S.erase(S.begin());
        sum += a + b;
        S.insert(a + b);
    }
    cout << sum;
    return 0;
}