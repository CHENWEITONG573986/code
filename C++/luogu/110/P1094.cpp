#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int w, n;
vector<int> V;
int main()
{
    cin >> w >> n;
    V.resize(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    sort(V.begin(), V.end());
    int count = 0;
    while (V.size())
    {
        if (V.back() + V.front() <= w)
            V.erase(V.begin());
        if (V.size())
            V.pop_back();
        count++;
    }
    cout << count;
    return 0;
}