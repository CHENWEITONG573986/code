#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int num[n];
    set<int> S;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (num[k] == num[i] + num[j])
                {
                    S.insert(num[k]);
                }
            }
        }
    }
    cout << S.size();
    return 0;
}