#include <iostream>
using namespace std;

class Minesweeper
{
public:
    int n;
    int m;
    char **matrix;

public:
    Minesweeper(int n, int m) : n(n), m(m)
    {
        matrix = new char *[n];
        for (int i = 0; i < n; i++)
            matrix[i] = new char[m];
    }
    void Init()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
    }
    int getMine(int x, int y)
    {
        int count = 0;
        for (int i = x - 1; i <= x + 1; i++)
            for (int j = y - 1; j <= y + 1; j++)
                if (i >= 0 && i < n && j >= 0 && j < m)
                    if (matrix[i][j] == '*')
                        count++;
        return count;
    }
    ~Minesweeper()
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
    Minesweeper M(n, m);
    M.Init();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M.matrix[i][j] == '*')
                cout << '*';
            else
                cout << M.getMine(i, j);
        }
        cout << endl;
    }
    return 0;
}