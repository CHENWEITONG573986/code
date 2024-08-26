#include <iostream>
using namespace std;
int main()
{
    int w, x, h;
    cin >> w >> x >> h;
    int Cube[w][x][h] = {0};
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < h; k++)
            {
                Cube[i][j][k] = 1;
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1 - 1; i < x2; i++)
        {
            for (int j = y1 - 1; j < y2; j++)
            {
                for (int k = z1 - 1; k < z2; k++)
                {
                    Cube[i][j][k] = 0;
                }
            }
        }
    }
    int Volume = 0;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < h; k++)
            {
                if (Cube[i][j][k] == 1)
                {
                    Volume++;
                }
            }
        }
    }
    cout << Volume;
}