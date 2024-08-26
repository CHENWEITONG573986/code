#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
using namespace std;

void test01()
{
    srand((unsigned int)time(NULL));
    vector<int> V;
    for (int i = 0; i < 10; i++)
    {
        V.push_back(i);
    }
    random_shuffle(V.begin(), V.end());
    for (auto c : V)
        cout << c << endl;
}

int main()
{
    test01();
}