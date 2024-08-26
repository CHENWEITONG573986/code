#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Magic
{
public:
    int n;
    int m;
    int **matrix;

public:
    Magic(int n, int m)
    {
        this->n = n;
        this->m = m;
        this->matrix = new int *[n + 1];
        for (int i = 0; i <= n; i++)
            this->matrix[i] = new int[n + 1];
        int num = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                this->matrix[i][j] = ++num;
    }
    void revolve(int x, int y, int r, int z)
    {
        int temp[n + 1][n + 1];
        if (z)
        {
            for (int i = x - r; i <= x + r; i++)
                for (int j = y - r; j <= y + r; j++)
                    temp[x + y - j][y - x + i] = matrix[i][j];
        }
        else
        {
            for (int i = x - r; i <= x + r; i++)
                for (int j = y - r; j <= y + r; j++)
                    temp[x - y + j][x + y - i] = matrix[i][j];
        }
        for (int i = x - r; i <= x + r; i++)
            for (int j = y - r; j <= y + r; j++)
                matrix[i][j] = temp[i][j];
    }
    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~Magic()
    {
        for (int i = 0; i < n; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Magic M(n, m);
    for (int i = 0; i < M.m; i++)
    {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        M.revolve(x, y, r, z);
    }
    M.print();
    return 0;
}