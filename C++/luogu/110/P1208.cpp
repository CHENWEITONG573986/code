#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n, m;
multimap<int, int> M;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int price, num;
        cin >> price >> num;
        M.insert(make_pair(price, num));
    }
    int sum = 0;
    while (n)
    {
        if (M.begin()->second < n)
        {
            sum += M.begin()->first * M.begin()->second;
            n -= M.begin()->second;
        }
        else
        {
            sum += M.begin()->first * n;
            n = 0;
        }
        M.erase(M.begin());
    }
    cout << sum;
    return 0;
}