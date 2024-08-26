#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n, JC;
    cin >> n;
    multiset<int> S;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        S.insert(x);
    }
    JC = *S.rbegin() - *S.begin();
    cout << JC;
    return 0;
}