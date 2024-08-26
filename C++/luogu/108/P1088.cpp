#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int COUNT = 0;
vector<int> V;

int main()
{
    cin >> n >> m;
    V.resize(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    while (next_permutation(V.begin(), V.end()))
    {
        COUNT++;
        if (COUNT == m)
        {
            for (int c : V)
                printf("%d ", c);
            break;
        }
    }
    return 0;
}