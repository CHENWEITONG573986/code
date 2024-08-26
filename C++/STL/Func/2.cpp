#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 谓词

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> V;
    for (int i = 0; i < 10; i++)
    {
        V.push_back(i);
    }
    // GreaterFive()匿名函数对象
    auto it = find_if(V.begin(), V.end(), GreaterFive());
}
int main()
{
    test01();
}