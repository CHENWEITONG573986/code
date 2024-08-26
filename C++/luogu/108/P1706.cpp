#include <iostream>
#include <vector>
using namespace std;
int n;
vector<bool> PD;
vector<int> V;

void DFS(int x)
{
    if (x == n)
    {
        for (int c : V)
            printf("%5d", c);
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!PD[i - 1])
        {
            PD[i - 1] = true;
            V[x] = i;
            DFS(x + 1);
            PD[i - 1] = false;
        }
    }
    return;
}

int main()
{
    cin >> n;
    V.resize(n);
    PD.resize(n);
    DFS(0);
    return 0;
}