#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MySort
{
public:
    bool operator()(const string &A, const string &B)
    {
        return A + B > B + A;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> V;
    V.resize(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    sort(V.begin(), V.end(), MySort());
    for (auto c : V)
        cout << c;
    return 0;
}