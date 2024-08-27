#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<vector<int>> V;

vector<int> operator+(const vector<int> &A, const vector<int> &B)
{
    vector<int> Add;
    int len = max(A.size(), B.size()) + 1;
    Add.resize(len);
    for (int i = 0; i < len - 1; i++)
    {
        Add[i] += A[i] + B[i];
        Add[i + 1] += Add[i] / 10;
        Add[i] %= 10;
    }
    while (Add.back() == 0)
        Add.pop_back();
    return Add;
}

int main()
{
    cin >> N;
    if (N < 2)
    {
        if (N == 0)
            cout << '0';
        if (N == 1)
            cout << '1';
        return 0;
    }
    V.resize(N + 1);
    V[0].push_back(0);
    V[1].push_back(1);
    V[2].push_back(2);
    for (int i = 3; i <= N; i++)
        V[i] = V[i - 1] + V[i - 2];
    reverse(V[N].begin(), V[N].end());
    for (int c : V[N])
        cout << c;
    return 0;
}