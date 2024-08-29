#include <iostream>
#define ll long long
using namespace std;
ll a, b, c;
ll dp[25][25][25];

ll w(ll a, ll b, ll c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    else if (a < b && b < c)
    {
        if (!dp[a][b][c - 1])
            dp[a][b][c - 1] = w(a, b, c - 1);
        if (!dp[a][b - 1][c - 1])
            dp[a][b - 1][c - 1] = w(a, b - 1, c - 1);
        if (!dp[a][b - 1][c])
            dp[a][b - 1][c] = w(a, b - 1, c);
        dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
    }
    else
    {
        if (!dp[a - 1][b][c])
            dp[a - 1][b][c] = w(a - 1, b, c);
        if (!dp[a - 1][b - 1][c])
            dp[a - 1][b - 1][c] = w(a - 1, b - 1, c);
        if (!dp[a - 1][b][c - 1])
            dp[a - 1][b][c - 1] = w(a - 1, b, c - 1);
        if (!dp[a - 1][b - 1][c - 1])
            dp[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
        dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - w(a - 1, b - 1, c - 1);
    }
    return dp[a][b][c];
}

int main()
{
    while (true)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
    return 0;
}