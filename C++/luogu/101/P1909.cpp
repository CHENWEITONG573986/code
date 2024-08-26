#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, A[3][2], x[3];
    cin >> n;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            cin >> A[i][j];
    for (int i = 0; i < 3; i++)
        x[i] = ceil((double)n / (double)A[i][0]) * A[i][1];
    cout << min(min(x[0], x[1]), x[2]) << endl;
    return 0;
}