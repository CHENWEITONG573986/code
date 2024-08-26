#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Ingredients
{
public:
    int acidity;
    int Bitterness;
};

int n;
int MIN = 1e9;
bool DP[10];
vector<Ingredients> V;

void DFS(int x, bool s)
{
    DP[x] = s;
    if (x == n - 1)
    {
        int sumA = 1, sumB = 0;
        for (int i = 0; i < n; i++)
        {
            if (DP[i])
            {
                sumA *= V[i].acidity;
                sumB += V[i].Bitterness;
            }
        }
        if (sumA == 1 && sumB == 0)
            return;
        MIN = min(MIN, abs(sumA - sumB));
        return;
    }
    DFS(x + 1, true);
    DFS(x + 1, false);
    return;
}

int main()
{
    cin >> n;
    V.resize(n);
    for (int i = 0; i < n; i++)
        cin >> V[i].acidity >> V[i].Bitterness;
    DFS(0, true);
    DFS(0, false);
    cout << MIN;
    return 0;
}