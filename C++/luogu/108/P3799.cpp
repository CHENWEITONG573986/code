// 知识点：组合数，暴力
/*
By:Luckyblock
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int kMaxn = 1e6 + 10;
const ll kMod = 1e9 + 7;
//=============================================================
ll n, ans, maxa, a[kMaxn], num[kMaxn];
//=============================================================
ll C(ll x, ll k)
{
    // 求得从n个数中取出k个数的组合
    // 此处k=1 / 2，用了特判写法。
    // k = 1 时，C(x, 1) = x;
    // k = 2 时，C(x, 2) = x * (x - 1) / 2;
    return (k == 1ll ? x : x * (x - 1ll) / 2ll) % kMod;
}
//=============================================================
int main()
{
    scanf("%lld\n", &n);
    for (int i = 1; i <= n; ++i)
    { // 读入,并放入计数数组中
        scanf("%lld", &a[i]);
        maxa = max(a[i], maxa);
        num[a[i]]++;
    }

    for (int i = 2; i <= maxa; ++i)
    { // 枚举两根相等的边
        if (num[i] >= 2ll)
        {
            ll times = C(num[i], 2ll) % kMod; // 求出组合数
            for (int j = 1; j <= i / 2; ++j)
            {                                                     // 枚举被合成的边(到i / 2即可)
                if (j != i - j && num[j] >= 1 && num[i - j] >= 1) // 用来合成的木棒长度不等
                    ans += times * C(num[j], 1) * C(num[i - j], 1) % kMod;
                if (j == i - j && num[j] >= 2) // 用来合成的木棒长度相等
                    ans += times * C(num[j], 2) % kMod;
                ans %= kMod;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}