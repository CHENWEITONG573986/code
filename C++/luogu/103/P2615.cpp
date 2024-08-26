#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int Matrix[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Matrix[i][j] = 0;
        }
    }
    int Row = 0, Column = N / 2;
    Matrix[Row][Column] = 1;
    for (int i = 2; i <= N * N; i++)
    {
        if (Row == 0 && Column != N - 1)
        {
            Row = N - 1;
            Column += 1;
            Matrix[Row][Column] = i;
        }
        else if (Row != 0 && Column == N - 1)
        {
            Row -= 1;
            Column = 0;
            Matrix[Row][Column] = i;
        }
        else if (Row == 0 && Column == N - 1)
        {
            Row += 1;
            Matrix[Row][Column] = i;
        }
        else if (Row != 0 && Column != N - 1)
        {
            if (Matrix[Row - 1][Column + 1] == 0)
            {
                Row -= 1;
                Column += 1;
                Matrix[Row][Column] = i;
            }
            else
            {
                Row += 1;
                Matrix[Row][Column] = i;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}