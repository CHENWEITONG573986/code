#include <bits/stdc++.h>
using namespace std;
int S[5], sum, Time, homework[21], DP[2501];
int main()
{
    for (int i = 1; i <= 4; i++)
        cin >> S[i];
    for (int i = 1; i <= 4; i++)
    {
        sum = 0;
        for (int j = 1; j <= S[i]; j++)
        {
            cin >> homework[j]; // 输入
            sum += homework[j];
        } // 总时间累加
        for (int j = 1; j <= S[i]; j++)
            for (int k = sum / 2; k >= homework[j]; k--)               // 只要是总和的一半
                DP[k] = max(DP[k], DP[k - homework[j]] + homework[j]); // 01背包
        Time += sum - DP[sum / 2];                                     // 累加为另一个脑子
        for (int j = 1; j <= sum / 2; j++)
            DP[j] = 0; // 清零
    }
    cout << Time; // 输出
    return 0;
}