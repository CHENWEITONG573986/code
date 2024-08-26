#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int Triangle[n][n];
    for (int i = 0; i < n; i++)
    {
        Triangle[i][0] = 1;
        Triangle[i][i] = 1;
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            Triangle[i][j] = Triangle[i - 1][j] + Triangle[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << Triangle[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
