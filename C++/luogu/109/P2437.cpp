#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m, n;
vector<vector<int>> V;

vector<int> operator+(const vector<int> &A, const vector<int> &B)
{
    vector<int> Add;
    int len = max(A.size(), B.size());
    Add.resize(len + 1);
    for (int i = 0; i < len; i++)
    {
        Add[i] += A[i] + B[i];
        Add[i + 1] += Add[i] / 10;
        Add[i] %= 10;
    }
    while (!Add.back())
        Add.pop_back();
    return Add;
}

int main()
{
    cin >> m >> n;
    V.resize(n + 1);
    V[m + 1].push_back(1);
    V[m + 2].push_back(2);
    for (int i = m + 3; i <= n; i++)
    {
        V[i] = V[i - 1] + V[i - 2];
    }
    reverse(V[n].begin(), V[n].end());
    for (int c : V[n])
        cout << c;
    return 0;
}