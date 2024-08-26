#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
// 关系仿函数
void test01()
{
    vector<int> V;
    V.push_back(1);
    V.push_back(3);
    V.push_back(2);
    V.push_back(5);
    V.push_back(4);
    sort(V.begin(),V.end(),greater<int>());
    for(auto c:V)
        cout << c <<endl;
}
int main()
{
    test01();
}