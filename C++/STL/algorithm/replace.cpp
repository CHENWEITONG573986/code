#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
void test01()
{
    vector<int> V1;
    for (int i = 0; i < 10; i++)
    {
        V1.push_back(i);
    }
    replace(V1.begin(), V1.end(), 4, 400);
    for (auto c : V1)
        cout << c << " ";
}
int main()
{
    test01();
}