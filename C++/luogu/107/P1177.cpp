#include <iostream>
#include <set>
using namespace std;
int main()
{
    int N;
    cin >> N;
    multiset<int> S;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        S.insert(a);
    }
    for (int c : S)
        cout << c << " ";
    return 0;
}