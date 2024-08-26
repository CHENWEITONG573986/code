#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
void test01()
{
    vector<int> V1, V2, V3;
    for (int i = 0; i < 10; i++)
    {
        V1.push_back(i);
        V2.push_back(i + 1);
    }
    V3.resize(V1.size() + V2.size());
    merge(V1.begin(), V1.end(), V2.begin(), V2.end(), V3.begin());
    for (auto c : V3)
        cout << c << " ";
}
int main()
{
    test01();
}