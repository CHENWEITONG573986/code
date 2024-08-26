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

string HPA(const string &a, const string &b)
{
    vector<int> A, B, Add;
    A.resize(a.size());
    B.resize(b.size());
    Add.resize(max(A.size(), B.size()) + 1);
    transform(a.begin(), a.end(), A.begin(), Transform());
    transform(b.begin(), b.end(), B.begin(), Transform());
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    A.resize(max(A.size(), B.size()));
    B.resize(max(A.size(), B.size()));
    for (int i = 0; i < Add.size() - 1; i++)
    {
        Add[i] += A[i] + B[i];
        Add[i + 1] += Add[i] / 10;
        Add[i] %= 10;
    }
    while (*Add.rbegin() == 0 && Add.size() > 1)
        Add.pop_back();
    reverse(Add.begin(), Add.end());
    string ADD;
    ADD.resize(Add.size());
    transform(Add.begin(), Add.end(), ADD.begin(), Transform());
    return ADD;
}

int main()
{
    string a, b, Add;
    cin >> a >> b;
    Add = HPA(a, b);
    cout << Add;
    return 0;
}