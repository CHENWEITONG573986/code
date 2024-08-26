#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 输出结果
void print(const vector<int> &V)
{
    for (vector<int>::const_reverse_iterator it = V.rbegin(); it != V.rend(); it++)
    {
        cout << *it;
    }
    cout << endl;
}
// 高精度加法
vector<int> Adder(const vector<int> &A, const vector<int> &B)
{
    vector<int> Add;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size())
        {
            t += A[i];
        }
        if (i < B.size())
        {
            t += B[i];
        }
        Add.push_back(t % 10);
        t /= 10;
    }
    if (t)
    {
        Add.push_back(t);
    }
    return Add;
}
// 高精度乘法
vector<int> Multiplier(const vector<int> A, const vector<int> B)
{
    vector<int> Mul;
    // 初始化乘积
    Mul.resize(A.size() + B.size());
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            Mul[i + j] += A[i] * B[j];         // 累加乘积
            Mul[i + j + 1] += Mul[i + j] / 10; // 进位
            Mul[i + j] %= 10;                  // 存余
        }
    }
    vector<int>::reverse_iterator it = Mul.rbegin();
    while (*it == 0)
    {
        Mul.pop_back();
        it++;
    }
    return Mul;
}
int main()
{
    int n;
    cin >> n;
    vector<int> Sn, Tn, temp, One;
    Sn.push_back(0);
    Tn.push_back(1);
    temp.push_back(0);
    One.push_back(1);
    for (int i = 0; i < n; i++)
    {
        temp = Adder(temp, One);
        Tn = Multiplier(Tn, temp);
        Sn = Adder(Sn, Tn);
    }
    print(Sn);
    return 0;
}