#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n, m;
    int num = 0;
    int direction, count;
    vector<pair<int, string>> V;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int direction;
        string name;
        cin >> direction >> name;
        V.push_back(pair<int, string>(direction, name));
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> direction >> count;
        if (V[num].first == 0 && direction == 0)
            num = (num + n - count) % n;
        else if (V[num].first == 0 && direction == 1)
            num = (num + count) % n;
        else if (V[num].first == 1 && direction == 0)
            num = (num + count) % n;
        else if (V[num].first == 1 && direction == 1)
            num = (num + n - count) % n;
    }
    cout << V[num].second;
    return 0;
}