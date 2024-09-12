#include <bits/stdc++.h>
using namespace std;
queue<int> Q;
int Hash[1003] = {0};
int M, N, COUNT = 0;
int main()
{
    cin >> M >> N;
    while (N--)
    {
        int a;
        cin >> a;
        if (!Hash[a])
        {
            COUNT++;
            Q.push(a);
            Hash[a] = 1;
            while (Q.size() > M)
            {
                Hash[Q.front()] = 0;
                Q.pop();
            }
        }
    }
    cout << COUNT;
    return 0;
}