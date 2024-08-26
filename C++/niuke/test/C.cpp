#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    map<int, int> M;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        M[x]++;
    }
    int id = 1, num, count = 0;
    for (auto c : M)
    {
        if (c.first == 1)
        {
            num = c.second;
            count += num;
        }
        else if (c.first == id)
        {
            if (c.second < num)
            {
                num = c.second;
                count += num;
            }
            else
            {
                count += num;
            }
        }
        id++;
    }
    cout << count;
    return 0;
}