#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
char map[2060][2060];
int n;
void DFS(int x, int y, int n)
{
    if (n == 1)
    {
        map[x][y + 1] = '/';
        map[x + 1][y] = '/';
        map[x][y + 2] = '\\';
        map[x + 1][y + 3] = '\\';
        map[x + 1][y + 1] = '_';
        map[x + 1][y + 2] = '_';
        return;
    }
    int dis = pow(2, n);
    DFS(x, y + dis / 2, n - 1);
    DFS(x + dis / 2, y, n - 1);
    DFS(x + dis / 2, y + dis, n - 1);
}

int main()
{
    cin >> n;
    for (int i = 0; i < 2060; i++)
        for (int j = 0; j < 2060; j++)
            map[i][j] = ' ';
    DFS(0, 0, n);
    int dis = pow(2, n);
    for (int i = 0; i < dis; i++)
    {
        for (int j = 0; j < dis * 2; j++)
            cout << map[i][j];
        cout << endl;
    }
    return 0;
}