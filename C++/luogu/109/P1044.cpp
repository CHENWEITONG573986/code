#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, COUNT = 0;
vector<vector<long long>> V;

long long DFS(int i, int j)
{
    if (V[i][j])
        return V[i][j];
    if (i == 0)
        return 1;
    if (j > 0)
        V[i][j] += DFS(i, j - 1);
    V[i][j] += DFS(i - 1, j + 1);
    return V[i][j];
}

int main()
{
    cin >> N;
    V.resize(N + 1);
    for (int i = 0; i <= N; i++)
        V[i].resize(N + 1);
    cout << DFS(N, 0);
    return 0;
}