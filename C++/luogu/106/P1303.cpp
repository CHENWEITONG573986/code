#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Transform
{
public:
    int operator()(char val)
    {
        return val - '0';
    }
    char operator()(int val)
    {
        return val + '0';
    }
};

string HPM(const string &a, const string &b)
{
    vector<int> A, B, Mul;
    A.resize(a.size());
    B.resize(b.size());
    Mul.resize(A.size() + B.size());
    transform(a.begin(), a.end(), A.begin(), Transform());
    transform(b.begin(), b.end(), B.begin(), Transform());
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            Mul[i + j] += A[i] * B[j];
            Mul[i + j + 1] += Mul[i + j] / 10;
            Mul[i + j] %= 10;
        }
    }
    while (*Mul.rbegin() == 0 && Mul.size() > 1)
        Mul.pop_back();
    reverse(Mul.begin(), Mul.end());
    string MUL;
    MUL.resize(Mul.size());
    transform(Mul.begin(), Mul.end(), MUL.begin(), Transform());
    return MUL;
}

int main()
{
    string a, b, Mul;
    cin >> a >> b;
    Mul = HPM(a, b);
    cout << Mul;
    return 0;
}