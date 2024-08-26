#include <iostream>
#include <set>
using namespace std;
int main()
{
    int N;
    cin >> N;
    set<int> S;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        S.insert(a);
    }
    cout << S.size() << endl;
    for (int c : S)
        cout << c << " ";
    return 0;
}