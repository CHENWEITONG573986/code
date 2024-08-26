#include <iostream>
using namespace std;
int main()
{
    int n, m, k, num = 0;
    cin >> n >> m >> k;
    int Matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        for (int j = x - 1; j <= x + 1; j++)
        {
            for (int k = y - 1; k <= y + 1; k++)
            {
                if (j >= 0 && j < n && k >= 0 && k < n)
                {
                    Matrix[j][k] = 1;
                }
            }
        }
        if (x - 2 >= 0)
            Matrix[x - 2][y] = 1;
        if (x + 2 < n)
            Matrix[x + 2][y] = 1;
        if (y - 2 >= 0)
            Matrix[x][y - 2] = 1;
        if (y + 2 < n)
            Matrix[x][y + 2] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        for (int j = x - 2; j <= x + 2; j++)
        {
            for (int k = y - 2; k <= y + 2; k++)
            {
                if (j >= 0 && j < n && k >= 0 && k < n)
                {
                    Matrix[j][k] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Matrix[i][j] == 0)
            {
                num++;
            }
        }
    }
    cout << num;
    return 0;
}