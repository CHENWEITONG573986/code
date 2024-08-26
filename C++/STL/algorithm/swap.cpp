#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
void test01()
{
    vector<int> V1, V2;
    for (int i = 0; i < 10; i++)
    {
        V1.push_back(i);
        V2.push_back(i + 1);
    }
    swap(V1, V2);
    for (auto c : V1)
        cout << c << " ";
    cout << endl;
    for (auto c : V2)
        cout << c << " ";
}
int main()
{
    test01();
}