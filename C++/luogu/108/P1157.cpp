#include <iostream>
#include <vector>
using namespace std;
int n, r;
vector<int> V;
void DFS(int num, int index)
{
    if (num == r)
    {
        for (int i = 0; i < r; i++)
            printf("%3d", V[i]);
        cout << endl;
        return;
    }
    for (int i = index + 1; i <= n; i++)
    {
        V[num] = i;
        DFS(num + 1, i);
    }
}

int main()
{
    cin >> n >> r;
    V.resize(n);
    DFS(0, 0);
    return 0;
}