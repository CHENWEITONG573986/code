#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> V;
    while (true)
    {
        int x;
        cin >> x;
        if (x)
        {
            V.push_back(x);
        }
        else
        {
            break;
        }
    }
    for (vector<int>::reverse_iterator it = V.rbegin(); it != V.rend(); it++)
    {
        cout << *it <<" ";
    }
    return 0;
}