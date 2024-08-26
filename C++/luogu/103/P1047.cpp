#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int l, m, num = 0;
    cin >> l >> m;
    vector<int> V;
    V.resize(l + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        for (int j = u; j <= v; j++)
        {
            V[j] = 1;
        }
    }
    for (int i = 0; i <= l; i++)
    {
        if (V[i] == 0)
        {
            num++;
        }
    }
    cout << num;
    return 0;
}