#include <bits/stdc++.h>
using namespace std;
int n, m;
list<int> L;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        L.push_back(i);
    auto now = L.begin();
    while (L.size() > 1)
    {
        for (int i = 1; i < m; i++)
        {
            now++;
            if (now == L.end())
                now = L.begin();
        }
        auto it = now;
        now++;
        if (now == L.end())
            now = L.begin();
        cout << *it << " ";
        L.erase(it);
    }
    cout << L.front();
    return 0;
}