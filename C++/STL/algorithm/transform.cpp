#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Transform
{
public:
    int operator()(int val)
    {
        return val;
    }
};

void test01()
{
    vector<int> V;
    for (int i = 0; i < 10; i++)
        V.push_back(i);
    vector<int> VT;
    VT.resize(V.size());
    transform(V.begin(), V.end(), VT.begin(), Transform());
}

int main()
{
    test01();
}