#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> V;
    for (int i = 0; i < n; i++)
    {
        int x, num = 0;
        cin >> x;
        V.push_back(x);
        for (int j = 0; j < i; j++)
        {
            if (V[i] > V[j])
            {
                num++;
            }
        }
        cout << num << " ";
    }
}