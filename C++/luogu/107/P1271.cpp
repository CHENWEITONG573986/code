#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    multiset<int> S;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        S.insert(a);
    }
    for (int c : S)
        cout << c << " ";
    return 0;
}