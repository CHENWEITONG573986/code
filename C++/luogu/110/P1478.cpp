#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, s, a, b;
vector<int> V;
int COUNT = 0;

int main()
{
    cin >> n >> s >> a >> b;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x <= a + b)
        {
            V.push_back(y);
        }
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < V.size(); i++)
    {
        if (s - V[i] >= 0)
        {
            s -= V[i];
            COUNT++;
        }
    }
    cout << COUNT;
    return 0;
}