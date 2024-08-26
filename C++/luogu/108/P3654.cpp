#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int R, C, K;
int COUNT = 0;
vector<string> V;
vector<vector<bool>> PD;
queue<pair<int, int>> q;

bool Inside(int x, int y)
{
    return x >= 0 && x < R && y >= 0 && y < C;
}

void DFS(int x, int y)
{
    q.pop();
    // 上
    if (Inside(x - 1, y) && V[x - 1][y] == '.' && !PD[x - 1][y])
    {
        q.push(make_pair(x - 1, y));
        PD[x - 1][y] = true;
        COUNT++;
    }
    // 左
    if (Inside(x, y + 1) && V[x][y + 1] == '.' && !PD[x][y + 1])
    {
        q.push(make_pair(x, y + 1));
        PD[x][y + 1] = true;
        COUNT++;
    }
    // 下
    if (Inside(x + 1, y) && V[x + 1][y] == '.' && !PD[x + 1][y])
    {
        q.push(make_pair(x + 1, y));
        PD[x + 1][y] = true;
        COUNT++;
    }
    // 右
    if (Inside(x, y - 1) && V[x][y - 1] == '.' && !PD[x][y - 1])
    {
        q.push(make_pair(x, y - 1));
        PD[x][y - 1] = true;
        COUNT++;
    }
    if (!q.empty())
        DFS(q.front().first, q.front().second);
    return;
}

int main()
{
    cin >> R >> C >> K;
    V.resize(R);
    PD.resize(R);
    for (int i = 0; i < R; i++)
        PD[i].resize(C);
    for (int i = 0; i < R; i++)
        cin >> V[i];
    // for (int i = 0; i < R; i++)
    //     for (int j = 0; j < C; j++)
    //         if (!PD[i][j] && V[i][j] == '.')
    //         {
    //             q.push(make_pair(i, j));
    //             PD[i][j] = true;
    //             DFS(q.front().first, q.front().second);
    //         }
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            if (V[i][j] == '.')
            {
                if (K > 1)
                {
                    int a = 1;
                    for (int k = 1; k < K; k++)
                        if (Inside(i, j + k) && V[i][j + k] == '.')
                            a++;
                    if (a == K)
                        COUNT++;
                    a = 1;
                    for (int k = 1; k < K; k++)
                        if (Inside(i + k, j) && V[i + k][j] == '.')
                            a++;
                    if (a == K)
                        COUNT++;
                }
                else
                    COUNT++;
            }
        }
    cout << COUNT;
    return 0;
}