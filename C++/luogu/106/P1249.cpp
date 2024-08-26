#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// 最优分解
vector<int> factorization(int n)
{
    int num = 2;
    vector<int> V;
    if (n == 0)
    {
        V.push_back(0);
        return V;
    }
    while (accumulate(V.begin(), V.end(), 0) < n)
    {
        V.push_back(num);
        num++;
    }
    if (accumulate(V.begin(), V.end(), 0) - n == 1)
    {
        V.erase(V.begin());
        V.back()++;
    }
    else if (accumulate(V.begin(), V.end(), 0) - n > 1)
    {
        int k = accumulate(V.begin(), V.end(), 0) - n;
        V.erase(find(V.begin(), V.end(), k));
    }
    return V;
}
// 高精度乘以低精度
vector<int> HPM(vector<int> V, int n)
{
    reverse(V.begin(), V.end());
    for (int i = 0; i < V.size(); i++)
        V[i] *= n;
    V.resize(V.size() + 4);
    for (int i = 0; i < V.size(); i++)
    {
        V[i + 1] += V[i] / 10;
        V[i] = V[i] % 10;
    }
    while (!V.back() && V.size() > 1)
        V.pop_back();
    reverse(V.begin(), V.end());
    return V;
}
// 累乘
vector<int> MaxMul(vector<int> V)
{
    vector<int> Mul;
    Mul.push_back(1);
    for (int c : V)
        Mul = HPM(Mul, c);
    return Mul;
}
int main()
{
    int n;
    cin >> n;
    vector<int> V = factorization(n);
    for (int c : V)
        cout << c << " ";
    cout << endl;
    vector<int> max = MaxMul(V);
    for (int c : max)
        cout << c;
    return 0;
}