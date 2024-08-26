#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, x, num = 1, max = 1;
    cin >> n;
    vector<int> V;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        V.push_back(x);
        if (i > 0)
        {
            if (V[i] == V[i - 1] + 1)
            {
                num++;
                if (num > max)
                {
                    max = num;
                }
            }
            else
            {
                num = 1;
            }
        }
    }
    cout << max;
    return 0;
}