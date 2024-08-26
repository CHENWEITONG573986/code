#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, N = 0;
    string num, LED[5][100];
    cin >> n;
    cin >> num;
    for (int i = 0; i < n; i++)
    {
        switch (num[i] - '0')
        {
        case 0:
            LED[0][N] = "XXX";
            LED[1][N] = "X.X";
            LED[2][N] = "X.X";
            LED[3][N] = "X.X";
            LED[4][N] = "XXX";
            N++;
            break;
        case 1:
            LED[0][N] = "..X";
            LED[1][N] = "..X";
            LED[2][N] = "..X";
            LED[3][N] = "..X";
            LED[4][N] = "..X";
            N++;
            break;
        case 2:
            LED[0][N] = "XXX";
            LED[1][N] = "..X";
            LED[2][N] = "XXX";
            LED[3][N] = "X..";
            LED[4][N] = "XXX";
            N++;
            break;
        case 3:
            LED[0][N] = "XXX";
            LED[1][N] = "..X";
            LED[2][N] = "XXX";
            LED[3][N] = "..X";
            LED[4][N] = "XXX";
            N++;
            break;
        case 4:
            LED[0][N] = "X.X";
            LED[1][N] = "X.X";
            LED[2][N] = "XXX";
            LED[3][N] = "..X";
            LED[4][N] = "..X";
            N++;
            break;
        case 5:
            LED[0][N] = "XXX";
            LED[1][N] = "X..";
            LED[2][N] = "XXX";
            LED[3][N] = "..X";
            LED[4][N] = "XXX";
            N++;
            break;
        case 6:
            LED[0][N] = "XXX";
            LED[1][N] = "X..";
            LED[2][N] = "XXX";
            LED[3][N] = "X.X";
            LED[4][N] = "XXX";
            N++;
            break;
        case 7:
            LED[0][N] = "XXX";
            LED[1][N] = "..X";
            LED[2][N] = "..X";
            LED[3][N] = "..X";
            LED[4][N] = "..X";
            N++;
            break;
        case 8:
            LED[0][N] = "XXX";
            LED[1][N] = "X.X";
            LED[2][N] = "XXX";
            LED[3][N] = "X.X";
            LED[4][N] = "XXX";
            N++;
            break;
        case 9:
            LED[0][N] = "XXX";
            LED[1][N] = "X.X";
            LED[2][N] = "XXX";
            LED[3][N] = "..X";
            LED[4][N] = "XXX";
            N++;
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << LED[i][j];
            if (j != n - 1)
                cout << '.';
        }
        cout << endl;
    }
    return 0;
}