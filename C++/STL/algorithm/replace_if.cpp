#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Myif
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> V1;
    for (int i = 0; i < 10; i++)
    {
        V1.push_back(i);
    }
    replace_if(V1.begin(), V1.end(), Myif(), 400);
    for (auto c : V1)
        cout << c << " ";
}
int main()
{
    test01();
}