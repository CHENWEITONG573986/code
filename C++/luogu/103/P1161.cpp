#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> V;
    V.resize(2000000);
    for (int i = 0; i < n; i++)
    {
        double a;
        int t;
        cin >> a >> t;
        for (int j = 1; j <= t; j++)
        {
            if (V[int(a * j)])
            {
                V[int(a * j)] = 0;
            }
            else
            {
                V[int(a * j)] = 1;
            }
        }
    }
    for (int i = 0; i < 2000000; i++)
    {
        if (V[i])
        {
            cout << i;
            break;
        }
    }
    return 0;
}