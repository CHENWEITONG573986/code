#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

void print(int val)
{
    cout << val << " ";
}
void test01()
{
    vector<int> V1, V2, V3;
    for (int i = 0; i < 10; i++)
    {
        V1.push_back(i);
        V2.push_back(i + 5);
    }
    V3.resize(min(V1.size(), V2.size()));
    auto it = set_intersection(V1.begin(), V1.end(), V2.begin(), V2.end(), V3.begin());
    for_each(V3.begin(),it,print);
}
int main()
{
    test01();
}