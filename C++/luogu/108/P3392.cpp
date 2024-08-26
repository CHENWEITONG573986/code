#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int N, M, ans = 0x7fffffff;
string str;
vector<int> W, B, R;

int check(char S)
{
    int count = 0;
    for (char c : str)
        if (c != S)
            count++;
    return count;
}
int main()
{
    cin >> N >> M;
    W.resize(N + 1);
    B.resize(N + 1);
    R.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> str;
        W[i] = W[i - 1] + check('W');
        B[i] = B[i - 1] + check('B');
        R[i] = R[i - 1] + check('R');
    }
    for (int i = 1; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            ans = min(ans, W[i] + B[j] - B[i] + R[N] - R[j]);
    cout << ans;
    return 0;
}