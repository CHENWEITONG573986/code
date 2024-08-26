#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int Matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Matrix[i][j] = 0;
        }
    }
    int Row = 0, Column = 0, num = 1;
    Matrix[Row][Column] = num;
    if (n > 1)
    {
        while (Matrix[Row][Column + 1] == 0 || Matrix[Row + 1][Column] == 0 || Matrix[Row][Column - 1] == 0 || Matrix[Row - 1][Column] == 0)
        {
            while (Matrix[Row][Column + 1] == 0 && Column + 1 < n)
            {
                Column++;
                num++;
                Matrix[Row][Column] = num;
            }
            while (Matrix[Row + 1][Column] == 0 && Row + 1 < n)
            {
                Row++;
                num++;
                Matrix[Row][Column] = num;
            }
            while (Matrix[Row][Column - 1] == 0 && Column > 0)
            {
                Column--;
                num++;
                Matrix[Row][Column] = num;
            }
            while (Matrix[Row - 1][Column] == 0 && Row > 0)
            {
                Row--;
                num++;
                Matrix[Row][Column] = num;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", Matrix[i][j]);
        }
        cout << endl;
    }
}