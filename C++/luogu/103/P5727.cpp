#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> V;
    V.push_back(n);
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = n * 3 + 1;
        }
        V.push_back(n);
    }
    for (vector<int>::reverse_iterator it = V.rbegin(); it != V.rend(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}