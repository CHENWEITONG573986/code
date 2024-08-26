#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int num[n], MIN = 0, temp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        if (i < m)
        {
            temp += num[i];
            MIN = temp;
        }
        else
        {
            temp = temp + num[i] - num[i - m];
        }
        MIN = min(MIN, temp);
    }
    cout << MIN;
    return 0;
}