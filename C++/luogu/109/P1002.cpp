#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int B_x, B_y, Horse_x, Horse_y;
vector<vector<long long>> num;

bool Horse(int x, int y)
{
    if (x == Horse_x && y == Horse_y)
        return true;
    if ((x == Horse_x + 2 || x == Horse_x - 2) && (y == Horse_y + 1 || y == Horse_y - 1))
        return true;
    if ((x == Horse_x + 1 || x == Horse_x - 1) && (y == Horse_y + 2 || y == Horse_y - 2))
        return true;
    return false;
}

int main()
{
    cin >> B_x >> B_y >> Horse_x >> Horse_y;
    num.resize(B_x + 1);
    for (int i = 0; i <= B_x; i++)
        num[i].resize(B_y + 1);
    num[B_x][B_y] = 1;
    for (int x = B_x; x >= 0; x--)
        for (int y = B_y; y >= 0; y--)
        {
            if (Horse(x, y))
                num[x][y] = 0;
            else if (x == B_x && y != B_y)
                num[x][y] = num[x][y + 1];
            else if (x != B_x && y == B_y)
                num[x][y] = num[x + 1][y];
            else if (x < B_x && y < B_y)
                num[x][y] = num[x + 1][y] + num[x][y + 1];
        }
    cout << num[0][0];
    return 0;
}