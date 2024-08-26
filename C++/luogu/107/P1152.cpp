#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> V, N;
    V.resize(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    for (int i = 1; i < V.size(); i++)
    {
        if (V[i] - V[i - 1] < 0)
            N.push_back(V[i - 1] - V[i]);
        else
            N.push_back(V[i] - V[i - 1]);
    }
    sort(N.begin(), N.end());
    for (int i = 0; i < N.size(); i++)
    {
        if (N[i] != i + 1)
        {
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout << "Jolly" << endl;
    return 0;
}