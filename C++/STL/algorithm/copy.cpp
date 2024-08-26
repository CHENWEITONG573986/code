#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
void test01()
{
    vector<int> V1,V2;
    for (int i = 0; i < 10; i++)
    {
        V1.push_back(i);
    }
    V2.resize(V1.size());
    copy(V1.begin(), V1.end(),V2.begin());
    for (auto c : V2)
        cout << c << " ";

}
int main()
{
    test01();
}