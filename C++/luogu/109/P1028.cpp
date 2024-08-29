#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> V;

int main()
{
    cin >> n;
    V.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i / 2; j++)
            V[i] += V[j];
        V[i]++;
    }
    cout << V[n];
    return 0;
}