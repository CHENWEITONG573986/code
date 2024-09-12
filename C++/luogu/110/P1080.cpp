#include <iostream>
#include <algorithm>
using namespace std;
int s[1000000] = {1}, ans[1000000], slen = 1;
struct Persion
{
    int a, b;
} ps[10005];
bool cmp(const Persion &A, const Persion &B)
{
    return A.a * A.b < B.a * B.b;
}

void mul(int n)
{
    int tem = 0;
    for (int i = 0; i < slen; i++)
        s[i] *= n;
    for (int i = 0; i < slen; i++)
    {
        tem += s[i];
        s[i] = tem % 10;
        tem /= 10;
    }
    while (tem != 0)
    {
        s[slen] = tem % 10;
        slen++;
        tem /= 10;
    }
    return;
}
void div(int n)
{
    int tem = 0;
    for (int i = slen - 1; i >= 0; i--)
    {
        tem = tem * 10 + s[i];
        ans[i] = tem / n;
        tem %= n;
    }
    return;
}
void print()
{
    int tmp = slen;
    while (ans[tmp] == 0)
    {
        tmp--;
        if (tmp == -1)
        {
            cout << 1;
            return;
        }
    }
    for (int i = tmp; i >= 0; i--)
        cout << ans[i];
    return;
}
int main()
{
    long long n, s = 1, ans = 0;
    cin >> n;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i <= n; i++)
        cin >> ps[i].a >> ps[i].b;
    sort(ps + 1, ps + n + 1, cmp);
    for (int i = 0; i < n; i++)
        mul(ps[i].a);
    div(ps[n].b);
    print();
    return 0;
}