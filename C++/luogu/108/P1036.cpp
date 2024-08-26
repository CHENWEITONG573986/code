#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, k;
vector<int> V;
int COUNT = 0;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i < sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void DFS(int x, int sum, int index)
{
    if (x == k)
    {
        if (isPrime(sum))
            COUNT++;
        return;
    }
    for (int i = index; i < n; i++)
        DFS(x + 1, sum + V[i], i + 1);
    return;
}

int main()
{
    cin >> n >> k;
    V.resize(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    DFS(0, 0, 0);
    cout << COUNT << endl;
    return 0;
}